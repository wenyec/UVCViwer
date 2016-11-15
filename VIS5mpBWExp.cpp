// VIS5mpBWExp.cpp : implementation file
//
/*******************************************************************
*
* The extention controls used are following
* 	PROPERTY_ID_EXT_SHUTTER = 1,
*	PROPERTY_ID_EXT_EXPOSURE_MODE_AND_AGC = 10,
*	PROPERTY_ID_EXT_AE_REFERENCE_LEVEL = 11,
*	PROPERTY_ID_EXT_SHUTTER_LEVEL = 12, 
*	PROPERTY_ID_EXT_BLCGRID_POS_SIZE = 17,
*	PROPERTY_ID_EXT_BLC_WEIGHT_LEVEL = 18,
*	PROPERTY_ID_EXT_BLCGRID_ENABLE = 19,
*	PROPERTY_ID_EXT_EXPOSURE_HYST = 20,
*	PROPERTY_ID_EXT_EXPOSURE_CTRLSPD = 21,
*	PROPERTY_ID_EXT_GAMMA_CORRECT_LEVEL = 27,
*	PROPERTY_ID_EXT_AGCMAX_GAIN_LEVEL = 28,
*
*   CY_FX_UVC_PU_BACKLIGHT_COMPENSATION_CONTROL         (uint16_t)(0x0100)
*
*********************************************************************/

#include "stdafx.h"
#include "VIS5mpBWExp.h"
#include "afxdialogex.h"


// VIS5mpBWExp dialog

IMPLEMENT_DYNAMIC(VIS5mpBWExp, CDialog)

VIS5mpBWExp::VIS5mpBWExp(CWnd* pParent /*=NULL*/)
	: CDialog(VIS5mpBWExp::IDD, pParent)
{

}

VIS5mpBWExp::~VIS5mpBWExp()
{
}

void VIS5mpBWExp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_EXPOSURE_MODE, c_ExpMode);
	DDX_Control(pDX, IDC_COMBO_SHUT_CONTL, c_ShutCtrl);
	DDX_Control(pDX, IDC_FINE_SHUTTER_ENABLE, c_FineShuChk);
	DDX_Control(pDX, IDC_SLD_SHUT_LVL, c_sldShuLvl);
	DDX_Control(pDX, IDC_EDIT_SHUT_LVL, tx_edtShuLvl);
	DDX_Control(pDX, IDC_SLD_AGC_LVL, c_sldGainCtrl);
	DDX_Control(pDX, IDC_EDIT_AGC_LVL, tx_edtGainCtrl);
	DDX_Control(pDX, IDC_SLD_AE_REF_LVL, c_sldAERefLvl);
	DDX_Control(pDX, IDC_EDIT_AE_REF_LVL, tx_edtAERefLvl);
	DDX_Control(pDX, IDC_SLD_AE_HYSTER, c_sldAEHystCtrl);
	DDX_Control(pDX, IDC_EDIT_AE_HYSTER, tx_edtAEHystCtrl);
	DDX_Control(pDX, IDC_SLD_AE_CTRLSPEED, c_sldSpedCtrl);
	DDX_Control(pDX, IDC_EDIT_AE_CTRLSPEED, tx_edtSpedCtrl);
	DDX_Control(pDX, IDC_COMBO_BACK_LIGHT, c_BLKCompCtrl);
	DDX_Control(pDX, IDC_SLD_BLCWLvl, c_sldBLKWgtCtrl);
	DDX_Control(pDX, IDC_EDIT_BLCWLvl, tx_edtBLKWgtCtrl);
	DDX_Control(pDX, IDC_COMBO_BLC_GRID, c_BLKGrid);
	DDX_Control(pDX, IDC_SLD_HPos, c_sldHPosCtrl);
	DDX_Control(pDX, IDC_EDIT_HPos, tx_edtHPosCtrl);
	DDX_Control(pDX, IDC_SLD_VPos, c_sldVPosCtrl);
	DDX_Control(pDX, IDC_EDIT_VPos, tx_edtVPosCtrl);
	DDX_Control(pDX, IDC_SLD_HSize, c_sldHSizeCtrl);
	DDX_Control(pDX, IDC_EDIT_HSize, tx_edtHSizeCtrl);
	DDX_Control(pDX, IDC_SLD_VSize, c_sldVSizeCtrl);
	DDX_Control(pDX, IDC_EDIT_VSize, tx_edtVSizeCtrl);
	DDX_Control(pDX, IDC_SLD_AE_MAX_LVL, c_sldAEMaxLvl);
	DDX_Control(pDX, IDC_EDIT_AE_MAX_LVL, tx_edtAEMaxLvl);
}


BEGIN_MESSAGE_MAP(VIS5mpBWExp, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_EXPOSURE_MODE, &VIS5mpBWExp::OnCbnSelchangeComboExposureMode)
	ON_CBN_SELCHANGE(IDC_COMBO_SHUT_CONTL, &VIS5mpBWExp::OnCbnSelchangeComboShutContl)
	ON_BN_CLICKED(IDC_FINE_SHUTTER_ENABLE, &VIS5mpBWExp::OnBnClickedFineShutterEnable)
//	ON_WM_HSCROLL()
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_SHUT_LVL, &VIS5mpBWExp::OnNMReleasedcaptureSldShutLvl)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_AE_CTRLSPEED, &VIS5mpBWExp::OnNMReleasedcaptureSldAeCtrlspeed)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_AGC_LVL, &VIS5mpBWExp::OnNMReleasedcaptureSldAgcLvl)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_AE_REF_LVL, &VIS5mpBWExp::OnNMReleasedcaptureSldAeRefLvl)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_AE_HYSTER, &VIS5mpBWExp::OnNMReleasedcaptureSldAeHyster)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_BLCWLvl, &VIS5mpBWExp::OnNMReleasedcaptureSldBlcwlvl)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_HPos, &VIS5mpBWExp::OnNMReleasedcaptureSldHpos)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_VPos, &VIS5mpBWExp::OnNMReleasedcaptureSldVpos)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_HSize, &VIS5mpBWExp::OnNMReleasedcaptureSldHsize)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_VSize, &VIS5mpBWExp::OnNMReleasedcaptureSldVsize)
	ON_CBN_SELCHANGE(IDC_COMBO_BACK_LIGHT, &VIS5mpBWExp::OnCbnSelchangeComboBackLight)
	ON_CBN_SELCHANGE(IDC_COMBO_BLC_GRID, &VIS5mpBWExp::OnCbnSelchangeComboBlcGrid)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_AE_MAX_LVL, &VIS5mpBWExp::OnNMReleasedcaptureSldAeMaxLvl)
END_MESSAGE_MAP()


// VIS5mpBWExp message handlers


BOOL VIS5mpBWExp::OnInitDialog()
{
	CDialog::OnInitDialog();

	HRESULT hr;
	CString retValueStr;
	int retValue = 0;
	long currValue, lCaps;
	long lMin, lMax, lStep, lDefault;

	int expMode = 0, AGCLvl = 0, isBLCon = 0;
	//hr = getExt2ControlValues(10, &expMode, &AGCLvl);//initCtrlSetting.ExposureMode, &initCtrlSetting.AGCLevel
	expMode = initCtrlSetting.ExposureMode;
	AGCLvl = initCtrlSetting.AGCLevel;
#if 1 //disable the exposure mode menu
	//HWND hListExpoMode = GetDlgItem(hwnd, IDC_COMBO_EXPOSURE_MODE);
	if (FAILED(hr))
	{
		c_ExpMode.EnableWindow(FALSE);
	}
	c_ExpMode.AddString(L"0x00:AUTO Shutter & AGC");
	c_ExpMode.AddString(L"0x01:Manual Shutter & AGC");
	c_ExpMode.AddString(L"0x02:Auto Shutter & Manual GC");
	c_ExpMode.AddString(L"0x03:Manual Shutter & GC");
	c_ExpMode.SetCurSel(expMode);

#endif
#if 1 // for debugging -wcheng

	//hr = getExtControlValue(12, &retValue); //&initCtrlSetting.SHUTLevel
	retValue = initCtrlSetting.SHUTLevel;
	//hr = getExtControlValue(17, &retValue);

	//HWND hListShutCtrl = GetDlgItem(hwnd, IDC_COMBO_SHUT_CONTL);
	//HWND hListSldSHUTLVL = GetDlgItem(hwnd, IDC_SLD_SHUT_LVL);

	SendMessageA(c_sldShuLvl, TBM_SETRANGEMAX, TRUE, 255);
	SendMessageA(c_sldShuLvl, TBM_SETRANGEMIN, TRUE, 0);
	SendMessageA(c_sldShuLvl, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sldShuLvl, TBM_SETPOS, TRUE, retValue);

	//HWND hListSHUTLVL = GetDlgItem(hwnd, IDC_EDIT_SHUT_LVL);
	//Edit_SetText(hListAGCLVL, L"0");
	tx_edtShuLvl.EnableWindow(FALSE);
	retValueStr.Format(L"%d", retValue);
	tx_edtShuLvl.ReplaceSel(retValueStr, TRUE);
	//HWND hListFineShutEnb = GetDlgItem(hwnd, IDC_FINE_SHUTTER_ENABLE);
	if (initCtrlSetting.shutterEnable)
		c_FineShuChk.SetCheck(BST_CHECKED);// setting shutter enable checkbox.
	else
		c_FineShuChk.SetCheck(BST_UNCHECKED);// cleaning shutter enable checkbox.

	//hr = getExtControlValue(1, &retValue); // &initCtrlSetting.ShutterControl
	retValue = initCtrlSetting.ShutterControl;
	if (FAILED(hr) || expMode == 0 || expMode == 2)
	{
		c_ShutCtrl.EnableWindow(FALSE);
		c_sldShuLvl.EnableWindow(FALSE);
		c_FineShuChk.EnableWindow(FALSE);

	}
	if (expMode == 1 | expMode == 3){
		if (initCtrlSetting.shutterEnable){
			c_ShutCtrl.EnableWindow(FALSE);
		}
		else{
			c_sldShuLvl.EnableWindow(FALSE);
		}
	}

	c_ShutCtrl.AddString(L"0x00:Max Integration Time");
	c_ShutCtrl.AddString(L"0x01:7/8");
	c_ShutCtrl.AddString(L"0x02:6/8");
	c_ShutCtrl.AddString(L"0x03:5/8");
	c_ShutCtrl.AddString(L"0x04:4/8");
	c_ShutCtrl.AddString(L"0x05:3/8");
	c_ShutCtrl.AddString(L"0x06:2/8");
	c_ShutCtrl.AddString(L"0x07:1/8");
	c_ShutCtrl.SetCurSel(retValue);
#endif //for debugging -wcheng
#if 0 	
	HWND hListSenseUpMode = GetDlgItem(hwnd, IDC_COMBO_SEN_UP_MODE);
	hr = getExtControlValue(2, &retValue);
	if (FAILED(hr))
	{
		EnableWindow(hListSenseUpMode, FALSE);
	}

	ComboBox_AddString(hListSenseUpMode, L"00:OFF");
	ComboBox_AddString(hListSenseUpMode, L"01:X2");
	ComboBox_AddString(hListSenseUpMode, L"02:X4");
	ComboBox_AddString(hListSenseUpMode, L"03:X6");
	ComboBox_AddString(hListSenseUpMode, L"04:X8");
	ComboBox_AddString(hListSenseUpMode, L"05:X10");
	ComboBox_AddString(hListSenseUpMode, L"06:X15");
	ComboBox_AddString(hListSenseUpMode, L"07:X20");
	ComboBox_AddString(hListSenseUpMode, L"08:X25");
	ComboBox_AddString(hListSenseUpMode, L"09:X30");
	ComboBox_SetCurSel(hListSenseUpMode, retValue);
#endif
	//HWND hListSldAELVL = GetDlgItem(hwnd, IDC_SLD_AE_REF_LVL);
	//hr = getExtControlValue(11, &retValue); // &initCtrlSetting.AEReferenceLevel
	retValue = initCtrlSetting.AEReferenceLevel;
	if (FAILED(hr))
	{
		c_sldAERefLvl.EnableWindow(FALSE);
	}

	SendMessageA(c_sldAERefLvl, TBM_SETRANGEMAX, TRUE, 254);
	SendMessageA(c_sldAERefLvl, TBM_SETRANGEMIN, TRUE, 1);
	SendMessageA(c_sldAERefLvl, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sldAERefLvl, TBM_SETPOS, TRUE, retValue);

	//HWND hListAELVL = GetDlgItem(hwnd, IDC_EDIT_AE_REF_LVL);
	retValueStr.Format(L"%d", retValue);
	tx_edtAERefLvl.EnableWindow(FALSE);
	tx_edtAERefLvl.ReplaceSel(retValueStr, TRUE);

	//HWND hListAgcMaxLVL = GetDlgItem(hwnd, IDC_SLD_AE_MAX_LVL);  // for AGC maximum limitation -wcheng
	//hr = getExtControlValue(28, &retValue);
	retValue = initCtrlSetting.AGCMaxLvl;
	if (FAILED(hr))
	{
		c_sldAEMaxLvl.EnableWindow(FALSE);
	}
	SendMessageA(c_sldAEMaxLvl, TBM_SETRANGEMAX, TRUE, 0xB2);
	SendMessageA(c_sldAEMaxLvl, TBM_SETRANGEMIN, TRUE, 0);
	SendMessageA(c_sldAEMaxLvl, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sldAEMaxLvl, TBM_SETPOS, TRUE, retValue);

	//HWND hListEditAGCMaxLVL = GetDlgItem(hwnd, IDC_EDIT_AE_MAX_LVL);
	retValueStr.Format(L"%d", retValue);
	tx_edtAEMaxLvl.EnableWindow(FALSE);
	tx_edtAEMaxLvl.ReplaceSel(retValueStr, TRUE);

	//HWND hListSldAEHysterLVL = GetDlgItem(hwnd, IDC_SLD_AE_HYSTER);
	//hr = getExtControlValue(20, &retValue); //&initCtrlSetting.AEHyster
	retValue = initCtrlSetting.AEHyster;
	if (FAILED(hr))
	{
		c_sldAEHystCtrl.EnableWindow(FALSE);
	}

	SendMessageA(c_sldAEHystCtrl, TBM_SETRANGEMAX, TRUE, 32);
	SendMessageA(c_sldAEHystCtrl, TBM_SETRANGEMIN, TRUE, 1);
	SendMessageA(c_sldAEHystCtrl, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sldAEHystCtrl, TBM_SETPOS, TRUE, retValue);

	//HWND hListEditAEHysterLVL = GetDlgItem(hwnd, IDC_EDIT_AE_HYSTER);
	retValueStr.Format(L"%d", retValue);
	tx_edtAEHystCtrl.EnableWindow(FALSE);
	tx_edtAEHystCtrl.ReplaceSel(retValueStr, TRUE);

	//HWND hListSldAECtrlLVL = GetDlgItem(hwnd, IDC_SLD_AE_CTRLSPEED);
	//hr = getExtControlValue(21, &retValue); // &initCtrlSetting.AECtrlSpeed
	retValue = initCtrlSetting.AECtrlSpeed;
	if (FAILED(hr))
	{
		c_sldSpedCtrl.EnableWindow(FALSE);
	}

	SendMessageA(c_sldSpedCtrl, TBM_SETRANGEMAX, TRUE, 0x7);
	SendMessageA(c_sldSpedCtrl, TBM_SETRANGEMIN, TRUE, 0);
	SendMessageA(c_sldSpedCtrl, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sldSpedCtrl, TBM_SETPOS, TRUE, retValue);

	//HWND hListEditAECtrlLVL = GetDlgItem(hwnd, IDC_EDIT_AE_CTRLSPEED);
	retValueStr.Format(L"%d", retValue);
	tx_edtSpedCtrl.EnableWindow(FALSE);
	tx_edtSpedCtrl.ReplaceSel(retValueStr, TRUE);

	//HWND hListSldAGCLVL = GetDlgItem(hwnd, IDC_SLD_AGC_LVL);
	if (FAILED(hr) || expMode == 0 || expMode == 1)
	{
		c_sldGainCtrl.EnableWindow(FALSE);
	}

	SendMessageA(c_sldGainCtrl, TBM_SETRANGEMAX, TRUE, 255);
	SendMessageA(c_sldGainCtrl, TBM_SETRANGEMIN, TRUE, 0);
	SendMessageA(c_sldGainCtrl, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sldGainCtrl, TBM_SETPOS, TRUE, AGCLvl);

	//HWND hListAGCLVL = GetDlgItem(hwnd, IDC_EDIT_AGC_LVL);
	//Edit_SetText(hListAGCLVL, L"0");
	tx_edtGainCtrl.EnableWindow(FALSE);
	retValueStr.Format(L"%d", AGCLvl);
	tx_edtGainCtrl.ReplaceSel(retValueStr, TRUE);

	/* //move to gamma menu
	HWND hListMirrorMode = GetDlgItem(hwnd, IDC_COMBO_MIRROR_MODE);
	hr = getExtControlValue(3, &retValue);
	if (FAILED(hr))
	{
	EnableWindow(hListMirrorMode, FALSE);
	}
	ComboBox_AddString(hListMirrorMode, L"ORIGINAL");  //original "OFF"
	ComboBox_AddString(hListMirrorMode, L"MIRROR");
	ComboBox_AddString(hListMirrorMode, L"V_FLIP");
	ComboBox_AddString(hListMirrorMode, L"ROTATE ");
	ComboBox_SetCurSel(hListMirrorMode, retValue);
	*/
#if 0 ///move to gamma menu
	HWND hListMainFeq = GetDlgItem(hwnd, IDC_COMBO_MAIN_FEQ);
	ComboBox_AddString(hListMainFeq, L"Disabled");
	ComboBox_AddString(hListMainFeq, L"50 Hz");
	ComboBox_AddString(hListMainFeq, L"60 Hz");
	ComboBox_SetCurSel(hListMainFeq, getMainsFrequency());
#endif
	/* check the res */
//	AM_MEDIA_TYPE *pmt;  // -- wcheng debugging
//	gcap.pVSC->GetFormat(&pmt);
	int setV = 0;
	//getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_BACKLIGHT_COMPENSATION, &currValue, &lCaps); //initCtrlSetting.BacklightCompensation
	currValue = initCtrlSetting.BacklightCompensation;
	//HWND hListBackLight = GetDlgItem(hwnd, IDC_COMBO_BACK_LIGHT);
	if (expMode == 3){
		c_BLKCompCtrl.EnableWindow(FALSE);
	}
	else{
		c_BLKCompCtrl.EnableWindow(TRUE);
	}

	//EnableWindow(hListBackLight, FALSE);
	if (0/*(pmt->lSampleSize == 4147200) || (pmt->lSampleSize == 1036800)*/){
		c_BLKCompCtrl.AddString(L"Wide Dyn Range");
		switch (currValue)
		{
		case 0:
			setV = 1;// 3;
			break;
		case 1:
			setV = 3;// 0;
			break;
		case 2:
			setV = 2;
			break;
		case 3:
			setV = 0;// 1;
			break;
		default:
			setV = 1;
			break;
		}
	}
	else{
		switch (currValue)
		{
		case 0:
			setV = 0;
			break;
		case 1:
			setV = 1;
			break;
		default:
			setV = 0;
			break;
		}
	}
	c_BLKCompCtrl.AddString(L"BLC off");
	if (0/*(pmt->lSampleSize == 4147200) || (pmt->lSampleSize == 1036800)*/){
		c_BLKCompCtrl.AddString(L"HBLC");
	}
	c_BLKCompCtrl.AddString(L"BLC on");
	c_BLKCompCtrl.SetCurSel(setV);
	if (setV){
		isBLCon = 1;
	}
	else{
		isBLCon = 0;
	}

#if 0
	HWND hListCameraMode = GetDlgItem(hwnd, IDC_COMBO_CAM_MODE);
	hr = getExtControlValue(13, &retValue);
	if (FAILED(hr))
	{
		EnableWindow(hListCameraMode, FALSE);
	}

	// default capture format

	// DV capture does not use a VIDEOINFOHEADER
	if (1 || pmt->lSampleSize == 4147200) //1080p
	{
		ComboBox_AddString(hListCameraMode, L"5MP Camera");
		//ComboBox_AddString(hListCameraMode, L"Linear 1080P(25/30fps),BLC OFF");
		//ComboBox_AddString(hListCameraMode, L"Linear 1080P(25/30fps),BLC ON");
		//ComboBox_AddString(hListCameraMode, L"Linear 1080P(25/30fps),HBLC OFF");
		//ComboBox_AddString(hListCameraMode, L"WDR 1080P(25/30fps),BLC OFF");
	}
	if (pmt->lSampleSize == 1036800) //1080p/2
	{
		ComboBox_AddString(hListCameraMode, L"1080P(25/30fps) USB2");
		//ComboBox_AddString(hListCameraMode, L"Linear 1080P(25/30fps),BLC OFF");
		//ComboBox_AddString(hListCameraMode, L"Linear 1080P(25/30fps),BLC ON");
		//ComboBox_AddString(hListCameraMode, L"Linear 1080P(25/30fps),HBLC OFF");
		//ComboBox_AddString(hListCameraMode, L"WDR 1080P(25/30fps),BLC OFF");
	}

	if (pmt->lSampleSize == 1843200) //720p
	{
		ComboBox_AddString(hListCameraMode, L"720P(50/60fps)");
		// This capture filter captures something other that pure video.
		//ComboBox_AddString(hListCameraMode, L"Linear 720P(50 / 60fps), BLC OFF");
		//ComboBox_AddString(hListCameraMode, L"Linear 720P(50/60fps), BLC ON");
		//ComboBox_AddString(hListCameraMode, L"Linear 720P(50/60fps), HBLC ON");
	}
	if (pmt->lSampleSize == 460800) //720p/2
	{
		ComboBox_AddString(hListCameraMode, L"720P(50/60fps) USB2");
		// This capture filter captures something other that pure video.
		//ComboBox_AddString(hListCameraMode, L"Linear 720P(50 / 60fps), BLC OFF");
		//ComboBox_AddString(hListCameraMode, L"Linear 720P(50/60fps), BLC ON");
		//ComboBox_AddString(hListCameraMode, L"Linear 720P(50/60fps), HBLC ON");
	}

	/*
	ComboBox_AddString(hListCameraMode, L"Linear 1080P(25/30fps),BLC OFF");
	ComboBox_AddString(hListCameraMode, L"Linear 1080P(25/30fps),BLC ON");
	ComboBox_AddString(hListCameraMode, L"Linear 1080P(25/30fps),HBLC OFF");
	ComboBox_AddString(hListCameraMode, L"WDR 1080P(25/30fps),BLC OFF");
	ComboBox_AddString(hListCameraMode, L"Linear 720P(50 / 60fps), BLC OFF");
	ComboBox_AddString(hListCameraMode, L"Linear 720P(50/60fps), BLC ON");
	ComboBox_AddString(hListCameraMode, L"Linear 720P(50/60fps), HBLC ON");*/
	ComboBox_SetCurSel(hListCameraMode, 0/*retValue*/);
#endif

	//HWND hListBLCGrid = GetDlgItem(hwnd, IDC_COMBO_BLC_GRID);
	//hr = getExtControlValue(19, &retValue); // &initCtrlSetting.BLCGrid
	retValue = initCtrlSetting.BLCGrid;
	if (retValue == 0)
		retValue = 0;
	else
		retValue = 1;
	if (FAILED(hr) || !isBLCon)
	{
		c_BLKGrid.EnableWindow(FALSE);
	}
	c_BLKGrid.AddString(L"disable");
	c_BLKGrid.AddString(L"enable");
	c_BLKGrid.SetCurSel(retValue);
	/*
	HWND hListBLCWF = GetDlgItem(hwnd, IDC_COMBO_BLC_WGHT_FACT);
	hr = getExtControlValue(18, &retValue);
	if (FAILED(hr))
	{
	EnableWindow(hListBLCWF, FALSE);
	}
	ComboBox_AddString(hListBLCWF, L"low-gain");
	ComboBox_AddString(hListBLCWF, L"medium-gain");
	ComboBox_AddString(hListBLCWF, L"high-gain");
	ComboBox_SetCurSel(hListBLCWF, retValue);
	*/
	int hpos = 0, hsize = 0, vpos = 0, vsize = 0;
	hr = getBLCRangeValue(17, &hpos, &hsize, &vpos, &vsize);
	initCtrlSetting.HPos = hpos; initCtrlSetting.VPos = vpos;
	initCtrlSetting.HSize = hsize; initCtrlSetting.VSize = vsize;

	//hr = getExtControlValue(18, &retValue); // &initCtrlSetting.BLCWeightFactor
	retValue = initCtrlSetting.BLCWeightFactor;

	//HWND hListSldBLCWLvl = GetDlgItem(hwnd, IDC_SLD_BLCWLvl);
	//HWND hListSldHPos = GetDlgItem(hwnd, IDC_SLD_HPos);
	//HWND hListSldHSize = GetDlgItem(hwnd, IDC_SLD_HSize);
	//HWND hListSldVPos = GetDlgItem(hwnd, IDC_SLD_VPos);
	//HWND hListSldVSize = GetDlgItem(hwnd, IDC_SLD_VSize);
	if (FAILED(hr) || isBLCon == 0)
	{
		c_sldBLKWgtCtrl.EnableWindow(FALSE);
		c_sldHPosCtrl.EnableWindow(FALSE);
		c_sldVPosCtrl.EnableWindow(FALSE);
		c_sldHSizeCtrl.EnableWindow(FALSE);
		c_sldVSizeCtrl.EnableWindow(FALSE);
	}

	SendMessageA(c_sldBLKWgtCtrl, TBM_SETRANGEMAX, TRUE, 255);
	SendMessageA(c_sldBLKWgtCtrl, TBM_SETRANGEMIN, TRUE, 0);
	SendMessageA(c_sldBLKWgtCtrl, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sldBLKWgtCtrl, TBM_SETPOS, TRUE, retValue);

	//HWND hListEditBLCLvl = GetDlgItem(hwnd, IDC_EDIT_BLCWLvl);
	tx_edtBLKWgtCtrl.EnableWindow(FALSE);
	retValueStr.Format(L"%d", retValue);
	tx_edtBLKWgtCtrl.ReplaceSel(retValueStr, TRUE);

	SendMessageA(c_sldHPosCtrl, TBM_SETRANGEMAX, TRUE, 15);
	SendMessageA(c_sldHPosCtrl, TBM_SETRANGEMIN, TRUE, 0);
	SendMessageA(c_sldHPosCtrl, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sldHPosCtrl, TBM_SETPOS, TRUE, hpos);

	//HWND hListEditHPos = GetDlgItem(hwnd, IDC_EDIT_HPos);
	tx_edtHPosCtrl.EnableWindow(FALSE);
	retValueStr.Format(L"%d", hpos);
	tx_edtHPosCtrl.ReplaceSel(retValueStr, TRUE);

	SendMessageA(c_sldHSizeCtrl, TBM_SETRANGEMAX, TRUE, 15);
	SendMessageA(c_sldHSizeCtrl, TBM_SETRANGEMIN, TRUE, 0);
	SendMessageA(c_sldHSizeCtrl, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sldHSizeCtrl, TBM_SETPOS, TRUE, hsize);

	//HWND hListEditHSize = GetDlgItem(hwnd, IDC_EDIT_HSize);
	tx_edtHSizeCtrl.EnableWindow(FALSE);
	retValueStr.Format(L"%d", hsize);
	tx_edtHSizeCtrl.ReplaceSel(retValueStr, TRUE);

	SendMessageA(c_sldVPosCtrl, TBM_SETRANGEMAX, TRUE, 15);
	SendMessageA(c_sldVPosCtrl, TBM_SETRANGEMIN, TRUE, 0);
	SendMessageA(c_sldVPosCtrl, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sldVPosCtrl, TBM_SETPOS, TRUE, vpos);

	//HWND hListEditVPos = GetDlgItem(hwnd, IDC_EDIT_VPos);
	tx_edtVPosCtrl.EnableWindow(FALSE);
	retValueStr.Format(L"%d", vpos);
	tx_edtVPosCtrl.ReplaceSel(retValueStr, TRUE);

	SendMessageA(c_sldVSizeCtrl, TBM_SETRANGEMAX, TRUE, 15);
	SendMessageA(c_sldVSizeCtrl, TBM_SETRANGEMIN, TRUE, 0);
	SendMessageA(c_sldVSizeCtrl, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sldVSizeCtrl, TBM_SETPOS, TRUE, vsize);

	//HWND hListEditVSize = GetDlgItem(hwnd, IDC_EDIT_VSize);
	tx_edtVSizeCtrl.EnableWindow(FALSE);
	retValueStr.Format(L"%d", vsize);
	tx_edtVSizeCtrl.ReplaceSel(retValueStr, TRUE);

	return TRUE;
}
#if 1
void VIS5mpBWExp::saveCameraControlInitSetting()
{
	long currValue, lCaps;
//	int setV = 0;

	// reset global struct
	initCtrlSetting.ShutterControl = 0;
	initCtrlSetting.SenseUpMode = 0;
	initCtrlSetting.AEReferenceLevel = 1;
	initCtrlSetting.ExposureMode = 0;
	initCtrlSetting.AGCLevel = 0;
	initCtrlSetting.MirrorMode = 0;
	initCtrlSetting.MainsFrequency = 0;
	initCtrlSetting.BacklightCompensation = 0;
	initCtrlSetting.CameraMode = 0;
	initCtrlSetting.SHUTLevel = 0;

	// get current Value
	getExtControlValue(1, &initCtrlSetting.ShutterControl);
	initCtrlSetting.ShutterControl = (initCtrlSetting.ShutterControl & 0x70) >> 4;
	//getExtControlValue(2, &initCtrlSetting.SenseUpMode); //not be used in 5MP
	getExtControlValue(11, &initCtrlSetting.AEReferenceLevel);
	getExtControlValue(12, &initCtrlSetting.SHUTLevel);

	getExt2ControlValues(10, &initCtrlSetting.ExposureMode, &initCtrlSetting.AGCLevel);
	//getExtControlValue(3, &initCtrlSetting.MirrorMode); //move to gamma... menu
	//getExtControlValue(13, &initCtrlSetting.CameraMode);
	//initCtrlSetting.CameraMode = 0;
	getExtControlValue(18, &initCtrlSetting.BLCWeightFactor);
	getExtControlValue(19, &initCtrlSetting.BLCGrid);
	getExtControlValue(20, &initCtrlSetting.AEHyster);
	getExtControlValue(21, &initCtrlSetting.AECtrlSpeed);
	initCtrlSetting.shutterEnable = initCtrlSetting.AECtrlSpeed & 0x08; //the input has 4-bit available: bit3:0. the bit3 is for shutter enable.
	initCtrlSetting.shutterEnable_bak = initCtrlSetting.shutterEnable;
	initCtrlSetting.AECtrlSpeed &= 0x07;
	initCtrlSetting.AECtrlSpeed_bak = initCtrlSetting.AECtrlSpeed;

	getExtControlValue(28, &initCtrlSetting.AGCMaxLvl);

	//getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_POWERLINE_FREQUENCY, &currValue, &lCaps); //move to gamma... menu
	//initCtrlSetting.MainsFrequency = currValue;
	//currValue = 0;
	getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_BACKLIGHT_COMPENSATION, &currValue, &lCaps);
#if 0	
	/* check the res */
	AM_MEDIA_TYPE *pmt;
	gcap.pVSC->GetFormat(&pmt);

	if ((pmt->lSampleSize == 4147200) || (pmt->lSampleSize == 1036800)) //1080p
	{
		switch (currValue)
		{
		case 0:
			setV = 1;
			break;
		case 1:
			setV = 3;
			break;
		case 2:
			setV = 2;
			break;
		case 3:
			setV = 0;
			break;
		}
	}
	else{ //720p
		switch (currValue)
		{
		case 0:
			setV = 0;
			break;
		case 1:
			setV = 1;
			break;
		}

	}

#endif	
	initCtrlSetting.BacklightCompensation = 0x01&currValue; // BLC Mode: 1-enable; 0-disable;

	// TODO:  Add extra initialization here

	//return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
#endif


void VIS5mpBWExp::OnCbnSelchangeComboExposureMode()
{
	HRESULT hr = S_OK;
	CButton *shutCheck;

	try
	{
		//HWND hListExpoMode =GetDlgItem(hwnd, IDC_COMBO_EXPOSURE_MODE);

		int sel = c_ExpMode.GetCurSel();
		//HWND hListBackLight = GetDlgItem(hwnd, IDC_COMBO_BACK_LIGHT); -- c_BLKCompCtrl
		//HWND hListSldAGCLVL = GetDlgItem(hwnd, IDC_SLD_AGC_LVL); -- c_sldGainCtrl
		//HWND hListComboShutCtrl = GetDlgItem(hwnd, IDC_COMBO_SHUT_CONTL); -- c_ShutCtrl
		//HWND hListSldShutLVL = GetDlgItem(hwnd, IDC_SLD_SHUT_LVL); -- c_sldShuLvl
		//HWND hListSldBLCWLvl = GetDlgItem(hwnd, IDC_SLD_BLCWLvl); --  c_sldBLKWgtCtrl
		//HWND hListSldHPos = GetDlgItem(hwnd, IDC_SLD_HPos); -- c_sldHPosCtrl
		//HWND hListSldHSize = GetDlgItem(hwnd, IDC_SLD_HSize); -- c_sldHSizeCtrl
		//HWND hListSldVPos = GetDlgItem(hwnd, IDC_SLD_VPos); -- c_sldVPosCtrl
		//HWND hListSldVSize = GetDlgItem(hwnd, IDC_SLD_VSize); -- c_sldVSizeCtrl
		//HWND hListFineShutEnb = GetDlgItem(hwnd, IDC_FINE_SHUTTER_ENABLE); -- c_FineShuChk
		switch (sel)
		{
		case 0:
			c_BLKCompCtrl.EnableWindow(TRUE);
			c_sldGainCtrl.EnableWindow(FALSE);
			c_ShutCtrl.EnableWindow(FALSE);
			c_sldShuLvl.EnableWindow(FALSE);
			c_FineShuChk.EnableWindow(FALSE);
			break;
		case 1:
			c_sldGainCtrl.EnableWindow(FALSE);
			c_FineShuChk.EnableWindow(TRUE);
			
			if (c_FineShuChk.GetCheck() == BST_CHECKED){
				c_ShutCtrl.EnableWindow(FALSE);
				c_sldShuLvl.EnableWindow(TRUE);
				initCtrlSetting.shutterEnable = 8;
			}
			else{
				c_ShutCtrl.EnableWindow(TRUE);
				c_sldShuLvl.EnableWindow(FALSE);
				initCtrlSetting.shutterEnable = 0;
			}

			//EnableWindow(hListComboShutCtrl, TRUE);
			//EnableWindow(hListSldShutLVL, TRUE);

			c_BLKCompCtrl.EnableWindow(TRUE);
			break;
		case 2:
			c_BLKCompCtrl.EnableWindow(TRUE);
			c_sldGainCtrl.EnableWindow(TRUE);
			c_ShutCtrl.EnableWindow(FALSE);
			c_sldShuLvl.EnableWindow(FALSE);
			c_FineShuChk.EnableWindow(FALSE);
			break;
		case 3:
			c_sldGainCtrl.EnableWindow(TRUE);
			c_FineShuChk.EnableWindow(TRUE);

			if (c_FineShuChk.GetCheck() == BST_CHECKED){
				c_ShutCtrl.EnableWindow(FALSE);
				c_sldShuLvl.EnableWindow(TRUE);
				initCtrlSetting.shutterEnable = 8;
			}
			else{
				c_ShutCtrl.EnableWindow(TRUE);
				c_sldShuLvl.EnableWindow(FALSE);
				initCtrlSetting.shutterEnable = 0;
			}

			//EnableWindow(hListComboShutCtrl, TRUE);
			//EnableWindow(hListSldShutLVL, TRUE);

			c_BLKCompCtrl.EnableWindow(FALSE);
//			ksNodeTree.pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_BACKLIGHT_COMPENSATION, (long)0, VideoProcAmp_Flags_Manual); // TODO: need a helper function to call --wcheng
//			camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_BACKLIGHT_COMPENSATION, (long)0, VideoProcAmp_Flags_Manual); // TODO: need a helper function to call --wcheng

			/* check the res */
			//AM_MEDIA_TYPE *pmt;
			//gcap.pVSC->GetFormat(&pmt);
			//if (initCtrlSetting.BacklightCompensation == 0)
			//{
			c_sldBLKWgtCtrl.EnableWindow(FALSE);
			c_sldHPosCtrl.EnableWindow(FALSE);
			c_sldHSizeCtrl.EnableWindow(FALSE);
			c_sldVPosCtrl.EnableWindow(FALSE);
			c_sldVSizeCtrl.EnableWindow(FALSE);

			//}

			break;
		default:
			break;
		}
		/*
		if (sel == 0)
		{
		HWND hListSldAGCLVL = GetDlgItem(hwnd, IDC_SLD_AGC_LVL);
		EnableWindow(hListSldAGCLVL, FALSE);
		//HWND hListAGCLVL = GetDlgItem(hwnd, IDC_EDIT_AGC_LVL);
		//EnableWindow(hListAGCLVL, FALSE);
		}
		else
		{
		HWND hListSldAGCLVL = GetDlgItem(hwnd, IDC_SLD_AGC_LVL);
		EnableWindow(hListSldAGCLVL, TRUE);
		//HWND hListAGCLVL = GetDlgItem(hwnd, IDC_EDIT_AGC_LVL);
		//EnableWindow(hListAGCLVL, TRUE);
		}
		*/
		if (sel != LB_ERR && camNodeTree->isOK)
		{

			ULONG ulSize;
			BYTE *pbPropertyValue;
			int PropertId = 10;

			hr = getExtionControlPropertySize(PropertId, &ulSize);
			if (FAILED(hr) || (ulSize != 4)) // first two byte Exposure Mode & last two byte AGC level mast be 4 byte
			{
#ifdef DEBUG
//				sprintf(logMessage, "\nERROR \t Function : OnExposureModeChange \t Msg : Unable to find property size : %x", hr);
//				printLogMessage(logMessage);
#endif
			}
			else
			{
				pbPropertyValue = new BYTE[ulSize];
				if (!pbPropertyValue)
				{
#ifdef DEBUG
//					sprintf(logMessage, "\nERROR \t Function : OnExposureModeChange \t Msg : Unable to allocate memory for property value");
//					printLogMessage(logMessage);
#endif
				}
				else
				{
					long agcSldPos = 0;
					CString strPos;
					//HWND hListSldAGCLVL = GetDlgItem(hwnd, IDC_SLD_AGC_LVL);
					agcSldPos = (long)SendMessageA(c_sldGainCtrl, TBM_GETPOS, TRUE, agcSldPos);

					int ExposureByte = 2;
					int AgcLvlByte = 2;
					//if (c_FineShuChk.GetCheck() == BST_CHECKED){
						//sel |= 0x80;
					//}
					memcpy(&pbPropertyValue[0], (char*)&sel, ExposureByte); // first two byte Exposure Mode & last two byte AGC level
					memcpy(&pbPropertyValue[ExposureByte], (char*)&agcSldPos, AgcLvlByte); // first two byte Exposure Mode & last two byte AGC level

					hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
				}
				delete[] pbPropertyValue;
			}

#ifdef DEBUG
//			sprintf(logMessage, "\nFunction : OnExposureModeChange \t Msg : Return Value:%ld", hr);
//			printLogMessage(logMessage);
#endif
		}

	}
	catch (...)
	{
#ifdef DEBUG
//		sprintf(logMessage, "\nERROR : In Function : OnExposureModeChange");
//		printLogMessage(logMessage);
#endif
	}

}


void VIS5mpBWExp::OnCbnSelchangeComboShutContl()
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	//HWND hListComboShutCtrl = GetDlgItem(hwnd, IDC_COMBO_SHUT_CONTL); -- c_ShutCtrl

	int sel = c_ShutCtrl.GetCurSel();

	if (sel != LB_ERR && camNodeTree->isOK)
	{

		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 1;

		hr = getExtionControlPropertySize(PropertId, &ulSize);
		if (FAILED(hr))
		{
#ifdef DEBUG
//			sprintf(logMessage, "\nFunction : OnShutCtrlChange \t Msg : Unable to find property size : %x", hr);
//			printLogMessage(logMessage);
#endif
		}
		else
		{
			pbPropertyValue = new BYTE[ulSize];
			if (!pbPropertyValue)
			{
#ifdef DEBUG
//				sprintf(logMessage, "\nFunction : OnShutCtrlChange \t Msg : Unable to allocate memory for property value");
//				printLogMessage(logMessage);
#endif
			}
			else
			{
				memcpy(pbPropertyValue, (char*)&sel, ulSize);
				hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
			}
			delete[] pbPropertyValue;
		}

#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : OnShutCtrlChange \t Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}
}


void VIS5mpBWExp::OnBnClickedFineShutterEnable()
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long ExCtrlSpdSldPos = 0;
	CString strPos;

	if (c_FineShuChk.GetCheck() == BST_CHECKED){
		c_ShutCtrl.EnableWindow(FALSE);
		c_sldShuLvl.EnableWindow(TRUE);
		initCtrlSetting.shutterEnable = 8;
	}
	else{
		c_ShutCtrl.EnableWindow(TRUE);
		c_sldShuLvl.EnableWindow(FALSE);
		initCtrlSetting.shutterEnable = 0;
	}
	ExCtrlSpdSldPos = initCtrlSetting.shutterEnable | initCtrlSetting.AECtrlSpeed;
	if (camNodeTree->isOK)
	{
		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 21;

		hr = getExtionControlPropertySize(PropertId, &ulSize);
		if (FAILED(hr) || (ulSize != 2)) // first two byte Exposure Mode & last two byte AGC level mast be 4 byte
		{
#ifdef DEBUG
			//			sprintf(logMessage, "\nERROR \t Function : onAgcLvlChange \t Msg : Unable to find property size : %x", hr);
			//			printLogMessage(logMessage);
#endif
		}
		else
		{
			pbPropertyValue = new BYTE[ulSize];
			if (!pbPropertyValue)
			{
#ifdef DEBUG
				//				sprintf(logMessage, "\nERROR \t Function : onAgcLvlChange \t Msg : Unable to allocate memory for property value");
				//				printLogMessage(logMessage);
#endif
			}
			else
			{
				//int ExposureByte = 2;
				int ShutLvlByte = 2;
				//memcpy(&pbPropertyValue[0], (char*)&sel, ExposureByte); // first two byte Exposure Mode & last two byte AGC level
				memcpy(&pbPropertyValue[0], (char*)&ExCtrlSpdSldPos, ShutLvlByte); // two byte SHUT level

				hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
			}
			delete[] pbPropertyValue;
		}

#ifdef DEBUG
		//		sprintf(logMessage, "\nFunction : onAgcLvlChange \t Msg : Return Value:%ld", hr);
		//		printLogMessage(logMessage);
#endif
	}

	//OnCbnSelchangeComboExposureMode();
}


//void VIS5mpBWExp::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
//{
//	// TODO: Add your message handler code here and/or call default
//	/* the fine shutter slider */
//	int CurVal = c_sldShuLvl.GetPos();
//	/* the gain shutter slider */
//	c_sldGainCtrl;
//	/* the AE reference slider */
//	c_sldAERefLvl;
//	/* the AE Hysterses slilder*/
//	c_sldAEHystCtrl;
//	/* the AE speed slider */
//	c_sldSpedCtrl;
//	/* the BLK compensation factor slider */
//	c_sldBLKWgtCtrl;
//	/* the H-position slider */
//	c_sldHPosCtrl;
//	/* the V-position slider */
//	c_sldVPosCtrl;
//	/* the H-size slider */
//	c_sldHSizeCtrl;
//	/* the V-size slider */
//	c_sldVSizeCtrl;
//
//
//
//	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
//}

/* the slider settings */
#if 0
void VIS5mpBWExp::SetSliderLvl(CSliderCtrl c_sliderCtrl, CEdit c_editCtrl, int properId)
{
	HRESULT hr = S_OK;
	long ExCtrlSpdSldPos = 0;
	CString strPos;
	//HWND hSLDAeCtrlspdLVL = GetDlgItem(hwnd, IDC_SLD_AE_CTRLSPEED);
	ExCtrlSpdSldPos = (long)SendMessageA(c_sliderCtrl, TBM_GETPOS, TRUE, ExCtrlSpdSldPos);

	//HWND hListExpoMode = GetDlgItem(hwnd, IDC_COMBO_EXPOSURE_MODE);
	//int sel = ComboBox_GetCurSel(hListExpoMode);

	//HWND hEditCtrlSpdLVL = GetDlgItem(hwnd, IDC_EDIT_AE_CTRLSPEED);
	strPos.Format(L"%ld", ExCtrlSpdSldPos);
	Edit_SetText(hEditCtrlSpdLVL, strPos);

	if (camNodeTree->isOK)
	{
		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 21;

		hr = getExtionControlPropertySize(PropertId, &ulSize);
		if (FAILED(hr) || (ulSize != 2)) // The length of EX control speed level must be 2 bytes
		{
	#ifdef DEBUG
			sprintf(logMessage, "\nERROR \t Function : onAgcLvlChange \t Msg : Unable to find property size : %x", hr);
			printLogMessage(logMessage);
	#endif
		}
		else
		{
			pbPropertyValue = new BYTE[ulSize];
			if (!pbPropertyValue)
			{
	#ifdef DEBUG
				sprintf(logMessage, "\nERROR \t Function : onAgcLvlChange \t Msg : Unable to allocate memory for property value");
				printLogMessage(logMessage);
	#endif
			}
			else
			{
				//int ExposureByte = 2;
				int ExCtrlSpdLvlByte = 2;
				//memcpy(&pbPropertyValue[0], (char*)&sel, ExposureByte); // first two byte Exposure Mode & last two byte AGC level
				memcpy(&pbPropertyValue[0], (char*)&ExCtrlSpdSldPos, ExCtrlSpdLvlByte); // first two byte Exposure Mode & last two byte AGC level

				hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
			}
			delete[] pbPropertyValue;
		}
	}


	#ifdef DEBUG
		sprintf(logMessage, "\nFunction : onAgcLvlChange \t Msg : Return Value:%ld", hr);
		printLogMessage(logMessage);
	#endif
}
#endif

void VIS5mpBWExp::OnNMReleasedcaptureSldShutLvl(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long shutSldPos = 0;
	CString strPos;
	//HWND hListSldSHUTLVL = GetDlgItem(hwnd, IDC_SLD_SHUT_LVL);
	shutSldPos = (long)SendMessageA(c_sldShuLvl, TBM_GETPOS, TRUE, shutSldPos);

	//HWND hListExpoMode = GetDlgItem(hwnd, IDC_COMBO_EXPOSURE_MODE);
	int sel = c_ExpMode.GetCurSel();

	//HWND hListSHUTLVL = GetDlgItem(hwnd, IDC_EDIT_SHUT_LVL);
	strPos.Format(L"%ld", shutSldPos);
	tx_edtShuLvl.SetSel(0, -1);
	tx_edtShuLvl.Clear();
	tx_edtShuLvl.ReplaceSel(strPos, TRUE);

	if (camNodeTree->isOK && (sel > 0))
	{
		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 12;

		hr = getExtionControlPropertySize(PropertId, &ulSize);
		if (FAILED(hr) || (ulSize != 2)) // first two byte Exposure Mode & last two byte AGC level mast be 4 byte
		{
#ifdef DEBUG
//			sprintf(logMessage, "\nERROR \t Function : onAgcLvlChange \t Msg : Unable to find property size : %x", hr);
//			printLogMessage(logMessage);
#endif
		}
		else
		{
			pbPropertyValue = new BYTE[ulSize];
			if (!pbPropertyValue)
			{
#ifdef DEBUG
//				sprintf(logMessage, "\nERROR \t Function : onAgcLvlChange \t Msg : Unable to allocate memory for property value");
//				printLogMessage(logMessage);
#endif
			}
			else
			{
				//int ExposureByte = 2;
				int ShutLvlByte = 2;
				//memcpy(&pbPropertyValue[0], (char*)&sel, ExposureByte); // first two byte Exposure Mode & last two byte AGC level
				memcpy(&pbPropertyValue[0], (char*)&shutSldPos, ShutLvlByte); // two byte SHUT level

				hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
			}
			delete[] pbPropertyValue;
		}

#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : onAgcLvlChange \t Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}

	*pResult = 0;
}


void VIS5mpBWExp::OnNMReleasedcaptureSldAeCtrlspeed(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long ExCtrlSpdSldPos = 0;
	CString strPos;
	//HWND hSLDAeCtrlspdLVL = GetDlgItem(hwnd, IDC_SLD_AE_CTRLSPEED);
	ExCtrlSpdSldPos = (long)SendMessageA(c_sldSpedCtrl, TBM_GETPOS, TRUE, ExCtrlSpdSldPos);
	initCtrlSetting.AECtrlSpeed = (int)ExCtrlSpdSldPos;

	//HWND hListExpoMode = GetDlgItem(hwnd, IDC_COMBO_EXPOSURE_MODE);
	//int sel = ComboBox_GetCurSel(hListExpoMode);

	//HWND hEditCtrlSpdLVL = GetDlgItem(hwnd, IDC_EDIT_AE_CTRLSPEED);
	strPos.Format(L"%ld", ExCtrlSpdSldPos);
	tx_edtSpedCtrl.SetSel(0, -1);
	tx_edtSpedCtrl.Clear();
	tx_edtSpedCtrl.ReplaceSel(strPos, TRUE);
	ExCtrlSpdSldPos |= initCtrlSetting.shutterEnable;

	if (camNodeTree->isOK)
	{
		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 21;

		hr = getExtionControlPropertySize(PropertId, &ulSize);
		if (FAILED(hr) || (ulSize != 2)) // The length of EX control speed level must be 2 bytes
		{
#ifdef DEBUG
//			sprintf(logMessage, "\nERROR \t Function : onAgcLvlChange \t Msg : Unable to find property size : %x", hr);
//			printLogMessage(logMessage);
#endif
		}
		else
		{
			pbPropertyValue = new BYTE[ulSize];
			if (!pbPropertyValue)
			{
#ifdef DEBUG
//				sprintf(logMessage, "\nERROR \t Function : onAgcLvlChange \t Msg : Unable to allocate memory for property value");
//				printLogMessage(logMessage);
#endif
			}
			else
			{
				//int ExposureByte = 2;
				int ExCtrlSpdLvlByte = 2;
				//memcpy(&pbPropertyValue[0], (char*)&sel, ExposureByte); // first two byte Exposure Mode & last two byte AGC level
				memcpy(&pbPropertyValue[0], (char*)&ExCtrlSpdSldPos, ExCtrlSpdLvlByte); // first two byte Exposure Mode & last two byte AGC level

				hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
			}
			delete[] pbPropertyValue;
		}

#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : onAgcLvlChange \t Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}

	*pResult = 0;
}


void VIS5mpBWExp::OnNMReleasedcaptureSldAgcLvl(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here

	HRESULT hr = S_OK;
	long agcSldPos = 0;
	CString strPos;
	//HWND hListSldAGCLVL = GetDlgItem(hwnd, IDC_SLD_AGC_LVL);
	agcSldPos = (long)SendMessageA(c_sldGainCtrl, TBM_GETPOS, TRUE, agcSldPos);

	//HWND hListExpoMode = GetDlgItem(hwnd, IDC_COMBO_EXPOSURE_MODE);
	int sel = c_ExpMode.GetCurSel();

	//HWND hListAGCLVL = GetDlgItem(hwnd, IDC_EDIT_AGC_LVL);
	strPos.Format(L"%ld", agcSldPos);
	tx_edtGainCtrl.SetSel(0, -1);
	tx_edtGainCtrl.Clear();
	tx_edtGainCtrl.ReplaceSel(strPos, TRUE);

	if (camNodeTree->isOK && (sel > 0))
	{
		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 10;

		hr = getExtionControlPropertySize(PropertId, &ulSize);
		if (FAILED(hr) || (ulSize != 4)) // first two byte Exposure Mode & last two byte AGC level mast be 4 byte
		{
#ifdef DEBUG
//			sprintf(logMessage, "\nERROR \t Function : onAgcLvlChange \t Msg : Unable to find property size : %x", hr);
//			printLogMessage(logMessage);
#endif
		}
		else
		{
			pbPropertyValue = new BYTE[ulSize];
			if (!pbPropertyValue)
			{
#ifdef DEBUG
//				sprintf(logMessage, "\nERROR \t Function : onAgcLvlChange \t Msg : Unable to allocate memory for property value");
//				printLogMessage(logMessage);
#endif
			}
			else
			{
				int ExposureByte = 2;
				int AgcLvlByte = 2;
				memcpy(&pbPropertyValue[0], (char*)&sel, ExposureByte); // first two byte Exposure Mode & last two byte AGC level
				memcpy(&pbPropertyValue[ExposureByte], (char*)&agcSldPos, AgcLvlByte); // first two byte Exposure Mode & last two byte AGC level

				hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
			}
			delete[] pbPropertyValue;
		}

#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : onAgcLvlChange \t Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}

	*pResult = 0;
}


void VIS5mpBWExp::OnNMReleasedcaptureSldAeRefLvl(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;

	try
	{
		long arSldPos = 0;
		CString strPos;
//		HWND hListSldAELVL = GetDlgItem(hwnd, IDC_SLD_AE_REF_LVL);
		arSldPos = (long)SendMessageA(c_sldAERefLvl, TBM_GETPOS, TRUE, arSldPos);

		//HWND hListAELVL = GetDlgItem(hwnd, IDC_EDIT_AE_REF_LVL);
		strPos.Format(L"%ld", arSldPos);
		tx_edtAERefLvl.SetSel(0, -1);
		tx_edtAERefLvl.Clear();
		tx_edtAERefLvl.ReplaceSel(strPos, TRUE);

		if (camNodeTree->isOK)
		{
			ULONG ulSize;
			BYTE *pbPropertyValue;
			int PropertId = 11;

			hr = getExtionControlPropertySize(PropertId, &ulSize);
			if (FAILED(hr))
			{
#ifdef DEBUG
//				sprintf(logMessage, "\nERROR \t Function : onAEReferenceLevelChange \t Msg : Unable to find property size : %x", hr);
//				printLogMessage(logMessage);
#endif
			}
			else
			{
				pbPropertyValue = new BYTE[ulSize];
				if (!pbPropertyValue)
				{
#ifdef DEBUG
//					sprintf(logMessage, "\nERROR \t Function : onAEReferenceLevelChange \t Msg : Unable to allocate memory for property value");
//					printLogMessage(logMessage);
#endif
				}
				else
				{
					memcpy(pbPropertyValue, (char*)&arSldPos, ulSize);
					hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
				}
				delete[] pbPropertyValue;
			}

#ifdef DEBUG
//			sprintf(logMessage, "\nERROR \t Function : onAEReferenceLevelChange \t Msg : Return Value:%ld", hr);
//			printLogMessage(logMessage);
#endif
		}

	}
	catch (...)
	{
#ifdef DEBUG
//		sprintf(logMessage, "\nERROR : In Function : onAEReferenceLevelChange");
//		printLogMessage(logMessage);
#endif
	}

	*pResult = 0;
}


void VIS5mpBWExp::OnNMReleasedcaptureSldAeHyster(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long ExHystSldPos = 0;
	CString strPos;
	//HWND hSLDHystLvl = GetDlgItem(hwnd, IDC_SLD_AE_HYSTER);
	ExHystSldPos = (long)SendMessageA(c_sldAEHystCtrl, TBM_GETPOS, TRUE, ExHystSldPos);

	//HWND hListExpoMode = GetDlgItem(hwnd, IDC_COMBO_EXPOSURE_MODE);
	//int sel = ComboBox_GetCurSel(hListExpoMode);

//	HWND hEditHystLVL = GetDlgItem(hwnd, IDC_EDIT_AE_HYSTER);
	strPos.Format(L"%ld", ExHystSldPos);
	tx_edtAEHystCtrl.SetSel(0, -1);
	tx_edtAEHystCtrl.Clear();
	tx_edtAEHystCtrl.ReplaceSel(strPos, TRUE);

	if (camNodeTree->isOK)
	{
		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 20;

		hr = getExtionControlPropertySize(PropertId, &ulSize);
		if (FAILED(hr) || (ulSize != 2)) // 2 bytes value
		{
#ifdef DEBUG
//			sprintf(logMessage, "\nERROR \t Function : onAgcLvlChange \t Msg : Unable to find property size : %x", hr);
//			printLogMessage(logMessage);
#endif
		}
		else
		{
			pbPropertyValue = new BYTE[ulSize];
			if (!pbPropertyValue)
			{
#ifdef DEBUG
//				sprintf(logMessage, "\nERROR \t Function : onAgcLvlChange \t Msg : Unable to allocate memory for property value");
//				printLogMessage(logMessage);
#endif
			}
			else
			{
				//int ExposureByte = 2;
				int HystLvlByte = 2;
				//memcpy(&pbPropertyValue[0], (char*)&sel, ExposureByte); // first two byte Exposure Mode & last two byte AGC level
				memcpy(&pbPropertyValue[0], (char*)&ExHystSldPos, HystLvlByte); //

				hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
			}
			delete[] pbPropertyValue;
		}

#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : onAgcLvlChange \t Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}

	*pResult = 0;
}


void VIS5mpBWExp::OnNMReleasedcaptureSldBlcwlvl(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long BLCWSldLvl = 0;
	CString strLvl;
	//HWND hListSldBLCWLvl = GetDlgItem(hwnd, IDC_SLD_BLCWLvl);
	BLCWSldLvl = (long)SendMessageA(c_sldBLKWgtCtrl, TBM_GETPOS, TRUE, BLCWSldLvl);

	//HWND hListExpoMode = GetDlgItem(hwnd, IDC_COMBO_EXPOSURE_MODE);
	//int sel = ComboBox_GetCurSel(hListExpoMode);

	//HWND hListBLCW = GetDlgItem(hwnd, IDC_EDIT_BLCWLvl);
	strLvl.Format(L"%ld", BLCWSldLvl);
	tx_edtBLKWgtCtrl.SetSel(0, -1);
	tx_edtBLKWgtCtrl.Clear();
	tx_edtBLKWgtCtrl.ReplaceSel(strLvl, TRUE);

	if (camNodeTree->isOK /*&& (sel > 0)*/)
	{
		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 18;

		hr = getExtionControlPropertySize(PropertId, &ulSize);
		if (FAILED(hr) || (ulSize != 2)) // first two byte Exposure Mode & last two byte AGC level mast be 4 byte
		{
#ifdef DEBUG
//			sprintf(logMessage, "\nERROR \t Function : onAgcLvlChange \t Msg : Unable to find property size : %x", hr);
//			printLogMessage(logMessage);
#endif
		}
		else
		{
			pbPropertyValue = new BYTE[ulSize];
			if (!pbPropertyValue)
			{
#ifdef DEBUG
//				sprintf(logMessage, "\nERROR \t Function : onAgcLvlChange \t Msg : Unable to allocate memory for property value");
//				printLogMessage(logMessage);
#endif
			}
			else
			{
				//int ExposureByte = 2;
				int BLCWByte = 2;
				//memcpy(&pbPropertyValue[0], (char*)&sel, ExposureByte); // first two byte Exposure Mode & last two byte AGC level
				memcpy(&pbPropertyValue[0], (char*)&BLCWSldLvl, BLCWByte); // two byte BLC Weight Factor level

				hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
			}
			delete[] pbPropertyValue;
		}

#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : onAgcLvlChange \t Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}

	*pResult = 0;
}


void VIS5mpBWExp::BLCRangeChange()
{

	HRESULT hr = S_OK;
	unsigned short hpos = 0, hsize = 0, vpos = 0, vsize = 0;
	CString strPos;

	//HWND hListSldHPos = GetDlgItem(hwnd, IDC_SLD_HPos);
	//HWND hListSldHSize = GetDlgItem(hwnd, IDC_SLD_HSize);
	//HWND hListSldVPos = GetDlgItem(hwnd, IDC_SLD_VPos);
	//HWND hListSldVSize = GetDlgItem(hwnd, IDC_SLD_VSize);

	hpos = (unsigned short)SendMessageA(c_sldHPosCtrl, TBM_GETPOS, TRUE, hpos);
	hsize = (unsigned short)SendMessageA(c_sldHSizeCtrl, TBM_GETPOS, TRUE, hsize);
	vpos = (unsigned short)SendMessageA(c_sldVPosCtrl, TBM_GETPOS, TRUE, vpos);
	vsize = (unsigned short)SendMessageA(c_sldVSizeCtrl, TBM_GETPOS, TRUE, vsize);

	//HWND hListEditHPos = GetDlgItem(hwnd, IDC_EDIT_HPos);
	strPos.Format(L"%ld", hpos);
	tx_edtHPosCtrl.SetSel(0, -1);
	tx_edtHPosCtrl.Clear();
	tx_edtHPosCtrl.ReplaceSel(strPos, TRUE);

	//HWND hListEditHSize = GetDlgItem(hwnd, IDC_EDIT_HSize);
	strPos.Format(L"%ld", hsize);
	tx_edtHSizeCtrl.SetSel(0, -1);
	tx_edtHSizeCtrl.Clear();
	tx_edtHSizeCtrl.ReplaceSel(strPos, TRUE);

	//HWND hListEditVPos = GetDlgItem(hwnd, IDC_EDIT_VPos);
	strPos.Format(L"%ld", vpos);
	tx_edtVPosCtrl.SetSel(0, -1);
	tx_edtVPosCtrl.Clear();
	tx_edtVPosCtrl.ReplaceSel(strPos, TRUE);

	//HWND hListEditVSize = GetDlgItem(hwnd, IDC_EDIT_VSize);
	strPos.Format(L"%ld", vsize);
	tx_edtVSizeCtrl.SetSel(0, -1);
	tx_edtVSizeCtrl.Clear();
	tx_edtVSizeCtrl.ReplaceSel(strPos, TRUE);

	if (camNodeTree->isOK)
	{
		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 17;

		hr = getExtionControlPropertySize(PropertId, &ulSize);
		//ulSize = 2;
		if (FAILED(hr) || (ulSize != 2))
		{
#ifdef DEBUG
//			sprintf(logMessage, "\nERROR \t Function : onBLCRangeChange \t Msg : Unable to find property size : %x", hr);
//			printLogMessage(logMessage);
#endif
		}
		else
		{
			pbPropertyValue = new BYTE[ulSize];
			if (!pbPropertyValue)
			{
#ifdef DEBUG
//				sprintf(logMessage, "\nERROR \t Function : onBLCRangeChange \t Msg : Unable to allocate memory for property value");
//				printLogMessage(logMessage);
#endif
			}
			else
			{
				/*
				*vpos = ((*pbPropertyValue) & 0x0F);
				*vsize = ((*pbPropertyValue) >> 4 & 0x0F);
				*hpos = ((*(pbPropertyValue + 1)) & 0x0F);
				*hsize = ((*(pbPropertyValue + 1) >> 4) & 0x0F);
				*/
				/*
				*pbPropertyValue = (*pbPropertyValue & 0x00) | ((vsize & 0x000F) << 4) | (hsize & 0x000F);
				*(pbPropertyValue+1) = (*(pbPropertyValue+1) & 0x00) | ((vpos & 0x000F) << 4) | (hpos & 0x000F);
				*/
				*pbPropertyValue = (*pbPropertyValue & 0x00) | ((vpos & 0x000F) << 4) | (hpos & 0x000F);
				*(pbPropertyValue + 1) = (*(pbPropertyValue + 1) & 0x00) | ((vsize & 0x000F) << 4) | (hsize & 0x000F);
				hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
			}
			delete[] pbPropertyValue;
		}

#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : onBLCRangeChange \t Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}

}

void VIS5mpBWExp::OnNMReleasedcaptureSldHpos(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	BLCRangeChange();
	*pResult = 0;
}


void VIS5mpBWExp::OnNMReleasedcaptureSldVpos(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	BLCRangeChange();
	*pResult = 0;
}


void VIS5mpBWExp::OnNMReleasedcaptureSldHsize(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	BLCRangeChange();
	*pResult = 0;
}


void VIS5mpBWExp::OnNMReleasedcaptureSldVsize(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	BLCRangeChange();
	*pResult = 0;
}


void VIS5mpBWExp::OnCbnSelchangeComboBackLight()
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	//HWND hListBackLight = GetDlgItem(hwnd, IDC_COMBO_BACK_LIGHT);
	int setV = 0;

	int sel = c_BLKCompCtrl.GetCurSel();

	/* check the res */
//	AM_MEDIA_TYPE *pmt;
//	gcap.pVSC->GetFormat(&pmt);

	if (sel != LB_ERR && camNodeTree->isOKpProcAmp)
	{
#ifdef DEBUG
//		sprintf(logMessage, "\nbmRequestType:SET \t bRequest:SET_CUR \t wValue:BacklightCompensation \t wIndex:0x02\t PutValue:%d", sel);
//		printLogMessage(logMessage);
#endif
		if (0 /*&& ((pmt->lSampleSize == 4147200) || (pmt->lSampleSize == 1036800))*/) //1080p
		{
			switch (sel)
			{
			case 0:
				setV = 3;
				break;
			case 1:
				setV = 0;
				break;
			case 2:
				setV = 2;
				break;
			case 3:
				setV = 1;
				break;
			}
		}
		else{ //720p
			switch (sel)
			{
			case 0:
				setV = 0;
				break;
			case 1:
				setV = 1;
				break;
			}

		}
		//HWND hListBLCGrid = GetDlgItem(hwnd, IDC_COMBO_BLC_GRID);
		//HWND hListSldBLCWLvl = GetDlgItem(hwnd, IDC_SLD_BLCWLvl);
		//HWND hListSldHPos = GetDlgItem(hwnd, IDC_SLD_HPos);
		//HWND hListSldHSize = GetDlgItem(hwnd, IDC_SLD_HSize);
		//HWND hListSldVPos = GetDlgItem(hwnd, IDC_SLD_VPos);
		//HWND hListSldVSize = GetDlgItem(hwnd, IDC_SLD_VSize);
		if (setV == 0)
		{
			c_BLKGrid.EnableWindow(FALSE);
			c_sldBLKWgtCtrl.EnableWindow(FALSE);
			c_sldHPosCtrl.EnableWindow(FALSE);
			c_sldHSizeCtrl.EnableWindow(FALSE);
			c_sldVPosCtrl.EnableWindow(FALSE);
			c_sldVSizeCtrl.EnableWindow(FALSE);
		}
		else{
			c_BLKGrid.EnableWindow(TRUE);
			c_sldBLKWgtCtrl.EnableWindow(TRUE);
			c_sldHPosCtrl.EnableWindow(TRUE);
			c_sldHSizeCtrl.EnableWindow(TRUE);
			c_sldVPosCtrl.EnableWindow(TRUE);
			c_sldVSizeCtrl.EnableWindow(TRUE);
		}

		int l_BLCGrid = initCtrlSetting.BLCGrid;
		//setV |= l_BLCGrid << 7;

//		hr = ksNodeTree.pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_BACKLIGHT_COMPENSATION, (long)setV, VideoProcAmp_Flags_Manual); // TODO: need a helper function -- wcheng
		hr = camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_BACKLIGHT_COMPENSATION, (long)setV, VideoProcAmp_Flags_Manual); // TODO: need a helper function -- wcheng
		/*
		if (SUCCEEDED(hr))
		{
			HWND hListCameraMode = GetDlgItem(hwnd, IDC_COMBO_CAM_MODE);
			int retValue = 0;
			getExtControlValue(13, &retValue);
			ComboBox_SetCurSel(hListCameraMode, retValue);
		}
		*/
#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : onBacklightCompensationChange Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}

}


void VIS5mpBWExp::OnCbnSelchangeComboBlcGrid()
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	//HWND hListComboBLCGrid = GetDlgItem(hwnd, IDC_COMBO_BLC_GRID);

	int sel = c_BLKGrid.GetCurSel();

	if (sel != LB_ERR && camNodeTree->isOK)
	{

		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 19;

		hr = getExtionControlPropertySize(PropertId, &ulSize);
		if (FAILED(hr))
		{
#ifdef DEBUG
//			sprintf(logMessage, "\nERROR \t Function : OnBLCGridChange \t Msg : Unable to find property size : %x", hr);
//			printLogMessage(logMessage);
#endif
		}
		else
		{
			pbPropertyValue = new BYTE[ulSize];
			if (!pbPropertyValue)
			{
#ifdef DEBUG
//				sprintf(logMessage, "\nERROR \t Function : OnBLCGridChange \t Msg : Unable to allocate memory for property value");
//				printLogMessage(logMessage);
#endif
			}
			else
			{
				memcpy(pbPropertyValue, (char*)&sel, ulSize);
				hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
			}
			delete[] pbPropertyValue;
		}

#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : OnBLCGridChange \t Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}
}


void VIS5mpBWExp::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class
	//HWND hListComboShutCtrl = GetDlgItem(hwnd, IDC_COMBO_SHUT_CONTL);
	int sel = ComboBox_GetCurSel(c_ShutCtrl);
	int setV = 0, isBLCon = 0;
	if (sel != initCtrlSetting.ShutterControl)
		setExtControls(1, initCtrlSetting.ShutterControl);

#if 0
	HWND hListSenseUpMode = GetDlgItem(hwnd, IDC_COMBO_SEN_UP_MODE);
	sel = ComboBox_GetCurSel(hListSenseUpMode);
	if (sel != initCtrlSetting.SenseUpMode)
		setExtControls(2, initCtrlSetting.SenseUpMode);

	HWND hListComboMirror = GetDlgItem(hwnd, IDC_COMBO_MIRROR_MODE);
	sel = c_Mirror.GetCurSel(hListComboMirror);
	if (sel != initCtrlSetting.MirrorMode)
		setExtControls(3, initCtrlSetting.MirrorMode);

	HWND hListComboCameraMode = GetDlgItem(hwnd, IDC_COMBO_CAM_MODE);
	sel = ComboBox_GetCurSel(hListComboCameraMode);
	if (sel != initCtrlSetting.CameraMode)
		setExtControls(13, initCtrlSetting.CameraMode);
#endif
	//HWND hListSldAELVL = GetDlgItem(hwnd, IDC_SLD_AE_REF_LVL);
	long arSldPos = (long)SendMessageA(c_sldAERefLvl, TBM_GETPOS, TRUE, arSldPos);
	if (arSldPos != initCtrlSetting.AEReferenceLevel)
		setExtControls(11, initCtrlSetting.AEReferenceLevel);

	//HWND hListComboBLCWF = GetDlgItem(hwnd, IDC_COMBO_BLC_WGHT_FACT);
	//sel = c_BLKCompCtrl.GetCurSel();
	int BLKWgCtrlSldPos = (int)SendMessageA(c_sldBLKWgtCtrl, TBM_GETPOS, TRUE, BLKWgCtrlSldPos);
	if (BLKWgCtrlSldPos != initCtrlSetting.BLCWeightFactor)
		setExtControls(18, initCtrlSetting.BLCWeightFactor);

	//HWND hListComboBLCGrid = GetDlgItem(hwnd, IDC_COMBO_BLC_GRID);
	sel = c_BLKGrid.GetCurSel();
	if (sel != initCtrlSetting.BLCGrid)
		setExtControls(19, initCtrlSetting.BLCGrid);


	//HWND hListExpoMode = GetDlgItem(hwnd, IDC_COMBO_EXPOSURE_MODE);
	sel = c_ExpMode.GetCurSel();
	//HWND hListSldAGCLVL = GetDlgItem(hwnd, IDC_SLD_AGC_LVL);
	int agcSldPos = (int)SendMessageA(c_sldGainCtrl, TBM_GETPOS, TRUE, agcSldPos);

	if (sel != initCtrlSetting.ExposureMode || agcSldPos != initCtrlSetting.AGCLevel)
	{
		setExt2ControlValues(10, initCtrlSetting.ExposureMode, initCtrlSetting.AGCLevel);
		if (initCtrlSetting.ExposureMode == 3){
			//HWND hListBackLight = GetDlgItem(hwnd, IDC_COMBO_BACK_LIGHT);
			//ComboBox_SetCurSel(hListBackLight, 0);
			initCtrlSetting.BacklightCompensation = 0;
		}

	}

	//HWND hListSldSHUTLVL = GetDlgItem(hwnd, IDC_SLD_SHUT_LVL);
	int shutSldPos = (int)SendMessageA(c_sldShuLvl, TBM_GETPOS, TRUE, shutSldPos);

	if (shutSldPos != initCtrlSetting.SHUTLevel)
	{
		setExtControls(12, initCtrlSetting.SHUTLevel);
	}

	//HWND hListAGCMaxLVL = GetDlgItem(hwnd, IDC_SLD_AE_MAX_LVL); // for AGC maximum limitation - wcheng
	int gacmaxSldPos = (int)SendMessageA(c_sldAEMaxLvl, TBM_GETPOS, TRUE, gacmaxSldPos);

	if (gacmaxSldPos != initCtrlSetting.AGCMaxLvl)
	{
		setExtControls(28, initCtrlSetting.AGCMaxLvl);
	}

	//HWND hListSldHysteLVL = GetDlgItem(hwnd, IDC_SLD_AE_HYSTER);
	int hysteSldPos = (int)SendMessageA(c_sldAEHystCtrl, TBM_GETPOS, TRUE, hysteSldPos);

	if (hysteSldPos != initCtrlSetting.AEHyster)
	{
		setExtControls(20, initCtrlSetting.AEHyster);
	}

	//HWND hListSldCtrlSpdLVL = GetDlgItem(hwnd, IDC_SLD_AE_CTRLSPEED);
	//int ctrlspdSldPos = (int)SendMessageA(c_sldSpedCtrl, TBM_GETPOS, TRUE, ctrlspdSldPos); //the record is initCtrlSetting.AECtrlSpeed at the moment of changed

	if (initCtrlSetting.AECtrlSpeed != initCtrlSetting.AECtrlSpeed_bak || initCtrlSetting.shutterEnable_bak != initCtrlSetting.shutterEnable)
	{
		setExtControls(21, initCtrlSetting.AECtrlSpeed | initCtrlSetting.shutterEnable_bak);
	}


	if (camNodeTree->isOKpProcAmp)
	{
#if 0		
		HWND hListMainFeq = GetDlgItem(hwnd, IDC_COMBO_MAIN_FEQ);
		sel = ComboBox_GetCurSel(hListMainFeq);
		if (sel != initCtrlSetting.MainsFrequency)
			ksNodeTree.pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_POWERLINE_FREQUENCY, (long)initCtrlSetting.MainsFrequency, VideoProcAmp_Flags_Manual);
#endif
		//HWND hListBackLight = GetDlgItem(hwnd, IDC_COMBO_BACK_LIGHT);
		sel = c_BLKCompCtrl.GetCurSel();
		/* check the res */
		AM_MEDIA_TYPE *pmt;
		devCap->pVSC->GetFormat(&pmt);

		if (0 && ((pmt->lSampleSize == 4147200) || (pmt->lSampleSize == 1036800))) //1080p
		{
			switch (sel)
			{
			case 0:
				setV = 3;
				break;
			case 1:
				setV = 0;
				break;
			case 2:
				setV = 2;
				break;
			case 3:
				setV = 1;
				break;
			}
		}
		else{ //720p
			switch (sel)
			{
			case 0:
				setV = 0;
				break;
			case 1:
				setV = 1;
				break;
			}

		}
		if (setV == 0){
			isBLCon = 0;
		}
		else{
			isBLCon = 1;
		}
		//HWND hListSldBLCWLvl = GetDlgItem(hwnd, IDC_SLD_BLCWLvl);
		//HWND hListSldHPos = GetDlgItem(hwnd, IDC_SLD_HPos);
		//HWND hListSldHSize = GetDlgItem(hwnd, IDC_SLD_HSize);
		//HWND hListSldVPos = GetDlgItem(hwnd, IDC_SLD_VPos);
		//HWND hListSldVSize = GetDlgItem(hwnd, IDC_SLD_VSize);
		if (isBLCon == 0)
		{
			c_sldBLKWgtCtrl.EnableWindow(FALSE);
			c_sldHPosCtrl.EnableWindow(FALSE);
			c_sldHSizeCtrl.EnableWindow(FALSE);
			c_sldVPosCtrl.EnableWindow(FALSE);
			c_sldVSizeCtrl.EnableWindow(FALSE);
		}
		else{
			c_sldBLKWgtCtrl.EnableWindow(TRUE);
			c_sldHPosCtrl.EnableWindow(TRUE);
			c_sldHSizeCtrl.EnableWindow(TRUE);
			c_sldVPosCtrl.EnableWindow(TRUE);
			c_sldVSizeCtrl.EnableWindow(TRUE);
		}

		if (setV != initCtrlSetting.BacklightCompensation){
			camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_BACKLIGHT_COMPENSATION, (long)initCtrlSetting.BacklightCompensation, VideoProcAmp_Flags_Manual);

			/* check the res */
			//AM_MEDIA_TYPE *pmt;
			//gcap.pVSC->GetFormat(&pmt);
			//HWND hListSldBLCWLvl = GetDlgItem(hwnd, IDC_SLD_BLCWLvl);
			//HWND hListSldHPos = GetDlgItem(hwnd, IDC_SLD_HPos);
			//HWND hListSldHSize = GetDlgItem(hwnd, IDC_SLD_HSize);
			//HWND hListSldVPos = GetDlgItem(hwnd, IDC_SLD_VPos);
			//HWND hListSldVSize = GetDlgItem(hwnd, IDC_SLD_VSize);
			if (initCtrlSetting.BacklightCompensation == 0)
			{
				c_sldBLKWgtCtrl.EnableWindow(FALSE);
				c_sldHPosCtrl.EnableWindow(FALSE);
				c_sldHSizeCtrl.EnableWindow(FALSE);
				c_sldVPosCtrl.EnableWindow(FALSE);
				c_sldVSizeCtrl.EnableWindow(FALSE);
			}
			else{
				c_sldBLKWgtCtrl.EnableWindow(TRUE);
				c_sldHPosCtrl.EnableWindow(TRUE);
				c_sldHSizeCtrl.EnableWindow(TRUE);
				c_sldVPosCtrl.EnableWindow(TRUE);
				c_sldVSizeCtrl.EnableWindow(TRUE);
			}

		}
		//ksNodeTree.pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_BACKLIGHT_COMPENSATION, (long)initCtrlSetting.BacklightCompensation, VideoProcAmp_Flags_Manual);

	}
	int hposSldPos = (int)SendMessageA(c_sldHPosCtrl, TBM_GETPOS, TRUE, hposSldPos);
	int vposSldPos = (int)SendMessageA(c_sldVPosCtrl, TBM_GETPOS, TRUE, vposSldPos);
	int hsizeSldPos = (int)SendMessageA(c_sldHSizeCtrl, TBM_GETPOS, TRUE, hsizeSldPos);
	int vizeSldPos = (int)SendMessageA(c_sldVSizeCtrl, TBM_GETPOS, TRUE, vizeSldPos);
	if (hposSldPos != initCtrlSetting.HPos || vposSldPos != initCtrlSetting.VPos ||
		hsizeSldPos != initCtrlSetting.HSize || vizeSldPos != initCtrlSetting.VSize){
		if (camNodeTree->isOK)
		{
			ULONG ulSize;
			BYTE *pbPropertyValue;
			int PropertId = 17;

			HRESULT hr = getExtionControlPropertySize(PropertId, &ulSize);
			//ulSize = 2;
			if (FAILED(hr) || (ulSize != 2))
			{
#ifdef DEBUG
				//			sprintf(logMessage, "\nERROR \t Function : onBLCRangeChange \t Msg : Unable to find property size : %x", hr);
				//			printLogMessage(logMessage);
#endif
			}
			else
			{
				pbPropertyValue = new BYTE[ulSize];
				if (!pbPropertyValue)
				{
#ifdef DEBUG
					//				sprintf(logMessage, "\nERROR \t Function : onBLCRangeChange \t Msg : Unable to allocate memory for property value");
					//				printLogMessage(logMessage);
#endif
				}
				else
				{
					/*
					*vpos = ((*pbPropertyValue) & 0x0F);
					*vsize = ((*pbPropertyValue) >> 4 & 0x0F);
					*hpos = ((*(pbPropertyValue + 1)) & 0x0F);
					*hsize = ((*(pbPropertyValue + 1) >> 4) & 0x0F);
					*/
					/*
					*pbPropertyValue = (*pbPropertyValue & 0x00) | ((vsize & 0x000F) << 4) | (hsize & 0x000F);
					*(pbPropertyValue+1) = (*(pbPropertyValue+1) & 0x00) | ((vpos & 0x000F) << 4) | (hpos & 0x000F);
					*/
					hposSldPos = initCtrlSetting.HPos;
					vposSldPos = initCtrlSetting.VPos;
					hsizeSldPos = initCtrlSetting.HSize;
					vizeSldPos = initCtrlSetting.VSize;
					*pbPropertyValue = (*pbPropertyValue & 0x00) | ((vposSldPos & 0x000F) << 4) | (hposSldPos & 0x000F);
					*(pbPropertyValue + 1) = (*(pbPropertyValue + 1) & 0x00) | ((vizeSldPos & 0x000F) << 4) | (hsizeSldPos & 0x000F);
					hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
				}
				delete[] pbPropertyValue;
			}

#ifdef DEBUG
			//		sprintf(logMessage, "\nFunction : onBLCRangeChange \t Msg : Return Value:%ld", hr);
			//		printLogMessage(logMessage);
#endif
		}

	}

	CDialog::OnCancel();
}


void VIS5mpBWExp::OnNMReleasedcaptureSldAeMaxLvl(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long AGCMaxSldPos = 0;
	CString strPos;
	//HWND hSLDHystLvl = GetDlgItem(hwnd, IDC_SLD_AE_MAX_LVL);
	AGCMaxSldPos = (long)SendMessageA(c_sldAEMaxLvl, TBM_GETPOS, TRUE, AGCMaxSldPos);

	//HWND hListExpoMode = GetDlgItem(hwnd, IDC_COMBO_EXPOSURE_MODE);
	//int sel = ComboBox_GetCurSel(hListExpoMode);

	//HWND hEditGACMaxLVL = GetDlgItem(hwnd, IDC_EDIT_AE_MAX_LVL);
	strPos.Format(L"%ld", AGCMaxSldPos);
	tx_edtAEMaxLvl.SetSel(0, -1);
	tx_edtAEMaxLvl.Clear();
	tx_edtAEMaxLvl.ReplaceSel(strPos, TRUE);

	if (camNodeTree->isOK)
	{
		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 28;

		hr = getExtionControlPropertySize(PropertId, &ulSize);
		if (FAILED(hr) || (ulSize != 2)) // 2 bytes value
		{
#ifdef DEBUG
//			sprintf(logMessage, "\nERROR \t Function : OnhAgcMaxChangeSLD \t Msg : Unable to find property size : %x", hr);
//			printLogMessage(logMessage);
#endif
		}
		else
		{
			pbPropertyValue = new BYTE[ulSize];
			if (!pbPropertyValue)
			{
#ifdef DEBUG
//				sprintf(logMessage, "\nERROR \t Function : OnhAgcMaxChangeSLD \t Msg : Unable to allocate memory for property value");
//				printLogMessage(logMessage);
#endif
			}
			else
			{
				//int ExposureByte = 2;
				int AGCMaxLvlByte = 2;
				//memcpy(&pbPropertyValue[0], (char*)&sel, ExposureByte); // first two byte Exposure Mode & last two byte AGC level
				memcpy(&pbPropertyValue[0], (char*)&AGCMaxSldPos, AGCMaxLvlByte); //

				hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
			}
			delete[] pbPropertyValue;
		}

#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : onAgcLvlChange \t Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}

	*pResult = 0;
}
