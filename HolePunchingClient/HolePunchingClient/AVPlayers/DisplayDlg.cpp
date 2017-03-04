// DisplayDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DisplayDlg.h"
#include "avPlayer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDisplayDlg dialog


CDisplayDlg::CDisplayDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDisplayDlg::IDD, pParent)
{
	m_fFullScreen=FALSE;
	//{{AFX_DATA_INIT(CDisplayDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_fMute = FALSE;
	m_fWarning = FALSE;

}


void CDisplayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDisplayDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDisplayDlg, CDialog)
	//{{AFX_MSG_MAP(CDisplayDlg)
	ON_WM_ERASEBKGND()
	ON_WM_MOVE()
	ON_WM_SIZE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDisplayDlg message handlers

BOOL CDisplayDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetTimer(1, 200, NULL);

	m_hMuteIcon = LoadBitmapFile(MAKEINTRESOURCE(IDB_MUTE), 0, 0);
	m_hWarningIcon = LoadBitmapFile(MAKEINTRESOURCE(IDB_WARNING), 0, 0);

	DrawBitmap(m_hMuteIcon,0,800,0,0,60,60);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CDisplayDlg::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
	GetClientRect(&rect);

	CPen pen;
	int width = rect.Width();
	int height = rect.Height();
	pDC->FillSolidRect(&rect,RGB(0,0,0));

	DisplayText();

	DisplayVcsName();

	if(m_fMute)
		DrawBitmap(m_hMuteIcon,rect.left+60,rect.bottom-60,0,0,60,60);

	if(m_fWarning)
		DrawBitmap(m_hWarningIcon,rect.left+180,rect.bottom-60,0,0,60,60);

	return 1;
}

void CDisplayDlg::OnMove(int x, int y) 
{
	CDialog::OnMove(x, y);
	
	// TODO: Add your message handler code here
	Invalidate();
	GetClientRect(&m_WndRect);
	ClientToScreen(&m_WndRect);
	CavPlayer::UpdateOverlay();
	CavPlayer::OnKey(KEY_UPDATE);
}

void CDisplayDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	Invalidate();
	GetClientRect(&m_WndRect);
	ClientToScreen(&m_WndRect);
	CavPlayer::UpdateOverlay();
	CavPlayer::OnKey(KEY_UPDATE);
}

void CDisplayDlg::ChangeDisplayMode()
{
	m_fFullScreen = !m_fFullScreen;
	if (m_fFullScreen)
	{
		GetWindowPlacement(&m_OldWndpl);
		ModifyStyle(WS_SIZEBOX, 0, 0);

		CRect WindowRect, ClientRect;
		RECT FullScreenRect;

		GetWindowRect(&WindowRect);
		WindowRect.left ++;
		WindowRect.top ++;
		WindowRect.right --;
		WindowRect.bottom --;
		GetClientRect(&ClientRect);
		ClientToScreen(&ClientRect);
		int nFullWidth = GetSystemMetrics(SM_CXSCREEN);
		int nFullHeight = GetSystemMetrics(SM_CYSCREEN);
		FullScreenRect.left = WindowRect.left - ClientRect.left;
		FullScreenRect.top = WindowRect.top - ClientRect.top;
		FullScreenRect.right = WindowRect.right - ClientRect.right + nFullWidth;
		FullScreenRect.bottom = WindowRect.bottom - ClientRect.bottom + nFullHeight;
		WINDOWPLACEMENT wndpl;
		wndpl.length = sizeof(WINDOWPLACEMENT);
		wndpl.flags = 0;
		wndpl.showCmd = SW_SHOWNORMAL;
		wndpl.rcNormalPosition = FullScreenRect;
		SetWindowPlacement(&wndpl);
	}
	else
	{
		ModifyStyle(0, WS_SIZEBOX, 0);
		SetWindowPlacement(&m_OldWndpl);
	}

	RECT rec;
	GetClientRect(&rec);
	int width=rec.right-rec.left;
	int height=rec.bottom-rec.top;

	m_recPreview.left=width=width*15/24;
	m_recPreview.top=height*15/24;
	m_recPreview.right=width-width/16;
	m_recPreview.bottom=height-height/16;
}

void CDisplayDlg::DisplayText()
{
	HGDIOBJ hOldFont;
	CDC* pDC;
	CBrush brush;

	static HFONT hTextFont = CavPlayer::CreateTextFont(_T(".VnArial"), 36, FW_REGULAR);
	pDC = GetDC();
	hOldFont = pDC->SelectObject(hTextFont);
	pDC->SetBkMode(TRANSPARENT);
	int len = m_DisplayText.GetLength();

	RECT rect;
	GetClientRect(&rect);
	rect.bottom = rect.top + 50;

	if (m_DisplayText.IsEmpty())
	{
		ReleaseDC(pDC);	
		return;
	}

	//Draw text
	pDC->SetTextColor(RGB(0, 0, 4));
	pDC->DrawText(m_DisplayText, -1, &rect, DT_SINGLELINE | DT_CENTER);
	OffsetRect(&rect, 2, 0);
	pDC->DrawText(m_DisplayText, -1, &rect, DT_SINGLELINE | DT_CENTER);
	OffsetRect(&rect, 0, 2);
	pDC->DrawText(m_DisplayText, -1, &rect, DT_SINGLELINE | DT_CENTER);
	OffsetRect(&rect, -2, 0);
	pDC->DrawText(m_DisplayText, -1, &rect, DT_SINGLELINE | DT_CENTER);

	pDC->SetTextColor(RGB(255, 255, 255));
	OffsetRect(&rect, 1, -1);
	pDC->DrawText(m_DisplayText, -1, &rect, DT_SINGLELINE | DT_CENTER);
	pDC->SelectObject(hOldFont);



	ReleaseDC(pDC);	
}

HBITMAP CDisplayDlg::LoadBitmapFile(TCHAR* strBMP,
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

int CDisplayDlg::DrawBitmap(HBITMAP hBMP,
							   DWORD dwOriginX, DWORD dwOriginY,
							   DWORD dwSrcX, DWORD dwSrcY,
							   int dwWidth, int dwHeight)
{
	HDC            hDCImage;
	HDC			   hDC;
	BITMAP         bmp;

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

	hDC = ::GetDC(this->m_hWnd);
	BOOL b=StretchBlt( hDC, dwOriginX, dwOriginY, 
		dwWidth, dwHeight, 
		hDCImage, dwSrcX, dwSrcY,
		dwWidth, dwHeight,
		SRCCOPY);
	DeleteObject(hDCImage);
	::ReleaseDC(this->m_hWnd,hDC);

	return 0;
}

void CDisplayDlg::DisplayVcsName()
{
	HGDIOBJ hOldFont;
	CDC* pDC;
	CBrush brush;

	static HFONT hVcsFont = CavPlayer::CreateTextFont(_T(".VnArial"),24, FW_REGULAR);
	pDC = GetDC();
	hOldFont = pDC->SelectObject(hVcsFont);
	pDC->SetBkMode(TRANSPARENT);

	CString sText;
	RECT playerRect;
	
	for(int i=0;i<m_arVcsName.GetSize();i++)
	{
		int ret=getRect(&playerRect,i+1);
		if(ret==-1)
			continue;
		if(CavPlayer::m_fPreview)
		{
			if((playerRect.top>m_recPreview.top)&&(playerRect.top<m_recPreview.bottom))
			{
				if(playerRect.right>m_recPreview.left)
					playerRect.right=m_recPreview.left-4;
			}
		}

		sText=m_arVcsName.GetAt(i);

		//Draw text
		pDC->SetTextColor(RGB(0, 0, 15));
		pDC->DrawText(sText, -1, &playerRect, DT_SINGLELINE | DT_LEFT);
		OffsetRect(&playerRect, 2, 0);
		pDC->DrawText(sText, -1, &playerRect, DT_SINGLELINE | DT_LEFT);
		OffsetRect(&playerRect, 0, 2);
		pDC->DrawText(sText, -1, &playerRect, DT_SINGLELINE | DT_LEFT);
		OffsetRect(&playerRect, -2, 0);
		pDC->DrawText(sText, -1, &playerRect, DT_SINGLELINE | DT_LEFT);

		pDC->SetTextColor(RGB(255, 255,255));
		OffsetRect(&playerRect, 1, -1);
		pDC->DrawText(sText, -1, &playerRect, DT_SINGLELINE | DT_LEFT);
	}
	pDC->SelectObject(hOldFont);
	ReleaseDC(pDC);		
}

int CDisplayDlg::getRect(LPRECT rect,int i)
{
	int nMode=CavPlayer::GetMuxMode();
	int page=CavPlayer::GetPage();
	int index=(page-1)*nMode;
	
	if((i<=index)||(i>index+nMode))
	{
		return -1;
	}
	i-=index;

	RECT rec;
	GetClientRect(&rec);
	int textWidth=200;
	int textHeight=30;

	switch(nMode)
	{
		case 1:
			rect->left=rec.left;
			rect->top=rec.bottom-textHeight;
			rect->right=rect->left+textWidth;
			rect->bottom=rec.bottom;
			return 0;
		case 2:
			switch(i)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 9:
				case 11:
				case 13:
				case 15:
					rect->left=rec.left;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom*3/4;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 2:
				case 4:
				case 6:
				case 8:
				case 10:
				case 12:
				case 14:
				case 16:
					rect->left=rec.right/2;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom*3/4;
					rect->top=rect->bottom-textHeight;
					return 0;
			}
			break;
		case 4:
			switch(i)
			{
				case 1:
				case 5:
				case 9:
				case 13:
					rect->left=rec.left;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/2;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 2:
				case 6:
				case 10:
				case 14:
					rect->left=rec.right/2;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/2;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 3:
				case 7:
				case 11:
				case 15:
					rect->left=rec.left;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 4:
				case 8:
				case 12:
				case 16:
					rect->left=rec.right/2;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom;
					rect->top=rect->bottom-textHeight;
					return 0;
			}
			break;
		case 6:
			switch(i)
			{
				case 1:
				case 7:
				case 13:
					rect->left=rec.left;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom*2/3;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 2:
				case 8:
				case 14:
					rect->left=rec.right*2/3;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/3;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 3:
				case 9:
				case 15:
					rect->left=rec.right*2/3;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom*2/3;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 4:
				case 10:
				case 16:
					rect->left=rec.left;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 5:
				case 11:
					rect->left=rec.right/3;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 6:
				case 12:
					rect->left=rec.right*2/3;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom;
					rect->top=rect->bottom-textHeight;
					return 0;
			}
			break;
		case 9:
			switch(i)
			{
				case 1:
				case 10:
					rect->left=rec.left;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/3;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 2:
				case 11:
					rect->left=rec.right/3;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/3;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 3:
				case 12:
					rect->left=rec.right*2/3;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/3;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 4:
				case 13:
					rect->left=rec.left;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom*2/3;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 5:
				case 14:
					rect->left=rec.right/3;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom*2/3;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 6:
				case 15:
					rect->left=rec.right*2/3;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom*2/3;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 7:
				case 16:
					rect->left=rec.left;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 8:
					rect->left=rec.right/3;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 9:
					rect->left=rec.right*2/3;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom;
					rect->top=rect->bottom-textHeight;
					return 0;
			}
			break;
		case 13:
			switch(i)
			{
				case 1:
				case 14:
					rect->left=rec.left;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/4;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 2:
				case 15:
					rect->left=rec.right/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/4;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 3:
				case 16:
					rect->left=rec.right*2/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/4;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 4:
					rect->left=rec.right*3/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/4;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 5:
					rect->left=rec.left;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/2;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 6:
					rect->left=rec.right/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom*3/4;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 7:
					rect->left=rec.right*3/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom*2/4;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 8:
					rect->left=rec.left;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom*3/4;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 9:
					rect->left=rec.right*3/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom*3/4;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 10:
					rect->left=rec.left;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 11:
					rect->left=rec.right/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 12:
					rect->left=rec.right*2/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 13:
					rect->left=rec.right*3/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom;
					rect->top=rect->bottom-textHeight;
					return 0;
			}
			break;
		case 16:
			switch(i)
			{
				case 1:
					rect->left=rec.left;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/4;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 2:
					rect->left=rec.right/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/4;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 3:
					rect->left=rec.right*2/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/4;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 4:
					rect->left=rec.right*3/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/4;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 5:
					rect->left=rec.left;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/2;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 6:
					rect->left=rec.right/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/2;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 7:
					rect->left=rec.right*2/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/2;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 8:
					rect->left=rec.right*3/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom*3/4;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 9:
					rect->left=rec.left;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom/2;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 10:
					rect->left=rec.right/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom*3/4;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 11:
					rect->left=rec.right*2/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom*3/4;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 12:
					rect->left=rec.right*3/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom*3/4;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 13:
					rect->left=rec.left;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 14:
					rect->left=rec.right/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 15:
					rect->left=rec.right*2/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom;
					rect->top=rect->bottom-textHeight;
					return 0;
				case 16:
					rect->left=rec.right*3/4;
					rect->right=rect->left+textWidth;
					rect->bottom=rec.bottom;
					rect->top=rect->bottom-textHeight;
					return 0;
			}
			break;
	}

	return -1;
}
BOOL CDisplayDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_F5)
			ChangeDisplayMode();
		else if (pMsg->wParam == VK_TAB)
			::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_SWITCH_SCREEN, 0, 0);
		else
			CavPlayer::OnKey(pMsg->wParam, 0);
	}

	return CDialog::PreTranslateMessage(pMsg);
}

void CDisplayDlg::OnOK()
{

}

void CDisplayDlg::OnCancel()
{

}


void CDisplayDlg::OnTimer(UINT nIDEvent) 
{

	CDialog::OnTimer(nIDEvent);
}
