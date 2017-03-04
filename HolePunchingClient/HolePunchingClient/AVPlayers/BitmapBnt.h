#if !defined(AFX_BITMAPBNT_H__C9942611_3246_4D40_BD48_FBBEC4198AD8__INCLUDED_)
#define AFX_BITMAPBNT_H__C9942611_3246_4D40_BD48_FBBEC4198AD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BitmapBnt.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BitmapBnt window

class BitmapBnt : public CButton
{
protected:
	static int		nButtons;
	//static HBITMAP	hBntBMP;
	RECT			m_BitmapRect;
	int				m_iButtons;
	CString			m_sText;
// Construction
public:
	BitmapBnt();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BitmapBnt)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~BitmapBnt();

	// Generated message map functions
protected:
	//{{AFX_MSG(BitmapBnt)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPBNT_H__C9942611_3246_4D40_BD48_FBBEC4198AD8__INCLUDED_)
