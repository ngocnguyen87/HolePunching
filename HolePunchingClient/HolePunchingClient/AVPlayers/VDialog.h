#if !defined(AFX_VDIALOG_H__54CA0D86_37AC_4BB2_9E92_9239FB19CB23__INCLUDED_)
#define AFX_VDIALOG_H__54CA0D86_37AC_4BB2_9E92_9239FB19CB23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VDialog.h : header file
//
#include "resource.h"
#include "BitmapBnt.h"

/////////////////////////////////////////////////////////////////////////////
// CVDialog dialog

class CVDialog : public CDialog
{
protected:
	CString			m_sText;
	DWORD			m_dwStyle;
public:
	static HFONT	m_hTextFont;
	void SetText(LPCTSTR sText, DWORD dwStyle)
	{
		m_dwStyle = dwStyle;
		m_sText = sText;
	}
// Construction
public:
	CVDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CVDialog)
	enum { IDD = IDD_VDIALOG };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CVDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VDIALOG_H__54CA0D86_37AC_4BB2_9E92_9239FB19CB23__INCLUDED_)
