#pragma once

// DirectShow capture
#include <dshow.h>
#include <qedit.h>
#include <atlbase.h>
#include <streams.h>

#include "DeckLinkInterface.h"

// custome macro
#ifndef SAFE_STOP
#define SAFE_STOP(x) if(x) (x)->Stop();
#endif//SAFE_STOP

#ifndef SAFE_RELEASE
#define SAFE_RELEASE(x) if(x) { (x)->Release(); (x) = NULL; }
#endif//SAFE_RELEASE

#ifndef SAFE_DELETE
#define SAFE_DELETE(x) if(x) { delete (x); (x) = NULL; }
#endif//SAFE_DELETE


class CaptureVideo;

class CSampleGrabberCB : public ISampleGrabberCB
{
public:
	CSampleGrabberCB(CaptureVideo* pSampleSink);
	virtual ~CSampleGrabberCB();
	// Fake out any COM ref counting
    //
    STDMETHODIMP_(ULONG) AddRef() { return 2; };
    STDMETHODIMP_(ULONG) Release() { return 1; };

    // Fake out any COM QI'ing
    //
    STDMETHODIMP QueryInterface(REFIID riid, void ** ppv)
    {
        CheckPointer(ppv,E_POINTER);
        
        if( riid == IID_ISampleGrabberCB || riid == IID_IUnknown ) 
        {
            *ppv = (void *) static_cast<ISampleGrabberCB*> ( this );
            return NOERROR;
        }    

        return E_NOINTERFACE;
    };

	// The sample grabber is calling us back on its deliver thread
	// This is NOT the main app thread!
	STDMETHODIMP SampleCB( double SampleTime, IMediaSample * pSample )
    {
        return 0;
    };


    // The sample grabber is calling us back on its deliver thread.
    // This is NOT the main app thread!
    //
	STDMETHODIMP BufferCB( double dblSampleTime, BYTE * pBuffer, long lBufferSize );

protected:
	CaptureVideo* m_pSampleSink;
};

class CaptureVideo
{
public:
	CaptureVideo(void);
	virtual ~CaptureVideo(void);

	HRESULT Init();
	HRESULT Exit();
	HRESULT Run();
	HRESULT Stop();

	virtual void CALLBACK OnVidSample(double dbSampleTime, BYTE* pBuffer, long lBufferSize);
	void (*m_pOnVideopCapture)(double dbSampleTime, BYTE* pBuffer, long lBufferSize, void* pUser);

	void SetCallbackFunc(void (*OnVidepCapture)(double dbSampleTime, BYTE* pBuffer, long lBufferSize, void* pUser), void* pUser)
	{
		m_pOnVideopCapture = OnVidepCapture;
		m_pParent = pUser;
	}

protected:
	CSampleGrabberCB* m_pVCB;
	IGraphBuilder* m_pGraph;
	ICaptureGraphBuilder2 *m_pBuilder;
	IBaseFilter *m_pVCaptureFilter;
	IBaseFilter *m_pColorSpaceConverter;
	ISampleGrabber *m_pVSampleGrabber;
	IMediaControl *m_pControl;
	IMediaEventEx *m_pEvent;
	IDecklinkIOControl* m_pDeviceControl;

public:
	int m_nWidth;
	int m_nHeight;
	void* m_pParent;
};
