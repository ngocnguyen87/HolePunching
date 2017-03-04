#if !defined(AFX_DISPLAYDLG_H__490037B9_B122_4306_AB36_FFDF3FC043DE__INCLUDED_)
#define AFX_DISPLAYDLG_H__490037B9_B122_4306_AB36_FFDF3FC043DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DisplayDlg.h : header file
//
#include "resource.h"
/////////////////////////////////////////////////////////////////////////////
// CDisplayDlg dialog

class CDisplayDlg : public CDialog
{
protected:
	WINDOWPLACEMENT		m_OldWndpl;
// Construction
public:
	virtual void OnCancel();
	virtual void OnOK();
	CDisplayDlg(CWnd* pParent = NULL);   // standard constructor
	void DisplayText();
	RECT m_WndRect;
	void ChangeDisplayMode();
	BOOL m_fFullScreen;
	CString m_DisplayText;
	int DrawBitmap(HBITMAP hBMP,
		DWORD dwOriginX, DWORD dwOriginY,
		DWORD dwSrcX, DWORD dwSrcY,
		int dwWidth, int dwHeight);

	HBITMAP LoadBitmapFile(TCHAR* strBMP,
		DWORD dwDesiredWidth, DWORD dwDesiredHeight);

	HBITMAP m_hMuteIcon;
	HBITMAP m_hWarningIcon;

	void SetMuteIcon(BOOL fMute){m_fMute=fMute;Invalidate();};
	void SetWarningIcon(BOOL fWarning){m_fWarning=fWarning;Invalidate();};

	BOOL m_fMute;
	BOOL m_fWarning;
	CStringArray m_arVcsName;

	void DisplayVcsName();
	int getRect(LPRECT rect,int i);
	void addVcsAlias(CString sAlias){m_arVcsName.Add(sAlias);Invalidate();};
	void removeVcsAlias(CString sAlias)
	{
		for(int i=0;i<m_arVcsName.GetSize();i++)
		{
			CString s=m_arVcsName.GetAt(i);
			if(s==sAlias)
			{
				m_arVcsName.RemoveAt(i);
				break;
			}
		}
		Invalidate();
	};
	
	RECT m_recPreview;

// Dialog Data
	//{{AFX_DATA(CDisplayDlg)
	enum { IDD = IDD_DISPLAY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDisplayDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDisplayDlg)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMove(int x, int y);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISPLAYDLG_H__490037B9_B122_4306_AB36_FFDF3FC043DE__INCLUDED_)
