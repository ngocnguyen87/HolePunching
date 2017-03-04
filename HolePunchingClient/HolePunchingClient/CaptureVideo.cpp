#include "StdAfx.h"
#include "CaptureVideo.h"

//// Implementation of CSampleGrabberCB
CSampleGrabberCB::CSampleGrabberCB(CaptureVideo* pSampleSink)
	:m_pSampleSink(pSampleSink)
{
}

CSampleGrabberCB::~CSampleGrabberCB()
{
}

STDMETHODIMP CSampleGrabberCB::BufferCB( double dblSampleTime, BYTE * pBuffer, long lBufferSize )
{
	if(m_pSampleSink)
	{
		m_pSampleSink->OnVidSample(dblSampleTime,pBuffer,lBufferSize); // callback
	}
	return 0;
}

const GUID CLSID_ColorSpaceConverter = {0x1643E180,0x90F5,0x11CE,0x97,0xD5,0x00,0xAA,0x00,0x55,0x59,0x5A};

const GUID CLSID_AVIDecompressor = {0xCF49D4E0,0x1115,0x11CE,0xB0,0x3A,0x00,0x20,0xAF,0x0B,0xA7,0x70};

CaptureVideo::CaptureVideo(void)
: m_pVCB(0)
, m_pGraph(0)
, m_pBuilder(0)
, m_pVCaptureFilter(0)
, m_pVSampleGrabber(0)
, m_pControl(0)
, m_pEvent(0)
, m_pColorSpaceConverter(0)
, m_pDeviceControl(0)
{
	CoInitialize(NULL);
	m_pOnVideopCapture = NULL;
	m_pParent = NULL;
}

CaptureVideo::~CaptureVideo(void)
{
	Exit();
	CoUninitialize();
}

HRESULT CaptureVideo::Init()
{
	HRESULT hr;

	// Create the filter graph.
	CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC,
		IID_IGraphBuilder, (void **)&m_pGraph);

	// Create the capture graph builder.
	CoCreateInstance(CLSID_CaptureGraphBuilder2, NULL, CLSCTX_INPROC,
		IID_ICaptureGraphBuilder2, (void **)&m_pBuilder);
	
	m_pBuilder->SetFiltergraph(m_pGraph);
	
	IBaseFilter *pVGrabFilter;
	CoCreateInstance(CLSID_SampleGrabber, NULL, CLSCTX_INPROC_SERVER,IID_IBaseFilter, (LPVOID *)&pVGrabFilter);
	m_pGraph->AddFilter(pVGrabFilter,L"Video Grabber");
	
	pVGrabFilter->QueryInterface(IID_ISampleGrabber, (void **)&m_pVSampleGrabber);
	
	// Create the system device enumerator.
	ICreateDevEnum *pDevEnum = NULL;
	CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC,
		IID_ICreateDevEnum, (void **)&pDevEnum);
	ULONG cFetched;
	IMoniker* pMoniker = NULL;
	IEnumPins* pEPins = 0; // enumerator input pins
	
	// Create an enumerator for video capture devices.
	IEnumMoniker *pClassEnum = NULL;
	hr = pDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory, &pClassEnum, 0);
	
	if ( FAILED(hr))
	{
		return hr;
	}
	
	pClassEnum->Reset();
	while(pClassEnum->Next(1, &pMoniker, &cFetched) == S_OK)
	{
		// search for capture device has ID equal to m_nVCapID.
		pMoniker->BindToObject(0, 0, IID_IBaseFilter, (void**)&m_pVCaptureFilter);
		pMoniker->Release();
	}

	m_pGraph->AddFilter(m_pVCaptureFilter, L"Video Capture");
	pClassEnum->Release();

	hr = m_pVCaptureFilter->QueryInterface(__uuidof(IDecklinkIOControl),(void**)&m_pDeviceControl);
	if(hr == S_OK && m_pDeviceControl)
	{
		hr = m_pDeviceControl->SetBlackToDeckInCapture(DECKLINK_BLACKINCAPTURE_NONE);
		if(hr)
		{
			TRACE("SetBlackToDeckInCapture got error.\n");
		}

		hr = m_pDeviceControl->SetVideoInput2(DECKLINK_VIDEOINPUT_COMPONENT, FALSE, FALSE);
	}

	// Set format output
	IAMStreamConfig* pISC = NULL;
	AM_MEDIA_TYPE *pmt = 0;

	hr = m_pBuilder->FindInterface(&PIN_CATEGORY_CAPTURE,
		&MEDIATYPE_Video,m_pVCaptureFilter,IID_IAMStreamConfig,
		(void **)&pISC);

	if(SUCCEEDED(hr) && pISC)
	{
		int iFmt,iSize,i;
		BYTE* bbuf = 0;
		hr = pISC->GetNumberOfCapabilities(&iFmt,&iSize);
		if(SUCCEEDED(hr))
		{
			bbuf = new BYTE[iSize];
			for(i = 0; i< iFmt; i++)
			{
				hr = pISC->GetStreamCaps(i,&pmt,bbuf);
				if(SUCCEEDED(hr))
				{
					//VIDEOINFOHEADER *pvih = (VIDEOINFOHEADER *)pmt->pbFormat;
					//WORD PixelFormat;
					//float FrameRate = (float)UNITS / pvih->AvgTimePerFrame;

					//if ((pvih->bmiHeader.biHeight == 480) && (pvih->bmiHeader.biWidth == 640))
					//{
					//	m_nWidth = pvih->bmiHeader.biWidth;
					//	m_nHeight = pvih->bmiHeader.biHeight;
					//	pvih->AvgTimePerFrame = (REFERENCE_TIME)((float)UNITS / 29.97);
					//	pISC->SetFormat(pmt);
					//	DeleteMediaType(pmt);
					//	break;
					//}

					VIDEOINFOHEADER *pvih = (VIDEOINFOHEADER *)pmt->pbFormat;
					WORD PixelFormat;
					float FrameRate = (float)UNITS / pvih->AvgTimePerFrame;

					if (pvih->bmiHeader.biBitCount == 16) 
						PixelFormat = 8;
					else if (pvih->bmiHeader.biBitCount == 20) 
						PixelFormat = 10;
					else 
						PixelFormat = pvih->bmiHeader.biBitCount;
					
					//if ((720 == pvih->bmiHeader.biHeight) && (59.94 <= FrameRate) && ((FrameRate - (int)FrameRate) > 0.01) && (PixelFormat == 8))
					//{
					//	m_nWidth = pvih->bmiHeader.biWidth;
					//	m_nHeight = pvih->bmiHeader.biHeight;
					//	hr = pISC->SetFormat(pmt);
					//	DeleteMediaType(pmt);
					//	break;
					//}

					if ((pvih->bmiHeader.biHeight == 600) && (pvih->bmiHeader.biWidth == 800) && (pvih->bmiHeader.biBitCount == 12))
					{
						m_nWidth = pvih->bmiHeader.biWidth;
						m_nHeight = pvih->bmiHeader.biHeight;
						pvih->AvgTimePerFrame = (REFERENCE_TIME)((float)UNITS / 29.97);
						pISC->SetFormat(pmt);
						DeleteMediaType(pmt);
						break;
					}

				}// end if
				
				DeleteMediaType(pmt);

			}// end for

			if(bbuf)
				delete bbuf;

		}// end SUCCEEDED(hr)

		pISC->Release();
	}
	/////////////////////////////////////////////////////////////////////////////////// end set format out put

	hr = CoCreateInstance(CLSID_AVIDecompressor, NULL, CLSCTX_INPROC_SERVER,IID_IBaseFilter, (LPVOID *)&m_pColorSpaceConverter);

	ASSERT( SUCCEEDED(hr) && (m_pColorSpaceConverter!=NULL));
	hr = m_pGraph->AddFilter(m_pColorSpaceConverter,L"ColorSpace Converter");

	hr = m_pBuilder->RenderStream(
		&PIN_CATEGORY_CAPTURE,  // Pin category
		&MEDIATYPE_Video,       // Media type
		m_pVCaptureFilter,         // Capture filter
		NULL,                   // Compression filter (optional)
		pVGrabFilter             // grabber
	);

	pVGrabFilter->Release();

	// init video sample callback
	m_pVCB = new CSampleGrabberCB(this);
	hr = m_pVSampleGrabber->SetCallback(m_pVCB,1);   // call BufferCB method
	hr = m_pVSampleGrabber->SetOneShot(FALSE);      // disable one-shot mode
	hr = m_pVSampleGrabber->SetBufferSamples(TRUE); // uses buffer samples

	IMediaFilter *pMediaFilter;
	m_pGraph->QueryInterface(IID_IMediaFilter,(void **)&pMediaFilter);
	pMediaFilter->SetSyncSource(NULL); // Turn off the reference clock
	pMediaFilter->Release();

	m_pGraph->QueryInterface(IID_IMediaControl, (void **)&m_pControl);
	m_pGraph->QueryInterface(IID_IMediaEvent, (void **)&m_pEvent);

	return 0;
}

HRESULT CaptureVideo::Exit()
{
	return 0;
}

HRESULT CaptureVideo::Run()
{
	if(!m_pControl)
		return E_POINTER;

	return m_pControl->Run();
}

HRESULT CaptureVideo::Stop()
{
	if(!m_pControl)
		return E_POINTER;

	return m_pControl->Stop();
}

void CALLBACK CaptureVideo::OnVidSample(double dbSampleTime, BYTE* pBuffer, long lBufferSize)
{
	if(m_pOnVideopCapture)
		m_pOnVideopCapture(dbSampleTime, pBuffer, lBufferSize, m_pParent);
}
