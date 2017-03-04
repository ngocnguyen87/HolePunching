#pragma once


typedef void (*PVSOFTCALLBACKVFUNCTION)(unsigned char*,int,unsigned long,void*);
typedef void (*PVSOFT_LOG)( void *, int i_level, const char *psz);


#define VSS_BALINE_PROFILE 66
#define VSS_MAIN_PROFILE 77
#define VSS_HIGHT_PROFILE 100

#define VSS_ENTROPY_CAVLC 0
#define VSS_ENTROPY_CABAC 1

#define VSS_RATE_CONTROL_VBR 0
#define VSS_RATE_CONTROL_CBR 1

#define VSS_FRAME_RATE_FULL 1 //30 for NTSC,25 for PAL
#define VSS_FRAME_RATE_15 2 //15 for all
#define VSS_FRAME_RATE_10 3 //10 frame/s
#define VSS_FRAME_RATE_5 6

#define VSS_COLOR_PAL 0
#define VSS_COLOR_NTSC 1


typedef struct VSS_SETTING
{
	int nProfile; //66 baseline, 77 main
	int nLevel; //Chi ho tro tu 1 den 4.2

	int nEntropyMode; //CAVLC or CABAC. Note rang CABAC khong ho trong trong baseline
	int nRateControlMode; //0: CBR,1 VBR
	int nSenceDectect; //1 enable, 0 disable

	int nBitrate; //Tinh theo kilobit

	int nContentEncoder; //1: Content 0:Source

	//lien quan den cac thu khac
	int nWidth;  //frame width
	int nHeight; //frame height
	int nIdrPicture; //khoang cach giua 2 frame I

	int nFrameRate; // 0 full, 15: 1, 10:2,5:3
	int nColor;  //0 PAL,1 NTSC
	int nSource; //0: Composite, 1: SVideo

	int nSendIp;
	int nSendPort;

}VSS_SETTING;

class CEncoder
{
protected:
	int m_nLogLevel;
	BOOL m_bIsInitialize;
	//static int m_cEncoders;

	LPVOID m_pUser;
	PVSOFTCALLBACKVFUNCTION m_pEncodedCallback;
	PVSOFT_LOG m_pLog;

protected:
	void Log(int nLevel, char* psz, ...);

public:
	CEncoder(void);
	virtual ~CEncoder(void);

	virtual int setting(LPVOID pParam) { return 0; }
	virtual int getVideoSetting(LPVOID pParam) { return 0; }
	virtual int Init()=0;
	virtual int Exit() {return 0;};
	virtual int encode(BYTE* pData, DWORD dwSize, DWORD dwTS) {return 0; }

	virtual int changeBitrate(int nNewBitrate) { return 0; }
	virtual int fastUpdate() { return 0; }


	void SetLogLevel(int lvl) { m_nLogLevel = lvl; }
	void SetCallback(PVSOFTCALLBACKVFUNCTION pCallback, PVSOFT_LOG pLog, LPVOID pUser)
	{
		m_pEncodedCallback = pCallback;
		m_pLog = pLog;
		m_pUser = pUser;
	}

};
