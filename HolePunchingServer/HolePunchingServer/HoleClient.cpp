#include "StdAfx.h"
#include ".\holeclient.h"

CHoleClient::CHoleClient(void)
{
	memset(m_szName, 0, sizeof(m_szName));
	memset(m_szPrivateIp, 0, sizeof(m_szPrivateIp));
	memset(m_szPublicIp, 0, sizeof(m_szPublicIp));

	m_nPrivatePort = 0;
	m_nPublicPort = 0;
}

CHoleClient::~CHoleClient(void)
{

}


