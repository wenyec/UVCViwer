// VIS5MPColSupWBL.cpp : implementation file
//

#include "stdafx.h"
#include "VIS5MPColSupWBL.h"
#include "afxdialogex.h"


// VIS5MPColSupWBL dialog

IMPLEMENT_DYNAMIC(VIS5MPColSupWBL, CDialog)

VIS5MPColSupWBL::VIS5MPColSupWBL(CWnd* pParent /*=NULL*/)
	: CDialog(VIS5MPColSupWBL::IDD, pParent)
{

}

VIS5MPColSupWBL::~VIS5MPColSupWBL()
{
}

void VIS5MPColSupWBL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_WHTBLCMODE2, cb_WBLMode);
	DDX_Control(pDX, IDC_WBL_P2W_ENABL, c_bP2WOn);
	DDX_Control(pDX, IDC_SLD_WHTCOM, c_sldWBLComBlue);
	DDX_Control(pDX, IDC_SLD_WHTCOM_RED, c_sldWBLComRed);
	DDX_Control(pDX, IDC_EDIT_WHTCOM, c_edtWBLComBlue);
	DDX_Control(pDX, IDC_EDIT_WHTCOM_RED, c_edtWBLComRed);
	DDX_Control(pDX, IDC_COLOR_SUPPRESSION_ENABL, c_bColSupEnable);
	DDX_Control(pDX, IDC_SLD_COLSUPP_GAIN_VAL, c_sldColSupGain);
	DDX_Control(pDX, IDC_SLD_COLSUPP_GAINSTR_VAL, c_sldColSupAGCStart);
	DDX_Control(pDX, IDC_SLD_COLSUPP_GAINEND_VAL, c_sldColSupAGCEnd);
	DDX_Control(pDX, IDC_EDIT_COLSUPP_GAIN_VAL, c_edtColSupGain);
	DDX_Control(pDX, IDC_EDIT_COLSUPP_GAINSTR_VAL, c_edtColSupGainStart);
	DDX_Control(pDX, IDC_EDIT_COLSUPP_GAINEND_VAL, c_edtColSupGainEnd);
	DDX_Control(pDX, IDC_SLD_EDGE_COLSUP_GAIN, c_sldColSupEdgeGain);
	DDX_Control(pDX, IDC_SLD_HIGHTLOW_COLSUP_GAIN, c_sldHighLowLightGain);
	DDX_Control(pDX, IDC_EDIT_EDGE_COLSUP_GAIN, c_edtColSupEdgeGain);
	DDX_Control(pDX, IDC_EDIT_HIGHTLOW_COLSUP_GAIN, c_edtHighLowLightGain);
}


BEGIN_MESSAGE_MAP(VIS5MPColSupWBL, CDialog)
	ON_BN_CLICKED(IDC_COLOR_SUPPRESSION_ENABL, &VIS5MPColSupWBL::OnBnClickedColorSuppressionEnabl)
	ON_BN_CLICKED(IDC_WBL_P2W_ENABL, &VIS5MPColSupWBL::OnBnClickedWblP2wEnabl)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_COLSUPP_GAIN_VAL, &VIS5MPColSupWBL::OnNMReleasedcaptureSldColsuppGainVal)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_COLSUPP_GAINEND_VAL, &VIS5MPColSupWBL::OnNMReleasedcaptureSldColsuppGainendVal)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_COLSUPP_GAINSTR_VAL, &VIS5MPColSupWBL::OnNMReleasedcaptureSldColsuppGainstrVal)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_EDGE_COLSUP_GAIN, &VIS5MPColSupWBL::OnNMReleasedcaptureSldEdgeColsupGain)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_HIGHTLOW_COLSUP_GAIN, &VIS5MPColSupWBL::OnNMReleasedcaptureSldHightlowColsupGain)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_WHTCOM, &VIS5MPColSupWBL::OnNMReleasedcaptureSldWhtcom)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_WHTCOM_RED, &VIS5MPColSupWBL::OnNMReleasedcaptureSldWhtcomRed)
	ON_CBN_SELCHANGE(IDC_COMBO_WHTBLCMODE2, &VIS5MPColSupWBL::OnCbnSelchangeComboWhtblcmode2)
END_MESSAGE_MAP()


// VIS5MPColSupWBL message handlers


BOOL VIS5MPColSupWBL::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	HRESULT hr;
	long lMin = 0x0, lMax = 0xFF, lStep, lDefault;
	long currValue, lCaps;
	CString currValueStr;
	
	c_bColSupEnable.SetCheck(BST_CHECKED);

	if (0 && !SUCCEEDED(hr))  // no UVC controls for color suppression gain insteat of I2C - wcheng
	{
		c_sldColSupGain.EnableWindow(FALSE);
	}

	c_sldColSupGain.EnableWindow(TRUE);

	currValue = initCtrlSetting.colsupGain;
	SendMessageA(c_sldColSupGain, TBM_SETRANGEMAX, TRUE, lMax);
	SendMessageA(c_sldColSupGain, TBM_SETRANGEMIN, TRUE, lMin);
	SendMessageA(c_sldColSupGain, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sldColSupGain, TBM_SETPOS, TRUE, currValue);

	currValueStr.Format(L"%ld", currValue);
	c_edtColSupGain.ReplaceSel(currValueStr, TRUE);
	c_edtColSupGain.EnableWindow(FALSE);


	currValue = initCtrlSetting.colsupAGCStart;

	if (0 && !SUCCEEDED(hr))  // no UVC controls for color suppression AGC start insteat of I2C
	{
		c_sldColSupAGCStart.EnableWindow(FALSE);
	}
	SendMessageA(c_sldColSupAGCStart, TBM_SETRANGEMAX, TRUE, 177);
	SendMessageA(c_sldColSupAGCStart, TBM_SETRANGEMIN, TRUE, 0);
	SendMessageA(c_sldColSupAGCStart, TBM_SETPOS, TRUE, currValue);
	SendMessageA(c_sldColSupAGCStart, TBM_SETPAGESIZE, TRUE, 1);

	currValueStr.Format(L"%ld", currValue);
	c_edtColSupGainStart.ReplaceSel(currValueStr, TRUE);
	c_edtColSupGainStart.EnableWindow(FALSE);

	currValue = initCtrlSetting.colsupAGCEnd;
	if (0 && !SUCCEEDED(hr)) // no UVC controls for color suppression AGC end insteat of I2C
	{
		c_sldColSupAGCEnd.EnableWindow(FALSE);
	}
	SendMessageA(c_sldColSupAGCEnd, TBM_SETRANGEMAX, TRUE, 178);
	SendMessageA(c_sldColSupAGCEnd, TBM_SETRANGEMIN, TRUE, 1);
	SendMessageA(c_sldColSupAGCEnd, TBM_SETPOS, TRUE, currValue);
	SendMessageA(c_sldColSupAGCEnd, TBM_SETPAGESIZE, TRUE, 1);

	currValueStr.Format(L"%ld", currValue);
	c_edtColSupGainEnd.ReplaceSel(currValueStr, TRUE);
	c_edtColSupGainEnd.EnableWindow(FALSE);

	currValue = initCtrlSetting.collightGain;
	if (0 && !SUCCEEDED(hr))  // no UVC controls for high-low light color suppression gain insteat of I2C
	{
		c_sldHighLowLightGain.EnableWindow(FALSE);
	}
	SendMessageA(c_sldHighLowLightGain, TBM_SETRANGEMAX, TRUE, lMax);
	SendMessageA(c_sldHighLowLightGain, TBM_SETRANGEMIN, TRUE, lMin);
	SendMessageA(c_sldHighLowLightGain, TBM_SETPOS, TRUE, currValue);
	SendMessageA(c_sldHighLowLightGain, TBM_SETPAGESIZE, TRUE, 1);
	//HWND hListSaturation = GetDlgItem(hwnd, IDC_EDIT_SATURATION);
	currValueStr.Format(L"%ld", currValue);
	c_edtHighLowLightGain.ReplaceSel(currValueStr, TRUE);
	c_edtHighLowLightGain.EnableWindow(FALSE);

	currValue = initCtrlSetting.coledgSupp;
	if (0 && !SUCCEEDED(hr))   // no UVC controls for edge color suppression gain insteat of I2C
	{
		c_sldColSupEdgeGain.EnableWindow(FALSE);
	}
	SendMessageA(c_sldColSupEdgeGain, TBM_SETRANGEMAX, TRUE, lMax);
	SendMessageA(c_sldColSupEdgeGain, TBM_SETRANGEMIN, TRUE, lMin);
	SendMessageA(c_sldColSupEdgeGain, TBM_SETPOS, TRUE, currValue);
	SendMessageA(c_sldColSupEdgeGain, TBM_SETPAGESIZE, TRUE, 1);
	//HWND hListSharpness = GetDlgItem(hwnd, IDC_EDIT_SHARPNESS);
	currValueStr.Format(L"%ld", currValue);
	c_edtColSupEdgeGain.ReplaceSel(currValueStr, TRUE);
	c_edtColSupEdgeGain.EnableWindow(FALSE);

	//hr = getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_WHITEBALANCE, &currValue, &lCaps);
	currValue = initCtrlSetting.WhiteBalance;
	if (!SUCCEEDED(hr))
	{
		cb_WBLMode.EnableWindow(FALSE);
	}
	cb_WBLMode.AddString(L"AWB MODE");
	cb_WBLMode.AddString(L"ATW MODE");
	cb_WBLMode.AddString(L"AWC-set");
	cb_WBLMode.AddString(L"MANUAL");
	cb_WBLMode.AddString(L"INDOOR");
	cb_WBLMode.AddString(L"OUTDOOR");
	//cb_WBLMode.AddString(L"PUSH TO WHITE");

	cb_WBLMode.SetCurSel(currValue);

	if ((SUCCEEDED(hr) && currValue == 6))	// if it's P2W mode enable P2W check box
	{
		c_bP2WOn.SetCheck(BST_CHECKED);
	}
	else{
		c_bP2WOn.SetCheck(BST_UNCHECKED);
	}

	if ((SUCCEEDED(hr) && (currValue == 1 || currValue == 0)))	// if it's AWB or ATW
	{
		c_bP2WOn.EnableWindow(TRUE);
		initCtrlSetting.WBLPreP2W = currValue;
	}
	else
	{
		c_bP2WOn.EnableWindow(FALSE);
	}

	if ((SUCCEEDED(hr) && currValue == 3))	// if it's manual mode enable red & blue comp
	{
		c_sldWBLComBlue.EnableWindow(TRUE);
		c_sldWBLComRed.EnableWindow(TRUE);
	}
	else{
		c_sldWBLComBlue.EnableWindow(FALSE);
		c_sldWBLComRed.EnableWindow(FALSE);
	}

	int blueValue = 0;
	int redValue = 0;

	//getWhiteBalanceComponent(&redValue, &blueValue); //&initCtrlSetting.WhiteBalanceComponentRed, &initCtrlSetting.WhiteBalanceComponentBlue
	redValue = initCtrlSetting.WhiteBalanceComponentRed;
	blueValue = initCtrlSetting.WhiteBalanceComponentBlue;
	SendMessageA(c_sldWBLComBlue, TBM_SETRANGEMAX, TRUE, 0x80/*lMax*/);
	SendMessageA(c_sldWBLComBlue, TBM_SETRANGEMIN, TRUE, lMin);
	SendMessageA(c_sldWBLComBlue, TBM_SETPOS, TRUE, blueValue);
	SendMessageA(c_sldWBLComBlue, TBM_SETPAGESIZE, TRUE, 1);

	SendMessageA(c_sldWBLComRed, TBM_SETRANGEMAX, TRUE, 0x80/*lMax*/);
	SendMessageA(c_sldWBLComRed, TBM_SETRANGEMIN, TRUE, lMin);
	SendMessageA(c_sldWBLComRed, TBM_SETPOS, TRUE, redValue);
	SendMessageA(c_sldWBLComRed, TBM_SETPAGESIZE, TRUE, 1);

	//HWND hListWhiteBalanceComp = GetDlgItem(hwnd, IDC_EDIT_WHTCOM);
	currValueStr.Format(L"%d", blueValue);
	c_edtWBLComBlue.ReplaceSel(currValueStr, TRUE);
	c_edtWBLComBlue.EnableWindow(FALSE);
	//HWND hListWhiteBalanceCompRed = GetDlgItem(hwnd, IDC_EDIT_WHTCOM_RED);
	currValueStr.Format(L"%d", redValue);
	c_edtWBLComRed.ReplaceSel(currValueStr, TRUE);
	c_edtWBLComRed.EnableWindow(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void VIS5MPColSupWBL::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class
	if (camNodeTree->isOKpProcAmp)
	{
		long SldPosRed = 0;
		long SldPos = 0;

		//check color suppression gain
		SldPos = (long)SendMessageA(c_sldColSupGain, TBM_GETPOS, TRUE, SldPos);
		if (SldPos != initCtrlSetting.colsupGain)
			setRegVal(REG_COLSUPGAIN, &initCtrlSetting.colsupGain);

		//check color supperession AGC start value
		SldPos = (long)SendMessageA(c_sldColSupAGCStart, TBM_GETPOS, TRUE, SldPos);
		if (SldPos != initCtrlSetting.colsupAGCStart)
			setRegVal(REG_COLSUPAGCSTART, &initCtrlSetting.colsupAGCStart);

		//check color supperession AGC end value
		SldPos = (long)SendMessageA(c_sldColSupAGCEnd, TBM_GETPOS, TRUE, SldPos);
		if (SldPos != initCtrlSetting.colsupAGCEnd)
			setRegVal(REG_COLSUPAGCEND, &initCtrlSetting.colsupAGCEnd);

		//check high/low light color supperession gain
		SldPos = (long)SendMessageA(c_sldHighLowLightGain, TBM_GETPOS, TRUE, SldPos);
		if (SldPos != initCtrlSetting.collightGain)
			setRegVal(REG_COLLIGHTGAIN, &initCtrlSetting.collightGain);

		//check edge color supperession gain
		SldPos = (long)SendMessageA(c_sldColSupEdgeGain, TBM_GETPOS, TRUE, SldPos);
		if (SldPos != initCtrlSetting.coledgSupp)
			setRegVal(REG_COLEDGESUP, &initCtrlSetting.coledgSupp);

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
		int sel = cb_WBLMode.GetCurSel();
		if (sel != initCtrlSetting.WhiteBalance)
			camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_WHITEBALANCE, (long)initCtrlSetting.WhiteBalance, VideoProcAmp_Flags_Manual);
		//ksNodeTree.pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_WHITEBALANCE_COMPONENT, (long)initCtrlSetting.WhiteBalanceComponentControl, VideoProcAmp_Flags_Manual);

		//HWND hListSldWhiteBalanceComp = GetDlgItem(hwnd, IDC_SLD_WHTCOM);
		SldPos = (long)SendMessageA(c_sldWBLComBlue, TBM_GETPOS, TRUE, SldPos);
		//HWND hListSldWhiteBalanceCompRed = GetDlgItem(hwnd, IDC_SLD_WHTCOM_RED);
		SldPosRed = (long)SendMessageA(c_sldWBLComRed, TBM_GETPOS, TRUE, SldPosRed);
		if (SldPosRed != initCtrlSetting.WhiteBalanceComponentRed || SldPos != initCtrlSetting.WhiteBalanceComponentBlue)
			setWhiteBalanceComponent(initCtrlSetting.WhiteBalanceComponentRed, initCtrlSetting.WhiteBalanceComponentBlue);
	}
	CDialog::OnCancel();
}


void VIS5MPColSupWBL::OnBnClickedColorSuppressionEnabl()
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	int enableColSuppre = 0;

	if (c_bColSupEnable.GetCheck() == BST_CHECKED){
		c_sldColSupGain.EnableWindow(TRUE);
		c_sldColSupAGCStart.EnableWindow(TRUE);
		c_sldColSupAGCEnd.EnableWindow(TRUE);
		enableColSuppre = 1;
	}
	else{
		c_sldColSupGain.EnableWindow(FALSE);
		c_sldColSupAGCStart.EnableWindow(FALSE);
		c_sldColSupAGCEnd.EnableWindow(FALSE);
		enableColSuppre = 0;
	}

	if (0&&camNodeTree->isOK) //no setting needs sending to device.
	{
		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 4;

		hr = getExtionControlPropertySize(PropertId, &ulSize);
		if (FAILED(hr))
		{
#ifdef DEBUG
			//			sprintf(logMessage, "\nERROR \t Function : on3DNoiseRedLvlChange \t Msg : Unable to find property size : %x", hr);
			//			printLogMessage(logMessage);
#endif
		}
		else
		{
			pbPropertyValue = new BYTE[ulSize];
			if (!pbPropertyValue)
			{
#ifdef DEBUG
				//				sprintf(logMessage, "\nERROR \t Function : on3DNoiseRedLvlChange \t Msg : Unable to allocate memory for property value");
				//				printLogMessage(logMessage);
#endif
			}
			else
			{
				memcpy(pbPropertyValue, (char*)&enableColSuppre, ulSize);
				hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
			}
			delete[] pbPropertyValue;
		}

#ifdef DEBUG
		//		sprintf(logMessage, "\nFunction : on3DNoiseRedLvlChange \t Msg : Return Value:%ld", hr);
		//		printLogMessage(logMessage);
#endif
	}

}


void VIS5MPColSupWBL::OnBnClickedWblP2wEnabl()
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	int enableP2W = 0;

	if (c_bP2WOn.GetCheck() == BST_CHECKED){
		enableP2W = 6;
	}
	else{
		enableP2W = initCtrlSetting.WBLPreP2W;
	}

	if (camNodeTree->isOKpProcAmp)
	{
#ifdef DEBUG
		//		sprintf(logMessage, "\nbmRequestType:SET \t bRequest:SET_CUR \t wValue:WhiteBalance \t wIndex:0x02\t PutValue:%d", sel);
		//		printLogMessage(logMessage);
#endif
		hr = camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_WHITEBALANCE, (long)enableP2W, VideoProcAmp_Flags_Auto);
		//hr = camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_WHITEBALANCE, (long)sel, VideoProcAmp_Flags_Auto);
	}

}


void VIS5MPColSupWBL::OnNMReleasedcaptureSldColsuppGainVal(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long SldPos = 0;
	int value;
	CString strPos;
	//HWND hListSldBrightness = GetDlgItem(hwnd, IDC_SLD_BRIGHTNESS);
	SldPos = (long)SendMessageA(c_sldColSupGain, TBM_GETPOS, TRUE, SldPos);

	//HWND hListBrightness = GetDlgItem(hwnd, IDC_EDIT_BRIGHTNESS);
	strPos.Format(L"%ld", SldPos);
	c_edtColSupGain.SetSel(0, -1);
	c_edtColSupGain.Clear();
	c_edtColSupGain.ReplaceSel(strPos, TRUE);
	value = SldPos;
	setRegVal(REG_COLSUPGAIN, &value);
	*pResult = 0;
}


void VIS5MPColSupWBL::OnNMReleasedcaptureSldColsuppGainendVal(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long SldPos = 0;
	int value;
	CString strPos;
	//HWND hListSldBrightness = GetDlgItem(hwnd, IDC_SLD_BRIGHTNESS);
	SldPos = (long)SendMessageA(c_sldColSupAGCEnd, TBM_GETPOS, TRUE, SldPos);

	//HWND hListBrightness = GetDlgItem(hwnd, IDC_EDIT_BRIGHTNESS);
	strPos.Format(L"%ld", SldPos);
	c_edtColSupGainEnd.SetSel(0, -1);
	c_edtColSupGainEnd.Clear();
	c_edtColSupGainEnd.ReplaceSel(strPos, TRUE);
	value = SldPos;
	setRegVal(REG_COLSUPAGCEND, &value);
	*pResult = 0;
}


void VIS5MPColSupWBL::OnNMReleasedcaptureSldColsuppGainstrVal(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long SldPos = 0;
	int value;
	CString strPos;
	//HWND hListSldBrightness = GetDlgItem(hwnd, IDC_SLD_BRIGHTNESS);
	SldPos = (long)SendMessageA(c_sldColSupAGCStart, TBM_GETPOS, TRUE, SldPos);

	//HWND hListBrightness = GetDlgItem(hwnd, IDC_EDIT_BRIGHTNESS);
	strPos.Format(L"%ld", SldPos);
	c_edtColSupGainStart.SetSel(0, -1);
	c_edtColSupGainStart.Clear();
	c_edtColSupGainStart.ReplaceSel(strPos, TRUE);
	value = SldPos;
	setRegVal(REG_COLSUPAGCSTART, &value);
	*pResult = 0;
}


void VIS5MPColSupWBL::OnNMReleasedcaptureSldEdgeColsupGain(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long SldPos = 0;
	int value;
	CString strPos;
	//HWND hListSldBrightness = GetDlgItem(hwnd, IDC_SLD_BRIGHTNESS);
	SldPos = (long)SendMessageA(c_sldColSupEdgeGain, TBM_GETPOS, TRUE, SldPos);

	//HWND hListBrightness = GetDlgItem(hwnd, IDC_EDIT_BRIGHTNESS);
	strPos.Format(L"%ld", SldPos);
	c_edtColSupEdgeGain.SetSel(0, -1);
	c_edtColSupEdgeGain.Clear();
	c_edtColSupEdgeGain.ReplaceSel(strPos, TRUE);
	value = SldPos;
	setRegVal(REG_COLEDGESUP, &value);
	*pResult = 0;
}


void VIS5MPColSupWBL::OnNMReleasedcaptureSldHightlowColsupGain(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long SldPos = 0;
	int value;
	CString strPos;
	//HWND hListSldBrightness = GetDlgItem(hwnd, IDC_SLD_BRIGHTNESS);
	SldPos = (long)SendMessageA(c_sldHighLowLightGain, TBM_GETPOS, TRUE, SldPos);

	//HWND hListBrightness = GetDlgItem(hwnd, IDC_EDIT_BRIGHTNESS);
	strPos.Format(L"%ld", SldPos);
	c_edtHighLowLightGain.SetSel(0, -1);
	c_edtHighLowLightGain.Clear();
	c_edtHighLowLightGain.ReplaceSel(strPos, TRUE);
	value = SldPos;
	setRegVal(REG_COLLIGHTGAIN, &value);
	*pResult = 0;
}


void VIS5MPColSupWBL::OnNMReleasedcaptureSldWhtcom(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long SldPos = 0;
	CString strPos;
	//HWND hListSldWhiteBalanceComp = GetDlgItem(hwnd, IDC_SLD_WHTCOM);
	SldPos = (long)SendMessageA(c_sldWBLComBlue, TBM_GETPOS, TRUE, SldPos);
	initCtrlSetting.WhiteBalanceComponentBlueCur = SldPos;

	//HWND hListWhiteBalanceComp = GetDlgItem(hwnd, IDC_EDIT_WHTCOM);
	strPos.Format(L"%ld", SldPos);
	c_edtWBLComBlue.SetSel(0, -1);
	c_edtWBLComBlue.Clear();
	c_edtWBLComBlue.ReplaceSel(strPos, TRUE);

	hr = setWhiteBalanceComponent(initCtrlSetting.WhiteBalanceComponentRedCur, SldPos);

#ifdef DEBUG
	//	sprintf(logMessage, "\nFunction : onWhiteBalanceCompBlueChange Msg : Return Value:%ld", hr);
	//	printLogMessage(logMessage);
#endif
	*pResult = 0;
}


void VIS5MPColSupWBL::OnNMReleasedcaptureSldWhtcomRed(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long SldPosRed = 0;
	CString strPos;

	//HWND hListSldWhiteBalanceCompRed = GetDlgItem(hwnd, IDC_SLD_WHTCOM_RED);
	SldPosRed = (long)SendMessageA(c_sldWBLComRed, TBM_GETPOS, TRUE, SldPosRed);
	initCtrlSetting.WhiteBalanceComponentRedCur = SldPosRed;

	//HWND hListWhiteBalanceCompRed = GetDlgItem(hwnd, IDC_EDIT_WHTCOM_RED);
	strPos.Format(L"%ld", SldPosRed);
	c_edtWBLComRed.SetSel(0, -1);
	c_edtWBLComRed.Clear();
	c_edtWBLComRed.ReplaceSel(strPos, TRUE);

	hr = setWhiteBalanceComponent(SldPosRed, initCtrlSetting.WhiteBalanceComponentBlueCur);

#ifdef DEBUG
	//	sprintf(logMessage, "\nFunction : onWhiteBalanceCompBlueChange Msg : Return Value:%ld", hr);
	//	printLogMessage(logMessage);
#endif
	*pResult = 0;
}


void VIS5MPColSupWBL::OnCbnSelchangeComboWhtblcmode2()
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	//HWND hListBackLight = GetDlgItem(hwnd, IDC_COMBO_WHTBLCMODE);

	int sel = cb_WBLMode.GetCurSel();

	if (sel != LB_ERR && camNodeTree->isOKpProcAmp)
	{
#ifdef DEBUG
		//		sprintf(logMessage, "\nbmRequestType:SET \t bRequest:SET_CUR \t wValue:WhiteBalance \t wIndex:0x02\t PutValue:%d", sel);
		//		printLogMessage(logMessage);
#endif
		hr = camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_WHITEBALANCE, (long)sel, VideoProcAmp_Flags_Auto);

		//HWND hListSldWhiteBalanceComp = GetDlgItem(hwnd, IDC_SLD_WHTCOM);
		//HWND hListSldWhiteBalanceCompRed = GetDlgItem(hwnd, IDC_SLD_WHTCOM_RED);
		if ((SUCCEEDED(hr) && sel == 3))	// if it's manual mode enable red & blue comp
		{
			c_sldWBLComBlue.EnableWindow(TRUE);
			c_sldWBLComRed.EnableWindow(TRUE);
		}
		else
		{
			c_sldWBLComBlue.EnableWindow(FALSE);
			c_sldWBLComRed.EnableWindow(FALSE);
		}
		if ((SUCCEEDED(hr) && (sel == 1 || sel == 0)))	// if it's manual mode enable red & blue comp
		{
			c_bP2WOn.EnableWindow(TRUE);
			initCtrlSetting.WBLPreP2W = sel;
		}
		else
		{
			c_bP2WOn.EnableWindow(FALSE);
		}

#ifdef DEBUG
		//		sprintf(logMessage, "\nFunction : onWhiteBalanceControlChange Msg : Return Value:%ld", hr);
		//		printLogMessage(logMessage);
#endif
	}

	//return hr;
}

void VIS5MPColSupWBL::saveColSupWBLInitSetting(){
	long currValue, lCaps;

	// reset global struct
	initCtrlSetting.WhiteBalance = 0;
	initCtrlSetting.WhiteBalanceComponentRed = 0;
	initCtrlSetting.WhiteBalanceComponentBlue = 0;
	initCtrlSetting.colsupGain = 0;
	initCtrlSetting.colsupAGCStart = 0;
	initCtrlSetting.colsupAGCEnd = 0;
	initCtrlSetting.collightGain = 0;
	initCtrlSetting.coledgSupp = 0;

	// get current Value
	currValue = 0;
	getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_WHITEBALANCE, &currValue, &lCaps);
	initCtrlSetting.WhiteBalance = currValue;

	getWhiteBalanceComponent(&initCtrlSetting.WhiteBalanceComponentRed, &initCtrlSetting.WhiteBalanceComponentBlue);
	initCtrlSetting.WhiteBalanceComponentBlueCur = initCtrlSetting.WhiteBalanceComponentBlue;
	initCtrlSetting.WhiteBalanceComponentRedCur = initCtrlSetting.WhiteBalanceComponentRed;

	getRegVal(REG_COLSUPGAIN, &initCtrlSetting.colsupGain);
	getRegVal(REG_COLSUPAGCSTART, &initCtrlSetting.colsupAGCStart);
	getRegVal(REG_COLSUPAGCEND, &initCtrlSetting.colsupAGCEnd);
	getRegVal(REG_COLLIGHTGAIN, &initCtrlSetting.collightGain);
	getRegVal(REG_COLEDGESUP, &initCtrlSetting.coledgSupp);

}
