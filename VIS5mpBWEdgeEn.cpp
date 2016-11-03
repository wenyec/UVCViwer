// VIS5mpBWEdgeEn.cpp : implementation file
//

#include "stdafx.h"
#include "VIS5mpBWEdgeEn.h"
#include "afxdialogex.h"


// VIS5mpBWEdgeEn dialog

IMPLEMENT_DYNAMIC(VIS5mpBWEdgeEn, CDialog)

VIS5mpBWEdgeEn::VIS5mpBWEdgeEn(CWnd* pParent /*=NULL*/)
	: CDialog(VIS5mpBWEdgeEn::IDD, pParent)
{

}

VIS5mpBWEdgeEn::~VIS5mpBWEdgeEn()
{
}

void VIS5mpBWEdgeEn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_EDGEENHN_CONTL, c_EdgeEnhanceM);
	DDX_Control(pDX, IDC_COMBO_MAIN_FEQ, c_MainFreq);
	DDX_Control(pDX, IDC_COMBO_MIRROR_MODE, c_MirrorCtrl);
	DDX_Control(pDX, IDC_SLD_EDGEGAIN_LVL, c_sldEdgeLevel);
	DDX_Control(pDX, IDC_SLD_GAIN_END_LVL, c_sldEdgeGainEnd);
	DDX_Control(pDX, IDC_SLD_GAIN_START_LVL, c_sldEdgeGainStart);
	DDX_Control(pDX, IDC_EDIT_EDGEGAIN_LVL, txt_edtEdgeLevel);
	DDX_Control(pDX, IDC_EDIT_GAIN_END_LVL, txt_edtEdgeGainEnd);
	DDX_Control(pDX, IDC_EDIT_GAIN_START_LVL, txt_edtEdgeGainStart);
}


BEGIN_MESSAGE_MAP(VIS5mpBWEdgeEn, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_EDGEENHN_CONTL, &VIS5mpBWEdgeEn::OnCbnSelchangeComboEdgeenhnContl)
	ON_CBN_SELCHANGE(IDC_COMBO_MAIN_FEQ, &VIS5mpBWEdgeEn::OnCbnSelchangeComboMainFeq)
	ON_CBN_SELCHANGE(IDC_COMBO_MIRROR_MODE, &VIS5mpBWEdgeEn::OnCbnSelchangeComboMirrorMode)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_EDGEGAIN_LVL, &VIS5mpBWEdgeEn::OnNMReleasedcaptureSldEdgegainLvl)
//	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_GAIN_END_LVL, &VIS5mpBWEdgeEn::OnNMReleasedcaptureSldGainEndLvl)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_GAIN_START_LVL, &VIS5mpBWEdgeEn::OnNMReleasedcaptureSldGainStartLvl)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_GAIN_END_LVL, &VIS5mpBWEdgeEn::OnNMReleasedcaptureSldGainEndLvl)
END_MESSAGE_MAP()


// VIS5mpBWEdgeEn message handlers


BOOL VIS5mpBWEdgeEn::OnInitDialog()
{
	CDialog::OnInitDialog();
	/*
	getExtControlValue(22, &initCtrlSetting.EGEEnhanceMode);
	getExtControlValue(23, &initCtrlSetting.EGEEnhanceGain);
	getExt2ControlValues(24, &initCtrlSetting.EGEEnhGainStart, &initCtrlSetting.EGEEnhGainEnd);

	//getExposureAGCLvlValue(10, &initCtrlSetting.ExposureMode, &initCtrlSetting.AGCLevel);

	getExtControlValue(3, &initCtrlSetting.MirrorMode);

	*/

	// TODO:  Add extra initialization here
	HRESULT hr;
	CString retValueStr;
	int retValue = 0;
	long currValue, lCaps;
	long lMin, lMax, lStep, lDefault;
	int edgeEnhaMode = 0;
	//int expMode = 0, AGCLvl = 0, isBLCon = 0;
	//hr = getExposureAGCLvlValue(10, &expMode, &AGCLvl);

	//hr = getExtControlValue(23, &retValue); // &initCtrlSetting.EGEEnhanceGain
	retValue = initCtrlSetting.EGEEnhanceGain;
	//hr = getExtControlValue(22, &edgeEnhaMode); // &initCtrlSetting.EGEEnhanceMode
	edgeEnhaMode = initCtrlSetting.EGEEnhanceMode;

	//HWND hListEdgeEnhanModeCtrl = GetDlgItem(hwnd, IDC_COMBO_EDGEENHN_CONTL);

	if (FAILED(hr))
	{
		c_EdgeEnhanceM.EnableWindow(FALSE);
	}
	c_EdgeEnhanceM.AddString(L"Edge Enhancement Off");
	c_EdgeEnhanceM.AddString(L"Stand Edge Enhancement");
	c_EdgeEnhanceM.AddString(L"Boost 2X");
	c_EdgeEnhanceM.AddString(L"Boost 4X");
	c_EdgeEnhanceM.AddString(L"Boost 8X");
	c_EdgeEnhanceM.SetCurSel(edgeEnhaMode);

	//HWND hListSldEnhanGainVL = GetDlgItem(hwnd, IDC_SLD_EDGEGAIN_LVL);

	SendMessageA(c_sldEdgeLevel, TBM_SETRANGEMAX, TRUE, 0x7F);
	SendMessageA(c_sldEdgeLevel, TBM_SETRANGEMIN, TRUE, 0);
	SendMessageA(c_sldEdgeLevel, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sldEdgeLevel, TBM_SETPOS, TRUE, retValue);

	//HWND hListEditEnhaGainVL = GetDlgItem(hwnd, IDC_EDIT_EDGEGAIN_LVL);
	//Edit_SetText(hListAGCLVL, L"0");
	txt_edtEdgeLevel.EnableWindow(FALSE);
	retValueStr.Format(L"%d", retValue);
	txt_edtEdgeLevel.ReplaceSel(retValueStr,TRUE);

	int startLvl = 0, endLvl = 0;
	//hr = getExt2ControlValues(24, &startLvl, &endLvl); //&initCtrlSetting.EGEEnhGainStart, &initCtrlSetting.EGEEnhGainEnd
	startLvl = initCtrlSetting.EGEEnhGainStart;
	endLvl = initCtrlSetting.EGEEnhGainEnd;
	//HWND hListSldEnhanStartVL = GetDlgItem(hwnd, IDC_SLD_GAIN_START_LVL);

	SendMessageA(c_sldEdgeGainStart, TBM_SETRANGEMAX, TRUE, 0xB1);
	SendMessageA(c_sldEdgeGainStart, TBM_SETRANGEMIN, TRUE, 0);
	SendMessageA(c_sldEdgeGainStart, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sldEdgeGainStart, TBM_SETPOS, TRUE, startLvl);

	//HWND hListEditEnhaStartVL = GetDlgItem(hwnd, IDC_EDIT_GAIN_START_LVL);
	//Edit_SetText(hListAGCLVL, L"0");
	txt_edtEdgeGainStart.EnableWindow(FALSE);
	retValueStr.Format(L"%d", startLvl);
	txt_edtEdgeGainStart.ReplaceSel(retValueStr, TRUE);

	//HWND hListSldEnhanEndVL = GetDlgItem(hwnd, IDC_SLD_GAIN_END_LVL);

	SendMessageA(c_sldEdgeGainEnd, TBM_SETRANGEMAX, TRUE, 0xB2);
	SendMessageA(c_sldEdgeGainEnd, TBM_SETRANGEMIN, TRUE, 1);
	SendMessageA(c_sldEdgeGainEnd, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sldEdgeGainEnd, TBM_SETPOS, TRUE, endLvl);

	//HWND hListEditEnhaEndVL = GetDlgItem(hwnd, IDC_EDIT_GAIN_END_LVL);
	//Edit_SetText(hListAGCLVL, L"0");
	txt_edtEdgeGainEnd.EnableWindow(FALSE);
	retValueStr.Format(L"%d", endLvl);
	txt_edtEdgeGainEnd.ReplaceSel(retValueStr, TRUE);


	if (FAILED(hr) || edgeEnhaMode == 0)
	{
		c_sldEdgeLevel.EnableWindow(FALSE);
		c_sldEdgeGainStart.EnableWindow(FALSE);
		c_sldEdgeGainEnd.EnableWindow(FALSE);
	}
	else{
		c_sldEdgeLevel.EnableWindow(TRUE);
		c_sldEdgeGainStart.EnableWindow(TRUE);
		c_sldEdgeGainEnd.EnableWindow(TRUE);
	}

	//move to edge enhancement menu
	//HWND hListMirrorMode = GetDlgItem(hwnd, IDC_COMBO_MIRROR_MODE);
	//hr = getExtControlValue(3, &retValue); // &initCtrlSetting.MirrorMode
	retValue = initCtrlSetting.MirrorMode;
	if (FAILED(hr))
	{
		c_MirrorCtrl.EnableWindow(FALSE);
	}
	c_MirrorCtrl.AddString(L"ORIGINAL");  //original "OFF"
	c_MirrorCtrl.AddString(L"MIRROR");
	c_MirrorCtrl.AddString(L"V_FLIP");
	c_MirrorCtrl.AddString(L"ROTATE ");
	c_MirrorCtrl.SetCurSel(retValue);

#if 1 ///move to edge enhancement menu
	//HWND hListMainFeq = GetDlgItem(hwnd, IDC_COMBO_MAIN_FEQ);
	retValue = initCtrlSetting.MainsFrequency;
	c_MainFreq.AddString(L"60 Hz");
	c_MainFreq.AddString(L"50 Hz");
	c_MainFreq.SetCurSel(retValue);
#endif

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void VIS5mpBWEdgeEn::saveEnhanceInitSetting()
{
	long currValue, lCaps;
	int setV = 0;
	int value;

	// reset global struct
	initCtrlSetting.MirrorMode = 0;
	initCtrlSetting.MainsFrequency = 0;

	// get current Value
	getExtControlValue(22, &value); // the enhancement mode is indicated by bit[3:2] when it's on.
	if (value & 0x1)
	{
		value = (value & 0xC) >> 2;
		initCtrlSetting.EGEEnhanceMode = value + 1;
		}
	else
		initCtrlSetting.EGEEnhanceMode = 0; // the enhancement off.
	getExtControlValue(23, &initCtrlSetting.EGEEnhanceGain);
	getExt2ControlValues(24, &initCtrlSetting.EGEEnhGainEnd, &initCtrlSetting.EGEEnhGainStart);

	//getExposureAGCLvlValue(10, &initCtrlSetting.ExposureMode, &initCtrlSetting.AGCLevel);

	getExtControlValue(3, &initCtrlSetting.MirrorMode);

	getStandardControlPropertyCurrentValue(KSPROPERTY_VIDEOPROCAMP_POWERLINE_FREQUENCY, &currValue, &lCaps);
	initCtrlSetting.MainsFrequency = currValue;

}


void VIS5mpBWEdgeEn::OnCbnSelchangeComboEdgeenhnContl()
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	//HWND hListComboEnhaMode = GetDlgItem(hwnd, IDC_COMBO_EDGEENHN_CONTL);
	//HWND hListSldEnhanGainVL = GetDlgItem(hwnd, IDC_SLD_EDGEGAIN_LVL);
	//HWND hListSldEnhanStartVL = GetDlgItem(hwnd, IDC_SLD_GAIN_START_LVL);
	//HWND hListSldEnhanEndVL = GetDlgItem(hwnd, IDC_SLD_GAIN_END_LVL);

	int sel = c_EdgeEnhanceM.GetCurSel();

	if (sel == 0){
		c_sldEdgeLevel.EnableWindow(FALSE);
		c_sldEdgeGainStart.EnableWindow(FALSE);
		c_sldEdgeGainEnd.EnableWindow(FALSE);
	}
	else{
		c_sldEdgeLevel.EnableWindow(TRUE);
		c_sldEdgeGainStart.EnableWindow(TRUE);
		c_sldEdgeGainEnd.EnableWindow(TRUE);
	}

	if (sel != LB_ERR && camNodeTree->isOK)
	{

		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 22;
		const char data[5] = { 0, 1, 5, 9, 13 };
		char setVlu = data[sel];
		hr = getExtionControlPropertySize(PropertId, &ulSize);
		if (FAILED(hr))
		{
#ifdef DEBUG
//			sprintf(logMessage, "\nERROR \t Function : OnSelectedIndexChangeMirror \t Msg : Unable to find property size : %x", hr);
//			printLogMessage(logMessage);
#endif
		}
		else
		{
			pbPropertyValue = new BYTE[ulSize];
			if (!pbPropertyValue)
			{
#ifdef DEBUG
//				sprintf(logMessage, "\nERROR \t Function : OnSelectedIndexChangeMirror \t Msg : Unable to allocate memory for property value");
//				printLogMessage(logMessage);
#endif
			}
			else
			{
				memcpy(pbPropertyValue, (char*)&setVlu, ulSize);
				hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
			}
			delete[] pbPropertyValue;
		}

#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : OnSelectedIndexChangeMirror \t Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}

}


void VIS5mpBWEdgeEn::OnCbnSelchangeComboMainFeq()
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	//HWND hListMainFeq = GetDlgItem(hwnd, IDC_COMBO_MAIN_FEQ);

	int sel = c_MainFreq.GetCurSel();
	if (sel != LB_ERR && camNodeTree->isOKpProcAmp)
	{
#ifdef DEBUG
//		sprintf(logMessage, "\nbmRequestType:SET \t bRequest:SET_CUR \t wValue:Mains frequency \t wIndex:0x02\t PutValue:%d", sel);
//		printLogMessage(logMessage);
#endif
		hr = camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_POWERLINE_FREQUENCY, (long)sel, VideoProcAmp_Flags_Manual);
#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : OnMainsFrequencyChange Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}
}


void VIS5mpBWEdgeEn::OnCbnSelchangeComboMirrorMode()
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	//HWND hListComboMirror = GetDlgItem(hwnd, IDC_COMBO_MIRROR_MODE);

	int sel = c_MirrorCtrl.GetCurSel();

	if (sel != LB_ERR && camNodeTree->isOK)
	{

		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 3;

		hr = getExtionControlPropertySize(PropertId, &ulSize);
		if (FAILED(hr))
		{
#ifdef DEBUG
//			sprintf(logMessage, "\nERROR \t Function : OnSelectedIndexChangeMirror \t Msg : Unable to find property size : %x", hr);
//			printLogMessage(logMessage);
#endif
		}
		else
		{
			pbPropertyValue = new BYTE[ulSize];
			if (!pbPropertyValue)
			{
#ifdef DEBUG
//				sprintf(logMessage, "\nERROR \t Function : OnSelectedIndexChangeMirror \t Msg : Unable to allocate memory for property value");
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
//		sprintf(logMessage, "\nFunction : OnSelectedIndexChangeMirror \t Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}

}


void VIS5mpBWEdgeEn::OnNMReleasedcaptureSldEdgegainLvl(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;

	try
	{
		long arSldPos = 0;
		CString strPos;
		//HWND hListSldEnhanGainLVL = GetDlgItem(hwnd, IDC_SLD_EDGEGAIN_LVL);
		arSldPos = (long)SendMessageA(c_sldEdgeLevel, TBM_GETPOS, TRUE, arSldPos);

		//HWND hListEnhanGainLVL = GetDlgItem(hwnd, IDC_EDIT_EDGEGAIN_LVL);
		strPos.Format(L"%ld", arSldPos);
		txt_edtEdgeLevel.SetSel(0, -1);
		txt_edtEdgeLevel.Clear();
		txt_edtEdgeLevel.ReplaceSel(strPos, TRUE);

		if (camNodeTree->isOK)
		{
			ULONG ulSize;
			BYTE *pbPropertyValue;
			int PropertId = 23;

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

void VIS5mpBWEdgeEn::OnNMReleasedcaptureSldGainEndLvl(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	OnStartEndChange();
	*pResult = 0;
}

void VIS5mpBWEdgeEn::OnNMReleasedcaptureSldGainStartLvl(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	OnStartEndChange();
	*pResult = 0;
}

void VIS5mpBWEdgeEn::OnStartEndChange()
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long startSldPos = 0, endSldPos = 0;
	CString strPos;
	//HWND hListSldEnhanStartLVL = GetDlgItem(hwnd, IDC_SLD_GAIN_START_LVL);
	startSldPos = (long)SendMessageA(c_sldEdgeGainStart, TBM_GETPOS, TRUE, startSldPos);

	//HWND hListSldEnhanEndLVL = GetDlgItem(hwnd, IDC_SLD_GAIN_END_LVL);
	endSldPos = (long)SendMessageA(c_sldEdgeGainEnd, TBM_GETPOS, TRUE, endSldPos);

	//HWND hListEditEnhanStartLVL = GetDlgItem(hwnd, IDC_EDIT_GAIN_START_LVL);
	strPos.Format(L"%ld", startSldPos);
	txt_edtEdgeGainStart.SetSel(0, -1);
	txt_edtEdgeGainStart.Clear();
	txt_edtEdgeGainStart.ReplaceSel(strPos, TRUE);

	//HWND hListEditEnhanEndLVL = GetDlgItem(hwnd, IDC_EDIT_GAIN_END_LVL);
	strPos.Format(L"%ld", endSldPos);
	txt_edtEdgeGainEnd.SetSel(0, -1);
	txt_edtEdgeGainEnd.Clear();
	txt_edtEdgeGainEnd.ReplaceSel(strPos, TRUE);

	if (camNodeTree->isOK)
	{
		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 24;

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
				int startByte = 2;
				int endByte = 2;
				memcpy(&pbPropertyValue[0], (char*)&startSldPos, startByte); // first two byte Exposure Mode & last two byte AGC level
				memcpy(&pbPropertyValue[startByte], (char*)&endSldPos, endByte); // first two byte Exposure Mode & last two byte AGC level

				hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
			}
			delete[] pbPropertyValue;
		}

#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : onAgcLvlChange \t Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}

}


//void VIS5mpBWEdgeEn::OnCancel()
//{
//	// TODO: Add your specialized code here and/or call the base class
//
//	CDialog::OnCancel();
//}




void VIS5mpBWEdgeEn::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class
	//HWND hListComboEdgeEnhanModeCtrl = GetDlgItem(hwnd, IDC_COMBO_EDGEENHN_CONTL);
	int sel = c_EdgeEnhanceM.GetCurSel();

	if (sel != initCtrlSetting.EGEEnhanceMode)
		setExtControls(22, initCtrlSetting.EGEEnhanceMode);

	//HWND hListComboMirror = GetDlgItem(hwnd, IDC_COMBO_MIRROR_MODE);
	sel = c_MirrorCtrl.GetCurSel();
	if (sel != initCtrlSetting.MirrorMode)
		setExtControls(3, initCtrlSetting.MirrorMode);

	//HWND hListSldEnhanceGainLVL = GetDlgItem(hwnd, IDC_EDIT_EDGEGAIN_LVL);
	long arSldPos = (long)SendMessageA(c_sldEdgeLevel, TBM_GETPOS, TRUE, arSldPos);
	if (arSldPos != initCtrlSetting.EGEEnhanceGain)
		setExtControls(23, initCtrlSetting.EGEEnhanceGain);

	//HWND hListSldEnhanStartLVL = GetDlgItem(hwnd, IDC_SLD_GAIN_START_LVL);
	int enhanStartSldPos = (int)SendMessageA(c_sldEdgeGainStart, TBM_GETPOS, TRUE, enhanStartSldPos);

	//HWND hListSldEnhanEndLVL = GetDlgItem(hwnd, IDC_SLD_GAIN_END_LVL);
	int enhanEndSldPos = (int)SendMessageA(c_sldEdgeGainEnd, TBM_GETPOS, TRUE, enhanEndSldPos);

	if ((enhanStartSldPos != initCtrlSetting.EGEEnhGainStart) || (enhanEndSldPos != initCtrlSetting.EGEEnhGainEnd))
	{
		setExt2ControlValues(24, initCtrlSetting.EGEEnhGainStart, initCtrlSetting.EGEEnhGainEnd);
	}

	if (camNodeTree->isOKpProcAmp)
	{
		//HWND hListMainFeq = GetDlgItem(hwnd, IDC_COMBO_MAIN_FEQ);
		sel = c_MainFreq.GetCurSel();
		if (sel != initCtrlSetting.MainsFrequency)
			camNodeTree->pProcAmp->Set(KSPROPERTY_VIDEOPROCAMP_POWERLINE_FREQUENCY, (long)initCtrlSetting.MainsFrequency, VideoProcAmp_Flags_Manual);
	}

	if (initCtrlSetting.EGEEnhanceMode == 0)
	{
		c_sldEdgeLevel.EnableWindow(FALSE);
		c_sldEdgeGainStart.EnableWindow(FALSE);
		c_sldEdgeGainEnd.EnableWindow(FALSE);
	}
	else{
		c_sldEdgeLevel.EnableWindow(TRUE);
		c_sldEdgeGainStart.EnableWindow(TRUE);
		c_sldEdgeGainEnd.EnableWindow(TRUE);
	}

	CDialog::OnCancel();
}
