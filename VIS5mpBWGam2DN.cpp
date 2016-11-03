// VIS5mpBWGam2DN.cpp : implementation file
//

#include "stdafx.h"
#include "VIS5mpBWGam2DN.h"
#include "afxdialogex.h"


// VIS5mpBWGam2DN dialog

IMPLEMENT_DYNAMIC(VIS5mpBWGam2DN, CDialog)

VIS5mpBWGam2DN::VIS5mpBWGam2DN(CWnd* pParent /*=NULL*/)
	: CDialog(VIS5mpBWGam2DN::IDD, pParent)
{

}

VIS5mpBWGam2DN::~VIS5mpBWGam2DN()
{
}

void VIS5mpBWGam2DN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_GAMMA_MODE, c_GammaSet);
	DDX_Control(pDX, IDC_2DNR_ENABL, c_2DNRenable);
	DDX_Control(pDX, IDC_SLD_2D_NOISE_REDU_VAL, c_sld2DNRLevel);
	DDX_Control(pDX, IDC_SLD_2D_NR_GAINEND_VAL, c_sld2DNRGainend);
	DDX_Control(pDX, IDC_SLD_2D_NR_GAINSTR_VAL, c_sld2DNRGainstart);
	DDX_Control(pDX, IDC_EDIT_2D_NOISE_REDU_VAL, txt_edt2DNRLevel);
	DDX_Control(pDX, IDC_EDIT_2D_NR_GAINEND_VAL, txt_edt2DNRGainEnd);
	DDX_Control(pDX, IDC_EDIT_2D_NR_GAINSTR_VAL, txt_edt2DNRGainStart);
}


BEGIN_MESSAGE_MAP(VIS5mpBWGam2DN, CDialog)
//	ON_CBN_EDITCHANGE(IDC_COMBO_GAMMA_MODE, &VIS5mpBWGam2DN::OnCbnEditchangeComboGammaMode)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_2D_NOISE_REDU_VAL, &VIS5mpBWGam2DN::OnNMReleasedcaptureSld2dNoiseReduVal)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_2D_NR_GAINEND_VAL, &VIS5mpBWGam2DN::OnNMReleasedcaptureSld2dNrGainendVal)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_2D_NR_GAINSTR_VAL, &VIS5mpBWGam2DN::OnNMReleasedcaptureSld2dNrGainstrVal)
	ON_CBN_SELCHANGE(IDC_COMBO_GAMMA_MODE, &VIS5mpBWGam2DN::OnCbnSelchangeComboGammaMode)
	ON_BN_CLICKED(IDC_2DNR_ENABL, &VIS5mpBWGam2DN::OnBnClicked2dnrEnabl)
END_MESSAGE_MAP()


// VIS5mpBWGam2DN message handlers


BOOL VIS5mpBWGam2DN::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	HRESULT hr = S_OK;
	int retValue = 0;
	CString retValueStr;

	//HWND hListCombGammaMode = GetDlgItem(hwnd, IDC_COMBO_GAMMA_MODE);
	//hr = getExtControlValue(27, &retValue); //&initCtrlSetting.GammaCorrect
	retValue = initCtrlSetting.GammaCorrect;
	if (FAILED(hr))
	{
		c_GammaSet.EnableWindow(FALSE);
	}
	c_GammaSet.AddString(L"0.45");
	c_GammaSet.AddString(L"0.50");
	c_GammaSet.AddString(L"0.55");
	c_GammaSet.AddString(L"0.60");
	c_GammaSet.AddString(L"0.65");
	c_GammaSet.AddString(L"0.70");
	c_GammaSet.AddString(L"0.75");
	c_GammaSet.AddString(L"0.80");
	c_GammaSet.AddString(L"0.85");
	c_GammaSet.AddString(L"0.90");
	c_GammaSet.AddString(L"0.95");
	c_GammaSet.AddString(L"1.00");
	c_GammaSet.SetCurSel(retValue);

	//HWND hListSld2DNoise = GetDlgItem(hwnd, IDC_SLD_2D_NOISE_REDU_VAL);
	//hr = getExtControlValue(5, &retValue);  //using original 3D NR ID &initCtrlSetting.NoiseReductionControl
	retValue = initCtrlSetting.NoiseReductionControl;
	if (FAILED(hr))
	{
		c_sld2DNRLevel.EnableWindow(FALSE);
	}
	SendMessageA(c_sld2DNRLevel, TBM_SETRANGEMAX, TRUE, 255);
	SendMessageA(c_sld2DNRLevel, TBM_SETRANGEMIN, TRUE, 0);
	SendMessageA(c_sld2DNRLevel, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sld2DNRLevel, TBM_SETPOS, TRUE, retValue);

	//HWND hListEdit2DNoiseRedu = GetDlgItem(hwnd, IDC_EDIT_2D_NOISE_REDU_VAL);
	retValueStr.Format(L"%d", retValue);
	txt_edt2DNRLevel.ReplaceSel(retValueStr, TRUE);
	txt_edt2DNRLevel.EnableWindow(FALSE);

	int startLvl = 0, endLvl = 0;
	//hr = getExt2ControlValues(26, &startLvl, &endLvl); //&initCtrlSetting.NR2DGainStart, &initCtrlSetting.NR2DGainEnd
	startLvl = initCtrlSetting.NR2DGainStart;
	endLvl = initCtrlSetting.NR2DGainEnd;

	//HWND hListSld2DNRStartLVL = GetDlgItem(hwnd, IDC_SLD_2D_NR_GAINSTR_VAL);

	SendMessageA(c_sld2DNRGainstart, TBM_SETRANGEMAX, TRUE, 0xB1);
	SendMessageA(c_sld2DNRGainstart, TBM_SETRANGEMIN, TRUE, 0);
	SendMessageA(c_sld2DNRGainstart, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sld2DNRGainstart, TBM_SETPOS, TRUE, startLvl);

	//HWND hListEdit2DNRStartLVL = GetDlgItem(hwnd, IDC_EDIT_2D_NR_GAINSTR_VAL);
	//Edit_SetText(hListAGCLVL, L"0");
	txt_edt2DNRGainStart.EnableWindow(FALSE);
	retValueStr.Format(L"%d", startLvl);
	txt_edt2DNRGainStart.ReplaceSel(retValueStr, TRUE);

	//HWND hListSld2DNREndLVL = GetDlgItem(hwnd, IDC_SLD_2D_NR_GAINEND_VAL);

	SendMessageA(c_sld2DNRGainend, TBM_SETRANGEMAX, TRUE, 0xB2);
	SendMessageA(c_sld2DNRGainend, TBM_SETRANGEMIN, TRUE, 1);
	SendMessageA(c_sld2DNRGainend, TBM_SETPAGESIZE, TRUE, 1);
	SendMessageA(c_sld2DNRGainend, TBM_SETPOS, TRUE, endLvl);

	//HWND hListEdit2DNREndLVL = GetDlgItem(hwnd, IDC_EDIT_2D_NR_GAINEND_VAL);
	//Edit_SetText(hListAGCLVL, L"0");
	txt_edt2DNRGainEnd.EnableWindow(FALSE);
	retValueStr.Format(L"%d", endLvl);
	txt_edt2DNRGainEnd.ReplaceSel(retValueStr, TRUE);

	if (initCtrlSetting.NoiseReductionMode != 0){
		c_2DNRenable.SetCheck(BST_CHECKED);
		c_sld2DNRLevel.EnableWindow(TRUE);
		c_sld2DNRGainend.EnableWindow(TRUE);
		c_sld2DNRGainstart.EnableWindow(TRUE);

	}
	else{
		c_2DNRenable.SetCheck(BST_UNCHECKED);
		c_sld2DNRLevel.EnableWindow(FALSE);
		c_sld2DNRGainend.EnableWindow(FALSE);
		c_sld2DNRGainstart.EnableWindow(FALSE);

	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void VIS5mpBWGam2DN::saveGammaInitSetting()
{
	initCtrlSetting.NoiseReductionMode = 0;
	initCtrlSetting.NoiseReductionControl = 0;

	// get current Value
	getExtControlValue(27, &initCtrlSetting.GammaCorrect);
	getExtControlValue(4, &initCtrlSetting.NoiseReductionMode);
	getExtControlValue(5, &initCtrlSetting.NoiseReductionControl);
	getExt2ControlValues(26, &initCtrlSetting.NR2DGainEnd, &initCtrlSetting.NR2DGainStart);
}

void VIS5mpBWGam2DN::OnNMReleasedcaptureSld2dNoiseReduVal(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	long noiseRedSldPos = 0;
	CString strPos;
	//HWND hListSld2DNoise = GetDlgItem(hwnd, IDC_SLD_2D_NOISE_REDU_VAL);
	noiseRedSldPos = (long)SendMessageA(c_sld2DNRLevel, TBM_GETPOS, TRUE, noiseRedSldPos);

	//HWND hListEdit2DNoise = GetDlgItem(hwnd, IDC_EDIT_2D_NOISE_REDU_VAL);
	strPos.Format(L"%ld", noiseRedSldPos);
	txt_edt2DNRLevel.SetSel(0, -1);
	txt_edt2DNRLevel.Clear();
	txt_edt2DNRLevel.ReplaceSel(strPos, TRUE);

	if (camNodeTree->isOK)
	{
		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 5;

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
				memcpy(pbPropertyValue, (char*)&noiseRedSldPos, ulSize);
				hr = setExtionControlProperty(PropertId, ulSize, pbPropertyValue);
			}
			delete[] pbPropertyValue;
		}

#ifdef DEBUG
//		sprintf(logMessage, "\nFunction : on3DNoiseRedLvlChange \t Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}

	*pResult = 0;
}


void VIS5mpBWGam2DN::OnNMReleasedcaptureSld2dNrGainendVal(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	GainStartnEndChange();
	*pResult = 0;
}


void VIS5mpBWGam2DN::OnNMReleasedcaptureSld2dNrGainstrVal(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	GainStartnEndChange();
	*pResult = 0;
}


void VIS5mpBWGam2DN::OnCbnSelchangeComboGammaMode()
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	//HWND hListCombGammaMode = GetDlgItem(hwnd, IDC_COMBO_GAMMA_MODE);

	int sel = c_GammaSet.GetCurSel();

	if (sel != LB_ERR && camNodeTree->isOK)
	{

		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 27;

		hr = getExtionControlPropertySize(PropertId, &ulSize);
		if (FAILED(hr))
		{
#ifdef DEBUG
//			sprintf(logMessage, "\nERROR \t Function : On3DNoiseReductionMode \t Msg : Unable to find property size : %x", hr);
//			printLogMessage(logMessage);
#endif
		}
		else
		{
			pbPropertyValue = new BYTE[ulSize];
			if (!pbPropertyValue)
			{
#ifdef DEBUG
//				sprintf(logMessage, "\nERROR \t Function : On3DNoiseReductionMode \t Msg : Unable to allocate memory for property value");
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
//		sprintf(logMessage, "\nFunction : On3DNoiseReductionMode \t Msg : Return Value:%ld", hr);
//		printLogMessage(logMessage);
#endif
	}

}


void VIS5mpBWGam2DN::GainStartnEndChange()
{
	HRESULT hr = S_OK;
	long startSldPos = 0, endSldPos = 0;
	CString strPos;

	//HWND hListSld2DNRStartLVL = GetDlgItem(hwnd, IDC_SLD_2D_NR_GAINSTR_VAL);
	startSldPos = (long)SendMessageA(c_sld2DNRGainstart, TBM_GETPOS, TRUE, startSldPos);

	//HWND hListEdit2DNRStartLVL = GetDlgItem(hwnd, IDC_EDIT_2D_NR_GAINSTR_VAL);
	strPos.Format(L"%d", startSldPos);
	txt_edt2DNRGainStart.SetSel(0, -1);
	txt_edt2DNRGainStart.Clear();
	txt_edt2DNRGainStart.ReplaceSel(strPos, TRUE);

	//HWND hListSld2DNREndLVL = GetDlgItem(hwnd, IDC_SLD_2D_NR_GAINEND_VAL);
	endSldPos = (long)SendMessageA(c_sld2DNRGainend, TBM_GETPOS, TRUE, endSldPos);

	//HWND hListEdit2DNREndLVL = GetDlgItem(hwnd, IDC_EDIT_2D_NR_GAINEND_VAL);
	strPos.Format(L"%d", endSldPos);
	txt_edt2DNRGainEnd.SetSel(0, -1);
	txt_edt2DNRGainEnd.Clear();
	txt_edt2DNRGainEnd.ReplaceSel(strPos, TRUE);

	if (camNodeTree->isOK)
	{
		ULONG ulSize;
		BYTE *pbPropertyValue;
		int PropertId = 26;

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


void VIS5mpBWGam2DN::OnBnClicked2dnrEnabl()
{
	// TODO: Add your control notification handler code here
	HRESULT hr = S_OK;
	int enable2DNR = 0;

	//HWND hListSld2DNoise = GetDlgItem(hwnd, IDC_SLD_2D_NOISE_REDU_VAL);
	//HWND hListSld2DNRStartLVL = GetDlgItem(hwnd, IDC_SLD_2D_NR_GAINSTR_VAL);
	//HWND hListSld2DNREndLVL = GetDlgItem(hwnd, IDC_SLD_2D_NR_GAINEND_VAL);
	
	if (c_2DNRenable.GetCheck() == BST_CHECKED){
		c_sld2DNRLevel.EnableWindow(TRUE);
		c_sld2DNRGainstart.EnableWindow(TRUE);
		c_sld2DNRGainend.EnableWindow(TRUE);
		enable2DNR = 1;
	}
	else{
		c_sld2DNRLevel.EnableWindow(FALSE);
		c_sld2DNRGainstart.EnableWindow(FALSE);
		c_sld2DNRGainend.EnableWindow(FALSE);
		enable2DNR = 0;
	}

	if (camNodeTree->isOK)
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
				memcpy(pbPropertyValue, (char*)&enable2DNR, ulSize);
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


void VIS5mpBWGam2DN::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class
	//HWND hListCombGammaMode = GetDlgItem(hwnd, IDC_COMBO_GAMMA_MODE);
	int checked;
	int sel = c_GammaSet.GetCurSel();
	if (sel != initCtrlSetting.GammaCorrect)
		setExtControls(27, initCtrlSetting.GammaCorrect);
#if 0  // for 2DNR enable
	HWND hListWhiteBalanceMode = GetDlgItem(hwnd, IDC_COMBO_3D_NOISE_REDU_MODE);
	int sel = ComboBox_GetCurSel(hListWhiteBalanceMode);
	if (sel != initCtrlSetting.NoiseReductionMode)
		setExtControls(4, initCtrlSetting.NoiseReductionMode);
#endif

	//HWND hListSld2DNoise = GetDlgItem(hwnd, IDC_SLD_2D_NOISE_REDU_VAL);
	long arSldPos = (long)SendMessageA(c_sld2DNRLevel, TBM_GETPOS, TRUE, arSldPos);
	if (arSldPos != initCtrlSetting.NoiseReductionControl)
		setExtControls(5, initCtrlSetting.NoiseReductionControl);

	//HWND hListSld2DNRStartLVL = GetDlgItem(hwnd, IDC_SLD_2D_NR_GAINSTR_VAL);
	int StartSldPos = (int)SendMessageA(c_sld2DNRGainstart, TBM_GETPOS, TRUE, StartSldPos);

	//HWND hListSld2DNREndLVL = GetDlgItem(hwnd, IDC_SLD_2D_NR_GAINEND_VAL);
	int EndSldPos = (int)SendMessageA(c_sld2DNRGainend, TBM_GETPOS, TRUE, EndSldPos);

	if ((StartSldPos != initCtrlSetting.NR2DGainStart) || (EndSldPos != initCtrlSetting.NR2DGainEnd))
	{
		setExt2ControlValues(26, initCtrlSetting.NR2DGainStart, initCtrlSetting.NR2DGainEnd);
	}

	if (c_2DNRenable.GetCheck() == BST_CHECKED){
		checked = 1;
	}
	else{
		checked = 0;
	}
	if (checked != initCtrlSetting.NoiseReductionMode)
		setExtControls(4, initCtrlSetting.NoiseReductionMode);

	CDialog::OnCancel();
}
