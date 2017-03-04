/*****************************************************************
*        Project	: E&Conf                                     *
*        Version	: 1.0.0.0                                    *
*        Module		: H323Dll.dll                                *
*        File		: IAVPlayer.h                                *
*        Description: Define IAVPlayer interface		         *
*        History	:                                            *
*****************************************************************/

#ifndef __IAVPLAYER_H__
#define __IAVPLAYER_H__

class IAVPlayer
{
public:

	virtual int setConfig(void* pConfig){return 0;};
	virtual int getConfig(void* pConfig){return 0;};
	virtual int init() = 0;
	virtual int exit() = 0;
	virtual int switchFullScreen(BOOL bFullScreen){return 0;};
	virtual void onMove(){return ;};
	virtual int setVolume(int nVol){return 0;}
	virtual void writeYUV420PData(const char* szCallToken, const unsigned char* pVideoBuff, 
									int width, int height, unsigned long timeStamp){};
	virtual void writeLocalYUV420PData(const char* szCallToken, const unsigned char* pVideoBuff, 
									int width, int height, unsigned long timeStamp){};
	virtual void writeContentYUV420PData(const char* szCallToken, const unsigned char* pVideoBuff, 
									int width, int height, unsigned long timeStamp){};
	virtual void writeAudioData(const unsigned char* pData, int nSize)=0;

	virtual void closeChannel(const char* szCallToken){};
};
#endif  // __IAVPLAYER_H__