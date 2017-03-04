// avPlayer.cpp: implementation of the CavPlayer class.
//
//-----------------------------------------------------------------------------



#include "stdafx.h"

#include "avPlayer.h"

//#include <xmmintrin.h>
//#include <emmintrin.h>




#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//#define VE_LUON
#define RENDER_THREAD

DDPIXELFORMAT g_PixelFormats[] = {
	{sizeof(DDPIXELFORMAT), DDPF_FOURCC,MAKEFOURCC('Y','V','1','2'),0,0,0,0,0},  //YV12
	{sizeof(DDPIXELFORMAT), DDPF_FOURCC,MAKEFOURCC('Y','U','Y','2'),0,0,0,0,0},  // YUV422	
	{sizeof(DDPIXELFORMAT), DDPF_RGB, 0, 16,  0x0000F800, 0x000007E0, 0x0000001F, 0},
	{sizeof(DDPIXELFORMAT), DDPF_RGB, 0, 24,  0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000},   // 24-bit
	{sizeof(DDPIXELFORMAT), DDPF_RGB, 0, 32,  0x00FF0000 , 0x0000FF00 , 0x000000FF , 0xFF000000}, //32bits
	{sizeof(DDPIXELFORMAT), DDPF_RGB, 0, 32,  0x000000FF , 0x0000FF00 , 0x00FF0000 , 0}, //32bits
	{sizeof(DDPIXELFORMAT), DDPF_ALPHA, 0, 8,  0x00 , 0x00 , 0x00 , 0x000000FF}
};

#define CX 1024
#define CY 768

RECT g_PreviewRect = {CX*15/24, CY*15/24, CX-CX/16, CY-CY/16};
RECT g_PreviewFrmRect = {g_PreviewRect.left-3, g_PreviewRect.top-3, g_PreviewRect.right+3, g_PreviewRect.bottom+3};
#if CX == 800
	RECT g_MenuRect = {120, 125, 680, 475};
#else
	RECT g_MenuRect = {CX*15/100, CY/5+4, CX-CX*15/100, CY-CY/5-4};
#endif
RECT g_LogRect = {0, 0, CX, CY/14};
RECT g_IconRect = {0, CY-100*CY/600, CX, CY};

RECT g_Mux1RectArray[1]={ {0, 0, CX, CY} };

RECT g_Mux2RectArray[2]={{0, CY/4, CX/2, CY*3/4},{CX/2+1, CY/4, CX, CY*3/4}};

RECT g_Mux4RectArray[4]={
	{0, 0,	    CX/2, CY/2}, {CX/2+1, 0,      CX, CY/2},
	{0, CY/2+1, CX/2, CY  }, {CX/2+1, CY/2+1, CX, CY  }
};

RECT g_Mux6RectArray[6]={
	{0, 0,		                                        CX*2/3, CY*2/3}, {CX*2/3+1, 0,		  CX, CY*1/3}, 
																		 {CX*2/3+1, CY*1/3+1, CX, CY*2/3},
	{0, CY*2/3+1, CX/3,	  CY*3/3}, {CX/3+1,	  CY*2/3+1, CX*2/3, CY*3/3}, {CX*2/3+1, CY*2/3+1, CX, CY*3/3}
};

RECT g_Mux66RectArray[6]={
	{0, CY/6,   CX/3,   CY/2}, {CX/3+1, CY/6,   CX*2/3,   CY/2}, {CX*2/3+1, CY/6,   CX, CY/2},
	{0, CY/2+1, CX/3, CY*5/6}, {CX/3+1, CY/2+1, CX*2/3, CY*5/6}, {CX*2/3+1, CY/2+1, CX, CY*5/6}
};

RECT g_Mux9RectArray[9]={
	{0, 0,        CX/3, CY*1/3}, {CX/3+1, 0,        CX*2/3, CY*1/3}, {CX*2/3+1, 0,        CX, CY*1/3},
	{0, CY*1/3+1, CX/3, CY*2/3}, {CX/3+1, CY*1/3+1, CX*2/3, CY*2/3}, {CX*2/3+1, CY*1/3+1, CX, CY*2/3},
	{0, CY*2/3+1, CX/3, CY*3/3}, {CX/3+1, CY*2/3+1, CX*2/3, CY*3/3}, {CX*2/3+1, CY*2/3+1, CX, CY*3/3}
};

RECT g_Mux13RectArray[13]={
	{0, 0,        CX/4, CY*1/4}, {CX/4+1,   0,        CX/2, CY*1/4}, {CX/2+1, 0,        CX*3/4, CY*1/4}, {CX*3/4+1, 0,        CX, CY*1/4},
	{0, CY*1/4+1, CX/4, CY*2/4}, {CX/4+1,   CY*1/4+1,                                   CX*3/4, CY*3/4}, {CX*3/4+1, CY*1/4+1, CX, CY*2/4},
	{0, CY*2/4+1, CX/4, CY*3/4},                                                                         {CX*3/4+1, CY*2/4+1, CX, CY*3/4},
	{0, CY*3/4+1, CX/4, CY*4/4}, {CX/4+1,   CY*3/4+1, CX/2, CY*4/4}, {CX/2+1, CY*3/4+1, CX*3/4, CY*4/4}, {CX*3/4+1, CY*3/4+1, CX, CY*4/4}
};

RECT g_Mux16RectArray[16]={
	{0, 0,        CX/4, CY*1/4}, {CX/4+1, 0,        CX/2, CY*1/4}, {CX/2+1, 0,        CX*3/4, CY*1/4}, {CX*3/4+1, 0,        CX, CY*1/4},
	{0, CY*1/4+1, CX/4, CY*2/4}, {CX/4+1, CY*1/4+1, CX/2, CY*2/4}, {CX/2+1, CY*1/4+1, CX*3/4, CY*2/4}, {CX*3/4+1, CY*1/4+1, CX, CY*2/4},
	{0, CY*2/4+1, CX/4, CY*3/4}, {CX/4+1, CY*2/4+1, CX/2, CY*3/4}, {CX/2+1, CY*2/4+1, CX*3/4, CY*3/4}, {CX*3/4+1, CY*2/4+1, CX, CY*3/4},
	{0, CY*3/4+1, CX/4, CY*4/4}, {CX/4+1, CY*3/4+1, CX/2, CY*4/4}, {CX/2+1, CY*3/4+1, CX*3/4, CY*4/4}, {CX*3/4+1, CY*3/4+1, CX, CY*4/4}
};

/*
RECT g_Mux25RectArray[25]={
	{0,0,  160,120},{161,0,  320,120},{321,0,  480,120},{481,0,  640,120},{641,0,  800,120},
	{0,121,160,240},{161,121,320,240},{321,121,480,240},{481,121,640,240},{641,121,800,240},
	{0,241,160,360},{161,241,320,360},{321,241,480,360},{481,241,640,360},{641,241,800,360},
	{0,361,160,480},{161,361,320,480},{321,361,480,480},{481,361,640,480},{641,361,800,480},
	{0,481,160,600},{161,481,320,600},{321,481,480,600},{481,481,640,600},{641,481,800,600}
};
	

RECT g_Mux36RectArray[36]={
	{0,0,  133,100},{134,0,  266,100},{267,0,  400,100},{401,0,  533,100},{534,0,  666,100},{667,0,  800,100},
	{0,101,133,200},{134,101,266,200},{267,101,400,200},{401,101,533,200},{534,101,666,200},{667,101,800,200},
	{0,201,133,300},{134,201,266,300},{267,201,400,300},{401,201,533,300},{534,201,666,300},{667,201,800,300},
	{0,301,133,400},{134,301,266,400},{267,301,400,400},{401,301,533,400},{534,301,666,400},{667,301,800,400},
	{0,401,133,500},{134,401,266,500},{267,401,400,500},{401,401,533,500},{534,401,666,500},{667,401,800,500},
	{0,501,133,600},{134,501,266,600},{267,501,400,600},{401,501,533,600},{534,501,666,600},{667,501,800,600},
};
*/


CDisplayDlg				CavPlayer::m_wndDisplay;
LPDIRECTDRAW			CavPlayer::m_lpDirectDraw			= NULL;
LPDIRECTDRAWSURFACE		CavPlayer::m_lpPrimarySurface		= NULL;
LPDIRECTDRAWSURFACE		CavPlayer::m_lpFrontSurface			= NULL;
LPDIRECTDRAWSURFACE		CavPlayer::m_lpBackSurface			= NULL;
LPDIRECTDRAWSURFACE		CavPlayer::m_lpBlackSurface			= NULL;
LPDIRECTDRAWSURFACE		CavPlayer::m_lpPreviewFrmSurface	= NULL;
LPDIRECTDRAWSURFACE		CavPlayer::m_lpLogSurface			= NULL;

//MMRESULT				CavPlayer::m_UpdateOverlayTimerID	= 0;
CPtrArray				CavPlayer::m_Players;
CavPlayer*				CavPlayer::m_pLocalPlayer			= NULL;
LPRECT					CavPlayer::m_lpRectArray			= g_Mux1RectArray;
int						CavPlayer::m_ColorSpace				= COLOR_SPACE_YV12;
int						CavPlayer::m_nMuxMode				= 1;
int						CavPlayer::m_nPageNo				= 1;
int						CavPlayer::m_nTVRatio				= 0;
int						CavPlayer::m_nNumOfPlayer			= 0;
BOOL					CavPlayer::m_fLogDisplayed			= FALSE;
BOOL					CavPlayer::m_fPreview				= FALSE;
BOOL					CavPlayer::m_fAVTest				= FALSE;
CVideoMenu*				CavPlayer::m_pMenu					= NULL;
HANDLE					CavPlayer::m_hRenderThreadExit		= NULL;
BOOL					CavPlayer::m_fExit					= FALSE;
//CRITICAL_SECTION		CavPlayer::m_hPlayerLock;
HANDLE					CavPlayer::m_hPlayerMutex			= CreateMutex(NULL,FALSE,NULL);

BOOL					CavPlayer::m_fVDialog				= FALSE;
CVDialog				CavPlayer::dlg;

int						CavPlayer::m_nDisplayTimer			= 0;
CString					CavPlayer::m_sError					= "";



//-----------------------------------------------------------------------------
// Construction/Destruction
//-----------------------------------------------------------------------------
CavPlayer::CavPlayer()
{
	WaitForSingleObject(m_hPlayerMutex,INFINITE);
	m_Players.Add(this);
	ReleaseMutex(m_hPlayerMutex);


	AutoMuxMode();

	m_nNumOfPlayer++;
	m_iPlayer = m_nNumOfPlayer - 1;
	m_fLocal = FALSE;

	m_nSurfaceHeight = m_nSurfaceWidth = 0;
	m_lpOfflineSurface = NULL;
	m_NoPictCount = 0;

	m_bDirty = FALSE;
}

CavPlayer::CavPlayer(BOOL fLocal)
{
	m_pLocalPlayer = this;
	m_fLocal = TRUE;
	m_nSurfaceHeight = m_nSurfaceWidth = 0;
	m_lpOfflineSurface = NULL;

	m_bDirty = FALSE;
}

CavPlayer::~CavPlayer()
{
	Exit();

	WaitForSingleObject(m_hPlayerMutex,INFINITE);
	int i;
	
	for (i=0; i < m_Players.GetSize(); i++)
		if (m_Players.GetAt(i) == LPVOID(this))
			m_Players.RemoveAt(i);

	CavPlayer* p;
	for (i=0; i < m_Players.GetSize(); i++)
	{
		p = (CavPlayer *)m_Players.GetAt(i);
		p->m_iPlayer = i;
	}

	if (m_fLocal)
		m_pLocalPlayer = NULL;
	else
		m_nNumOfPlayer--;

	ReleaseMutex(m_hPlayerMutex);

	AutoMuxMode();

}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HFONT CavPlayer::CreateTextFont(LPCTSTR lpFontName, int nFontSize, LONG lfWeight)
{
	LOGFONT logfont;
	HFONT hTmpFont;
	
	memset(&logfont, 0, sizeof (logfont));
	if (nFontSize != -1)
		logfont.lfHeight = nFontSize;
	logfont.lfWidth = 0;
	logfont.lfEscapement = 0;
	logfont.lfOrientation = 0;
	logfont.lfWeight = lfWeight;
	logfont.lfItalic = FALSE;
	logfont.lfUnderline = FALSE;
	logfont.lfStrikeOut = FALSE;
	logfont.lfCharSet = DEFAULT_CHARSET;
	logfont.lfOutPrecision = OUT_DEFAULT_PRECIS;
	logfont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	logfont.lfQuality = DEFAULT_QUALITY;
	logfont.lfPitchAndFamily = FIXED_PITCH;// DEFAULT_PITCH | FF_DONTCARE|FF_ROMAN;
	_tcscpy (logfont.lfFaceName, lpFontName);

	hTmpFont = CreateFontIndirect (&logfont);
	
	return hTmpFont;
}

BOOL CavPlayer::InitDirectDraw()
{

	DDSURFACEDESC ddsd;
	HRESULT hr;

	if (m_lpDirectDraw != NULL)
	{
		return FALSE;
	}
	
	

	if (!IsWindow(m_wndDisplay.m_hWnd))
	{
		m_wndDisplay.Create(IDD_DISPLAY_DIALOG);
		m_wndDisplay.ShowWindow(SW_NORMAL);
#ifndef _DEBUG
		m_wndDisplay.ChangeDisplayMode();
#endif
	}
	hr = DirectDrawCreate(NULL, &m_lpDirectDraw, NULL);
	ASSERT(hr == 0);
	hr = m_lpDirectDraw->SetCooperativeLevel(m_wndDisplay.m_hWnd, DDSCL_NORMAL);
	ASSERT(hr == 0);
	//m_lpDirectDraw->SetDisplayMode(800,600,16);

	m_ColorSpace = COLOR_SPACE_YV12;

	//Create primary surface
	ZeroMemory(&ddsd, sizeof(ddsd));
	ddsd.dwSize = sizeof(ddsd);	
	ddsd.dwFlags = DDSD_CAPS;
	ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
	hr = m_lpDirectDraw->CreateSurface(&ddsd, &m_lpPrimarySurface, NULL);
	ASSERT(hr==0);

	//Create overlay surface;
	int buffercount = 5;
	ZeroMemory(&ddsd, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd); 
    ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_PIXELFORMAT |
					DDSD_BACKBUFFERCOUNT;
    ddsd.ddsCaps.dwCaps = DDSCAPS_OVERLAY | DDSCAPS_FLIP | DDSCAPS_COMPLEX |DDSCAPS_VIDEOMEMORY;
	ddsd.dwBackBufferCount = buffercount;
    ddsd.dwWidth  = CX;
    ddsd.dwHeight = CY;
	ddsd.ddpfPixelFormat = g_PixelFormats[0];
	hr = m_lpDirectDraw->CreateSurface(&ddsd, &m_lpFrontSurface, NULL);
	if(hr!=0)
	{
		ddsd.ddpfPixelFormat = g_PixelFormats[4];
		hr = m_lpDirectDraw->CreateSurface(&ddsd, &m_lpFrontSurface, NULL);
		if(hr!=0)
		{
			return FALSE;
		}
	}

	//Get back buffer
	DDSCAPS ddscaps;
	ZeroMemory(&ddscaps, sizeof(ddscaps));
	ddscaps.dwCaps = DDSCAPS_BACKBUFFER;
	hr = m_lpFrontSurface->GetAttachedSurface(&ddscaps, &m_lpBackSurface);
	ASSERT(hr == 0);

	for (int i=0; i<buffercount; i++)
	{
		ClearSurface(m_lpBackSurface);
		hr = m_lpFrontSurface->Flip(NULL, DDFLIP_WAIT);
		if(hr!=0)
		{
		}
	}

	// Init Video Menu
	m_pMenu = new (CVideoMenu);
	m_pMenu->CreateMenuSurface(m_lpDirectDraw);
	m_pMenu->Init();

	CVideoMenu::CreateOfflineSurface(&m_lpLogSurface, 800, 50);
	

	CVideoMenu::CreateOfflineSurface(&m_lpBlackSurface, 40, 30);
	m_pMenu->ClearSurface(m_lpBlackSurface);
	CVideoMenu::CreateOfflineSurface(&m_lpPreviewFrmSurface, 40, 30, m_ColorSpace);
	ClearSurface(m_lpPreviewFrmSurface,215,215-36,215);//0xFFFF);


	if (m_hRenderThreadExit == NULL)
	{
		m_fExit = FALSE;
		m_hRenderThreadExit = CreateEvent(NULL, FALSE, FALSE, NULL);
#ifdef RENDER_THREAD
		AfxBeginThread(RenderThread, NULL,THREAD_PRIORITY_TIME_CRITICAL);
#else
#ifndef VE_LUON
		timeSetEvent(20,0,TimeProc,0,TIME_PERIODIC|TIME_CALLBACK_FUNCTION);
#endif
#endif
		
	}

	UpdateOverlay();

	//dat thoi gian timer chinh xac den 1ms
	timeBeginPeriod(1);


	return TRUE;
}


void CavPlayer::UpdateOverlay(LPDIRECTDRAWSURFACE lpSurface)
{
	if (lpSurface)
	{
		DDOVERLAYFX overlayFx;

		ZeroMemory(&overlayFx, sizeof(overlayFx));
		overlayFx.dwSize = sizeof(overlayFx);
		overlayFx.dckDestColorkey.dwColorSpaceHighValue = RGB(0, 0, 0);
		overlayFx.dckDestColorkey.dwColorSpaceLowValue = RGB(0,0, 0);
		RECT rect;
		m_wndDisplay.GetClientRect(&rect);
		m_wndDisplay.ClientToScreen(&rect);
		if (rect.right==0)
			SetRect(&rect, 0, 0, 1, 1);

		HRESULT hr = lpSurface->UpdateOverlay(NULL, m_lpPrimarySurface,&rect,
									DDOVER_SHOW | DDOVER_KEYDESTOVERRIDE, &overlayFx);
		
		if(hr!=0)
		{
		}
	}
}


void CavPlayer::DestroyDirectDraw()
{
	
	if (m_hRenderThreadExit)
	{
		m_fExit = TRUE;
		Sleep(2000);
		WaitForSingleObject(m_hRenderThreadExit,INFINITE);
		CloseHandle(m_hRenderThreadExit);
	}
	
	m_pMenu->Cleanup();
	delete m_pMenu;
	if (m_lpLogSurface != NULL) {
		m_lpLogSurface->Release();
		m_lpLogSurface = NULL;
	}
	m_lpBlackSurface->Release();
	m_lpPreviewFrmSurface->Release();
	m_lpFrontSurface->Release();
	m_lpPrimarySurface->Release();	
	m_lpFrontSurface = m_lpPrimarySurface = m_lpBackSurface = NULL;
	m_lpDirectDraw->Release();
	m_lpDirectDraw = NULL;
	m_wndDisplay.DestroyWindow();
	
	ReleaseMutex(m_hPlayerMutex);
	CloseHandle(m_hPlayerMutex);

}


int CavPlayer::Init(int video_width, int video_height, int audio_channels, int audio_samples_rate)
{

	int i;
	m_hPictureMutex = CreateMutex(NULL,FALSE,NULL);
	m_hAudioMutex = CreateMutex(NULL,FALSE,NULL);

	for (i = 0; i < MAX_PICTURES; i++)
		m_FreePictureList.AddTail(CreatePicture(1280,720));

	m_dwVidStartTime = m_dwVidStartPTS = 0;
	m_dwAudStartTime = m_dwAudStartPTS = 0;

	CAudioFrame* lpAudioFrame;
	for (i = 0; i < AUDIO_ARRAY_SIZE; i++)
	{
		lpAudioFrame = new CAudioFrame;
		lpAudioFrame->audio = new BYTE[1024*10];
		lpAudioFrame->pts = 0;
		m_FreeAudioList.AddTail(lpAudioFrame);
	}

	return 0;

}


void CavPlayer::Exit()
{

#ifdef RENDER_THREAD
	WaitForSingleObject(m_hPictureMutex,INFINITE);
#endif
	while (!m_FreePictureList.IsEmpty())
		DeletePicture((s_pict*)m_FreePictureList.RemoveHead());

	while (!m_PictureList.IsEmpty())
		DeletePicture((s_pict*)m_PictureList.RemoveHead());		
#ifdef RENDER_THREAD
	ReleaseMutex(m_hPictureMutex);
	CloseHandle(m_hPictureMutex);
#endif

#ifdef RENDER_THREAD
	WaitForSingleObject(m_hAudioMutex,INFINITE);
#endif
	CAudioFrame* lpAudioFrame;
	while (!m_FreeAudioList.IsEmpty())
	{
		lpAudioFrame = (CAudioFrame *)m_FreeAudioList.RemoveHead();
		delete [] lpAudioFrame->audio;
		delete lpAudioFrame;
	}
	while (!m_AudioList.IsEmpty())
	{
		lpAudioFrame = (CAudioFrame *)m_AudioList.RemoveHead();
		delete [] lpAudioFrame->audio;
		delete lpAudioFrame;
	}
#ifdef RENDER_THREAD
	ReleaseMutex(m_hAudioMutex);
	CloseHandle(m_hAudioMutex);
#endif
	
}


void CavPlayer::ClearSurface(LPDIRECTDRAWSURFACE lpSurface, int red, int green, int blue)
{
	if (lpSurface == NULL)
		return;

	DDPIXELFORMAT ddpf;
	DDBLTFX ddbltfx;
	HRESULT hr;

	ddbltfx.dwSize = sizeof(ddbltfx);
	
	memset(&ddpf, 0, sizeof(ddpf));
	ddpf.dwSize = sizeof(ddpf);
	lpSurface->GetPixelFormat(&ddpf);

	if (ddpf.dwFourCC == MAKEFOURCC('Y', 'V', '1', '2'))
	{
		DDSURFACEDESC ddsd;

		ddsd.dwSize = sizeof(ddsd);	
		hr = lpSurface->Lock(NULL, &ddsd, DDLOCK_SURFACEMEMORYPTR | DDLOCK_WAIT, NULL);
		if (hr != 0)
		{
			if(hr==DDERR_SURFACELOST)
			{
				lpSurface->Restore();
				return;
			}
			else
				ASSERT(0);
			return;
		}
		DWORD y, u, v;
		y = 299*red + 587*green + 114*blue;
		u = -147*red - 289*green + 437*blue;
		v = 615*red - 515*green - 100*blue;

		y /= 1000;
		u /= 1000;
		v /= 1000;

		LPBYTE lpSurfaceData = LPBYTE(ddsd.lpSurface);
		memset(lpSurfaceData, y, ddsd.lPitch*ddsd.dwHeight);
		lpSurfaceData += ddsd.lPitch*ddsd.dwHeight;

		memset(lpSurfaceData, u+0x74, ddsd.lPitch*ddsd.dwHeight/4);
		lpSurfaceData += ddsd.lPitch*ddsd.dwHeight/4;

		memset(lpSurfaceData, v+0x74, ddsd.lPitch*ddsd.dwHeight/4);
		lpSurface->Unlock(NULL);
	}
	else if (ddpf.dwFourCC == MAKEFOURCC('Y', 'U', 'Y', '2'))
	{ 
		ddbltfx.dwFillColor = 0x74007400;
		hr = lpSurface->Blt(NULL, NULL, NULL, DDBLT_COLORFILL, &ddbltfx);

		if(hr!=0)
		{
			if(hr==DDERR_SURFACELOST)
				lpSurface->Restore();
			else
			{
				ASSERT(0);
			}
		}
	}
	else
	{
		ddbltfx.dwFillColor = 0;
		hr = lpSurface->Blt(NULL, NULL, NULL, DDBLT_COLORFILL, &ddbltfx);
		if(hr!=0)
		{
			if(hr==DDERR_SURFACELOST)
				lpSurface->Restore();
			else
			{
				ASSERT(0);
			}
		}
	}
}

void CavPlayer::ClearSurfaceRect(LPDIRECTDRAWSURFACE lpSurface,LPRECT pRect, int red, int green, int blue)
{
	if (lpSurface == NULL)
		return;

	DDPIXELFORMAT ddpf;
	DDBLTFX ddbltfx;
	HRESULT hr;

	ddbltfx.dwSize = sizeof(ddbltfx);

	memset(&ddpf, 0, sizeof(ddpf));
	ddpf.dwSize = sizeof(ddpf);
	lpSurface->GetPixelFormat(&ddpf);

	if (ddpf.dwFourCC == MAKEFOURCC('Y', 'V', '1', '2'))
	{
		DDSURFACEDESC ddsd;

		ddsd.dwSize = sizeof(ddsd);	
		hr = lpSurface->Lock(pRect, &ddsd, DDLOCK_SURFACEMEMORYPTR | DDLOCK_WAIT, NULL);
		if (hr != 0)
		{
			if(hr==DDERR_SURFACELOST)
			{
				lpSurface->Restore();
				return;
			}
			else
				ASSERT(0);
			return;
		}
		DWORD y, u, v;
		y = 299*red + 587*green + 114*blue;
		u = -147*red - 289*green + 437*blue;
		v = 615*red - 515*green - 100*blue;

		y /= 1000;
		u /= 1000;
		v /= 1000;

		LPBYTE lpSurfaceData = LPBYTE(ddsd.lpSurface);
		memset(lpSurfaceData, y, ddsd.lPitch*ddsd.dwHeight);
		lpSurfaceData += ddsd.lPitch*ddsd.dwHeight;

		memset(lpSurfaceData, u+0x74, ddsd.lPitch*ddsd.dwHeight/4);
		lpSurfaceData += ddsd.lPitch*ddsd.dwHeight/4;

		memset(lpSurfaceData, v+0x74, ddsd.lPitch*ddsd.dwHeight/4);
		lpSurface->Unlock(NULL);
	}
	else if (ddpf.dwFourCC == MAKEFOURCC('Y', 'U', 'Y', '2'))
	{ 
		ddbltfx.dwFillColor = 0x74007400;
		hr = lpSurface->Blt(NULL, NULL, NULL, DDBLT_COLORFILL, &ddbltfx);

		if(hr!=0)
		{
			if(hr==DDERR_SURFACELOST)
				lpSurface->Restore();
			else
			{
				ASSERT(0);
			}
		}
	}
	else
	{
		ddbltfx.dwFillColor = 0;
		hr = lpSurface->Blt(NULL, NULL, NULL, DDBLT_COLORFILL, &ddbltfx);
		if(hr!=0)
		{
			if(hr==DDERR_SURFACELOST)
				lpSurface->Restore();
			else
			{
				ASSERT(0);
			}
		}
	}
}


s_pict* CavPlayer::CreatePicture(int width, int height)
{
	s_pict* pPict;
	pPict = new s_pict;
	pPict->lpLum = new BYTE[width*height];
	pPict->lpCr = new BYTE[width*height/4];
	pPict->lpCb = new BYTE[width*height/4];
	pPict->width = pPict->height = pPict->PTS = 0;

	return pPict;
}


void CavPlayer::DeletePicture(s_pict* pPict)
{
	delete[] pPict->lpLum;
	delete[] pPict->lpCr;
	delete[] pPict->lpCb;
	delete pPict;
}


int CavPlayer::CreateOfflineSur(int width,int height)
{
	DDSURFACEDESC ddsd;
	HRESULT hr;
	
	if (m_lpOfflineSurface)
		m_lpOfflineSurface->Release();
	m_lpOfflineSurface = NULL;

	//create offline screen
	ZeroMemory(&ddsd, sizeof(ddsd));
	ddsd.dwSize = sizeof(ddsd);
	ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_PIXELFORMAT;
	ddsd.dwWidth = width;
	ddsd.dwHeight = height;
	ddsd.ddsCaps.dwCaps = DDSCAPS_VIDEOMEMORY;
	ddsd.ddpfPixelFormat = g_PixelFormats[m_ColorSpace];
	hr = m_lpDirectDraw->CreateSurface(&ddsd, &m_lpOfflineSurface, NULL);
	ASSERT(hr==0);

	m_nSurfaceHeight = height;
	m_nSurfaceWidth = width;

	return 0;
}


// Semitransparent for Video Menu
//------------------
#define BITS 10
//------------------
int CavPlayer::Semitransparent(s_pict* lpPict, LPRECT pRect, int lmask)
{
	int x1, y1, w, h;
	int x_scale, y_scale;
	int width = lpPict->width;
	int height = lpPict->height;
	LPBYTE lpLum;
	LPRECT rect;

	if (m_fLocal)
	{
		if (m_fAVTest)
			rect = g_Mux1RectArray;
		else
			rect = &g_PreviewRect;
	}
	else
		rect = &m_lpRectArray[m_iPlayer - (m_nPageNo - 1)*m_nMuxMode];
	x_scale = (width<<BITS) / (rect->right - rect->left);
	y_scale = (height<<BITS) / (rect->bottom - rect->top);

	x1 = rect->left<pRect->left ? (pRect->left - rect->left)*x_scale >> BITS : 0; 
	y1 = rect->top<pRect->top ? (pRect->top - rect->top)*y_scale >> BITS : 0;

	w = (rect->right < pRect->right) ? width - x1
		: (((pRect->right - rect->left)*x_scale) >> BITS) - x1;
	h = (rect->bottom < pRect->bottom) ? height - y1
		: (((pRect->bottom - rect->top)*y_scale) >> BITS) - y1;

	if (m_nTVRatio == 1)
	{
		y1 = (y1 - height/2)*3/4 + height/2;
		h *= 3;
		h /= 4;
	}

	lpLum = lpPict->lpLum + width*y1 + x1;	//goto line y1, col x1
	int nPad = width - w;

	if ((w > 0) && (h > 0))
		for (int i=0; i<h; i++)
		{
			for (int j=0; j<w; j++)
			{
				*lpLum = max(0, *lpLum-lmask);
				*lpLum++ >>= 1;
			}
			lpLum += nPad;
		}

	return 0;
}


int CavPlayer::DisplayFrame(LPRECT pRect)
{
	s_pict* lpPict;
	DWORD dwCurTime=timeGetTime();
	CAudioFrame* lpAudioFrame;

	//EnterCriticalSection(&m_hCriticalSection);

	WaitForSingleObject(m_hPictureMutex,INFINITE);
	
	m_bDirty = FALSE;
	if (m_PictureList.IsEmpty())
		m_NoPictCount++;
	else
	{
		if ((m_iPlayer < (m_nPageNo - 1)*m_nMuxMode ||
			m_iPlayer >= m_nPageNo*m_nMuxMode) && (!m_fLocal))
			m_FreePictureList.AddTail(m_PictureList.RemoveHead());
		else
		{
			lpPict = (s_pict*)m_PictureList.GetHead();
			int delta=(timeGetTime() - m_dwVidStartTime)-(lpPict->PTS - m_dwVidStartPTS);
			if(abs(delta)>150)
				m_dwVidStartTime = 0;

			if (m_dwVidStartTime == 0)
			{
				m_dwVidStartPTS = lpPict->PTS;
				m_dwVidStartTime = timeGetTime()+ 150;
			}

			if(IsValidToPlay())
			{				
				m_FreePictureList.AddTail(m_PictureList.RemoveHead());		

				if (m_pMenu->IsVisible())
				{
					Semitransparent(lpPict, &g_MenuRect, 24);
				}
				if (m_fLogDisplayed)
					Semitransparent(lpPict, &g_LogRect, 24);
				if (m_fVDialog)
				{
					RECT m_VDialogRect;
					::GetWindowRect(dlg.m_hWnd, &m_VDialogRect);
					RECT VDialogRect;
					VDialogRect.left = m_VDialogRect.left*CX/800;
					VDialogRect.top = m_VDialogRect.top*CY/600;
					VDialogRect.right = m_VDialogRect.right*CX/800;
					VDialogRect.bottom = m_VDialogRect.bottom*CY/600;

					Semitransparent(lpPict, &VDialogRect, 16);
				}

				if (COLOR_SPACE_YV12 == m_ColorSpace)
				{

					CopyPict2SurYV12(lpPict);
					m_bDirty = TRUE;
				}
				else
				{
					CopyPict2SurYUY2(lpPict);				
					m_bDirty = TRUE;
				}
			}
			
		}
		m_NoPictCount = 0;
	}

	if (m_NoPictCount>=120)
	{
		ClearSurface(m_lpOfflineSurface);
		m_NoPictCount=0;
	}

	ReleaseMutex(m_hPictureMutex);



	WaitForSingleObject(m_hAudioMutex,INFINITE);

	//Phan choi tieng
	if (!m_AudioList.IsEmpty())
	{
		lpAudioFrame = (CAudioFrame*)m_AudioList.GetHead();
		int delta = (timeGetTime() - m_dwAudStartTime) - (lpAudioFrame->pts - m_dwAudStartPTS);
		if(abs(delta) > 64)
			m_dwAudStartTime = 0;

		if (m_dwAudStartTime == 0)
		{
			m_dwAudStartPTS = lpAudioFrame->pts;
			m_dwAudStartTime = timeGetTime()+ 64; //tre di 1 frame
		}
		if (timeGetTime() - m_dwAudStartTime >= lpAudioFrame->pts - m_dwAudStartPTS)
		{
			PlaySamples(lpAudioFrame->audio, lpAudioFrame->size);
			m_FreeAudioList.AddTail(m_AudioList.RemoveHead());
		}
	}
	
	ReleaseMutex(m_hAudioMutex);


	return -1;
}


int CavPlayer::PlayVideo(LPBYTE lpLum, LPBYTE lpCr, LPBYTE lpCb, int width,
						  int height, DWORD pts, int pitch)
{
#ifndef VE_LUON	
	WaitForSingleObject(m_hPictureMutex,INFINITE);

	if (m_FreePictureList.IsEmpty())
	{
		m_dwVidStartTime = 0;
		if(!m_PictureList.IsEmpty())
		{
			m_FreePictureList.AddTail(m_PictureList.RemoveHead());

		}
		else
		{
			for (int i = 0; i < MAX_PICTURES; i++)
				m_FreePictureList.AddTail(CreatePicture(1024,768));
		}
		ReleaseMutex(m_hPictureMutex);
		return -1;
	}

	int index = 0;
	if (pitch == 0)
		pitch = width;

	s_pict* pict = (s_pict*) m_FreePictureList.RemoveHead();
	for (int i = 0; i < height; i++)
	{
		memcpy(pict->lpLum + index, lpLum, width);
		lpLum += pitch;
		index += width;
	}
	index = 0;
	for (i = 0; i < height/2; i++)
	{
		memcpy(pict->lpCr + index, lpCr, width/2);
		memcpy(pict->lpCb + index, lpCb, width/2);
		index += width/2;
		lpCr += pitch/2;
		lpCb += pitch/2;
	}
	pict->width = width;
	pict->height = height;
	pict->PTS = pts;
	m_PictureList.AddTail(pict);
	ReleaseMutex(m_hPictureMutex);

#else
	int index = 0;
	s_pict* pict = CreatePicture(1024,768);
	for (int i = 0; i < height; i++)
	{
		memcpy(pict->lpLum + index, lpLum, width);
		lpLum += pitch;
		index += width;
	}
	index = 0;
	for (i = 0; i < height/2; i++)
	{
		memcpy(pict->lpCr + index, lpCr, width/2);
		memcpy(pict->lpCb + index, lpCb, width/2);
		index += width/2;
		lpCr += pitch/2;
		lpCb += pitch/2;
	}
	pict->width = width;
	pict->height = height;

	CopyPict2SurYV12(pict);
	
	TimeProc(0, 0, 0, 0, 0);

	DeletePicture(pict);

#endif
	//LeaveCriticalSection(&m_hCriticalSection);
	return 0;
}


void CavPlayer::PlayAudio(LPBYTE audio, int size, DWORD pts)
{
	CAudioFrame* lpAudioFrame=NULL;

	WaitForSingleObject(m_hAudioMutex,INFINITE);

	if (!m_FreeAudioList.IsEmpty())
	{
		lpAudioFrame = (CAudioFrame*)m_FreeAudioList.RemoveHead();

		memcpy(lpAudioFrame->audio, audio, size);
		lpAudioFrame->size = size;
		lpAudioFrame->pts = pts;
		m_AudioList.AddTail(lpAudioFrame);
	}
	else
	{
		if(!m_AudioList.IsEmpty())
			m_FreeAudioList.AddTail(m_AudioList.RemoveHead());
		else
		{
			for (int i = 0; i < AUDIO_ARRAY_SIZE; i++)
			{
				lpAudioFrame = new CAudioFrame;
				lpAudioFrame->audio = new BYTE[1024*10];
				lpAudioFrame->pts = 0;
				m_FreeAudioList.AddTail(lpAudioFrame);
			}
		}
	}

	ReleaseMutex(m_hAudioMutex);
}


void CavPlayer::PlaySamples(LPBYTE buffer, int samples)
{
	
}


void CavPlayer::SetStartPTS(DWORD pts)
{
	m_dwVidStartPTS = pts;
	m_dwVidStartTime = GetTickCount();
}


void CavPlayer::TimeProc(UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
	static DWORD prev_call=0;
	CavPlayer* lpPlayer;
	int i;
	HRESULT hr;

	WaitForSingleObject(m_hPlayerMutex,1000);
	BOOL bUpdate = TRUE;
	if (GetTickCount()-prev_call)
	{
		ClearSurface(m_lpBackSurface);
		
		int index = (m_nPageNo - 1)*m_nMuxMode;

		//copy cac chu tu queue vao surface
		for (i = 0; i < m_Players.GetSize();i++)
		{
			lpPlayer = (CavPlayer *)(m_Players.GetAt(i));
			lpPlayer->DisplayFrame();
		}

		for (i = 0; (index < m_nNumOfPlayer) && (i < m_nMuxMode); i++, index++)
		{
			lpPlayer = (CavPlayer *)(m_Players.GetAt(index));
			
			if (lpPlayer->m_lpOfflineSurface)
			{
				RECT rect;
				SetRect(&rect, 0, 0, lpPlayer->m_nSurfaceWidth, lpPlayer->m_nSurfaceHeight);
				if (m_nTVRatio == 1)
				{
					rect.top += lpPlayer->m_nSurfaceHeight / 8;
					rect.bottom -= lpPlayer->m_nSurfaceHeight / 8;
				}
				//if(lpPlayer->m_bDirty)
				{
					hr=m_lpBackSurface->Blt(&m_lpRectArray[i], lpPlayer->m_lpOfflineSurface, &rect, DDBLT_ASYNC, NULL);
					if(hr==DDERR_SURFACELOST)
						m_lpBackSurface->Restore();

					lpPlayer->m_bDirty = FALSE;
					bUpdate = TRUE;
				}
			}
			
		}

		
		
		if (m_pLocalPlayer)
		{
			m_pLocalPlayer->DisplayFrame();
			RECT rect;
			SetRect(&rect, 0, 0, m_pLocalPlayer->m_nSurfaceWidth, m_pLocalPlayer->m_nSurfaceHeight);
			if (m_nTVRatio == 1)
			{
				rect.top += m_pLocalPlayer->m_nSurfaceHeight / 8;
				rect.bottom -= m_pLocalPlayer->m_nSurfaceHeight / 8;
			}
			if (m_fPreview)
			{
				if (m_pLocalPlayer->m_lpOfflineSurface)
				{
					//if(m_pLocalPlayer->m_bDirty)
					{
						hr=m_lpBackSurface->Blt(&g_PreviewFrmRect, m_lpPreviewFrmSurface, NULL, DDBLT_ASYNC, NULL);

						hr=m_lpBackSurface->Blt(&g_PreviewRect, m_pLocalPlayer->m_lpOfflineSurface, &rect, DDBLT_ASYNC, NULL);

						if(hr==DDERR_SURFACELOST)
							m_lpBackSurface->Restore();
	
						m_pLocalPlayer->m_bDirty = FALSE;

						bUpdate = TRUE;
					}
				}
			}
		}

		// Ve~ menu
		if (m_pMenu && CVideoMenu::m_NeedUpdate > 0)
		{
			if (m_pMenu->IsVisible())
			{
				RECT menuRect;
				
				CRect wndRect;
				m_wndDisplay.GetClientRect(&menuRect);
				int wndWidth = menuRect.right - menuRect.left;
				int wndHeight = menuRect.bottom - menuRect.top;
				menuRect.left += wndWidth*15/100;
				menuRect.top += wndHeight/5 + 4;
				menuRect.right -= wndWidth*15/100;
				menuRect.bottom -= wndHeight/5 + 4;
				m_wndDisplay.ClientToScreen(&menuRect);

				hr = m_lpPrimarySurface->Blt(&menuRect,m_pMenu->GetSurface(),NULL,DDBLT_ASYNC,NULL);		
				ASSERT(hr == 0);
			}
			else
				m_wndDisplay.Invalidate();

			InterlockedDecrement(&(CVideoMenu::m_NeedUpdate));
		}
		if(bUpdate)
			hr=m_lpFrontSurface->Flip(NULL,DDFLIP_WAIT);

	}
	ReleaseMutex(m_hPlayerMutex);
	prev_call=GetTickCount();
}

void CavPlayer::asm_CopyPict2SurYV12(s_pict *lpPict)
{
	/*
	DDSURFACEDESC ddsd;
	__m128i* lpSurface;
	__m128i* lpSurface2;
	int width = lpPict->width, height = lpPict->height;
	__m128i* lpLum = (__m128i*)(lpPict->lpLum);
	__m128i* lpCb = (__m128i*)lpPict->lpCb;
	__m128i* lpCr = (__m128i*)lpPict->lpCr;
	int i,j;

	if ((m_nSurfaceWidth != width) || (m_nSurfaceHeight != height))
		CreateOfflineSur(width, height);

	if (m_lpOfflineSurface == NULL)
		return;

	//copy picture to surface
	ddsd.dwSize = sizeof(ddsd);
	HRESULT hr = m_lpOfflineSurface->Lock(NULL, &ddsd, DDLOCK_SURFACEMEMORYPTR | DDLOCK_WAIT, NULL);
	if (hr != 0)
		return;

	ASSERT(ddsd.lPitch % 16 == 0);
	int lPitch = ddsd.lPitch / 16 - width;
	lpSurface = (__m128i*)(ddsd.lpSurface);

	for (i = 0; i<height; i++)
	{
		for(j=0;j<width;j++,lpSurface++,lpLum++)
		{
			//_mm_stream_si32(lpSurface,*lpLum);
			_mm_stream_si128(lpSurface,*lpLum);
		}
		lpSurface += lPitch;
	}

	width /= 2;
	height /= 2;
	lPitch /= ddsd.lPitch / 16;
	lpSurface2 = lpSurface + lPitch*height;
	lPitch -= width;

	for (i=0; i<height; i++)
	{
		for(j=0;j<width;j++,lpSurface++,lpSurface2++,lpCb++,lpCr++)
		{
			//_mm_stream_si32(lpSurface,*lpCb);	
			//_mm_stream_si32(lpSurface2,*lpCr);
			_mm_stream_si128(lpSurface,*lpCb);
			_mm_stream_si128(lpSurface2,*lpCr);
		}
		lpSurface += lPitch;
		lpSurface2 += lPitch;
	}

	_mm_sfence();

	m_lpOfflineSurface->Unlock(NULL);
*/
}


void CavPlayer::CopyPict2SurYUY2(s_pict *lpPict)
{
	DDSURFACEDESC ddsd;
	HRESULT hr;
	LPBYTE lpSurfaceData;
	
	LPBYTE lpLum = lpPict->lpLum;
	LPBYTE lpCr = lpPict->lpCr;
	LPBYTE lpCb = lpPict->lpCb;
	int width = lpPict->width, height = lpPict->height;
	LPBYTE lpLum2 = lpLum + width, lpCr2 = lpCr, lpCb2 = lpCb;
	int i, j, nOffset;

	if ((m_nSurfaceWidth != width) || (m_nSurfaceHeight != height))
		CreateOfflineSur(width, height);

	//copy picture to surface
	ddsd.dwSize = sizeof(ddsd);	
	hr = m_lpOfflineSurface->Lock(NULL, &ddsd, DDLOCK_SURFACEMEMORYPTR |
									DDLOCK_WAIT, NULL);
	if (hr != 0)
		return;
	lpSurfaceData = LPBYTE(ddsd.lpSurface);
	nOffset = 2*(ddsd.lPitch - width);
	for (i=height; i>0; i-=2)
	{
		for (j=width; j>0; j-=2)
		{
			*lpSurfaceData++ = *lpLum++; *lpSurfaceData++ = *lpCr++;
			*lpSurfaceData++ = *lpLum++; *lpSurfaceData++ = *lpCb++;
		}
		lpSurfaceData += nOffset;
		lpLum += width;
	}
	lpSurfaceData = LPBYTE(ddsd.lpSurface) + ddsd.lPitch;
	for (i=height; i>0; i-=2)
	{
		for (j=width; j>0;j-=2)
		{
			*lpSurfaceData++ = *lpLum2++; *lpSurfaceData++ = *lpCr2++;
			*lpSurfaceData++ = *lpLum2++; *lpSurfaceData++ = *lpCb2++;
		}
		lpSurfaceData += nOffset;
		lpLum2 += width;
	}	
	m_lpOfflineSurface->Unlock(NULL);
}


void CavPlayer::CopyPict2SurYV12(s_pict *lpPict)
{
	DDSURFACEDESC ddsd;
	HRESULT hr;
	LPBYTE lpSurfaceData;
	int i;
	LPBYTE lpLum = lpPict->lpLum;
	LPBYTE lpCr = lpPict->lpCr;
	LPBYTE lpCb = lpPict->lpCb;
	int width = lpPict->width, height = lpPict->height;
	int lPitch;

	if ((m_nSurfaceWidth != width) || (m_nSurfaceHeight != height))
		CreateOfflineSur(width, height);

	if (m_lpOfflineSurface == NULL)
		return;
	//copy picture to surface
	ddsd.dwSize = sizeof(ddsd);
	hr = m_lpOfflineSurface->Lock(NULL, &ddsd, DDLOCK_SURFACEMEMORYPTR |
									DDLOCK_WAIT|DDLOCK_WRITEONLY, NULL);
	if (hr != 0)
	{
		if(hr==DDERR_SURFACELOST)
		{
			m_lpOfflineSurface->Restore();
		}
		return;
	}

	lPitch=ddsd.lPitch;
	lpSurfaceData = LPBYTE(ddsd.lpSurface);

	for (i=height; i>0; i--)
	{
		memcpy(lpSurfaceData,lpLum,width);
		lpSurfaceData+=lPitch;
		lpLum+=width;
	}

	width /= 2;
	height /= 2;
	lPitch/=2;
	LPBYTE lpSurfaceData2=lpSurfaceData + lPitch*height;

	for (i=height; i>0; i--)
	{
		memcpy(lpSurfaceData,lpCb,width);		
		memcpy(lpSurfaceData2,lpCr,width);

		lpSurfaceData+=lPitch;
		lpSurfaceData2+=lPitch;
		lpCb+=width;
		lpCr+=width;
	}
	m_lpOfflineSurface->Unlock(NULL);	
}

void CavPlayer::CopyPict2SurYV12Direct(s_pict *lpPict,LPRECT pRect)
{
	DDSURFACEDESC ddsd;
	HRESULT hr;
	LPBYTE lpSurfaceData;
	int i;
	LPBYTE lpLum = lpPict->lpLum;
	LPBYTE lpCr = lpPict->lpCr;
	LPBYTE lpCb = lpPict->lpCb;
	int width = lpPict->width, height = lpPict->height;
	int lPitch;

	//copy picture to surface
	ddsd.dwSize = sizeof(ddsd);
	hr = m_lpBackSurface->Lock(pRect, &ddsd, DDLOCK_SURFACEMEMORYPTR |
		DDLOCK_WAIT|DDLOCK_WRITEONLY, NULL);
		if (hr != 0)
		{
			if(hr==DDERR_SURFACELOST)
			{
				m_lpBackSurface->Restore();
			}
			return;
		}

		lPitch=ddsd.lPitch;
		lpSurfaceData = LPBYTE(ddsd.lpSurface);

		for (i=height; i>0; i--)
		{
			memcpy(lpSurfaceData,lpLum,width);
			lpSurfaceData+=lPitch;
			lpLum+=width;
		}

		width /= 2;
		height /= 2;
		lPitch/=2;
		LPBYTE lpSurfaceData2=lpSurfaceData + lPitch*height;

		for (i=height; i>0; i--)
		{
			memcpy(lpSurfaceData,lpCb,width);		
			memcpy(lpSurfaceData2,lpCr,width);

			lpSurfaceData+=lPitch;
			lpSurfaceData2+=lPitch;
			lpCb+=width;
			lpCr+=width;
		}
		m_lpBackSurface->Unlock(NULL);	
}


BOOL CavPlayer::DisplayText(CString lpszText)
{
	m_wndDisplay.m_DisplayText=lpszText;
	m_wndDisplay.DisplayText();
	m_fLogDisplayed = TRUE;

	return TRUE;
}

void CavPlayer::ClearText(LPCTSTR lpszText)
{
	CDC* pDC;
	CBrush brush;

	if (lpszText == NULL || m_wndDisplay.m_DisplayText.CompareNoCase(lpszText) == 0)
	{
		m_wndDisplay.m_DisplayText="";
		pDC = m_wndDisplay.GetDC();

		//RECT rect = {0, 0, 800, 50};
		RECT rect;
		m_wndDisplay.GetClientRect(&rect);
		rect.bottom=rect.top+50;

		brush.CreateSolidBrush(RGB(0, 0, 0));
		pDC->FillRect(&rect, &brush);
		m_wndDisplay.ReleaseDC(pDC);
		m_fLogDisplayed = FALSE;
	}
}


int CavPlayer::SetMuxMode(int mode)
{
	switch (mode)
	{
	case 1:
		m_lpRectArray = g_Mux1RectArray;
		break;
	case 2:
		m_lpRectArray = g_Mux2RectArray;
		break;
	case 4:
		m_lpRectArray = g_Mux4RectArray;
		break;
	case 6:
		m_lpRectArray = g_Mux6RectArray;
		break;
	case 9:
		m_lpRectArray = g_Mux9RectArray;
		break;
	case 13:
		m_lpRectArray = g_Mux13RectArray;
		break;
	case 16:
		m_lpRectArray = g_Mux16RectArray;
		break;
	default:
		return (-1);
	}
	
	m_nMuxMode = mode;
	m_nPageNo = 1;
	m_wndDisplay.Invalidate();
	return 0;
}


int CavPlayer::SetPage(int page)
{
	if (0 < page && page <= (m_nNumOfPlayer + m_nMuxMode - 1)/m_nMuxMode)
	{
		m_nPageNo = page;
		m_wndDisplay.Invalidate();
		return 0;
	}
	else
		return 0;
}


int CavPlayer::GetMuxMode()
{
	return m_nMuxMode;
}

void CavPlayer::OnKey(UINT nChar, LPARAM lParam)
{
	if (m_pMenu)
		m_pMenu->OnKey(nChar, lParam);
}

void CavPlayer::SetMuteIcon(BOOL fMute)
{
	m_wndDisplay.SetMuteIcon(fMute);
}

void CavPlayer::SetWarningIcon(BOOL fMute)
{
	m_wndDisplay.SetWarningIcon(fMute);
}


void CavPlayer::AutoMuxMode()
{
	WaitForSingleObject(m_hPlayerMutex,INFINITE);

	switch(m_Players.GetSize())
	{
	case 1:
		CavPlayer::SetMuxMode(1);
		break;
	case 2:
		CavPlayer::SetMuxMode(2);
		break;
	case 3:
	case 4:
		CavPlayer::SetMuxMode(4);
		break;
	case 5:
	case 6:
		CavPlayer::SetMuxMode(6);
		break;
	case 7:
	case 8:
	case 9:
		CavPlayer::SetMuxMode(9);
		break;
	case 10:
	case 11:
	case 12:
	case 13:
		CavPlayer::SetMuxMode(13);
		break;
	case 14:
	case 15:
	case 16:
		CavPlayer::SetMuxMode(16);
		break;
	}

	ReleaseMutex(m_hPlayerMutex);
	m_wndDisplay.Invalidate();
}


void CavPlayer::SetTopPos()
{
	CavPlayer* pThis=NULL;
	WaitForSingleObject(m_hPlayerMutex,INFINITE);
	for (int i=0; i < m_Players.GetSize(); i++)
		if (m_Players.GetAt(i) == this)
		{
			pThis = (CavPlayer *)m_Players.GetAt(i);
			m_Players.RemoveAt(i);
			m_Players.InsertAt(0, pThis);
			break;
		}
	for (i=0; i < m_Players.GetSize(); i++)
	{
		CavPlayer* pPlayer = (CavPlayer *)m_Players.GetAt(i);
		pPlayer->m_iPlayer = i;
		m_wndDisplay.removeVcsAlias(pPlayer->m_sPlayerAlias);
	}

	for (i=0; i < m_Players.GetSize(); i++)
	{
		CavPlayer* pPlayer = (CavPlayer *)m_Players.GetAt(i);
		m_wndDisplay.addVcsAlias(pPlayer->m_sPlayerAlias);
	}
	

	ReleaseMutex(m_hPlayerMutex);
}


int CavPlayer::ShowDialog(LPCTSTR sText, DWORD dwStyle)
{
	HideMenu();
	dlg.SetText(sText, dwStyle);
	int rc = dlg.DoModal();
	m_fVDialog = FALSE;
	return rc;
}

int CavPlayer::LogMsg(CString sMsg, int nClearTime)
{
	if (!IsWindow(m_wndDisplay))
		return -1;

	if (m_nDisplayTimer)
	{
		if(m_nDisplayTimer!=0)
			::timeKillEvent(m_nDisplayTimer);
		m_nDisplayTimer = 0;
		ClearText();
	}
	if (!sMsg.IsEmpty())
	{
		DisplayText(sMsg);
		m_nDisplayTimer = timeSetEvent(nClearTime*1000, 0, LogTimeProc, 0, TIME_ONESHOT | TIME_CALLBACK_FUNCTION);
	}

	return (0);
}

void CavPlayer::LogTimeProc(UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
	m_nDisplayTimer = 0;
	ClearText();
}


UINT CavPlayer::RenderThread(LPVOID lpParam)
{
	static preTime=GetTickCount();
	while (!m_fExit)
	{
		if(GetTickCount()-preTime>=25)
		{
			TimeProc(0, 0, 0, 0, 0);
			preTime = GetTickCount();
		}
		else
			Sleep(1);
	}
	SetEvent(m_hRenderThreadExit);
	return 0;
}

BOOL CavPlayer::IsValidToPlay()
{	
	s_pict* lpHeadPict=NULL;
	s_pict* lpTailPict=NULL;
	lpHeadPict = (s_pict*) m_PictureList.GetHead();

	if(lpHeadPict==NULL)
		return FALSE;

	if(m_pLocalPlayer != this)
	{
		if (timeGetTime() - m_dwVidStartTime >= lpHeadPict->PTS - m_dwVidStartPTS)
			return TRUE;
	}
	else
	{
		lpTailPict = (s_pict*) m_PictureList.GetTail();
		if(!lpTailPict)
			return FALSE;

		if(lpTailPict->PTS - lpHeadPict->PTS > 86)
			return TRUE;
	}
	
	return FALSE;
}

void CavPlayer::SetPlayerAlias(CString sAlias)
{
	m_sPlayerAlias=sAlias;
	m_wndDisplay.addVcsAlias(sAlias);
}
void CavPlayer::RemovePlayerAlias(CString sAlias)
{
	m_sPlayerAlias="";
	m_wndDisplay.removeVcsAlias(sAlias);
}