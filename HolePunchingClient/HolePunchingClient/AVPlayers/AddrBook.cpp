// AddrBook.cpp: implementation of the CAddrBook class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AddrBook.h"

#include "..\CommonLib\DataBase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


CIniReader* CAddrBook::m_ini = NULL;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAddrBook::CAddrBook()
{
	m_ini = CIniReader::getInstance();
	m_ini->setINIFileName("D:\\e264.ini");
}

CAddrBook::~CAddrBook()
{
}


int CAddrBook::GetAll(CPtrArray *lpAddr)
{
	CDataBase::getAllAddress(lpAddr);
	return lpAddr->GetSize();

	int n = m_ini->getKeyInt("Ip", "NumOfItem", 0);
	int i;
	CString alias, ip, sNum;
	PADDR_ITEM pItem = NULL;
	for (i=0; i < n; i++)
	{
		pItem = new ADDR_ITEM;

		sNum.Format("num%d", i);
		alias = m_ini->getKeyString("Alias", sNum, "");
		strcpy(pItem->alias, alias.GetBuffer(255));
		ip = m_ini->getKeyString("Ip", sNum, "");
		strcpy(pItem->ip, ip.GetBuffer(255));
		lpAddr->Add(pItem);
	}
	return n;
}


int CAddrBook::SaveAll(CPtrArray *lpAddr)
{
	return CDataBase::saveAllAddress(lpAddr);

	PADDR_ITEM pItem = NULL;
	CString sNum;
	m_ini->setKeyInt("Ip", "NumOfItem", lpAddr->GetSize());
	for (int i=0; i < lpAddr->GetSize(); i++)
	{
		sNum.Format("num%d", i);
		pItem = (PADDR_ITEM)lpAddr->GetAt(i);
		m_ini->setKeyString("Alias", sNum, pItem->alias);
		m_ini->setKeyString("Ip", sNum, pItem->ip);
	}
	return 0;
}
