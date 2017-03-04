//-----------------------------------------------------------------------------
// VideoMenu.cpp: implementation of the CVideoMenu class.
//-----------------------------------------------------------------------------

#include "Stdafx.h"
#include "..\resource.h"
#include "VideoMenu.h"
#include "..\avPlayer.h"

/*
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
*/


#define XT_START		16
#define YT_START		75
#define TEXT_HEIGHT		41
#define FONT_SIZE		34
#define MENU_WIDTH		560
#define MENU_HEIGHT		350
#define DARK_BLUE		(RGB(4, 4, 4))

extern DDPIXELFORMAT g_PixelFormats[];

//-----------------------------------------------------------------------------
// Static member variable
//-----------------------------------------------------------------------------
HFONT					CVideoMenu::m_hTextFont			= NULL;
BOOL					CVideoMenu::m_fVisible			= FALSE;
LPDIRECTDRAW			CVideoMenu::m_pDD				= NULL;
LPDIRECTDRAWSURFACE		CVideoMenu::m_lpMenuSurface		= NULL;
LPDIRECTDRAWSURFACE		CVideoMenu::m_lpAlphaSurface	= NULL;
LPDIRECTDRAWSURFACE		CVideoMenu::m_lpFrameSurface	= NULL;
LPDIRECTDRAWSURFACE		CVideoMenu::m_lpCsSurface		= NULL;
LPDIRECTDRAWSURFACE		CVideoMenu::m_lpTriSurface		= NULL;
LPDIRECTDRAWSURFACE		CVideoMenu::m_lpCheckSurface	= NULL;
LPDIRECTDRAWSURFACE		CVideoMenu::m_lpSpinLSurface	= NULL;
LPDIRECTDRAWSURFACE		CVideoMenu::m_lpSpinRSurface	= NULL;
LPDIRECTDRAWSURFACE		CVideoMenu::m_lpSpinLSurfaceD	= NULL;
LPDIRECTDRAWSURFACE		CVideoMenu::m_lpSpinRSurfaceD	= NULL;
LPDIRECTDRAWSURFACE		CVideoMenu::m_lpUpArrowSurface	= NULL;
LPDIRECTDRAWSURFACE		CVideoMenu::m_lpDownArrowSurface	= NULL;

LPVOID					CVideoMenu::m_lpUserData		= NULL;
LONG					CVideoMenu::m_NeedUpdate		= 0;
void (*CVideoMenu::m_lpOnUpdateItem)(LPMENUITEM pItem, LPVOID pParam, LPVOID pUserData) = NULL;
void (*CVideoMenu::m_lpOnCommand)(LPMENUITEM pItem, LPVOID pUserData) = NULL;

CTypedPtrArray<CPtrArray, PADDR_ITEM> CVideoMenu::m_Addrs;
CVideoMenu*				g_pMainMenu=NULL;

struct _ENCODERSET {
	int VideoBitrate;
	int AudioBitrate;
	int SourceId;
} EncoderSet;

static COMBO_MENU_ITEM VideoSource[] =
{
	0,	_T("Composite"),
	1,	_T("S-Video")
};

static COMBO_MENU_ITEM ColorSystem[] =
{
	0,	_T("PAL"),
	1,	_T("NTSC")
};

static COMBO_MENU_ITEM RS232BitRate[] =
{
	9600,	_T("9600"),
	14400,	_T("14400")
};

static COMBO_MENU_ITEM MuxModes[] =
{
	1,	_T("1"),
	2,	_T("2"),
	4,	_T("4"),
	6,	_T("6"),
	9,	_T("9"),
	13,	_T("13"),
	16,	_T("16")
};

static COMBO_MENU_ITEM PageNum[] = 
{
	1,	_T("1"),
	2,	_T("2"),
	3,	_T("3"),
	4,	_T("4"),
	5,	_T("5"),
	6,	_T("6"),
	7,	_T("7"),
	8,	_T("8"),
	9,	_T("9"),
	10,	_T("10"),
	11,	_T("11"),
	12,	_T("12"),
	13,	_T("13"),
	14,	_T("14"),
	15,	_T("15"),
	16,	_T("16")
};

static COMBO_MENU_ITEM TVRatio[] =
{
	0, _T("4:3"),
	1, _T("16:9")
};

static COMBO_MENU_ITEM CameraId[] =
{
	0,	_T("0"),
	1,	_T("1"),
	2,	_T("2"),
	3,	_T("3"),
	4,	_T("4"),
	5,	_T("5"),
	6,	_T("6"),
	7,	_T("7"),
	8,	_T("8"),
	9,	_T("9"),
	10,	_T("10"),
	11,	_T("11"),
	12,	_T("12"),
	13,	_T("13"),
	14,	_T("14"),
	15,	_T("15"),
	16,	_T("16")
};

static COMBO_MENU_ITEM OnOff[] =
{
	0,		_T("T¾t"),
	1,		_T("BËt"),
};

static COMBO_MENU_ITEM FrameRates[] =
{
	1,	_T("Tù ®éng"),
	2,	_T("Mét nöa"),
	4,_T("Mét phÇn t­")
};

static COMBO_MENU_ITEM Volume[] =
{
	0,		_T("0"),
	1,		_T("1"),
	2,		_T("2"),
	3,		_T("3"),
	4,		_T("4"),
	5,		_T("5"),
	6,		_T("6"),
	7,		_T("7"),
	8,		_T("8"),
	9,		_T("9"),
	10,		_T("10")
};

static COMBO_MENU_ITEM CameraSpeed[] =
{
	0,	_T("1"),
	1,	_T("2"),
	2,	_T("3"),
	3,	_T("4"),
	4,	_T("5"),
	5,	_T("6"),
	6,	_T("7"),
	7,	_T("8"),
	8,	_T("9"),
	9,	_T("10")
};

static COMBO_MENU_ITEM ConfMode[] =
{
	0, _T("Ngang hµng"),
	-1, _T("DiÔn thuyÕt")
};

static COMBO_MENU_ITEM ContentRate[] =
{
//	0,		_T("0%"),
	1,		_T("10%"),
	2,		_T("20%"),
	3,		_T("30%"),
	4,		_T("40%"),
	5,		_T("50%"),
	6,		_T("60%"),
	7,		_T("70%"),
	8,		_T("80%"),
	9,		_T("90%"),
	10,		_T("100%")
};


//-----------------------------------------------------------------------------
// Construction/Destruction
//-----------------------------------------------------------------------------
CVideoMenu::CVideoMenu()
{
	m_nCurrentPos = 0;
	m_nSize = 0;
	m_lpParent = 0;
	m_lpTextSurface = NULL;
	m_nStartItem = 0;
	m_lpActiveChild = NULL;
	if (NULL == g_pMainMenu)
		g_pMainMenu = this;
}

CVideoMenu::~CVideoMenu()
{
	while (m_SubMenuArray.GetSize())
	{
		if (m_SubMenuArray.GetAt(0) != NULL)
			delete m_SubMenuArray.GetAt(0);
		m_SubMenuArray.RemoveAt(0);
	}
	if (m_lpTextSurface != NULL) {
		m_lpTextSurface->Release();
		m_lpTextSurface = NULL;
	}

	for (int i=0; i<m_nSize; i++)
		delete m_ItemArray[i];
	if (g_pMainMenu == this)
		g_pMainMenu = NULL;
}


int CVideoMenu::Cleanup()
{
	if (m_lpMenuSurface != NULL) {
		m_lpMenuSurface->Release();
		m_lpMenuSurface = NULL;
	}
	if (m_lpCsSurface != NULL) {
		m_lpCsSurface->Release();
		m_lpCsSurface = NULL;
	}
	if (m_lpTriSurface != NULL) {
		m_lpTriSurface->Release();
		m_lpTriSurface = NULL;
	}
	if (m_lpCheckSurface != NULL) {
		m_lpCheckSurface->Release();
		m_lpCheckSurface = NULL;
	}
	if (m_lpSpinLSurface != NULL) {
		m_lpSpinLSurface->Release();
		m_lpSpinLSurface = NULL;
	}
	if (m_lpSpinRSurface != NULL) {
		m_lpSpinRSurface->Release();
		m_lpSpinRSurface = NULL;
	}
	if (m_lpSpinLSurfaceD != NULL) {
		m_lpSpinLSurfaceD->Release();
		m_lpSpinLSurfaceD = NULL;
	}
	if (m_lpSpinRSurfaceD != NULL) {
		m_lpSpinRSurfaceD->Release();
		m_lpSpinRSurfaceD = NULL;
	}

	while (m_Addrs.GetSize())
	{
		delete m_Addrs.GetAt(0);
		m_Addrs.RemoveAt(0);
	}

	return 0;
}


HRESULT CVideoMenu::CreateOfflineSurface(LPDIRECTDRAWSURFACE* lppSurface, int width, int height, int color)
{
	//
	if(color ==2)
		color = 4;

	DDSURFACEDESC ddsd;
	HRESULT hr;

	if (NULL == m_pDD)
		return E_FAIL;

	if (*lppSurface)
		(*lppSurface)->Release();
	*lppSurface = NULL;

	ZeroMemory(&ddsd, sizeof(ddsd));
	ddsd.dwSize = sizeof(ddsd);
	ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_PIXELFORMAT;
	ddsd.dwWidth = width;
	ddsd.dwHeight = height;
	ddsd.ddpfPixelFormat = g_PixelFormats[color];
	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
	hr = m_pDD->CreateSurface(&ddsd, lppSurface, NULL);
	ASSERT(hr==0);

	// Set Color Key
	DDCOLORKEY ddck;
	ddck.dwColorSpaceLowValue  = 0L;
	ddck.dwColorSpaceHighValue = 0L;
	(*lppSurface)->SetColorKey( DDCKEY_SRCBLT, &ddck );
	ClearSurface(*lppSurface);

	return 0;
}


int CVideoMenu::CreateMenuSurface(LPDIRECTDRAW pDD)
{
	m_pDD = pDD;
	return CreateOfflineSurface(&m_lpMenuSurface, MENU_WIDTH, MENU_HEIGHT);
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HRESULT CVideoMenu::ClearSurface(LPDIRECTDRAWSURFACE lpSurface,
								 DWORD dwColor, LPRECT pRect)
{
	DDBLTFX ddbltfx;
	ddbltfx.dwSize = sizeof(ddbltfx); 
	ddbltfx.dwFillColor = dwColor; 

	lpSurface->Blt(pRect, NULL, NULL, DDBLT_COLORFILL, &ddbltfx);

	return S_OK;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HFONT CVideoMenu::CreateTextFont(LPCTSTR lpFontName, int nFontSize, LONG lfWeight)
{
	LOGFONT logfont;
	HFONT hTmpFont;
	
	memset (&logfont, 0, sizeof (logfont));
	if (nFontSize!=-1)
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


//-----------------------------------------------------------------------------
// Name: LoadBitmapFile()
// Desc: Load a bitmap from a file or resource into a DirectDraw surface.
//       normaly used to re-load a surface after a restore.
//-----------------------------------------------------------------------------
HBITMAP CVideoMenu::LoadBitmapFile(TCHAR* strBMP,
								DWORD dwDesiredWidth, DWORD dwDesiredHeight)
{
	HBITMAP hBMP;

	if ( strBMP == NULL )
		return NULL;

	//  Try to load the bitmap as a resource, if that fails, try it as a file
	hBMP = (HBITMAP) LoadImage( GetModuleHandle(_T("Mp4Lib.dll")), strBMP, 
								IMAGE_BITMAP, dwDesiredWidth, dwDesiredHeight, 
								LR_CREATEDIBSECTION );
	if ( hBMP == NULL )
	{
		hBMP = (HBITMAP) LoadImage( NULL, strBMP, IMAGE_BITMAP, 
									dwDesiredWidth, dwDesiredHeight, 
									LR_LOADFROMFILE | LR_CREATEDIBSECTION );
	}

	return hBMP;
}


//-----------------------------------------------------------------------------
// Name: DrawBitmap()
// Desc: Draws a bitmap over an entire DirectDrawSurface, stretching the 
//       bitmap if nessasary
//-----------------------------------------------------------------------------
HRESULT CVideoMenu::DrawBitmap( LPDIRECTDRAWSURFACE lpSurface, HBITMAP hBMP,
							  DWORD dwOriginX, DWORD dwOriginY,
							  DWORD dwSrcX, DWORD dwSrcY,
							  int dwWidth, int dwHeight)
{
	HDC            hDCImage;
	HDC            hDC;
	BITMAP         bmp;
	DDSURFACEDESC ddsd;
	HRESULT        hr;

	if ( hBMP == NULL || lpSurface == NULL )
		return E_INVALIDARG;

	// Make sure this surface is restored.
	if ( FAILED( hr = lpSurface->Restore() ) )
		return hr;

	// Get the surface.description
	ddsd.dwSize  = sizeof(ddsd);
	lpSurface->GetSurfaceDesc( &ddsd );

	if ( ddsd.ddpfPixelFormat.dwFlags == DDPF_FOURCC )
		return E_NOTIMPL;

	// Select bitmap into a memoryDC so we can use it.
	hDCImage = CreateCompatibleDC( NULL );
	if ( NULL == hDCImage )
		return E_FAIL;

	SelectObject( hDCImage, hBMP );

	// Get size of the bitmap
	GetObject( hBMP, sizeof(bmp), &bmp );

	// Use the passed size, unless zero
	dwWidth  = ( dwWidth == 0 ) ? bmp.bmWidth  : 
		min(bmp.bmWidth, dwWidth);
	dwHeight = ( dwHeight == 0 ) ? bmp.bmHeight : 
		min(bmp.bmHeight, dwHeight);

	// Stretch the bitmap to cover this surface
	if ( FAILED( hr = lpSurface->GetDC( &hDC ) ) )
		return hr;

	StretchBlt( hDC, dwOriginX, dwOriginY, 
				dwWidth, dwHeight, 
				hDCImage, dwSrcX, dwSrcY,
				dwWidth, dwHeight,
				SRCCOPY );

	if ( FAILED( hr = lpSurface->ReleaseDC( hDC ) ) )
		return hr;

	DeleteDC( hDCImage );

	return S_OK;
}


void CVideoMenu::save_bmp(LPDIRECTDRAWSURFACE lpSurface, CString outname)
{
    int scanLineSize, width, height, i, j;
    FILE *ou;
    BITMAPFILEHEADER fileHd;
    BITMAPINFOHEADER infoHd;

    ou = fopen (outname, "wb");
    if (ou == NULL)
        return;

	DDSURFACEDESC ddsd;
	HRESULT hr;
	LPBYTE lpSurfaceData;
	int lPitch;

	if (lpSurface == NULL)
		return;

	// copy surface to picture
	ddsd.dwSize = sizeof(ddsd);
	hr = lpSurface->Lock(NULL, &ddsd, DDLOCK_SURFACEMEMORYPTR |
									DDLOCK_WAIT, NULL);
	if (hr != 0)
		return;

	lPitch = ddsd.lPitch;
	lpSurfaceData = LPBYTE(ddsd.lpSurface);
	width = ddsd.dwWidth;
	height = ddsd.dwHeight;

    scanLineSize = ((width + 3)) & ~3;

    fileHd.bfType          =     0x4d42;
    fileHd.bfSize          =     sizeof (fileHd) + sizeof (infoHd) +
                                 scanLineSize * height;
    fileHd.bfReserved1     =     0;
    fileHd.bfReserved2     =     0;
    fileHd.bfOffBits       =     sizeof (fileHd) + sizeof (infoHd);

    infoHd.biSize          =     sizeof (infoHd);
    infoHd.biWidth         =     width;
    infoHd.biHeight        =     height;
    infoHd.biPlanes        =     1;
    infoHd.biBitCount      =     24;
    infoHd.biCompression   =     0;
    infoHd.biSizeImage     =     scanLineSize * height * 3;
    infoHd.biXPelsPerMeter =     0;
    infoHd.biYPelsPerMeter =     0;
    infoHd.biClrUsed       =     0;
    infoHd.biClrImportant  =     0;

    fwrite (&fileHd, sizeof (fileHd), 1, ou);
    fwrite (&infoHd, sizeof (infoHd), 1, ou);

	BYTE lpRGB[1024*3];
	short int lprgb[1024];

	for (i = height; i > 0; i--)
	{
		fseek (ou, fileHd.bfOffBits + (long int) scanLineSize * (i - 1) * 3, SEEK_SET);

		memcpy(lprgb, lpSurfaceData, width*2);
		for (j=0; j<width; j++)
		{
			lpRGB[j*3] = (lprgb[j] & 0x1F) << 3;
			lpRGB[j*3+1] = ((lprgb[j] >> 5) & 0x3F) << 2;
			lpRGB[j*3+2] = (lprgb[j] >> 8) & ~7;
		}
		fwrite(lpRGB, width*3, 1, ou);
		lpSurfaceData += lPitch;
		for (j = width*3; j < scanLineSize; j++)
		{
			fputc (0, ou);
			fputc (0, ou);
			fputc (0, ou);
		}
	}
	lpSurface->Unlock(NULL);	
    fclose (ou);
    
} /* save_bmp */


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CVideoMenu::DrawTexts(LPDIRECTDRAWSURFACE lpSurface, CString str,
					 int x, int y, COLORREF color)
{
	HDC hTextDC;
	HGDIOBJ hGdiObj;
	HRESULT hr;

	hr = lpSurface->GetDC(&hTextDC);
	ASSERT(hr == 0);
	hGdiObj=::SelectObject(hTextDC, CVideoMenu::m_hTextFont);
	SetBkMode(hTextDC, TRANSPARENT);
	int len = str.GetLength();

	//Draw text
	SetTextColor(hTextDC, DARK_BLUE);
	TextOut(hTextDC, x + 1, y + 1, str, len);
	TextOut(hTextDC, x - 1, y - 1, str, len);
	TextOut(hTextDC, x + 1, y - 1, str, len);
	TextOut(hTextDC, x - 1, y + 1, str, len);

	SetTextColor(hTextDC, color);
	TextOut(hTextDC, x, y, str, len);

	lpSurface->ReleaseDC(hTextDC);
}


void CVideoMenu::DrawTexts(LPDIRECTDRAWSURFACE lpSurface, CString str, LPRECT pRect,
					 DWORD dwStyle, COLORREF color)
{
	HDC hTextDC;
	HGDIOBJ hGdiObj;
	HRESULT hr;

	hr = lpSurface->GetDC(&hTextDC);
	ASSERT(hr == 0);
	hGdiObj=::SelectObject(hTextDC, CVideoMenu::m_hTextFont);
	SetBkMode(hTextDC, TRANSPARENT);
	int len = str.GetLength();

	//Draw text
	SetTextColor(hTextDC, DARK_BLUE);
	DrawText(hTextDC, str, -1, pRect, DT_SINGLELINE | dwStyle);
	OffsetRect(pRect, 2, 0);
	DrawText(hTextDC, str, -1, pRect, DT_SINGLELINE | dwStyle);
	OffsetRect(pRect, 0, 2);
	DrawText(hTextDC, str, -1, pRect, DT_SINGLELINE | dwStyle);
	OffsetRect(pRect, -2, 0);
	DrawText(hTextDC, str, -1, pRect, DT_SINGLELINE | dwStyle);

	SetTextColor(hTextDC, color);
	OffsetRect(pRect, 1, -1);
	DrawText(hTextDC, str, -1, pRect, DT_SINGLELINE | dwStyle);

	lpSurface->ReleaseDC(hTextDC);
}


//-----------------------------------------------------------------------------
// Initialize
//-----------------------------------------------------------------------------
int CVideoMenu::Init()
{
	HBITMAP hFrameBMP;
	HBITMAP hBntBMP;
	CVideoMenu* pMenu;

	if (m_lpMenuSurface == NULL)
		return -1;
	CreateOfflineSurface(&m_lpTextSurface, MENU_WIDTH, MENU_HEIGHT);
	CreateOfflineSurface(&m_lpCsSurface, MENU_WIDTH-10, TEXT_HEIGHT);
	CreateOfflineSurface(&m_lpTriSurface, 40, TEXT_HEIGHT);
	CreateOfflineSurface(&m_lpCheckSurface, 60, TEXT_HEIGHT);
	CreateOfflineSurface(&m_lpSpinLSurface, 60, TEXT_HEIGHT);
	CreateOfflineSurface(&m_lpSpinRSurface, 35, TEXT_HEIGHT);
	CreateOfflineSurface(&m_lpSpinLSurfaceD, 60, TEXT_HEIGHT);
	CreateOfflineSurface(&m_lpSpinRSurfaceD, 35, TEXT_HEIGHT);
	CreateOfflineSurface(&m_lpUpArrowSurface, 60, TEXT_HEIGHT);
	CreateOfflineSurface(&m_lpDownArrowSurface, 60, TEXT_HEIGHT);
	CreateOfflineSurface(&m_lpFrameSurface, MENU_WIDTH, MENU_HEIGHT);

	hFrameBMP = LoadBitmapFile(MAKEINTRESOURCE(MENU_FRAME), 0, 0);
	hBntBMP = LoadBitmapFile(MAKEINTRESOURCE(IDB_BUTTONS), 0, 0);

	DrawBitmap(m_lpFrameSurface, hFrameBMP);
	DrawBitmap(m_lpTriSurface, hBntBMP, 0, 0, 0, 360, 0, 40);
	DrawBitmap(m_lpCheckSurface, hBntBMP, 0, 0, 0, 320, 0, 40);
	DrawBitmap(m_lpSpinRSurface, hBntBMP, 0, 0, 0, 400, 0, 40);
	DrawBitmap(m_lpSpinLSurface, hBntBMP, 0, 0, 0, 440, 0, 40);
	DrawBitmap(m_lpUpArrowSurface, hBntBMP, 0, 0, 0, 480, 0, 40);
	DrawBitmap(m_lpDownArrowSurface, hBntBMP, 0, 0, 0, 520, 0, 40);
	DrawBitmap(m_lpSpinRSurfaceD, hBntBMP, 0, 0, 0, 560, 0, 40);
	DrawBitmap(m_lpSpinLSurfaceD, hBntBMP, 0, 0, 0, 600, 0, 40);

	ClearSurface(m_lpCsSurface, RGB(128,0,0)/*0x0f*/);

	DeleteObject(hFrameBMP);

	// Create Font
	m_hTextFont = CreateTextFont(_T(".VnArial"), FONT_SIZE, FW_BOLD);

	AddMenuItem(_T("Chøc n¨ng héi nghÞ"));
	AddMenuItem(_T("ThiÕt lËp A/V"));
	AddMenuItem(_T("ThiÕt lËp Camera"));
	AddMenuItem(_T("ThiÕt lËp m¹ng"));
	AddMenuItem(_T("Danh b¹"));

	pMenu = this->CreateSubMenu(0);
	pMenu->AddMenuItem(_T("KÕt nèi ®Õn"), ID_CONNECT);
	pMenu->AddMenuItem(_T("Ng¾t kÕt nèi"), ID_DISCONNECT);
	pMenu->AddMenuItem(_T("Tù ®éng chÊp nhËn kÕt nèi"), ID_AUTO_ACCEPT, OnOff, 2);
	pMenu->AddMenuItem(_T("ChÕ ®é héi nghÞ"), ID_CONF_MODE, ConfMode, 2);
	pMenu->AddMenuItem(_T("ChÕ ®é trén h×nh"), ID_SETMUXMODE, MuxModes, 7);
	pMenu->AddMenuItem(_T("LËt trang mµn h×nh"), ID_SETPAGE, PageNum, 16);
	pMenu->AddMenuItem(_T("TiÕng Mic"), ID_AUDIOONOFF, OnOff, 2);

		pMenu = pMenu->CreateSubMenu(0);
		for (int i=0; i<m_Addrs.GetSize(); i++)
		{
			pMenu->AddMenuItem(m_Addrs[i]->alias, ID_CONNECT);
			pMenu->SetStrData(i, m_Addrs[i]->ip);
		}
		pMenu->AddMenuItem(_T("NhËp ®Þa chØ IP"), ID_CONNECT, DS_TEXTBOX | DS_IP);

	pMenu = this->CreateSubMenu(1);
	pMenu->AddMenuItem(_T("§æi nguån Video"), ID_CHANGEVIDEOSOURCE, VideoSource, 2);
	pMenu->AddMenuItem(_T("HÖ mµu"), ID_COLORSYS, ColorSystem, 2);
	pMenu->AddMenuItem(_T("Sè h×nh/gi©y"), ID_FRAME_RATE, FrameRates, 3);
	pMenu->AddMenuItem(_T("Tû lÖ néi dung/h×nh ¶nh"), ID_CONTENT_RATE, ContentRate, 10);
	pMenu->AddMenuItem(_T("Tû lÖ mµn h×nh TV"), ID_TV_RATIO, TVRatio, 2);
	pMenu->AddMenuItem(_T("Xem h×nh t¹i chç"), ID_PREVIEW, OnOff, 2);
	pMenu->AddMenuItem(_T("Nghe tiÕng t¹i chç"), ID_AVTEST, OnOff, 2);
	pMenu->AddMenuItem(_T("¢m l­îng"), ID_SETVOLUME, Volume, 11);

	pMenu = this->CreateSubMenu(2);
	pMenu->AddMenuItem(_T("Tèc ®é RS232"), ID_SETBITRATERS232, RS232BitRate, 2);
	pMenu->AddMenuItem(_T("Tèc ®é quay camera"), ID_CAMERA_SPEED, CameraSpeed, 10);
	pMenu->AddMenuItem(_T("Cho phÐp ®Çu xa ®iÒu khiÓn"), ID_CAMERA_CTRL);
	pMenu->AddMenuItem(_T("Chän h×nh ®iÒu khiÓn"), ID_CAMERA_ID, CameraId, 17);

	pMenu = this->CreateSubMenu(3);
	pMenu->AddMenuItem(_T("B¨ng th«ng (Kb)"), ID_BANDWIDTH, DS_TEXTBOX);
	pMenu->AddMenuItem(_T("§Þa chØ IP"), ID_LOCALIP, DS_TEXTBOX | DS_IP);
	pMenu->AddMenuItem(_T("§Þa chØ NAT"), ID_NAT_IP, DS_TEXTBOX);

	pMenu = this->CreateSubMenu(4);
	pMenu->AddMenuItem(_T("HiÓn thÞ danh s¸ch"), ID_ADDR);
	pMenu->AddMenuItem(_T("Thªm tªn"));
	pMenu->AddMenuItem(_T("Xãa tªn"), ID_ADDR);

	//	if (m_Addrs.GetSize())
		{
			// Hien thi danh sach
			pMenu = pMenu->CreateSubMenu(0);
			for (i=0; i<m_Addrs.GetSize(); i++)
			{
				pMenu->AddMenuItem(m_Addrs[i]->alias, ID_ADDR);
				pMenu->SetStrData(i, m_Addrs[i]->ip);
			}
			pMenu = pMenu->m_lpParent;

			// Xoa ten trong danh sach
			pMenu = pMenu->CreateSubMenu(2);
			for (i=0; i<m_Addrs.GetSize(); i++)
			{
				pMenu->AddMenuItem(m_Addrs[i]->alias, ID_REMOVE);
				pMenu->SetStrData(i, m_Addrs[i]->ip);
			}
			pMenu = pMenu->m_lpParent;
		}
		pMenu = pMenu->CreateSubMenu(1);
		pMenu->AddMenuItem(_T("§Þa chØ"), 0, DS_TEXTBOX | DS_IP);
		pMenu->AddMenuItem(_T("Tªn"), 0, DS_TEXTBOX);
		pMenu->AddMenuItem(_T("ChÊp nhËn"), ID_ADD);
		pMenu = pMenu->m_lpParent;

	DeleteObject(hBntBMP);
	pMenu->HideMenu();

	return 0;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CVideoMenu::DisplayMenu()
{
	ClearSurface(m_lpTextSurface);
	DrawTitle();
	//Draw text
	m_nStartItem = min(m_nStartItem, m_nCurrentPos);
	int lastItem = min(m_nStartItem + MAX_DISPLAY_ITEMS, GetSize());
	for (int i=m_nStartItem; i<lastItem; i++)
	{
		DrawItem(i);
	}

	m_fVisible = TRUE;
	m_lpActiveChild = NULL;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CVideoMenu::OnKey(UINT nChar, LPARAM lParam)
{
	static int cnt = 0;
	LPMENUITEM pItem = m_ItemArray[m_nCurrentPos]; 

	if ((nChar == KEY_RETURN || nChar == KEY_ESCAPE) && IsWindow(CavPlayer::dlg.m_hWnd))
	{
		PostMessage(CavPlayer::dlg.m_hWnd, WM_COMMAND,
			nChar == KEY_RETURN ? IDOK : IDCANCEL, 0);
	}
	else if (m_fVisible)
	{
		if (m_lpActiveChild != NULL)
			m_lpActiveChild->OnKey(nChar, lParam);
		else

		switch (nChar)
		{
		case KEY_DOWN:
			if (pItem->DataState & DS_INPUT)
			{
				if (pItem->DataState & DS_IP)
				{
					if (IsIP(pItem->StrData) != 0)
						break;
				}
				pItem->DataState &= ~DS_INPUT;
			}
			if (m_nCurrentPos < GetSize()-1)
			{
				m_nCurrentPos++;
				if (m_nCurrentPos - m_nStartItem > 5)
					m_nStartItem = m_nCurrentPos - 5;
			}
			UpdateMenu();
			break;

		case KEY_UP:
			if (pItem->DataState & DS_INPUT)
			{
				if (pItem->DataState & DS_IP)
				{
					if (IsIP(pItem->StrData) != 0)
						break;
				}
				pItem->DataState &= ~DS_INPUT;
			}
			if (m_nCurrentPos>0)
			{
				m_nCurrentPos--;
				if (m_nCurrentPos < m_nStartItem)
					m_nStartItem = m_nCurrentPos;
			}
			UpdateMenu();
			break;

		case KEY_RETURN:
			if (pItem->State & IS_DISABLED)
				break;
			m_lpActiveChild = GetItem(m_nCurrentPos);
			if (m_lpActiveChild != NULL)
			{
				m_lpActiveChild->UpdateMenu();
			}
			else
			{
				if (pItem->DataState & DS_INPUT)
				{
					if ((pItem->DataState & DS_IP) && (pItem->StrData[0] != '\0'))
					{
						if (IsIP(pItem->StrData) != 0)
							break;
					}
					pItem->DataState &= ~DS_INPUT;
					if (pItem->ItemId == 0 || (pItem->DataType & DT_STR && pItem->StrData[0] == '\0'))
						UpdateMenu();
					else
					{
						if (m_lpOnCommand != NULL)
							m_lpOnCommand(pItem, m_lpUserData);
						UpdateMenu();
					}
				}
				else if (pItem->DataState & DS_TEXTBOX)
				{
					pItem->DataState |= DS_INPUT;
					pItem->IntData = 0;
					if (pItem->DataType != DT_INT)
						SetStrData(pItem->Index, "");
					else
						pItem->StrData[0] = '\0';
					UpdateMenu();
				}
				else if (pItem->ItemId == ID_ADD)
				{
					if (m_lpParent != NULL)
					{
						if (AddAddrItem(m_ItemArray[1]->StrData, m_ItemArray[0]->StrData) == 0)
						{
							m_nCurrentPos = 0;
							SetStrData(0, "");
							SetStrData(1, "");
							m_lpParent->UpdateMenu();
						}
					}
				}
				else if (pItem->ItemId != 0)
				{
					if (m_lpOnCommand != NULL)
						m_lpOnCommand(pItem, m_lpUserData);
					UpdateMenu();
				}
			}
			break;

		case KEY_DELETE:
			if (pItem->ItemId == ID_REMOVE)
			{
				RemoveAddrItem(m_ItemArray[m_nCurrentPos]->Text);
				UpdateMenu();
			}
			break;

		case KEY_ESCAPE:
			if (pItem->DataState & DS_INPUT)
			{
				SetStrData(m_nCurrentPos, _T(""));
				pItem->DataState &= ~DS_INPUT;
				UpdateMenu();
			}
			else
				HideMenu();
			break;

		case KEY_BACK:
			if (pItem->DataState & DS_INPUT)
			{
				int len = strlen(pItem->StrData);
				if (len > 0)
					pItem->StrData[len-1] = '\0';
				if (pItem->IntData > 0)
					pItem->IntData /= 10;
				UpdateMenu();
			}
			else if (m_lpParent != NULL)
			{
				m_nCurrentPos = 0;
				m_lpParent->UpdateMenu();
			}
			else HideMenu();
			break;

		case KEY_LEFT:
		case KEY_RIGHT:
			if (pItem->State & IS_DISABLED)
				break;
			if (lParam && pItem->ItemId == ID_SETBITRATERS232)
			{
				CavPlayer::LogMsg("Kh«ng ®æi tèc ®é RS232 qua camera", 5);
				break;
			}
			if (pItem->DataType == DT_COMBO)
			{
				int i = pItem->cbi;
				if (pItem->cbi < pItem->cbItems-1)
					pItem->cbi += (nChar == KEY_RIGHT);
				if (pItem->cbi > 0)
					pItem->cbi -= (nChar == KEY_LEFT);
				if (m_lpOnCommand && pItem->cbi != i)
					m_lpOnCommand(pItem, m_lpUserData);
			}
			UpdateMenu();
			break;

		// Print Screen
		case VK_F6:
			{
				CString filename;
				filename.Format("menuImg%02d.bmp", cnt++);
				save_bmp(GetSurface(), filename);
			}
			break;

		// Update Menu
		case KEY_UPDATE:
			UpdateMenu();
			break;

		default:
			if (pItem->DataState & DS_INPUT)
			{
				char c = 0;
				if (nChar == 0xBE || nChar == VK_DECIMAL)
					c = '.';
				else if (VK_NUMPAD0 <= nChar && nChar <= VK_NUMPAD9)
					c = nChar - VK_NUMPAD0 + '0';
				else if (('0' <= nChar && nChar <= '9') ||
					('A' <= nChar && nChar <= 'Z') ||
					(nChar == 32 && strlen(pItem->StrData) > 0))
					c = nChar;
				if ('A' <= c && c <= 'Z')
				{
					SHORT caps_lock = GetKeyState(VK_CAPITAL) & 1;
					SHORT shift = HIBYTE(GetKeyState(VK_SHIFT));
					if (shift)
						caps_lock = !caps_lock;
					if (!caps_lock)
						c |= (1 << 5);
				}
				if (c)
				{
					if (pItem->DataType & DT_STR)
					{
						int len = strlen(pItem->StrData);
						if (len >= MAX_STR_LEN)
							break;
						pItem->StrData[len++] = c;
						pItem->StrData[len] = '\0';
						if (pItem->DataState & DS_IP)
							if (IsIP(pItem->StrData) < 0)
							{
								pItem->StrData[len-1] = '\0';
								break;
							}
						UpdateMenu();
					}
					else if (pItem->DataType & DT_INT)
					{
						if (pItem->IntData < 2000 || pItem->ItemId != ID_BANDWIDTH)
						{
							pItem->IntData *= 10;
							pItem->IntData += c - '0';
						}
						UpdateMenu();
					}
				}
			}
			break;
		}
	}
	else
		if (nChar == KEY_MENU)
		{
			m_fVisible = TRUE;
			UpdateMenu();
		}
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
CVideoMenu* CVideoMenu::GetItem(int nIndex)
{
	return m_SubMenuArray[nIndex];
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CVideoMenu::AddMenuItem(LPCTSTR sText, DWORD ItemId, PCOMBO_MENU_ITEM pComboData, int cbItems)
{
	LPMENUITEM pItem = new (MENUITEM);
	m_ItemArray[m_nSize] = pItem;
	pItem->Index = m_nSize;
	pItem->ItemId = ItemId;
	pItem->Text = sText;

	pItem->State = 0;
	pItem->cbi = 0;
	pItem->pComboData = pComboData;
	pItem->cbItems = cbItems;
	pItem->textlen = 0;
	pItem->DataState = 0;

	pItem->IntData = 0;
	strcpy(pItem->StrData, "");
	if (pComboData != NULL)
	{
		int i;
		HDC hdc;
		RECT textrect = {0, 0, 1, 1};
		hdc = CreateCompatibleDC(NULL);
		SelectObject(hdc, m_hTextFont);
		for (i=0; i<cbItems; i++)
		{
			int len = strlen(pComboData[i].String);
			::DrawText(hdc, pComboData[i].String, len, &textrect, DT_CALCRECT);
			if (pItem->textlen < textrect.right)
				pItem->textlen = textrect.right;
		}
		pItem->DataType = DT_COMBO;
		ReleaseDC(NULL, hdc);
	}
	else
		pItem->DataType = DT_NODATA;

	m_SubMenuArray.Add(NULL);
	m_nSize++;
}


void CVideoMenu::AddMenuItem(LPCTSTR sText, DWORD ItemId, int DataState)
{
	AddMenuItem(sText, ItemId);
	m_ItemArray[m_nSize-1]->DataState = DataState;
}


void CVideoMenu::RemoveAt(int index)
{
	if (0 <= index && index <= GetSize()-1)
	{
		delete m_ItemArray[index];
		for (int i=index; i<GetSize()-1; i++)
			m_ItemArray[i] = m_ItemArray[i + 1];
		m_nSize--;
	}
}


void CVideoMenu::RemoveItem(CString sText)
{
	for (int i=0; i<GetSize(); i++)
		if (sText.CompareNoCase(m_ItemArray[i]->Text) == 0)
			RemoveAt(i);
}


void CVideoMenu::RemoveItem(int id)
{
	for (int i=0; i<GetSize(); i++)
		if (m_ItemArray[i]->ItemId == id)
			RemoveAt(i);
}


void CVideoMenu::RemoveAll()
{
	while (GetSize())
	{
		delete m_ItemArray[m_nSize-1];
		m_ItemArray[m_nSize-1] = NULL;
		m_nSize--;
	}
}


int CVideoMenu::AddAddrItem(LPCTSTR alias, LPCTSTR ip,BOOL bSave)
{
	CString s = alias;
	CString sIp = ip;
	CString sLog;
	if (strlen(alias) == 0)
	{
		CavPlayer::LogMsg("Kh«ng chÊp nhËn tªn rçng", 5);
		return 1;
	}
	if (strlen(ip) == 0)
	{
		CavPlayer::LogMsg("§Þa chØ IP kh«ng hîp lÖ", 5);
		return 1;
	}
	
	for (int i=0; i<m_Addrs.GetSize(); i++)
	{
		if (s.CompareNoCase(m_Addrs[i]->alias) == 0)
		{	
			sLog.Format("Tªn %s ®· cã trong danh b¹",m_Addrs[i]->alias);
			CavPlayer::LogMsg(sLog, 5);
			return 2;
		}
		if (sIp.CompareNoCase(m_Addrs[i]->ip) == 0)
		{
			sLog.Format("§Þa chØ %s ®· cã trong danh b¹",m_Addrs[i]->ip);
			CavPlayer::LogMsg(sLog, 5);
			return 2;
		}
	}
	PADDR_ITEM pAddrItem = new ADDR_ITEM;
	_tcscpy(pAddrItem->alias, alias);
	_tcscpy(pAddrItem->ip, ip);
	m_Addrs.Add(pAddrItem);

	CVideoMenu* pMenu = (g_pMainMenu->GetItem(4))->GetItem(0);
	pMenu->AddMenuItem(pAddrItem->alias, ID_ADDR);
	pMenu->SetStrData(pMenu->m_nSize-1, pAddrItem->ip);

	pMenu = (g_pMainMenu->GetItem(4))->GetItem(2);
	pMenu->AddMenuItem(pAddrItem->alias, ID_REMOVE);
	pMenu->SetStrData(pMenu->m_nSize-1, pAddrItem->ip);

	pMenu = (g_pMainMenu->GetItem(0))->GetItem(0);
	pMenu->RemoveAt(pMenu->GetSize()-1);
	pMenu->AddMenuItem(pAddrItem->alias, ID_CONNECT);
	pMenu->SetStrData(pMenu->m_nSize-1, pAddrItem->ip);

	pMenu->AddMenuItem(_T("NhËp ®Þa chØ IP"), ID_CONNECT, DS_TEXTBOX | DS_IP);


	return 0;
}


void CVideoMenu::RemoveAddrItem(CString alias,BOOL bSave)
{
	CVideoMenu* pMainMenu = this;
	while (pMainMenu->m_lpParent != NULL)
		pMainMenu = pMainMenu->m_lpParent;
	CVideoMenu* pMenu = (pMainMenu->GetItem(4))->GetItem(0);
	pMenu->RemoveItem(alias);

	pMenu = (pMainMenu->GetItem(4))->GetItem(2);
	pMenu->RemoveItem(alias);

	pMenu = (pMainMenu->GetItem(0))->GetItem(0);
	pMenu->RemoveItem(alias);

	if(bSave==FALSE)
		return;

	for (int i=0; i<m_Addrs.GetSize(); i++)
		if (alias.CompareNoCase(m_Addrs[i]->alias) == 0)
		{
			delete m_Addrs.GetAt(i);
			m_Addrs.RemoveAt(i);
		}

}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
CVideoMenu* CVideoMenu::CreateSubMenu(int nIndex)
{
	if (m_SubMenuArray[nIndex] == NULL)
	{
		m_SubMenuArray[nIndex] = new CVideoMenu;
		CVideoMenu* pMenu = m_SubMenuArray[nIndex];
		pMenu->m_lpParent = this;
		pMenu->m_nCurrentPos = 0;
		pMenu->m_nSize = 0;
		m_ItemArray[nIndex]->State |= IS_POPUP;

		// Create text surface
		CreateOfflineSurface(&pMenu->m_lpTextSurface, MENU_WIDTH, MENU_HEIGHT);
	}

	return m_SubMenuArray[nIndex];
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CVideoMenu::HideMenu()
{
	CVideoMenu* pMenu = this;
	while (pMenu->m_lpActiveChild != NULL)
		pMenu = pMenu->m_lpActiveChild;

	ClearSurface(m_lpMenuSurface);
	m_fVisible = FALSE;
	while (pMenu != NULL)
	{
		pMenu->m_nCurrentPos = 0;
		pMenu->m_lpActiveChild = NULL;
		pMenu = pMenu->m_lpParent;
	}
	InterlockedIncrement(&m_NeedUpdate);
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CVideoMenu::UpdateMenu()
{
	if (!IsVisible())
		return;
	if (GetSize() == 0)
		AddMenuItem("", 0, 0);
	else if (GetSize() > 1)
		RemoveItem("");
	for (int i=0; i < GetSize(); i++)
	{
		if (m_lpOnUpdateItem != NULL && !(m_ItemArray[i]->DataState & DS_INPUT))
			m_lpOnUpdateItem(m_ItemArray[i], this, m_lpUserData);
	}
	m_nCurrentPos = min(m_nCurrentPos, m_nSize-1);
	m_nCurrentPos = max(0, m_nCurrentPos);
	DisplayMenu();

	int y = YT_START + (m_nCurrentPos - m_nStartItem) * TEXT_HEIGHT;
	ClearSurface(m_lpMenuSurface);
	m_lpMenuSurface->BltFast(0, 0, m_lpFrameSurface, NULL, DDBLTFAST_SRCCOLORKEY);
	m_lpMenuSurface->BltFast(5, y, m_lpCsSurface, NULL, DDBLTFAST_SRCCOLORKEY);
	m_lpMenuSurface->BltFast(0, 0, m_lpTextSurface, NULL, DDBLTFAST_SRCCOLORKEY);

	if (m_nStartItem > 0)
		m_lpMenuSurface->BltFast(MENU_WIDTH/2 - 35, 48, m_lpUpArrowSurface, NULL, DDBLTFAST_SRCCOLORKEY);
	if (m_nStartItem + MAX_DISPLAY_ITEMS < GetSize())
		m_lpMenuSurface->BltFast(MENU_WIDTH/2 - 35, MENU_HEIGHT - TEXT_HEIGHT, m_lpDownArrowSurface, NULL, DDBLTFAST_SRCCOLORKEY);

	InterlockedIncrement(&m_NeedUpdate);
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CVideoMenu::DrawTitle()
{
	HDC hTextDC;
	HGDIOBJ hGdiObj;
	RECT	rect = {0, 4, MENU_WIDTH, 4 + TEXT_HEIGHT};
	HRESULT hr;
	CString str;

	if (m_lpParent == NULL)
		str = _T("Menu chÝnh");
	else
		str = (m_lpParent->m_ItemArray[m_lpParent->m_nCurrentPos])->Text;
	int len = str.GetLength();

	hr = m_lpTextSurface->GetDC(&hTextDC);
	ASSERT(hr == 0);
	hGdiObj=::SelectObject(hTextDC, m_hTextFont);

	SetBkMode(hTextDC, TRANSPARENT);

	//Draw text
	::SetTextColor(hTextDC, RGB(4, 4, 4));
	DrawText(hTextDC, str, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	OffsetRect(&rect, 2, 0);
	DrawText(hTextDC, str, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	OffsetRect(&rect, 0, 2);
	DrawText(hTextDC, str, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	OffsetRect(&rect, -2, 0);
	DrawText(hTextDC, str, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	SetTextColor(hTextDC, RGB(128, 128, 255));
	OffsetRect(&rect, 1, -1);
	DrawText(hTextDC, str, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	m_lpTextSurface->ReleaseDC(hTextDC);

}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CVideoMenu::DrawItem(int nIndex)
{
	int	nYStart = YT_START + (nIndex-m_nStartItem)*TEXT_HEIGHT;
	int nXStart = XT_START;
	RECT rect = {0, nYStart, MENU_WIDTH, nYStart + TEXT_HEIGHT};
	CString str=_T("");
	TCHAR sBuffer[64];
	LPMENUITEM pItem = m_ItemArray[nIndex];

//	ClearSurface(m_lpTextSurface, 0, &rect);
	rect.right -= 35;
	RECT r_mask = {MENU_WIDTH - 260, nYStart+5, MENU_WIDTH - 30, nYStart + 35};
	if (pItem->DataState & DS_INPUT)
		ClearSurface(m_lpTextSurface, 2, &r_mask);

	if (pItem->State & IS_POPUP)
		// Draw symbol ">"
		m_lpTextSurface->BltFast(MENU_WIDTH - 40, nYStart, m_lpTriSurface, NULL, DDBLTFAST_SRCCOLORKEY);
	else if (pItem->State & IS_CHECKED)
		m_lpTextSurface->BltFast(MENU_WIDTH - 70, nYStart, m_lpCheckSurface, NULL, DDBLTFAST_SRCCOLORKEY);
	else if (pItem->DataType == DT_STR)
		str = pItem->StrData;
	else if (pItem->DataType == DT_INT)
		str = itoa(pItem->IntData, sBuffer, 10);
	else if (pItem->DataType == DT_COMBO)
		str = pItem->pComboData[pItem->cbi].String;

	if (!str.IsEmpty())
	{
		if (pItem->DataState & DS_INPUT)
			// Green
			DrawTexts(m_lpTextSurface, str, &rect, DT_RIGHT, RGB(128, 255, 128));
		else if (pItem->State & IS_DISABLED)
			// Dark Yellow
			DrawTexts(m_lpTextSurface, str, &rect, DT_RIGHT, RGB(128, 128, 64));
		else
			// Yellow
			DrawTexts(m_lpTextSurface, str, &rect, DT_RIGHT, RGB(255, 255, 128));

		RECT r_clear = {0, nYStart, MENU_WIDTH - 260, nYStart + 40};
		ClearSurface(m_lpTextSurface, 0, &r_clear);

		if (nIndex == m_nCurrentPos && pItem->DataType == DT_COMBO && !(pItem->State & IS_DISABLED))
		{
			if (pItem->cbi < pItem->cbItems-1)
				m_lpTextSurface->BltFast(MENU_WIDTH - 35, nYStart, m_lpSpinRSurface, NULL, DDBLTFAST_SRCCOLORKEY);
			else
				m_lpTextSurface->BltFast(MENU_WIDTH - 35, nYStart, m_lpSpinRSurfaceD, NULL, DDBLTFAST_SRCCOLORKEY);
			if (pItem->cbi > 0)
				m_lpTextSurface->BltFast(MENU_WIDTH - pItem->textlen - 85, nYStart, m_lpSpinLSurface, NULL, DDBLTFAST_SRCCOLORKEY);
			else
				m_lpTextSurface->BltFast(MENU_WIDTH - pItem->textlen - 85, nYStart, m_lpSpinLSurfaceD, NULL, DDBLTFAST_SRCCOLORKEY);
		}
	}
	
	if (pItem->State & IS_DISABLED)
		// Gray
		DrawTexts(m_lpTextSurface, pItem->Text, nXStart, nYStart, RGB(128, 128, 128));
	else
		// White
		DrawTexts(m_lpTextSurface, pItem->Text, nXStart, nYStart);
}


int CVideoMenu::IsIP(LPCTSTR s)
{
	int n = 0;
	int count = 0;
	int count2 = 0;
	for (DWORD i=0; i<strlen(s); i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			n = n*10 + (s[i] - '0');
			if (n > 255) return -1;
			if (++count > 3) return -1;
		}
		else if (s[i] == '.')
		{
			if (count == 0) return -1;
			count = n = 0;
			if (++count2 > 3) return -1;
		}
		else
			return -1;
	}
	if (count2 == 3 && count > 0)
		return 0;
	else
		return 1;
}


BOOL CVideoMenu::IsVisible()
{
	return m_fVisible;
}


int CVideoMenu::CreateTransparentRects(LPRECT rect1, LPRECT rect2)
{
	rect1->left = 0;
	rect1->top = 0;
	rect1->right = MENU_WIDTH;
	rect1->bottom = MENU_HEIGHT;

	return 1;
}


void CVideoMenu::SetUpdateItemCallback(void (*OnUpdateItem)(LPMENUITEM, CVideoMenu*, LPVOID), LPVOID pUserData)
{
	m_lpUserData = pUserData;
	m_lpOnUpdateItem = OnUpdateItem;
}


void CVideoMenu::SetCommandCallback(void (*OnMenuCommand)(LPMENUITEM, LPVOID), LPVOID pUserData)
{
	m_lpUserData = pUserData;
	m_lpOnCommand = OnMenuCommand;
}


//-----------------------------------------------------------------------------
// Update menu item
//-----------------------------------------------------------------------------
void CVideoMenu::SetItemText(int nIndex, CString sText)
{
	m_ItemArray[nIndex]->Text = sText;
}


int CVideoMenu::SetIntData(int nIndex, int nData, BOOL fVisible)
{
	if (m_ItemArray[nIndex]->DataType == DT_COMBO)
	{
		for (int i=0; i<m_ItemArray[nIndex]->cbItems; i++)
			if (nData == m_ItemArray[nIndex]->pComboData[i].Data)
				m_ItemArray[nIndex]->cbi = i;
	}
	else
	{
		if (fVisible)
			m_ItemArray[nIndex]->DataType = DT_INT;
		else
			m_ItemArray[nIndex]->DataType = DT_NODATA;
		m_ItemArray[nIndex]->IntData = nData;
	}
	return nData;
}


void CVideoMenu::SetStrData(int nIndex, LPCTSTR sText)
{
	m_ItemArray[nIndex]->DataType = DT_STR;
	_tcscpy(m_ItemArray[nIndex]->StrData, sText);
}


void CVideoMenu::SetCheck(int nIndex, BOOL fCheck)
{
	if (fCheck)
		m_ItemArray[nIndex]->State |= IS_CHECKED;
	else
		m_ItemArray[nIndex]->State &= ~IS_CHECKED;
	DrawItem(nIndex);
}


void CVideoMenu::Enable(int nIndex, BOOL fEnable)
{
	if (!fEnable)
		m_ItemArray[nIndex]->State |= IS_DISABLED;
	else
		m_ItemArray[nIndex]->State &= ~IS_DISABLED;
	DrawItem(nIndex);
}


CString CVideoMenu::GetAlias(LPCTSTR ip)
{
	CString s;
	s = ip;

	for (int i=0; i<m_Addrs.GetSize(); i++)
		if (s.CompareNoCase(m_Addrs[i]->ip) == 0)
			s = m_Addrs.GetAt(i)->alias;

	return s;
}


void CVideoMenu::updateAddressBook()
{
	//Xoa tren menu
	PADDR_ITEM pItem;
	for(int i=0;i<m_Addrs.GetSize();i++)
	{
		pItem=m_Addrs.GetAt(i);
		g_pMainMenu->RemoveAddrItem(pItem->alias,FALSE);
		delete pItem;
	}
	m_Addrs.RemoveAll();

	//cap nhat danh sach moi
	CTypedPtrArray<CPtrArray, PADDR_ITEM> newAddr;

	//Them vao moi
	for(i=0;i<newAddr.GetSize();i++)
	{
		pItem=newAddr.GetAt(i);
		AddAddrItem(pItem->alias,pItem->ip,FALSE);
		delete pItem;
	}
	newAddr.RemoveAll();

}
