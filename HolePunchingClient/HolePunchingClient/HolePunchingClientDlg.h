// HolePunchingClientDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "RtpHeader.h"
#include ".\AVPlayers\VideoPlayer.h"

class CaptureVideo;
class CVSS35Encoder;
class CVSS35Decoder;
class CDecoder;
class CVideoPlayer;


// CHolePunchingClientDlg dialog
class CHolePunchingClientDlg : public CDialog
{
// Construction
public:
	CHolePunchingClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_HOLEPUNCHINGCLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	static UINT SendDataThread(void* pUser);
	static UINT RecvThread(void* pUser);

	char* getNetworkIp();
	LRESULT SendData(WPARAM wParam, LPARAM lParam);

	void initCapture();
	void initEncode();
	void initDecode();

	static void OnVideoData(double dbSampleTime, BYTE* pBuffer, long lBufferSize, void* pUser);
	static void OnEncodedData(unsigned char* pData, int nSize, unsigned long dwtimestamp, void* pUser);
	static void OnDecodeData(void* pUserData,unsigned char* pData,int width,int height,unsigned long timestamp);

	void OnRecvVideoData(LPBYTE pData, int length);
	void DecodeData(unsigned char* pData, int length, unsigned long timestamp, BOOL marker);

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	SOCKET	m_hPunchingSocket;
	HANDLE	m_hTrafficMutex;

	char	m_szServerAddr[20];
	int		m_nServerPort;

	char    m_szName[20];
	char	m_szPrivateIp[20];
	int     m_nPrivatePort;

	bool	m_bSendData;
	bool	m_bServerConnected;
	bool	m_bEndSendThread;

	char	m_szDesAddr[20];
	int		m_nDesPort;
	afx_msg void OnBnClickedStop();
	afx_msg void OnBnClickedCall();
	CListBox m_listbox;

	CaptureVideo* m_pVideoCapture;
	CVSS35Encoder* m_pVSS35Encoder;
	CDecoder* m_pVSS35Decoder;

	static CVideoPlayer* m_pPlayer;

	int m_nWidth;
	int m_nHeight;

	LPBYTE	m_pDataBuffer;
	RtpHeader		m_RtpHeader;
	DWORD			m_dwIndex;

	DWORD			m_SeqNumber;
	int				nMySequence;

	int				m_nSender;

	bool			m_bTransmitVideo;
};
