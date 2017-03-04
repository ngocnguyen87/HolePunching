// VideoMenu.h: interface for the CVideoMenu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIDEOMENU_H__20294F68_1C41_490E_B4B3_50C35C3E2596__INCLUDED_)
#define AFX_VIDEOMENU_H__20294F68_1C41_490E_B4B3_50C35C3E2596__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <ddraw.h>
#include <afxtempl.h>
#include "..\AddrBook.h"


#define KEY_MENU		VK_APPS
#define KEY_UP			VK_UP
#define KEY_DOWN		VK_DOWN
#define KEY_LEFT		VK_LEFT
#define KEY_RIGHT		VK_RIGHT
#define KEY_RETURN		VK_RETURN
#define KEY_BACK		VK_BACK
#define KEY_ESCAPE		VK_ESCAPE
#define KEY_DELETE		VK_DELETE
#define KEY_UPDATE		0xFF

#define KEY_0			'0'
#define KEY_1			'1'
#define KEY_2			'2'
#define KEY_3			'3'
#define KEY_4			'4'
#define KEY_5			'5'
#define KEY_6			'6'
#define KEY_7			'7'
#define KEY_8			'8'
#define KEY_9			'9'

#define MAX_MENU_ITEMS			20
#define MAX_DISPLAY_ITEMS		6

#define ID_CONFERENCE			1001
#define ID_ADD					1002
#define ID_REMOVE				1003
#define ID_SETBITRATERS232		1004
#define ID_CONNECT				1005
#define ID_DISCONNECT			1006
#define ID_CHANGEVIDEOSOURCE	1007
#define ID_AUDIOONOFF			1008
#define ID_SETVOLUME			1009
#define ID_COLORSYS				1010
#define ID_FRAME_RATE			1011
#define ID_LOCALIP				1012
#define ID_IP					1013
#define ID_DEFAULT_VSOURCE		1014
#define ID_PREVIEW				1015
#define ID_ALIAS				1016
#define ID_LOCALDOING			1017
#define ID_SETMUXMODE			1018
#define ID_SETPAGE				1019
#define ID_ADDR					1020
#define ID_BANDWIDTH			1021
#define ID_CAMERA_ID			1022
#define ID_CAMERA_CTRL			1023
#define ID_CAMERA_SPEED			1024
#define ID_AVTEST				1025
#define ID_RESEND_LOST_PACKET	1026
#define ID_TV_RATIO				1027
#define ID_CONF_MODE			1028
#define ID_AUTO_ACCEPT			1029
#define ID_CONTENT_RATE			1030
#define ID_NAT_IP				1031

#define WM_MENU_ON_OFF			(WM_USER + 500)

#define IS_POPUP			0x0001
#define IS_DISABLED			0x0002
#define IS_CHECKED			0x0004

#define DS_ASC				0x0001
#define DS_DSC				0x0002
#define DS_INPUT			0x0004
#define DS_CHANGE			0x0008
#define DS_TEXTBOX			0x0010
#define DS_IP				0x0020

#define DT_NODATA			0x0000
#define DT_INT				0x0001
#define DT_STR				0x0002
#define DT_COMBO			0x0004


#define MAX_STR_LEN 16

#define RGB16(r,g,b) ((COLORREF)((((BYTE)(r)>>3)|((WORD)(((BYTE)(g)>>2))<<5))|(((DWORD)((BYTE)(b)>>3))<<11)))


typedef struct _COMBO_MENU_ITEM
{
    int    Data;
    LPCTSTR  String;
} COMBO_MENU_ITEM, *PCOMBO_MENU_ITEM;

typedef struct _MENUITEM
{
	int		Index;
	int		ItemId;
	LPCTSTR	Text;
	DWORD	State;
	DWORD	DataType;
	DWORD	DataState;
	int		IntData;
	TCHAR	StrData[64];
	PCOMBO_MENU_ITEM	pComboData;
	int		cbi;
	int		cbItems;
	int		textlen;
} MENUITEM, *LPMENUITEM;


class AFX_EXT_CLASS CVideoMenu  
{
public:
	static LPDIRECTDRAW			m_pDD;
	static LPDIRECTDRAWSURFACE	m_lpMenuSurface;
	static HFONT				m_hTextFont;
	static LPVOID				m_lpUserData;

	static LONG					m_NeedUpdate;

protected:
	LPDIRECTDRAWSURFACE			m_lpTextSurface;
	static LPDIRECTDRAWSURFACE	m_lpAlphaSurface;
	static LPDIRECTDRAWSURFACE	m_lpCsSurface;
	static LPDIRECTDRAWSURFACE	m_lpTriSurface;
	static LPDIRECTDRAWSURFACE	m_lpCheckSurface;
	static LPDIRECTDRAWSURFACE	m_lpSpinLSurface;
	static LPDIRECTDRAWSURFACE	m_lpSpinRSurface;
	static LPDIRECTDRAWSURFACE	m_lpSpinLSurfaceD;
	static LPDIRECTDRAWSURFACE	m_lpSpinRSurfaceD;
	static LPDIRECTDRAWSURFACE	m_lpUpArrowSurface;
	static LPDIRECTDRAWSURFACE	m_lpDownArrowSurface;
	static LPDIRECTDRAWSURFACE	m_lpFrameSurface;

	int							m_nCurrentPos;
	int							m_nSize;
	static BOOL					m_fVisible;
	CVideoMenu*					m_lpParent;
	CVideoMenu*					m_lpActiveChild;
	CTypedPtrArray<CPtrArray, CVideoMenu*> m_SubMenuArray;
	static CTypedPtrArray<CPtrArray, PADDR_ITEM> m_Addrs;
	LPMENUITEM					m_ItemArray[MAX_MENU_ITEMS];
	int							m_nStartItem;

	static CAddrBook			m_AddrBook;

public:
	CVideoMenu();
	virtual ~CVideoMenu();
	static HRESULT ClearSurface(LPDIRECTDRAWSURFACE lpSurface, DWORD dwColor = 0L, LPRECT pRect=NULL);
	int CreateMenuSurface(LPDIRECTDRAW pDD);
	int Cleanup();
	int Init();
	void DisplayMenu();
	BOOL IsVisible();
	LPDIRECTDRAWSURFACE GetSurface() { return m_lpMenuSurface; }
	virtual void OnKey(UINT nChar, LPARAM lParam = 0);
	virtual int CreateTransparentRects(LPRECT rect1, LPRECT rect2);

	static HRESULT CreateOfflineSurface(LPDIRECTDRAWSURFACE* lppSurface, int width, int height, int color=2);
	static HFONT CreateTextFont(LPCTSTR lpFontName, int nFontSize, LONG lfWeight);
	static HBITMAP LoadBitmapFile(TCHAR* strBMP,
								DWORD dwDesiredWidth, DWORD dwDesiredHeight);
	static HRESULT DrawBitmap( LPDIRECTDRAWSURFACE lpSurface, HBITMAP hBMP,
							  DWORD dwOriginX = 0, DWORD dwOriginY = 0,
							  DWORD dwSrcX = 0, DWORD dwSrcY = 0,
							  int dwWidth = 0, int dwHeight = 0 );
	static void save_bmp(LPDIRECTDRAWSURFACE lpSurface, CString outname);

	int GetSize() { return m_nSize; };
	// Update Menu
	void SetUpdateItemCallback(void (*OnUpdateItem)(LPMENUITEM, CVideoMenu*, LPVOID), LPVOID pUserData);
	void SetCommandCallback(void (*OnMenuCommand)(LPMENUITEM, LPVOID), LPVOID pUserData);
	void SetItemText(int nIndex, CString sText);
	int SetIntData(int nIndex, int nData, BOOL fVisible = TRUE);
	void SetStrData(int nIndex, LPCTSTR sText);
	void SetCheck(int nIndex, BOOL fCheck = TRUE);
	void Enable(int nIndex, BOOL fEnable = TRUE);

	CString GetAlias(LPCTSTR ip);
	void HideMenu();

	static void DrawTexts(LPDIRECTDRAWSURFACE lpSurface, CString str,
		int x, int y, COLORREF color=RGB(255, 255, 255));
	static void DrawTexts(LPDIRECTDRAWSURFACE lpSurface, CString str, LPRECT pRect,
		DWORD dwStyle=0, COLORREF color=RGB(255, 255, 255));



protected:
	void DrawTitle();
	void DrawItem(int nIndex);
	void UpdateMenu();
	CVideoMenu* CreateSubMenu(int nIndex);
	void AddMenuItem(LPCTSTR sText, DWORD ItemId = 0, PCOMBO_MENU_ITEM pComboData = NULL, int cbItems = 0);
	void AddMenuItem(LPCTSTR sText, DWORD ItemId, int DataState);
	void RemoveAt(int index);
	void RemoveItem(CString sText);
	void RemoveItem(int id);
	void RemoveAll();
	CVideoMenu* GetItem(int nIndex);

public:
	static int AddAddrItem(LPCTSTR alias, LPCTSTR ip,BOOL bSave=TRUE);
	void RemoveAddrItem(CString alias,BOOL bSave=TRUE);
	int IsIP(LPCTSTR s);
	static void updateAddressBook();

protected:
	static void (*m_lpOnUpdateItem)(LPMENUITEM pItem, CVideoMenu* pVMenu, LPVOID pUserData);
	static void (*m_lpOnCommand)(LPMENUITEM pItem, LPVOID pUserData);
};


#endif // !defined(AFX_VIDEOMENU_H__20294F68_1C41_490E_B4B3_50C35C3E2596__INCLUDED_)
