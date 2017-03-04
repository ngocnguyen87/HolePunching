// AddrBook.h: interface for the CAddrBook class.
//
//////////////////////////////////////////////////////////////////////

#pragma once
#pragma warning(disable:4995)


typedef struct _ADDR_ITEM
{
	char	alias[31];
	char	ip[16];
} ADDR_ITEM, *PADDR_ITEM;

class CDaoDatabase;

class CAddrBook  
{
private:

public:
	CAddrBook();
	virtual ~CAddrBook();

	int GetAll(CPtrArray *lpAddr);
	int SaveAll(CPtrArray *lpAddr);

};
