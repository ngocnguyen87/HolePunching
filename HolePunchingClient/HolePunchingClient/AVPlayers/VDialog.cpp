// VDialog.cpp : implementation file
//

#include "stdafx.h"
#include "VDialog.h"
#include "avPlayer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

HFONT	CVDialog::m_hTextFont		= NULL;


static void DrawText(HDC hTextDC, CString str, LPRECT pRect, DWORD dwStyle = 0,
					 COLORREF color = RGB(255, 255, 255))
{
	HGDIOBJ hGdiObj;

	hGdiObj=::SelectObject(hTextDC, CVDialog::m_hTextFont);
	SetBkMode(hTextDC, TRANSPARENT);
	int len = str.GetLength();

	//Draw text
	SetTextColor(hTextDC, color);
	DrawText(hTextDC, str, -1, pRect, dwStyle);
}

/////////////////////////////////////////////////////////////////////////////
// CVDialog dialog


CVDialog::CVDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CVDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CVDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVDialog)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CVDialog, CDialog)
	//{{AFX_MSG_MAP(CVDialog)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVDialog message handlers

BOOL CVDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CavPlayer::m_fVDialog = TRUE;
	m_hTextFont = CVideoMenu::CreateTextFont(".VnArial", 26, FW_NORMAL);

	SetTimer(1,20000,NULL);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CVDialog::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect rect;
	GetClientRect(&rect);
	rect.DeflateRect(1, 1);
	dc.FillSolidRect(&rect,RGB(0,0,0));

	rect.top += 20;
	dc.SelectObject(m_hTextFont);
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(255, 255, 255));
	dc.DrawText(m_sText, &rect, DT_CENTER);
	// Do not call CDialog::OnPaint() for painting messages
}

void CVDialog::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	
}

void CVDialog::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	PostMessage(WM_COMMAND,IDCANCEL,0);

	CDialog::OnTimer(nIDEvent);
}
