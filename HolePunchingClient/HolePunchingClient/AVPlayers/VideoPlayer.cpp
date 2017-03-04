// VideoPlayer.cpp: implementation of the CVideoPlayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VideoPlayer.h"

#include "avPlayer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int CVideoPlayer::m_nPlayerCount = 0;
CVideoPlayer::CVideoPlayer()
{
	m_nPlayerCount++;
}

CVideoPlayer::~CVideoPlayer()
{
	m_nPlayerCount--;
	if(m_nPlayerCount==0)
		CavPlayer::DestroyDirectDraw();

}

int CVideoPlayer::init()
{
	if(m_nPlayerCount==1)
	{
		CavPlayer::InitDirectDraw();
	}

	return 0;
}

int CVideoPlayer::exit()
{
	while (m_Writers.GetSize())
	{
		CavPlayer* pWriter = (CavPlayer *)m_Writers.GetAt(0);
		if(pWriter)
		{
			delete pWriter;
			pWriter = NULL;
		}
		m_Writers.RemoveAt(0);
	}
	return 0;
}

void CVideoPlayer::writeYUV420PData(const char* szCallToken, const unsigned char* pData, 
				int width, int height, unsigned long timeStamp)
{
	CavPlayer* pWriter=NULL;
	for (int i=0; i < m_Writers.GetSize(); i++)
	{
		pWriter = (CavPlayer *)m_Writers.GetAt(i);
		if (pWriter->m_sCallToken.CompareNoCase(szCallToken) == 0)
			break;
	}
	if (i >= m_Writers.GetSize())
	{
		pWriter = new CavPlayer();
		pWriter->Init(width, height, 2, 16000);
		pWriter->m_sCallToken = szCallToken;
		pWriter->SetPlayerAlias(szCallToken);
		m_Writers.Add(pWriter);
	}

	int framesize = width * height;
	LPBYTE pY = (LPBYTE)pData;
	LPBYTE pCr = pY + framesize;
	LPBYTE pCb = pCr + framesize / 4;

	try
	{
		pWriter->PlayVideo(pY, pCr, pCb, width, height, timeStamp, 0);
	}
	catch(...)
	{
		TRACE("\n m_pWriter->PlayVideo exeption");
	}
}

void CVideoPlayer::writeContentYUV420PData(const char* szCallToken, const unsigned char* pData, 
				int width, int height, unsigned long timeStamp)
{
	CavPlayer* pWriter=NULL;
	for (int i=0; i < m_Writers.GetSize(); i++)
	{
		pWriter = (CavPlayer *)m_Writers.GetAt(i);
		if (pWriter->m_sCallToken.CompareNoCase(szCallToken) == 0)
			break;
	}
	if (i >= m_Writers.GetSize())
	{
		pWriter = new CavPlayer();
		pWriter->Init(width, height, 2, 16000);
		pWriter->m_sCallToken = szCallToken;
		pWriter->SetPlayerAlias(szCallToken);
		m_Writers.Add(pWriter);
	}

	int framesize = width * height;
	LPBYTE pY = (LPBYTE)pData;
	LPBYTE pCr = pY + framesize;
	LPBYTE pCb = pCr + framesize / 4;

	try
	{
		pWriter->PlayVideo(pY, pCr, pCb, width, height, GetTickCount(), 0);
	}
	catch(...)
	{
		TRACE("\n m_pWriter->PlayVideo exeption");
	}
}

void CVideoPlayer::writeAudioData(const unsigned char* pData, int nSize)
{

}

void CVideoPlayer::closeChannel(const char* szCallToken)
{
	CavPlayer* pWriter=NULL;
	for (int i=0; i < m_Writers.GetSize(); i++)
	{
		pWriter = (CavPlayer *)m_Writers.GetAt(i);
		if (pWriter->m_sCallToken.CompareNoCase(szCallToken) == 0)
		{
			delete pWriter;
			m_Writers.RemoveAt(i);
			break;
		}
	}
}
