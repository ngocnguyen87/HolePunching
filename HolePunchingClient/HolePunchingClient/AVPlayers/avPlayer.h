// avPlayer.h: interface for the CavPlayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AVPLAYER_H__8BEC6ADC_0A28_4996_831B_D84AD97FBFD3__INCLUDED_)
#define AFX_AVPLAYER_H__8BEC6ADC_0A28_4996_831B_D84AD97FBFD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <ddraw.h>
#include <mmsystem.h>
#include "DisplayDlg.h"
#include "VMenu\VideoMenu.h"
#include "VDialog.h"


#define COLOR_SPACE_YV12	0
#define COLOR_SPACE_YUY2	1
#define COLOR_SPACE_RGB16	2

#define MAX_PICTURES		30
#define AUDIO_ARRAY_SIZE	30

#define AUDIO_CHANNELS		2
#define AUDIO_SAMPLES_RATE	32000

#define WM_SWITCH_SCREEN	(WM_USER + 111)


typedef struct
{
	LPBYTE	lpLum;
	LPBYTE	lpCr;
	LPBYTE	lpCb;
	DWORD	PTS;
	int		width;
	int		height;
} s_pict;

class CPict
{
public:
	LPBYTE	image;
	DWORD	PTS;
	int		width;
	int		height;
};


typedef struct
{
	LPBYTE	audio;
	int		size;
	DWORD	pts;
} CAudioFrame;


class CStreaming;

class AFX_EXT_CLASS CavPlayer
{
public:
	static CDisplayDlg			m_wndDisplay;
	static BOOL					m_fPreview;
	CString						m_sCallToken;

protected:
	//DirectDraw
	
	static LPDIRECTDRAW			m_lpDirectDraw;
	static LPDIRECTDRAWSURFACE	m_lpPrimarySurface;
	static LPDIRECTDRAWSURFACE	m_lpFrontSurface;
	static LPDIRECTDRAWSURFACE	m_lpBackSurface;
	static LPDIRECTDRAWSURFACE	m_lpLogSurface;

	static LPDIRECTDRAWSURFACE	m_lpBlackSurface;
	static LPDIRECTDRAWSURFACE	m_lpPreviewFrmSurface;

	LPDIRECTDRAWSURFACE			m_lpTextSurface;
//	static MMRESULT				m_UpdateOverlayTimerID;	
	static LPRECT				m_lpRectArray;
	static int					m_ColorSpace;
	static int					m_nMuxMode;
	static int					m_nPageNo;
	static int					m_nTVRatio;
	static int					m_nNumOfPlayer;
	static BOOL					m_fLogDisplayed;
	static BOOL					m_fAVTest;
	BOOL						m_fLocal;
	static HANDLE				m_hRenderThreadExit;
	static BOOL					m_fExit;

	static CPtrArray			m_Players;
	static CavPlayer*			m_pLocalPlayer;
	LPDIRECTDRAWSURFACE			m_lpOfflineSurface;	
	CPtrList					m_PictureList;
	CPtrList					m_FreePictureList;
	HANDLE						m_hPictureMutex;
	HANDLE						m_hAudioMutex;
	static HANDLE				m_hPlayerMutex;
	//CRITICAL_SECTION			m_hCriticalSection;
	//static CRITICAL_SECTION		m_hPlayerLock;
	int							m_nSurfaceHeight;
	int							m_nSurfaceWidth;

	//Video time
	DWORD						m_dwVidStartTime;
	DWORD						m_dwVidStartPTS;

	//Audio time
	DWORD						m_dwAudStartTime;
	DWORD						m_dwAudStartPTS;


	int							m_NoPictCount;
	int							m_iPlayer;

	int							m_nLVolume;
	int							m_nRVolume;

	CPtrList					m_AudioList;
	CPtrList					m_FreeAudioList;

	// Log message
	static int					m_nDisplayTimer;
	static CString				m_sError;

	CStreaming* m_pAPlayer;
	CString						m_sPlayerAlias;

public:
	// Video Menu
	static CVideoMenu*			m_pMenu;
	static CVDialog dlg;
	static BOOL					m_fVDialog;

public:
	static void AutoMuxMode();
	CavPlayer();
	CavPlayer(BOOL fLocal);
	~CavPlayer();

	static BOOL InitDirectDraw();
	static void DestroyDirectDraw();

	int Init(int video_width, int video_height, int audio_channels, int audio_samples_rate);

	int PlayVideo(LPBYTE lpLum, LPBYTE lpCr, LPBYTE lpCb, int width, int height, DWORD pts, int pitch = 0);
	void PlayAudio(LPBYTE audio, int size, DWORD pts);
	void SetStartPTS(DWORD pts);

	static BOOL DisplayText(CString lpszText);
	static void ClearText(LPCTSTR lpszText = NULL);

	static int SetMuxMode(int mode);
	static int GetMuxMode();


	static int GetPage()			{ return m_nPageNo; }
	static int SetPage(int page);
	static void SetMuteIcon(BOOL fMute);
	static void SetWarningIcon(BOOL fMute);
	static void SetPreview(BOOL fPreview) { m_fPreview = fPreview; }
	static void AVTest(BOOL fTest)	{ m_fAVTest = fTest; }
	void SetTopPos();

	static void SetTVSpectRatio(int mode) { m_nTVRatio = mode; }
	static int GetTVSpectRatio()	{ return m_nTVRatio; }

	static BOOL IsOnMenu()			{ return m_pMenu->IsVisible(); }
	CVideoMenu* GetMenu()			{ return m_pMenu; }
	static void OnKey(UINT nChar, LPARAM lParam = 0);
	static int ShowDialog(LPCTSTR sText, DWORD dwStyle);

	static int LogMsg(CString sMsg, int nClearTime = 10);
	static CString GetAlias(LPCTSTR ip) { return m_pMenu->GetAlias(ip); }

	static HFONT CreateTextFont(LPCTSTR lpFontName, int nFontSize, LONG lfWeight);
	static void HideMenu()			{ m_pMenu->HideMenu(); }
	static void UpdateOverlay(LPDIRECTDRAWSURFACE lpSurface=m_lpFrontSurface);
	BOOL IsValidToPlay();
	void SetPlayerAlias(CString sAlias);
	void RemovePlayerAlias(CString sAlias);
protected:
	void Exit();
	s_pict* CreatePicture(int width, int height);
	void DeletePicture(s_pict* pPict);
	int CreateOfflineSur(int width,int height);
	int Semitransparent(s_pict* lpPict, LPRECT pRect, int lmask);
	int DisplayFrame(LPRECT pRect=NULL);
	void PlaySamples(LPBYTE buffer, int samples);

	void CopyPict2SurYUY2(s_pict *lpPict);
	void CopyPict2SurYV12(s_pict *lpPict);
	void asm_CopyPict2SurYV12(s_pict *lpPict);
	void CopyPict2SurYV12Direct(s_pict *lpPict,LPRECT pRect);

	static void ClearSurface(LPDIRECTDRAWSURFACE lpSurface, int red=0, int green=0, int blue=0);
	static void ClearSurfaceRect(LPDIRECTDRAWSURFACE lpSurface, LPRECT pRect, int red=0, int green=0, int blue=0);


	static void CALLBACK TimeProc(UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2);
	static void CALLBACK LogTimeProc(UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2);
	static UINT RenderThread(LPVOID lpParam);
public: 
	BOOL m_bDirty;
};

#endif // !defined(AFX_AVPLAYER_H__8BEC6ADC_0A28_4996_831B_D84AD97FBFD3__INCLUDED_)
