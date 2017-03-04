#pragma once

class CHoleClient
{
public:
	CHoleClient(void);
	~CHoleClient(void);

public:
	char	m_szPrivateIp[20];
	int		m_nPrivatePort;

	char	m_szPublicIp[20];
	int		m_nPublicPort;

	char	m_szName[20];
};
