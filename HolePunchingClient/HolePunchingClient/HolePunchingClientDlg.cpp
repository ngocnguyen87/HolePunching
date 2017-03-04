// HolePunchingClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HolePunchingClient.h"
#include "HolePunchingClientDlg.h"
#include <winsock2.h>
#include "commonstruct.h"
#include ".\holepunchingclientdlg.h"
#include "CaptureVideo.h"
#include "VSS35Encoder.h"
#include "VSS35Decoder.h"
#include "RtpPacket.h"

#include <ippi.h>
#include <ippcc.h>

#pragma comment(lib,"ippcc.lib")

#define RTP_HEADER_SIZE  12
#define RAW_DATA_SIZE	 64*1024

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WM_SEND_DATA			WM_USER + 1
BYTE m_pDecodeBuffer[1024*1024];

// CAboutDlg dialog used for App About

CVideoPlayer* CHolePunchingClientDlg::m_pPlayer = NULL;

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CHolePunchingClientDlg dialog



CHolePunchingClientDlg::CHolePunchingClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHolePunchingClientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bSendData = false;
	m_bServerConnected = false;
	m_bEndSendThread = false;
	m_bTransmitVideo = false;

	m_hTrafficMutex = CreateMutex(NULL, FALSE, NULL);
	memset(m_szServerAddr, 0, sizeof(m_szServerAddr));
	memset(m_szName, 0, sizeof(m_szName));
	memset(m_szPrivateIp, 0, sizeof(m_szPrivateIp));

	memset(m_szDesAddr, 0, sizeof(m_szDesAddr));

	m_nDesPort = 0;
	m_SeqNumber = 0;
	int nMySequence = 0;

	m_pDataBuffer = new BYTE[RTP_HEADER_SIZE + RAW_DATA_SIZE];
}

void CHolePunchingClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listbox);
}

BEGIN_MESSAGE_MAP(CHolePunchingClientDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_STOP, OnBnClickedStop)
	ON_BN_CLICKED(IDC_CALL, OnBnClickedCall)
	ON_MESSAGE(WM_SEND_DATA, SendData)
END_MESSAGE_MAP()


// CHolePunchingClientDlg message handlers

BOOL CHolePunchingClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	GetDlgItem(IDC_STOP)->EnableWindow(0);

	GetPrivateProfileString("setting", "server_addr", NULL, m_szServerAddr, sizeof(m_szServerAddr), ".\\config.ini");
	if(m_szServerAddr == NULL)
	{
		TRACE("Cant get server addr");
		m_listbox.InsertString(0, "Cant get server addr");
		return TRUE;
	}
	m_nServerPort = GetPrivateProfileInt("setting", "server_port", 0, ".\\config.ini");

	GetPrivateProfileString("setting", "name", NULL, m_szName, sizeof(m_szName), ".\\config.ini");
	strcpy(m_szPrivateIp, getNetworkIp());

	m_nPrivatePort = GetPrivateProfileInt("setting", "private_port", 0, ".\\config.ini");
	

	//init socket
	sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(u_short(m_nPrivatePort));

	m_hPunchingSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(m_hPunchingSocket == INVALID_SOCKET)
	{
		TRACE("Init Socket false");
		m_listbox.InsertString(0, "Init Socket false");
		return TRUE;
	}

	if(bind(m_hPunchingSocket, (sockaddr*)&addr, sizeof(addr)) != 0)
	{
		TRACE("Bind Socket false");
		m_listbox.InsertString(0, "Bind Socket false");

		closesocket(m_hPunchingSocket);
		m_hPunchingSocket = INVALID_SOCKET;

		return TRUE;
	}
		
	//addr server
	int nByteSend;
	int addr_len;

	sockaddr_in addr_to;

	addr_to.sin_family = AF_INET;
	addr_to.sin_addr.S_un.S_addr = inet_addr(m_szServerAddr);
	addr_to.sin_port = htons(m_nServerPort);

	addr_len = sizeof(addr_to);

	//registration struct
	CommonStruct registration;
	memset(&registration, 0, sizeof(CommonStruct));
	
	registration.nId = ID_REGISTRATION;
	strcpy(registration.szName, m_szName);
	strcpy(registration.szPrivateIp, m_szPrivateIp);
	registration.nPrivatePort = m_nPrivatePort;

	nByteSend = sendto(m_hPunchingSocket, (LPSTR)&registration, sizeof(CommonStruct), 0, (sockaddr*)&addr_to, addr_len);

	AfxBeginThread(RecvThread, this);
	//AfxBeginThread(SendDataThread, this);
	//::PostMessage(pTHIS->m_hWnd, WM_SEND_DATA, NULL, NULL);

	m_nSender = GetPrivateProfileInt("setting", "sender", 0, ".\\config.ini");
	if(m_nSender)
		initEncode();
	else
		initDecode();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHolePunchingClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHolePunchingClientDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHolePunchingClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CHolePunchingClientDlg::SendData(WPARAM wParam, LPARAM lParam)
{
	AfxBeginThread(SendDataThread, this);
	return 0;
}

UINT CHolePunchingClientDlg::SendDataThread(void* pUser)
{
	CHolePunchingClientDlg* pTHIS = (CHolePunchingClientDlg*)pUser;

	char szMessage[100];
	int nByteSend;
	int addr_len;

	sockaddr_in addr_to;
	addr_to.sin_family = AF_INET;
	addr_to.sin_addr.S_un.S_addr = inet_addr(pTHIS->m_szDesAddr);
	addr_to.sin_port = htons(pTHIS->m_nDesPort);

	sockaddr_in addr_server;
	addr_server.sin_family = AF_INET;
	addr_server.sin_addr.S_un.S_addr = inet_addr(pTHIS->m_szServerAddr);
	addr_server.sin_port = htons(pTHIS->m_nServerPort);

	CommonStruct ack;
	memset(&ack, 0, sizeof(CommonStruct));
	ack.nId = ID_HEART_BEAT;

	addr_len = sizeof(addr_to);

	while(!pTHIS->m_bEndSendThread)
	{
		if(pTHIS->m_bSendData)
		{
			sprintf(szMessage, "%s %s", "Punching hole message from", pTHIS->m_szName);

			nByteSend = sendto(pTHIS->m_hPunchingSocket, szMessage, sizeof(szMessage), 0, (sockaddr*)&addr_to, addr_len);

			TRACE("\n");
			sprintf(szMessage, "%s %s", "Send punching hole message to", pTHIS->m_szDesAddr);
			TRACE(szMessage);
			pTHIS->m_listbox.InsertString(0, szMessage);
		}

		//if(pTHIS->m_bServerConnected)
		//{
		//	int nSendByte = sendto(pTHIS->m_hPunchingSocket, (LPSTR)&ack, sizeof(CommonStruct), 0, (sockaddr*)&addr_server, addr_len );					
		//	
		//	TRACE("\n");
		//	sprintf(szMessage, "%s", "Send heart beat back to server");
		//	TRACE(szMessage);
		//	pTHIS->m_listbox.InsertString(0, szMessage);
		//}

		Sleep(2000);
	}
	return 0;
}

UINT CHolePunchingClientDlg::RecvThread(void* pUser)
{
	CHolePunchingClientDlg* pTHIS = (CHolePunchingClientDlg*)pUser;

	static dwRecvTime = GetTickCount();
		
	char* szRecvBuf = new char[1024];
	memset(szRecvBuf, 0, 1024);

	char szMessage[100];

	int nByteRecv = 0;
	int nByteSend = 0;

	sockaddr_in addr_from;
	int len = sizeof(addr_from);

	while(1)
	{
		TRACE("\n");
		WaitForSingleObject(pTHIS->m_hTrafficMutex, INFINITE);

		nByteRecv = recvfrom(pTHIS->m_hPunchingSocket, szRecvBuf, 1024, 0, (sockaddr*)&addr_from, &len);
		if(nByteRecv > 0 && nByteRecv == sizeof(CommonStruct))
		{
			CommonStruct *commonStruct = (CommonStruct*)szRecvBuf;

			switch(commonStruct->nId)
			{
			case ID_REGISTRATION:
				break;
			case ID_HEART_BEAT:
				pTHIS->m_bServerConnected = true;
				{
					TRACE("Receive heart beat message from server");
					pTHIS->m_listbox.InsertString(0, "Receive heart beat message from server");
				}
				break;
			case ID_MAKE_CALL:
				break;
			case ID_COMMAND_MAKE_CALL:
				{
					memset(pTHIS->m_szDesAddr, 0, sizeof(pTHIS->m_szDesAddr));
					strcpy(pTHIS->m_szDesAddr, commonStruct->szPublicIp);
					pTHIS->m_nDesPort = commonStruct->nPublicPort;

					pTHIS->GetDlgItem(IDC_STOP)->EnableWindow(1);

					if(pTHIS->m_nSender)
					{
						//Sleep(1500);

						pTHIS->m_bEndSendThread = true;

						TRACE("Start SEND data to client");
						pTHIS->m_listbox.InsertString(0, "Start SEND data to client");

						pTHIS->initCapture();
						
						//ReleaseMutex(pTHIS->m_hTrafficMutex);
						//return 0;
					}
					else
					{
						TRACE("Start RECEIVE data from client");
						pTHIS->m_listbox.InsertString(0, "Start RECEIVE data from client");		
						pTHIS->m_bSendData = true;

						//AfxBeginThread(SendDataThread, pTHIS);
						CommonStruct ack;
						memset(&ack, 0, sizeof(CommonStruct));
						ack.nId = ID_SEND_DATA;

						sockaddr_in addr_video;
						memset(&addr_video, 0, sizeof(sockaddr_in));
						addr_video.sin_addr.S_un.S_addr = inet_addr(pTHIS->m_szDesAddr);
						addr_video.sin_family = AF_INET;
						addr_video.sin_port = pTHIS->m_nDesPort;

						int nlen_addr = sizeof(addr_video);

						sprintf(szMessage, "%s %s %d", "Send video command to", pTHIS->m_szDesAddr, pTHIS->m_nDesPort);
						pTHIS->m_listbox.InsertString(0, szMessage);

						nByteSend = sendto(pTHIS->m_hPunchingSocket, (LPSTR)&ack, sizeof(CommonStruct), 0, (sockaddr*)&addr_video, len);
					}
						
				}
				break;
			case ID_SEND_DATA:
				{
					pTHIS->m_bTransmitVideo = true;
					ReleaseMutex(pTHIS->m_hTrafficMutex);
					return 0;
				}
				break;				
			}
		}
		else if(nByteRecv > 0)
		{
			pTHIS->m_bEndSendThread = true;

			//Play video
			sprintf(szMessage, "%s %s", "Punching hole message from", pTHIS->m_szName);
		
			TRACE("Send reply video data packet");
			pTHIS->m_listbox.InsertString(0, "Send reply video data packet");
			nByteSend = sendto(pTHIS->m_hPunchingSocket, szMessage, sizeof(szMessage), 0, (sockaddr*)&addr_from, len);

			pTHIS->OnRecvVideoData((BYTE*)szRecvBuf, nByteRecv);
		}

		ReleaseMutex(pTHIS->m_hTrafficMutex);
	}

	return 0;
}

char* CHolePunchingClientDlg::getNetworkIp()
{
	in_addr in;
	hostent* host;

	char machineName[128];
	gethostname(machineName,128);
	host=gethostbyname(machineName);
	
	in.s_addr = ((in_addr*)(host->h_addr))->s_addr;

	return	inet_ntoa(in);
}
void CHolePunchingClientDlg::OnBnClickedStop()
{
	// TODO: Add your control notification handler code here
	if(m_bSendData)
	{
		m_bSendData = false;
		GetDlgItem(IDC_STOP)->EnableWindow(0);
	}
}

void CHolePunchingClientDlg::OnBnClickedCall()
{
	// TODO: Add your control notification handler code here
	char szName[20];
	memset(szName, 0, sizeof(szName));
	GetDlgItemText(IDC_NAME, szName, sizeof(szName));

	if(strlen(szName) == 0)
		return;

	int addr_len;

	sockaddr_in addr_to;

	addr_to.sin_family = AF_INET;
	addr_to.sin_addr.S_un.S_addr = inet_addr(m_szServerAddr);
	addr_to.sin_port = htons(1234);

	addr_len = sizeof(addr_to);

	CommonStruct call;
	memset(&call, 0, sizeof(CommonStruct));

	call.nId = ID_MAKE_CALL;
	strcpy(call.szName, szName);

	//WaitForSingleObject(m_hTrafficMutex, INFINITE);

	TRACE("\n");
	TRACE("Request Server to make call");

	int nByteSend = sendto(m_hPunchingSocket, (LPSTR)&call, sizeof(CommonStruct), 0, (sockaddr*)&addr_to, addr_len);

	//ReleaseMutex(m_hTrafficMutex);

}

void CHolePunchingClientDlg::initCapture()
{
	//Init Capture
	m_pVideoCapture = new CaptureVideo();
	
	m_pVideoCapture->SetCallbackFunc(OnVideoData, this);

	HRESULT hr = m_pVideoCapture->Init();

	if(hr != 0)
	{
		TRACE("Init capture return error.");
		return;
	}

	m_pVideoCapture->Run();
}

void CHolePunchingClientDlg::initEncode()
{
	//Init Encoder
	m_pVSS35Encoder = CVSS35Encoder::getInstance();
	VSS_SETTING setting;
	memset(&setting, 0, sizeof(VSS_SETTING));

	setting.nProfile = VSS_BALINE_PROFILE;
	setting.nLevel = 51;
	setting.nEntropyMode = VSS_ENTROPY_CAVLC;
	setting.nFrameRate = 30;	
	setting.nColor = 1;
	setting.nBitrate = 1000;
	setting.nIdrPicture = 120;

	setting.nWidth = 800;
	setting.nHeight = 600;

	setting.nSenceDectect = 1;
	setting.nRateControlMode = VSS_RATE_CONTROL_CBR;
	m_pVSS35Encoder->setting(&setting);
	m_pVSS35Encoder->SetCallback(OnEncodedData, NULL, this);
	m_pVSS35Encoder->Init();
}

void CHolePunchingClientDlg::initDecode()
{
	//Init Decoder
	if (m_pPlayer == NULL)
	{
		m_pPlayer = new CVideoPlayer();
		m_pPlayer->init();
	}

	m_pVSS35Decoder = new CVSS35Decoder();

	DECODER_SETTING setting;
	memset(&setting,0,sizeof(DECODER_SETTING));
	setting.dwOutColorSys = 1;
	setting.nCodecID = H264_CODEC_ID;
	setting.pLog = NULL;
	setting.pUserData = this;
	setting.pOnDecodedData = OnDecodeData;
	setting.nWidth = 800;
	setting.nHeight = 600;

	m_pVSS35Decoder->setting(&setting);
	m_pVSS35Decoder->init();
}

void CHolePunchingClientDlg::OnVideoData(double dbSampleTime, BYTE* pBuffer, long lBufferSize, void* pUser)
{
	CHolePunchingClientDlg* pThis = (CHolePunchingClientDlg*)pUser;

	//static BOOL bDeliver = FALSE;
	//static BYTE* buffOut = NULL;


	//pThis->m_nWidth = pThis->m_pVideoCapture->m_nWidth;
	//pThis->m_nHeight = pThis->m_pVideoCapture->m_nHeight;

	//if(buffOut == NULL)
	//{
	//	buffOut = new BYTE[pThis->m_nWidth*pThis->m_nHeight*3/2];
	//}

	//if(!buffOut)
	//	return;

	//bDeliver = !bDeliver;
	//if(!bDeliver)
	//	return;

	//BYTE *src[3]= {buffOut, buffOut+(pThis->m_nWidth*pThis->m_nHeight*5/4), buffOut+pThis->m_nWidth*pThis->m_nHeight};
	//int stride[3]={pThis->m_nWidth, pThis->m_nWidth >> 1, pThis->m_nWidth >> 1};

	//IppiSize roiSize = {pThis->m_nWidth, pThis->m_nHeight};

	/* convert to yv12 */
	//sws_scale(sws, rgb_src, rgb_stride, 0, m_nHeight, src, stride);
	//ippiCbYCr422ToYCrCb420_8u_C2P3R(pBuffer,2*pThis->m_nWidth,src,stride,roiSize);

	//RGB24toYUV(pBuffer, m_nWidth, m_nHeight, m_nWidth*3, buffOut, TRUE);

//	pThis->m_pVSS35Encoder->encode(buffOut, pThis->m_nWidth*pThis->m_nHeight*3/2 , GetTickCount());
	pThis->m_pVSS35Encoder->encode(pBuffer, lBufferSize , GetTickCount());
	
}

void CHolePunchingClientDlg::OnRecvVideoData(LPBYTE pData, int length)
{
	CRtpPacket* rtp = new CRtpPacket(pData, length);
	
	if (nMySequence == 0)
		nMySequence = rtp->m_Seq;
	//else if (rtp->m_Seq - pThis->nMySequence > 1)
		//TRACE("\n %s VideoReceive Lost Packet: dang cho %d nhan duoc %d", pThis->m_szIP, pThis->nMySequence + 1, rtp->m_Seq);
	nMySequence = rtp->m_Seq;

	TRACE("\n sequence = %d, timestamp = %d, length = %d", rtp->m_Seq, rtp->m_TimeStamp, length);
	
	//CReceive* pThis = (CReceive*)lParam;
	//sc_rtp_restruct_packet(pThis->h,pData,length);
	
	DecodeData(rtp->m_DataPtr, rtp->m_DataSize, rtp->m_TimeStamp/90, rtp->m_fMarker);
	delete rtp;
}

void CHolePunchingClientDlg::DecodeData(unsigned char* pData, int length, unsigned long timestamp, BOOL marker)
{
	m_pVSS35Decoder->decode(pData, length, timestamp);
}

void CHolePunchingClientDlg::OnEncodedData(unsigned char* pData, int nSize, unsigned long dwtimestamp, void* pUser)
{
	CHolePunchingClientDlg* pThis = (CHolePunchingClientDlg*)pUser;

	static dwTimeCounter = GetTickCount();

	pThis->m_RtpHeader.SetTimeStamp(dwtimestamp);
	DWORD sent_size;
	BOOL first=TRUE;
	int result = 0; // turn off warning
	LPBYTE data = pData;

	int nSendByte = 0;

	sockaddr_in addr;
	int addr_len = 0;
	memset(&addr, 0, sizeof(sockaddr_in));

	addr.sin_addr.S_un.S_addr = inet_addr(pThis->m_szDesAddr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(pThis->m_nDesPort);

	addr_len = sizeof(addr);

	while(nSize)
	{
		pThis->m_dwIndex = RTP_HEADER_SIZE;
		sent_size = min(nSize, 1408); // must be multiple of 16 for AES 128
		pThis->m_RtpHeader.SetMarker(FALSE);
		pThis->m_RtpHeader.SetSequenceNumber(pThis->m_SeqNumber++);

		memcpy(pThis->m_pDataBuffer + pThis->m_dwIndex, data, sent_size);
		nSize -= sent_size;
		data += sent_size;

		pThis->m_RtpHeader.SetPadding(FALSE);

		pThis->m_dwIndex += sent_size;

		pThis->m_RtpHeader.FillBuffer(pThis->m_pDataBuffer);

		//pThis->OnRecvVideoData(pThis->m_pDataBuffer, pThis->m_dwIndex);
		if(pThis->m_bTransmitVideo)
		{
			nSendByte = sendto(pThis->m_hPunchingSocket, (LPSTR)pThis->m_pDataBuffer, pThis->m_dwIndex, 0, (sockaddr*)&addr, addr_len );

			TRACE("\n");
			TRACE("Sending Video Data...");
			pThis->m_listbox.InsertString(0, "Sending Video Data...");
		}
	}

	//send heart beat to server
	//if((GetTickCount() - dwTimeCounter) > 2000)
	//{
	//	dwTimeCounter = GetTickCount();

	//	sockaddr_in addr_to;
	//	int addr_len = 0;
	//	memset(&addr_to, 0, sizeof(sockaddr_in));

	//	addr_to.sin_addr.S_un.S_addr = inet_addr(pThis->m_szServerAddr);
	//	addr_to.sin_family = AF_INET;
	//	addr_to.sin_port = htons(pThis->m_nServerPort);

	//	addr_len = sizeof(addr_to);

	//	CommonStruct ack;
	//	memset(&ack, 0, sizeof(CommonStruct));
	//	ack.nId = ID_HEART_BEAT;

	//	nSendByte = sendto(pThis->m_hPunchingSocket, (LPSTR)&ack, sizeof(CommonStruct), 0, (sockaddr*)&addr_to, addr_len );

	//	char szMessage[100];

	//	TRACE("\n");
	//	sprintf(szMessage, "%s", "Send heart beat back to server");
	//	TRACE(szMessage);
	//	pThis->m_listbox.InsertString(0, szMessage);
	//}

}

void CHolePunchingClientDlg::OnDecodeData(void* pUserData, unsigned char* pData, int width, int height, unsigned long timestamp)
{
	static int frmCount = 0;
	static DWORD lastTime = 0;
	CHolePunchingClientDlg* pThis= (CHolePunchingClientDlg*)pUserData;
	if (GetTickCount() - lastTime < 1000)
		frmCount++;
	else		
	{
		TRACE("Framerate = %d, width = %d, height = %d \n", frmCount, width, height);
		frmCount = 0;
		lastTime = GetTickCount();
	}
	m_pPlayer->writeYUV420PData(pThis->m_szDesAddr, pData, width, height, timestamp);
}