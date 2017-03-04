// HolePunchingServerDlg.h : header file
//

#pragma once

#include"holeclient.h"
#include <vector>
#include <iostream>
#include "afxwin.h"

using namespace std;


// CHolePunchingServerDlg dialog
class CHolePunchingServerDlg : public CDialog
{
// Construction
public:
	CHolePunchingServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_HOLEPUNCHINGSERVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	static UINT ReceiveThread(void* pUser);


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	SOCKET	m_hRecvSocket;

	vector<CHoleClient*>	m_vArrayOfHoleClient;
	afx_msg void OnBnClickedReset();
	CListBox m_listbox;
};
