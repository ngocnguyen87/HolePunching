// BitmapBnt.cpp : implementation file
//

#include "stdafx.h"
#include "BitmapBnt.h"
#include "resource.h"
#include "VMenu\VideoMenu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//HBITMAP	BitmapBnt::hBntBMP		= NULL;
int		BitmapBnt::nButtons	= 0;


HRESULT DrawBitmap(HDC hDC, HBITMAP hBMP,
							  DWORD dwOriginX, DWORD dwOriginY,
							  DWORD dwSrcX, DWORD dwSrcY,
							  int dwWidth, int dwHeight)
{
	HDC            hDCImage;
	BITMAP         bmp;

	if( hBMP == NULL )
		return E_INVALIDARG;

	// Select bitmap into a memoryDC so we can use it.
	hDCImage = CreateCompatibleDC( NULL );
	if( NULL == hDCImage )
		return E_FAIL;

	SelectObject( hDCImage, hBMP );

	// Get size of the bitmap
	GetObject( hBMP, sizeof(bmp), &bmp );

	// Use the passed size, unless zero
	dwWidth  = ( dwWidth == 0 ) ? bmp.bmWidth  : 
		min(bmp.bmWidth, dwWidth);
	dwHeight = ( dwHeight == 0 ) ? bmp.bmHeight : 
		min(bmp.bmHeight, dwHeight);

	StretchBlt( hDC, dwOriginX, dwOriginY, 
				dwWidth, dwHeight, 
				hDCImage, dwSrcX, dwSrcY,
				dwWidth, dwHeight,
				SRCCOPY );

	DeleteDC( hDCImage );

	return S_OK;
}
/////////////////////////////////////////////////////////////////////////////
// BitmapBnt

BitmapBnt::BitmapBnt()
{
	m_iButtons = nButtons++;
	//if (NULL == hBntBMP)
	//	hBntBMP = CVideoMenu::LoadBitmapFile(MAKEINTRESOURCE(IDB_DBUTTONS), 0, 0);
}

BitmapBnt::~BitmapBnt()
{
	//if (hBntBMP)
	//	DeleteObject(hBntBMP);
}


BEGIN_MESSAGE_MAP(BitmapBnt, CButton)
	//{{AFX_MSG_MAP(BitmapBnt)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BitmapBnt message handlers

void BitmapBnt::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	UINT uStyle = DFCS_BUTTONPUSH;

   // This code only works with buttons.
   ASSERT(lpDrawItemStruct->CtlType == ODT_BUTTON);

   // If drawing selected, add the pushed style to DrawFrameControl.
   if (lpDrawItemStruct->itemState & ODS_SELECTED)
      uStyle |= DFCS_PUSHED;

   // Draw the button frame.
   ::DrawFrameControl(lpDrawItemStruct->hDC, &lpDrawItemStruct->rcItem, 
      DFC_BUTTON, uStyle);

   CRect rect;
   GetClientRect(&rect);
   rect.DeflateRect(2, 2);
   CBrush br;
   br.CreateSolidBrush(RGB(0, 0, 0));
   ::FillRect(lpDrawItemStruct->hDC, &rect, br);

   // Get the button's text.
   CString strText;
   GetWindowText(strText);

   // Draw the button text using the text color red.
   COLORREF crOldColor = ::SetTextColor(lpDrawItemStruct->hDC, RGB(255,255,255));
   HFONT hTextFont = CVideoMenu::CreateTextFont(".VnArial", 24, FW_NORMAL);
   HFONT hOldFont = (HFONT)::SelectObject(lpDrawItemStruct->hDC, hTextFont);
   ::SetBkMode(lpDrawItemStruct->hDC, TRANSPARENT);
   ::DrawText(lpDrawItemStruct->hDC, strText, strText.GetLength(), 
      &lpDrawItemStruct->rcItem, DT_SINGLELINE|DT_VCENTER|DT_CENTER);
   ::SetTextColor(lpDrawItemStruct->hDC, crOldColor);
   ::SelectObject(lpDrawItemStruct->hDC, hOldFont);
}
