// VISImageProc.cpp : implementation file
//

#include "stdafx.h"
#include "VISImageProc.h"
#include "afxdialogex.h"


// VISImageProc dialog

IMPLEMENT_DYNAMIC(VISImageProc, CDialog)

VISImageProc::VISImageProc(CWnd* pParent /*=NULL*/)
	: CDialog(VISImageProc::IDD, pParent)
{

}

VISImageProc::~VISImageProc()
{
}

void VISImageProc::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLD_BRIGHTNESS, c_sldBrightness);
	DDX_Control(pDX, IDC_SLD_CONTRAST, c_sldContrast);
	DDX_Control(pDX, IDC_SLD_HUE, c_sldHue);
	DDX_Control(pDX, IDC_SLD_SATURATION, c_sldSaturation);
	DDX_Control(pDX, IDC_SLD_SHARPNESS, c_sldSharpness);
	DDX_Control(pDX, IDC_SLD_WHTCOM, c_sldWBLBlue);
	DDX_Control(pDX, IDC_SLD_WHTCOM_RED, c_sldWBLRed);
	DDX_Control(pDX, IDC_COMBO_WHTBLCMODE, c_WBLMode);
	DDX_Control(pDX, IDC_EDIT_BRIGHTNESS, txt_edtBrightness);
	DDX_Control(pDX, IDC_EDIT_CONTRAST, txt_edtContrast);
	DDX_Control(pDX, IDC_EDIT_HUE, txt_edtHue);
	DDX_Control(pDX, IDC_EDIT_SATURATION, txt_edtSaturation);
	DDX_Control(pDX, IDC_EDIT_SHARPNESS, txt_edtSharpness);
	DDX_Control(pDX, IDC_EDIT_WHTCOM, txt_edtWBLBlue);
	DDX_Control(pDX, IDC_EDIT_WHTCOM_RED, txt_edtWBLRed);
}


BEGIN_MESSAGE_MAP(VISImageProc, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_WHTBLCMODE, &VISImageProc::OnCbnSelchangeComboWhtblcmode)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_BRIGHTNESS, &VISImageProc::OnNMReleasedcaptureSldBrightness)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_CONTRAST, &VISImageProc::OnNMReleasedcaptureSldContrast)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_HUE, &VISImageProc::OnNMReleasedcaptureSldHue)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_SATURATION, &VISImageProc::OnNMReleasedcaptureSldSaturation)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_SHARPNESS, &VISImageProc::OnNMReleasedcaptureSldSharpness)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_WHTCOM, &VISImageProc::OnNMReleasedcaptureSldWhtcom)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_WHTCOM_RED, &VISImageProc::OnNMReleasedcaptureSldWhtcomRed)
END_MESSAGE_MAP()


// VISImageProc message handlers


BOOL VISImageProc::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	HRESULT hr;
	long lMin, lMax, lStep, lDefault;
	long currValue, lCaps;
	CString currValueStr;

	hr = getStandardControlPropertyRange(KSPROPERTY_VIDEOPROCAMP_BRIGHTNESS, &lMin, &lMax, &lStep, &lDefault, &lCaps);
	//HWND hListSldBrightness = GetDlgItem(hwnd, IDC_SLD_BRIGHTNESS);


	if (!SUCCEEDED(hr))
	{
		c_sldBrightness.EnableWindow(FALSE);
	}

	c_sldBrightness.EnableWindow(TRUE);
	//getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_BRIGHTNESS, &currValue, &lCaps);
	currValue = initCtrlSetting.Brightness;
	SendMessageA(c_sldBrightness, TBM_SETRANGEMAX, TRUE, lMax);
	SendMessageA(c_sldBrightness, TBM_SETRANGEMIN, TRUE, lMin);
	SendMessageA(c_sldBrightness, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sldBrightness, TBM_SETPOS, TRUE, currValue);
	//HWND hListBrightness = GetDlgItem(hwnd, IDC_EDIT_BRIGHTNESS);
	currValueStr.Format(L"%ld", currValue);
	txt_edtBrightness.ReplaceSel(currValueStr, TRUE);
	txt_edtBrightness.EnableWindow(FALSE);


	hr = getStandardControlPropertyRange(KSPROPERTY_VIDEOPROCAMP_CONTRAST, &lMin, &lMax, &lStep, &lDefault, &lCaps);
	//getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_CONTRAST, &currValue, &lCaps);
	currValue = initCtrlSetting.Contrast;
	//HWND hListSldContrast = GetDlgItem(hwnd, IDC_SLD_CONTRAST);
	if (!SUCCEEDED(hr))
	{
		c_sldContrast.EnableWindow(FALSE);
	}
	SendMessageA(c_sldContrast, TBM_SETRANGEMAX, TRUE, lMax);
	SendMessageA(c_sldContrast, TBM_SETRANGEMIN, TRUE, lMin);
	SendMessageA(c_sldContrast, TBM_SETPOS, TRUE, currValue);
	SendMessageA(c_sldContrast, TBM_SETPAGESIZE, TRUE, 1);
	//HWND hListContrast = GetDlgItem(hwnd, IDC_EDIT_CONTRAST);
	currValueStr.Format(L"%ld", currValue);
	txt_edtContrast.ReplaceSel(currValueStr, TRUE);
	txt_edtContrast.EnableWindow(FALSE);

	hr = getStandardControlPropertyRange(KSPROPERTY_VIDEOPROCAMP_HUE, &lMin, &lMax, &lStep, &lDefault, &lCaps);
	//getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_HUE, &currValue, &lCaps);
	currValue = initCtrlSetting.Hue;
	//HWND hListSldHue = GetDlgItem(hwnd, IDC_SLD_HUE);
	if (!SUCCEEDED(hr))
	{
		c_sldHue.EnableWindow(FALSE);
	}
	SendMessageA(c_sldHue, TBM_SETRANGEMAX, TRUE, lMax);
	SendMessageA(c_sldHue, TBM_SETRANGEMIN, TRUE, lMin);
	SendMessageA(c_sldHue, TBM_SETPOS, TRUE, currValue);
	SendMessageA(c_sldHue, TBM_SETPAGESIZE, TRUE, 1);
	//HWND hListHue = GetDlgItem(hwnd, IDC_EDIT_HUE);
	currValueStr.Format(L"%ld", currValue);
	txt_edtHue.ReplaceSel(currValueStr, TRUE);
	txt_edtHue.EnableWindow(FALSE);

	hr = getStandardControlPropertyRange(KSPROPERTY_VIDEOPROCAMP_SATURATION, &lMin, &lMax, &lStep, &lDefault, &lCaps);
	//getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_SATURATION, &currValue, &lCaps);
	currValue = initCtrlSetting.Saturation;
	//HWND hListSldSaturation = GetDlgItem(hwnd, IDC_SLD_SATURATION);
	if (!SUCCEEDED(hr))
	{
		c_sldSaturation.EnableWindow(FALSE);
	}
	SendMessageA(c_sldSaturation, TBM_SETRANGEMAX, TRUE, lMax);
	SendMessageA(c_sldSaturation, TBM_SETRANGEMIN, TRUE, lMin);
	SendMessageA(c_sldSaturation, TBM_SETPOS, TRUE, currValue);
	SendMessageA(c_sldSaturation, TBM_SETPAGESIZE, TRUE, 1);
	//HWND hListSaturation = GetDlgItem(hwnd, IDC_EDIT_SATURATION);
	currValueStr.Format(L"%ld", currValue);
	txt_edtSaturation.ReplaceSel(currValueStr, TRUE);
	txt_edtSaturation.EnableWindow(FALSE);

	hr = getStandardControlPropertyRange(KSPROPERTY_VIDEOPROCAMP_SHARPNESS, &lMin, &lMax, &lStep, &lDefault, &lCaps);
	//getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_SHARPNESS, &currValue, &lCaps);
	currValue = initCtrlSetting.Sharpness;
	//HWND hListSldSharpness = GetDlgItem(hwnd, IDC_SLD_SHARPNESS);
	if (!SUCCEEDED(hr))
	{
		c_sldSharpness.EnableWindow(FALSE);
	}
	SendMessageA(c_sldSharpness, TBM_SETRANGEMAX, TRUE, lMax);
	SendMessageA(c_sldSharpness, TBM_SETRANGEMIN, TRUE, lMin);
	SendMessageA(c_sldSharpness, TBM_SETPOS, TRUE, currValue);
	SendMessageA(c_sldSharpness, TBM_SETPAGESIZE, TRUE, 1);
	//HWND hListSharpness = GetDlgItem(hwnd, IDC_EDIT_SHARPNESS);
	currValueStr.Format(L"%ld", currValue);
	txt_edtSharpness.ReplaceSel(currValueStr, TRUE);
	txt_edtSharpness.EnableWindow(FALSE);

	hr = getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_WHITEBALANCE, &currValue, &lCaps);
	currValue = initCtrlSetting.WhiteBalance;
	//HWND hListWhiteBalanceMode = GetDlgItem(hwnd, IDC_COMBO_WHTBLCMODE);
	if (!SUCCEEDED(hr))
	{
		c_WBLMode.EnableWindow(FALSE);
	}
	if (devCap->CamIndex == CAM2MP_COLOR)
	{
		c_WBLMode.AddString(L"ATW MODE");
		c_WBLMode.AddString(L"AWC SET MODE");
		c_WBLMode.AddString(L"INDOOR MODE");
		c_WBLMode.AddString(L"OUTDOOR MODE");
		c_WBLMode.AddString(L"MANUAL MODE");
		c_WBLMode.AddString(L"PUSH TO WHITE");

	}
	else if (devCap->CamIndex == CAM1D2MP_COLOR)
	{
		c_WBLMode.AddString(L"ATW MODE");
		c_WBLMode.AddString(L"AWC SET MODE");
		c_WBLMode.AddString(L"INDOOR MODE");
		c_WBLMode.AddString(L"OUTDOOR MODE");
		c_WBLMode.AddString(L"MANUAL MODE");
		c_WBLMode.AddString(L"PUSH TO WHITE");

	}
	else if (devCap->CamIndex == CAM5MP_COLOR)
	{
		c_WBLMode.AddString(L"AWB MODE");
		c_WBLMode.AddString(L"ATW MODE");
		c_WBLMode.AddString(L"AWC-set");
		c_WBLMode.AddString(L"MANUAL");
		c_WBLMode.AddString(L"INDOOR");
		c_WBLMode.AddString(L"OUTDOOR");
		//c_WBLMode.AddString(L"PUSH TO WHITE");
	}
	//c_WBLMode.AddString(L"PUSH TO WHITE");
	/*
	*/
	c_WBLMode.SetCurSel(currValue);

	//HWND hListSldWhiteBalanceComp = GetDlgItem(hwnd, IDC_SLD_WHTCOM);
	//HWND hListSldWhiteBalanceCompRed = GetDlgItem(hwnd, IDC_SLD_WHTCOM_RED);
	if ((SUCCEEDED(hr) && (devCap->CamIndex == CAM2MP_COLOR) && currValue == 4)	// if it's manual mode enable red & blue comp
		|| (SUCCEEDED(hr) && (devCap->CamIndex == CAM1D2MP_COLOR) && currValue == 4)
		|| (SUCCEEDED(hr) && (devCap->CamIndex == CAM5MP_COLOR) && currValue == 3))
	{
		c_sldWBLBlue.EnableWindow(TRUE);
		c_sldWBLRed.EnableWindow(TRUE);
	}else{
		c_sldWBLBlue.EnableWindow(FALSE);
		c_sldWBLRed.EnableWindow(FALSE);
	}

	int blueValue = 0;
	int redValue = 0;

	//getWhiteBalanceComponent(&redValue, &blueValue); //&initCtrlSetting.WhiteBalanceComponentRed, &initCtrlSetting.WhiteBalanceComponentBlue
	redValue = initCtrlSetting.WhiteBalanceComponentRed;
	blueValue = initCtrlSetting.WhiteBalanceComponentBlue;
	SendMessageA(c_sldWBLBlue, TBM_SETRANGEMAX, TRUE, lMax);
	SendMessageA(c_sldWBLBlue, TBM_SETRANGEMIN, TRUE, lMin);
	SendMessageA(c_sldWBLBlue, TBM_SETPOS, TRUE, blueValue);
	SendMessageA(c_sldWBLBlue, TBM_SETPAGESIZE, TRUE, 1);

	SendMessageA(c_sldWBLRed, TBM_SETRANGEMAX, TRUE, lMax);
	SendMessageA(c_sldWBLRed, TBM_SETRANGEMIN, TRUE, lMin);
	SendMessageA(c_sldWBLRed, TBM_SETPOS, TRUE, redValue);
	SendMessageA(c_sldWBLRed, TBM_SETPAGESIZE, TRUE, 1);

	//HWND hListWhiteBalanceComp = GetDlgItem(hwnd, IDC_EDIT_WHTCOM);
	currValueStr.Format(L"%d", blueValue);
	txt_edtWBLBlue.ReplaceSel(currValueStr, TRUE);
	txt_edtWBLBlue.EnableWindow(FALSE);
	//HWND hListWhiteBalanceCompRed = GetDlgItem(hwnd, IDC_EDIT_WHTCOM_RED);
	currValueStr.Format(L"%d", redValue);
	txt_edtWBLRed.ReplaceSel(currValueStr, TRUE);
	txt_edtWBLRed.EnableWindow(FALSE);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void VISImageProc::saveImageInitSetting(){
	long currValue, lCaps;

	// reset global struct
	initCtrlSetting.Brightness = 0;
	initCtrlSetting.Sharpness = 0;
	initCtrlSetting.Contrast = 0;
	initCtrlSetting.Saturation = 0;
	initCtrlSetting.Hue = 0;
	initCtrlSetting.WhiteBalance = 0;
	initCtrlSetting.WhiteBalanceComponentRed = 0;
	initCtrlSetting.WhiteBalanceComponentBlue = 0;

	// get current Value
	currValue = 0;
	getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_BRIGHTNESS, &currValue, &lCaps);
	initCtrlSetting.Brightness = currValue;
	currValue = 0;
	getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_SHARPNESS, &currValue, &lCaps);
	initCtrlSetting.Sharpness = currValue;
	currValue = 0;
	getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_SATURATION, &currValue, &lCaps);
	initCtrlSetting.Saturation = currValue;
	currValue = 0;
	getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_CONTRAST, &currValue, &lCaps);
	initCtrlSetting.Contrast = currValue;
	currValue = 0;
	getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_HUE, &currValue, &lCaps);
	initCtrlSetting.Hue = currValue;
	currValue = 0;
	getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_WHITEBALANCE, &currValue, &lCaps);
	initCtrlSetting.WhiteBalance = currValue;

	getWhiteBalanceComponent(&initCtrlSetting.WhiteBalanceComponentRed, &initCtrlSetting.WhiteBalanceComponentBlue);
	initCtrlSetting.WhiteBalanceComponentBlueCur = initCtrlSetting.WhiteBalanceComponentBlue;
	initCtrlSetting.WhiteBalanceComponentRedCur = initCtrlSetting.WhiteBalanceComponentRed;
}


void VISImageProc::OnCbnSelchangeComboWhtblcmode()
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	//HWND hListBackLight = GetDlgItem(hwnd, IDC_COMBO_WHTBLCMODE);

	int sel = c_WBLMode.GetCurSel();

	if (sel != LB_ERR && camNodeTree->isOKpProcAmp)
	{
#ifdef DEBUG
//		sprintf(logMessage, "\nbmRequestType:SET \t bRequest:SET_CUR \t wValue:WhiteBalance \t wIndex:0x02\t PutValue:%d", sel);
//		printLogMessage(logMessage);
#endif
		hr = camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_WHITEBALANCE, (long)sel, VideoProcAmp_Flags_Auto);

		//HWND hListSldWhiteBalanceComp = GetDlgItem(hwnd, IDC_SLD_WHTCOM);
		//HWND hListSldWhiteBalanceCompRed = GetDlgItem(hwnd, IDC_SLD_WHTCOM_RED);
		if ((SUCCEEDED(hr) && (devCap->CamIndex == CAM2MP_COLOR) && sel == 4)	// if it's manual mode enable red & blue comp
			|| (SUCCEEDED(hr) && (devCap->CamIndex == CAM1D2MP_COLOR) && sel == 4)
			|| (SUCCEEDED(hr) && (devCap->CamIndex == CAM5MP_COLOR) && sel == 3))
		{
			c_sldWBLBlue.EnableWindow(TRUE);
			c_sldWBLRed.EnableWindow(TRUE);
		}
		else
		{
			c_sldWBLBlue.EnableWindow(FALSE);
			c_sldWBLRed.EnableWindow(FALSE);
		}

#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : onWhiteBalanceControlChange Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}

	//return hr;
}


void VISImageProc::OnNMReleasedcaptureSldBrightness(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long SldPos = 0;
	CString strPos;
	//HWND hListSldBrightness = GetDlgItem(hwnd, IDC_SLD_BRIGHTNESS);
	SldPos = (long)SendMessageA(c_sldBrightness, TBM_GETPOS, TRUE, SldPos);

	//HWND hListBrightness = GetDlgItem(hwnd, IDC_EDIT_BRIGHTNESS);
	strPos.Format(L"%ld", SldPos);
	txt_edtBrightness.SetSel(0, -1);
	txt_edtBrightness.Clear();
	txt_edtBrightness.ReplaceSel(strPos, TRUE);

	if (camNodeTree->isOKpProcAmp)
	{
#ifdef DEBUG
//		sprintf(logMessage, "\nbmRequestType:SET \t bRequest:SET_CUR \t wValue:Brightness \t wIndex:0x02\t PutValue:%ld", SldPos);
//		printLogMessage(logMessage);
#endif
		hr = camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_BRIGHTNESS, SldPos, VideoProcAmp_Flags_Manual);
#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : onBrightnessChange Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}

	*pResult = 0;
}


void VISImageProc::OnNMReleasedcaptureSldContrast(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long SldPos = 0;
	CString strPos;
	//HWND hListSldContrast = GetDlgItem(hwnd, IDC_SLD_CONTRAST);
	SldPos = (long)SendMessageA(c_sldContrast, TBM_GETPOS, TRUE, SldPos);

	//HWND hListContrast = GetDlgItem(hwnd, IDC_EDIT_CONTRAST);
	strPos.Format(L"%ld", SldPos);
	txt_edtContrast.SetSel(0, -1);
	txt_edtContrast.Clear();
	txt_edtContrast.ReplaceSel(strPos, TRUE);

	if (camNodeTree->isOKpProcAmp)
	{
#ifdef DEBUG
//		sprintf(logMessage, "\nbmRequestType:SET \t bRequest:SET_CUR \t wValue:Contrast \t wIndex:0x02\t PutValue:%ld", SldPos);
//		printLogMessage(logMessage);
#endif
		hr = camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_CONTRAST, SldPos, VideoProcAmp_Flags_Manual);
#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : onContrastChange Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}

	*pResult = 0;
}


void VISImageProc::OnNMReleasedcaptureSldHue(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long SldPos = 0;
	CString strPos;
	//HWND hListSldContrast = GetDlgItem(hwnd, IDC_SLD_CONTRAST);
	SldPos = (long)SendMessageA(c_sldHue, TBM_GETPOS, TRUE, SldPos);

	//HWND hListContrast = GetDlgItem(hwnd, IDC_EDIT_CONTRAST);
	strPos.Format(L"%ld", SldPos);
	txt_edtHue.SetSel(0, -1);
	txt_edtHue.Clear();
	txt_edtHue.ReplaceSel(strPos, TRUE);

	if (camNodeTree->isOKpProcAmp)
	{
#ifdef DEBUG
		//		sprintf(logMessage, "\nbmRequestType:SET \t bRequest:SET_CUR \t wValue:Contrast \t wIndex:0x02\t PutValue:%ld", SldPos);
		//		printLogMessage(logMessage);
#endif
		hr = camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_HUE, SldPos, VideoProcAmp_Flags_Manual);
#ifdef DEBUG
		//		sprintf(logMessage, "\nFunction : onContrastChange Msg : Return Value:%ld", hr);
		//		printLogMessage(logMessage);
#endif
	}

	*pResult = 0;
}


void VISImageProc::OnNMReleasedcaptureSldSaturation(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long SldPos = 0;
	CString strPos;
	//HWND hListSldContrast = GetDlgItem(hwnd, IDC_SLD_CONTRAST);
	SldPos = (long)SendMessageA(c_sldSaturation, TBM_GETPOS, TRUE, SldPos);

	//HWND hListContrast = GetDlgItem(hwnd, IDC_EDIT_CONTRAST);
	strPos.Format(L"%ld", SldPos);
	txt_edtSaturation.SetSel(0, -1);
	txt_edtSaturation.Clear();
	txt_edtSaturation.ReplaceSel(strPos, TRUE);

	if (camNodeTree->isOKpProcAmp)
	{
#ifdef DEBUG
		//		sprintf(logMessage, "\nbmRequestType:SET \t bRequest:SET_CUR \t wValue:Contrast \t wIndex:0x02\t PutValue:%ld", SldPos);
		//		printLogMessage(logMessage);
#endif
		hr = camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_SATURATION, SldPos, VideoProcAmp_Flags_Manual);
#ifdef DEBUG
		//		sprintf(logMessage, "\nFunction : onContrastChange Msg : Return Value:%ld", hr);
		//		printLogMessage(logMessage);
#endif
	}

	*pResult = 0;
}


void VISImageProc::OnNMReleasedcaptureSldSharpness(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long SldPos = 0;
	CString strPos;
	//HWND hListSldSharpness = GetDlgItem(hwnd, IDC_SLD_SHARPNESS);
	SldPos = (long)SendMessageA(c_sldSharpness, TBM_GETPOS, TRUE, SldPos);

	//HWND hListSharpness = GetDlgItem(hwnd, IDC_EDIT_SHARPNESS);
	strPos.Format(L"%ld", SldPos);
	txt_edtSharpness.SetSel(0, -1);
	txt_edtSharpness.Clear();
	txt_edtSharpness.ReplaceSel(strPos, TRUE);

	if (camNodeTree->isOKpProcAmp)
	{
#ifdef DEBUG
//		sprintf(logMessage, "\nbmRequestType:SET \t bRequest:SET_CUR \t wValue:Sharpness \t wIndex:0x02\t PutValue:%ld", SldPos);
//		printLogMessage(logMessage);
#endif
		hr = camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_SHARPNESS, SldPos, VideoProcAmp_Flags_Manual);
#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : onSharpnessChange Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}

	*pResult = 0;
}


void VISImageProc::OnNMReleasedcaptureSldWhtcom(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long SldPos = 0;
	CString strPos;
	//HWND hListSldWhiteBalanceComp = GetDlgItem(hwnd, IDC_SLD_WHTCOM);
	SldPos = (long)SendMessageA(c_sldWBLBlue, TBM_GETPOS, TRUE, SldPos);
	initCtrlSetting.WhiteBalanceComponentBlueCur = SldPos;

	//HWND hListWhiteBalanceComp = GetDlgItem(hwnd, IDC_EDIT_WHTCOM);
	strPos.Format(L"%ld", SldPos);
	txt_edtWBLBlue.SetSel(0, -1);
	txt_edtWBLBlue.Clear();
	txt_edtWBLBlue.ReplaceSel(strPos, TRUE);

	hr = setWhiteBalanceComponent(initCtrlSetting.WhiteBalanceComponentRedCur, SldPos);

#ifdef DEBUG
//	sprintf(logMessage, "\nFunction : onWhiteBalanceCompBlueChange Msg : Return Value:%ld", hr);
//	printLogMessage(logMessage);
#endif
	*pResult = 0;
}


void VISImageProc::OnNMReleasedcaptureSldWhtcomRed(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long SldPosRed = 0;
	CString strPos;

	//HWND hListSldWhiteBalanceCompRed = GetDlgItem(hwnd, IDC_SLD_WHTCOM_RED);
	SldPosRed = (long)SendMessageA(c_sldWBLRed, TBM_GETPOS, TRUE, SldPosRed);
	initCtrlSetting.WhiteBalanceComponentRedCur = SldPosRed;

	//HWND hListWhiteBalanceCompRed = GetDlgItem(hwnd, IDC_EDIT_WHTCOM_RED);
	strPos.Format(L"%ld", SldPosRed);
	txt_edtWBLRed.SetSel(0, -1);
	txt_edtWBLRed.Clear();
	txt_edtWBLRed.ReplaceSel(strPos, TRUE);

	hr = setWhiteBalanceComponent(SldPosRed, initCtrlSetting.WhiteBalanceComponentBlueCur);

#ifdef DEBUG
//	sprintf(logMessage, "\nFunction : onWhiteBalanceCompBlueChange Msg : Return Value:%ld", hr);
//	printLogMessage(logMessage);
#endif
	*pResult = 0;
}


void VISImageProc::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class
	if (camNodeTree->isOKpProcAmp)
	{
		long SldPosRed = 0;
		long SldPos = 0;

		//HWND hListSldBrightness = GetDlgItem(hwnd, IDC_SLD_BRIGHTNESS);
		SldPos = (long)SendMessageA(c_sldBrightness, TBM_GETPOS, TRUE, SldPos);
		if (SldPos != initCtrlSetting.Brightness)
			camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_BRIGHTNESS, (long)initCtrlSetting.Brightness, VideoProcAmp_Flags_Manual);

		//HWND hListSldContrast = GetDlgItem(hwnd, IDC_SLD_CONTRAST);
		SldPos = (long)SendMessageA(c_sldContrast, TBM_GETPOS, TRUE, SldPos);
		if (SldPos != initCtrlSetting.Contrast)
			camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_CONTRAST, (long)initCtrlSetting.Contrast, VideoProcAmp_Flags_Manual);

		//HWND hListSldSharpness = GetDlgItem(hwnd, IDC_SLD_SHARPNESS);
		SldPos = (long)SendMessageA(c_sldSharpness, TBM_GETPOS, TRUE, SldPos);
		if (SldPos != initCtrlSetting.Sharpness)
			camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_SHARPNESS, (long)initCtrlSetting.Sharpness, VideoProcAmp_Flags_Manual);
#if 0
		HWND hListSldSaturation = GetDlgItem(hwnd, IDC_SLD_SATURATION);
		SldPos = (long)SendMessageA(hListSldSaturation, TBM_GETPOS, TRUE, SldPos);
		if (SldPos != initCtrlSetting.Saturation)
			ksNodeTree.pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_SATURATION, (long)initCtrlSetting.Saturation, VideoProcAmp_Flags_Manual);

		HWND hListSldHue = GetDlgItem(hwnd, IDC_SLD_HUE);
		SldPos = (long)SendMessageA(hListSldHue, TBM_GETPOS, TRUE, SldPos);
		if (SldPos != initCtrlSetting.Hue)
			ksNodeTree.pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_HUE, (long)initCtrlSetting.Hue, VideoProcAmp_Flags_Manual);
#endif
		//HWND hListBackLight = GetDlgItem(hwnd, IDC_COMBO_WHTBLCMODE);
		int sel = c_WBLMode.GetCurSel();
		if (sel != initCtrlSetting.WhiteBalance)
			camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_WHITEBALANCE, (long)initCtrlSetting.WhiteBalance, VideoProcAmp_Flags_Manual);
		//ksNodeTree.pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_WHITEBALANCE_COMPONENT, (long)initCtrlSetting.WhiteBalanceComponentControl, VideoProcAmp_Flags_Manual);

		//HWND hListSldWhiteBalanceComp = GetDlgItem(hwnd, IDC_SLD_WHTCOM);
		SldPos = (long)SendMessageA(c_sldWBLBlue, TBM_GETPOS, TRUE, SldPos);
		//HWND hListSldWhiteBalanceCompRed = GetDlgItem(hwnd, IDC_SLD_WHTCOM_RED);
		SldPosRed = (long)SendMessageA(c_sldWBLRed, TBM_GETPOS, TRUE, SldPosRed);
		if (SldPosRed != initCtrlSetting.WhiteBalanceComponentRed || SldPos != initCtrlSetting.WhiteBalanceComponentBlue)
			setWhiteBalanceComponent(initCtrlSetting.WhiteBalanceComponentRed, initCtrlSetting.WhiteBalanceComponentBlue);
	}
	CDialog::OnCancel();
}
