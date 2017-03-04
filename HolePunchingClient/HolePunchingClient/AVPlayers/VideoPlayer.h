// VideoPlayer.h: interface for the CVideoPlayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIDEOPLAYER_H__B294F04A_D747_4352_A63C_67086C40F787__INCLUDED_)
#define AFX_VIDEOPLAYER_H__B294F04A_D747_4352_A63C_67086C40F787__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\Include\IAVPlayer.h"
class CavPlayer;

class AFX_EXT_CLASS CVideoPlayer : public IAVPlayer  
{
public:
	CVideoPlayer();
	virtual ~CVideoPlayer();

	virtual int init();
	virtual int exit();

	virtual void writeYUV420PData(const char* szCallToken, const unsigned char* pData, 
				int width, int height, unsigned long timeStamp);
	virtual void writeContentYUV420PData(const char* szCallToken, const unsigned char* pData, 
				int width, int height, unsigned long timeStamp);
	virtual void writeAudioData(const unsigned char* pData, int nSize);

	virtual void closeChannel(const char* szCallToken);

private:
	CPtrArray		m_Writers;
//	CavPlayer* m_pWriter;
	static int m_nPlayerCount;
};

#endif // !defined(AFX_VIDEOPLAYER_H__B294F04A_D747_4352_A63C_67086C40F787__INCLUDED_)
