// HolePunchingServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HolePunchingServer.h"
#include "HolePunchingServerDlg.h"
#include <winsock2.h>
#include "commonstruct.h"
#include ".\holepunchingserverdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

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


// CHolePunchingServerDlg dialog



CHolePunchingServerDlg::CHolePunchingServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHolePunchingServerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHolePunchingServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LOG, m_listbox);
}

BEGIN_MESSAGE_MAP(CHolePunchingServerDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_RESET, OnBnClickedReset)
END_MESSAGE_MAP()


// CHolePunchingServerDlg message handlers

BOOL CHolePunchingServerDlg::OnInitDialog()
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
	m_vArrayOfHoleClient.clear();

	sockaddr_in addr;
	m_hRecvSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if(m_hRecvSocket == INVALID_SOCKET)
		return TRUE;

	memset(&addr, 0, sizeof(sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(u_short(1234));

	if(bind(m_hRecvSocket, (sockaddr*)&addr, sizeof(addr)) != 0)
	{
		closesocket(m_hRecvSocket);
		m_hRecvSocket = INVALID_SOCKET;
		return TRUE;
	}

	AfxBeginThread(ReceiveThread, this);
	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHolePunchingServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHolePunchingServerDlg::OnPaint() 
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
HCURSOR CHolePunchingServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

UINT CHolePunchingServerDlg::ReceiveThread(void* pUser)
{
	CHolePunchingServerDlg* pTHIS = (CHolePunchingServerDlg*)pUser;

	char* szRecvBuf = new char[1024];
	memset(szRecvBuf, 0, 1024);

	char* szTrace = new char[1024];
	memset(szTrace, 0, 1024);

	//sprintf(szSendBuf, "%s", "Send back heart beat ack");

	int nByteRecv = 0;
	int nByteSend = 0;

	sockaddr_in addr_from;
	int len = sizeof(addr_from);


	while(1)
	{
		nByteRecv = recvfrom(pTHIS->m_hRecvSocket, szRecvBuf, 1024, 0, (sockaddr*)&addr_from, &len);
		//TRACE(szRecvBuf);
		TRACE("\n");
		if(nByteRecv > 0 && nByteRecv == sizeof(CommonStruct))
		{
			////send back ack
			//nByteSend = sendto(pTHIS->m_hRecvSocket, szSendBuf, 1024, 0, (sockaddr*)&addr_from, len);

			char* szSourceAddr = new char[64];
			memset(szSourceAddr, 0, 64);
			int nSourcePort = 0;

			szSourceAddr = inet_ntoa(addr_from.sin_addr);
			nSourcePort = ntohs(addr_from.sin_port);

			CommonStruct *commonStruct = (CommonStruct*)szRecvBuf;
	
			switch(commonStruct->nId)
			{
			case ID_REGISTRATION:
				//insert new client
				{
					CHoleClient* pNewClient = new CHoleClient();

					strcpy(pNewClient->m_szPublicIp, szSourceAddr);
					pNewClient->m_nPublicPort = nSourcePort;

					strcpy(pNewClient->m_szPrivateIp, commonStruct->szPrivateIp);
					pNewClient->m_nPrivatePort = commonStruct->nPrivatePort;

					strcpy(pNewClient->m_szName, commonStruct->szName);

					pTHIS->m_vArrayOfHoleClient.insert(pTHIS->m_vArrayOfHoleClient.begin(), pNewClient);
			
					CommonStruct ack;
					memset(&ack, 0, sizeof(CommonStruct)); 
					ack.nId = ID_HEART_BEAT;

					sprintf(szTrace, "%s %s", "Receive registration from", commonStruct->szName);
					pTHIS->m_listbox.InsertString(0, szTrace);
					TRACE(szTrace);

					nByteSend = sendto(pTHIS->m_hRecvSocket, (LPSTR)&ack, sizeof(CommonStruct), 0, (sockaddr*)&addr_from, len);
				}
				break;
			case ID_HEART_BEAT:
				//send back heart beat
				{
					CommonStruct ack;
					memset(&ack, 0, sizeof(CommonStruct));
					ack.nId = ID_HEART_BEAT;

					sprintf(szTrace, "%s %s:%d", "Receive heart beat from", szSourceAddr, nSourcePort);
					pTHIS->m_listbox.InsertString(0, szTrace);
					TRACE(szTrace);

					nByteSend = sendto(pTHIS->m_hRecvSocket, (LPSTR)&ack, sizeof(CommonStruct), 0, (sockaddr*)&addr_from, len);
				}
				break;
			case ID_MAKE_CALL:
				{
					for(int i=0; i<pTHIS->m_vArrayOfHoleClient.size(); i++)
					{

						CHoleClient* pClient = pTHIS->m_vArrayOfHoleClient.at(i);
						if(strcmp(commonStruct->szName, pClient->m_szName) == 0)
						{
							//command make call to callee client
							CommonStruct ack;
							memset(&ack, 0, sizeof(CommonStruct));
							
							ack.nId = ID_COMMAND_MAKE_CALL;
							
							strcpy(ack.szPublicIp, pClient->m_szPublicIp);
							strcpy(ack.szPrivateIp, pClient->m_szPrivateIp);
							strcpy(ack.szName, pClient->m_szName);
	
							ack.nPublicPort = pClient->m_nPublicPort;
							ack.nPrivatePort = pClient->m_nPrivatePort;

							TRACE("Send command make call to callee");
							pTHIS->m_listbox.InsertString(0, "Send command make call to callee");
							TRACE("\n");

							nByteSend = sendto(pTHIS->m_hRecvSocket, (LPSTR)&ack, sizeof(CommonStruct), 0, (sockaddr*)&addr_from, len);

							//command make call to called client
							CommonStruct ack2;
							memset(&ack2, 0, sizeof(CommonStruct));

							CHoleClient* pClient2;
							for(int i=0; i<pTHIS->m_vArrayOfHoleClient.size(); i++)
							{
								pClient2 = pTHIS->m_vArrayOfHoleClient.at(i);
								if(strcmp(szSourceAddr, pClient2->m_szPublicIp) == 0)
									break;

								//return 0;
							}
							
							ack2.nId = ID_COMMAND_MAKE_CALL;
							
							strcpy(ack2.szPublicIp, pClient2->m_szPublicIp);
							strcpy(ack2.szPrivateIp, pClient2->m_szPrivateIp);
							strcpy(ack2.szName, pClient2->m_szName);
	
							ack2.nPublicPort = pClient2->m_nPublicPort;
							ack2.nPrivatePort = pClient2->m_nPrivatePort;

							sockaddr_in addr_to;
							addr_to.sin_family = AF_INET;
							addr_to.sin_addr.S_un.S_addr = inet_addr(pClient->m_szPublicIp);
							addr_to.sin_port = htons(pClient->m_nPublicPort);

							int addr_len = sizeof(addr_to);

							pTHIS->m_listbox.InsertString(0, "Send command make call to called");
							TRACE("Send command make call to called");


							nByteSend = sendto(pTHIS->m_hRecvSocket, (LPSTR)&ack2, sizeof(CommonStruct), 0, (sockaddr*)&addr_to, addr_len);


						}
					}
				}
				break;
			case ID_COMMAND_MAKE_CALL:
				break;
			case ID_SEND_DATA:
				break;
			}
		}
	}

	return 0;
}

void CHolePunchingServerDlg::OnBnClickedReset()
{
	// TODO: Add your control notification handler code here
	m_vArrayOfHoleClient.clear();
	m_listbox.ResetContent();
}
