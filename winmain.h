//////////////////////////////////////////////////////////////////////////
//
// winmain.h : Application entry-point
//
//////////////////////////////////////////////////////////////////////////

#pragma once
#include <ks.h>
#include <ksproxy.h>
#include <ksmedia.h>
#include "qedit.h"
#include "SampleCGB.h"

static float aspRetio = 0;
static int image_w, image_h;

static struct EXT_KS_TREE
{
	// for Extension controls
	IKsControl *pKsControl;
	UINT		nodeID;
	BOOL		isOK;

	// IAMVideoProcAmp ptrs
	IAMVideoProcAmp *pProcAmp;
	IKsControl *pProcAmpKsControl;
	UINT		nodeIDProcAmpKsControl;
	BOOL		isOKpProcAmp;
	BOOL		isOKpProcAmpKsControl;

	// IAMCameraControl
	IAMCameraControl *pCamControl;
	IKsControl *pCamControlKsControl;
	UINT		nodeIDCamControlKsControl;
	BOOL		isOKpCamControl;
	BOOL		isOKpCamControlKsControl;

	IAMVideoControl *pVideoControl;
	BOOL		isOKpVideoControl;

	// video straming ks node
	IKsControl *pKsControlVideoStreaming;
	UINT		nodeIDVideoStreaming;
	BOOL		isOKVideoStreaming;

	IPin *pStillPin;

}ksNodeTree;

typedef struct StillFormats{
	TCHAR  Comp[5];
	int width;
	int height;
};

typedef struct CameraInfo{
	WCHAR rgpmVideoFriendlyName[120];
	ULONG VidPid;
};

static struct _capstuff
{
	WCHAR wszCaptureFile[_MAX_PATH];
	WORD wCapFileSize;  // size in Meg
	ISampleCaptureGraphBuilder *pBuilder;
	IVideoWindow *pVW;
	IMediaEventEx *pME;
	IAMDroppedFrames *pDF;
	IAMVideoCompression *pVC;
	IAMVfwCaptureDialogs *pDlg;
	IAMStreamConfig *pASC;      // for audio cap
	IAMStreamConfig *pVSC;      // for video cap
	IAMStreamConfig *pSSC;      // for still image cap --wenye
	IBaseFilter *pRender;
	IBaseFilter *pVCap, *pACap;
	IGraphBuilder *pFg;
	IMediaControl *pMediaCtrl;  // for media control --wenye
	IPin *pstilPin;				// for still pin --wenye
	IAMVideoControl *pAMVideoCtrl; // for video control --wenye
	IFileSinkFilter *pSink;
	IConfigAviMux *pConfigAviMux;
	int  iMasterStream;
	BOOL fCaptureGraphBuilt;
	BOOL fPreviewGraphBuilt;
	BOOL fCapturing;
	BOOL fPreviewing;
	BOOL fMPEG2;
	BOOL fCapAudio;
	BOOL fCapCC;
	BOOL fCCAvail;
	BOOL fCapAudioIsRelevant;
	bool fDeviceMenuPopulated;
	int defaultVideoLogyCamID;
	IMoniker *rgpmVideoMenu[10];
	CameraInfo vis_camID[10];
	IMoniker *rgpmAudioMenu[10];
	WCHAR rgpmAudioFriendlyName[10][120];
	IMoniker *pmVideo;
	IMoniker *pmAudio;
	double FrameRate;
	BOOL fWantPreview;
	long lCapStartTime;
	long lCapStopTime;
	WCHAR wachFriendlyName[120];
	BOOL fUseTimeLimit;
	BOOL fUseFrameRate;
	DWORD dwTimeLimit;
	int iFormatDialogPos;
	int iSourceDialogPos;
	int iDisplayDialogPos;
	int iVCapDialogPos;
	int iVCrossbarDialogPos;
	int iTVTunerDialogPos;
	int iACapDialogPos;
	int iACrossbarDialogPos;
	int iTVAudioDialogPos;
	int iVCapCapturePinDialogPos;
	int iVCapPreviewPinDialogPos;
	int iACapCapturePinDialogPos;
	long lDroppedBase;
	long lNotBase;
	BOOL fPreviewFaked;
	int iVideoInputMenuPos;
	LONG NumberOfVideoInputs;
	HMENU hMenuPopup;
	int iNumVCapDevices;
	int iSelectedDeviceIndex;

	// For capture pin
	IBaseFilter *pSampleGrabberFilter;
	ISampleGrabber *pSampleGrabber;
	IBaseFilter *pNullRenderer;
	IBaseFilter *VideoRenderer;  // it uses DirectShow and overlay surface. the video renderer can retrieve properties on the Video Renderer.

	// for still pin
	IBaseFilter *pSampleGrabberFilterStill;
	ISampleGrabber *pSampleGrabberStill;
	IBaseFilter *pNullRendererStill;
	BOOL isStillSup;  // the flag for still capture support --wenye
	DWORD stillWidth;
	DWORD stillHeight;
	StillFormats stillFmts[5];
	int CamIndex = 0xff; //keep the activity camera index.

} gcap;

static struct VIS_CameraID
{
	ULONG VidPid;
	//ULONG Pid;
};

static VIS_CameraID visID[16] = {	//available VIS camera ID
	{ 0x1bbdff50 },				// 5MP B/W		,0
	{ 0x1bbdff51 },				// 5MP Color	,1
	{ 0x1bbd3061 },				// 2MP Color	,2
	{ 0x1bbd3062 },				// 1.2MP Color	,3
	{ 0x1bbdff62 },				// Invendo		,4
	{ 0x1bbd2410 }, 			// misumi 5mp	,5
	{ 0x1bbd0bf6 }, 			// e-con 5mp	,6
	{ 0 } 			// unknow		,7

};

static enum CAMIDex{
	CAM5MP_BW = 0,
	CAM5MP_COLOR,
	CAM2MP_COLOR,
	CAM1D2MP_COLOR,
	CAMINVENDO,
	CAM5MPMISUMI,
	CAM5MPECON
};

//static StillFormats stillFmts[5];

static struct InitControlsSetting
{
	// Extension controls
	int ShutterControl;
	int SenseUpMode;
	int MirrorMode;
	int NoiseReductionMode;
	int NoiseReductionControl;
	int DayNightMode;
	int DayNightSwitchDelay;
	int DaytoNightStartLevel;
	int NighttoDayStartLevel;
	int ExposureMode;
	int AGCLevel;
	int AEReferenceLevel;
	int CameraMode;
	int CameraParametersRecovery;
	int I2Ccommand;
	int BLCWeightFactor;
	int BLCGrid;
	int HPos; int VPos;
	int HSize; int VSize;
	int BLCMode;
	int SHUTLevel;
	int AGCMaxLvl;
	int AEHyster;
	int AECtrlSpeed;
	int AECtrlSpeed_bak;
	int shutterEnable;
	int shutterEnable_bak;

	int EGEEnhanceMode;
	int EGEEnhanceGain;
	int EGEEnhGainStart;
	int EGEEnhGainEnd;

	int GammaCorrect;
	int NR2DGain;
	int NR2DGainStart;
	int NR2DGainEnd;

	//Standard Controls
	int BacklightCompensation;
	int Brightness;
	int Contrast;
	int MainsFrequency;
	int Hue;
	int Saturation;
	int Sharpness;
	int gamma;
	int WhiteBalance;
	int WhiteBalanceComponentRed;
	int WhiteBalanceComponentBlue;
	int DigitalMultiplier;

	//Camera Terminal Controls
	int AEMode;
	int AEPriority;
	int ExposureTimeAbsolute;

	int FocusMode;
	int FocusTrk;
	int FocusMode_bak;
	int FocusTrk_bak;

	// ROI setting
	int ROIMode;
	int ROIMode_bak;
	BOOL ROIModeVlu;

	// playback style
	int isFull = 1;

	// some share control should be records the current value
	int CurspeedCtrl = 0;

}initCtrlSetting;

// for stream type
typedef enum{
	MEDIA_MJPEG = 0,
	MEDIA_YUY2 = 1
}eMediaType;

/* for menu operation */
static CWnd *pMain;
//static CMenu Menu;

extern HRESULT	getExtControlValue(int PropertyId, int *curValue);
extern HRESULT  getExt2ControlValues(int PropertyId, int *ExpValue, int *AgcLvlValue);
extern HRESULT  getBLCRangeValue(int PropertyId, int *hpos, int *hsize, int *vpos, int *vsize);
extern HRESULT	getStandardControlPropertyCurrentValue(long PropertyID, long *currValue, long *lCaps);
extern HRESULT  setExtControls(int PropertyId, int PropertyValue);
extern HRESULT  setExt2ControlValues(int PropertyId, int ExpValue, int AgcLvlValue);
extern HRESULT  getExtionControlPropertySize(ULONG PropertyId, ULONG *pulSize);
extern HRESULT  setExtionControlProperty(ULONG PropertyId, ULONG ulSize, BYTE pValue[]);

extern HRESULT  getWhiteBalanceComponent(int *redValue, int *blueValue);
extern HRESULT  setWhiteBalanceComponent(int redValue, int blueValue);
extern HRESULT  getStandardControlPropertyRange(long PropertyID, long *lMin, long *lMax, long *lStep, long *lDefault, long *lCaps);


