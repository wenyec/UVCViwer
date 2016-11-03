// GetDevice.cpp : implementation file
//

#include "stdafx.h"
#include "GetDevice.h"
#include "afxdialogex.h"


// GetDevice dialog

IMPLEMENT_DYNAMIC(GetDevice, CDialog)

GetDevice::GetDevice(CWnd* pParent /*=NULL*/)
	: CDialog(GetDevice::IDD, pParent)
{

}

GetDevice::~GetDevice()
{
}

void GetDevice::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DEVICE_LIST, m_DevNameList);
}



BEGIN_MESSAGE_MAP(GetDevice, CDialog)
END_MESSAGE_MAP()


// GetDevice message handlers

void cIMonRelease(IMoniker *&pm)
{
	if (pm)
	{
		pm->Release();
		pm = 0;
	}
}

void GetDevice::DeviceNameToMenu()
{
	if (devCap->fDeviceMenuPopulated)
	{
		return;
	}
	devCap->fDeviceMenuPopulated = true;
	devCap->iNumVCapDevices = 0;
	devCap->iSelectedDeviceIndex = -1;

	UINT    uIndex = 0;
	HRESULT hr;

	for (int i = 0; i < NUMELMS(devCap->rgpmVideoMenu); i++)
	{
		cIMonRelease(devCap->rgpmVideoMenu[i]);
	}
	for (int i = 0; i < NUMELMS(devCap->rgpmAudioMenu); i++)
	{
		cIMonRelease(devCap->rgpmAudioMenu[i]);
	}


	// enumerate all video capture devices
	ICreateDevEnum *pCreateDevEnum = 0;
	hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC_SERVER,
		IID_ICreateDevEnum, (void**)&pCreateDevEnum);
	if (hr != NOERROR)
	{

#ifdef DEBUG
		//sprintf(logMessage, " \nERROR \t Function : AddDevicesToMenu \t Msg :  Error Creating Device Enumerator");
		//printLogMessage(logMessage);
#endif
		return;
	}

	IEnumMoniker *pEm = 0;
	hr = pCreateDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory, &pEm, 0);
	if (hr != NOERROR)
	{
#ifdef DEBUG
		//sprintf(logMessage, " \nERROR \t Function : AddDevicesToMenu \t Msg :  Sorry, you have no video capture hardware.\r\nVideo capture will not function properly.");
		//printLogMessage(logMessage);
#endif

		goto EnumAudio;
	}

	pEm->Reset();
	ULONG cFetched;
	IMoniker *pM;

	devCap->defaultVideoLogyCamID = -2;

	while (hr = pEm->Next(1, &pM, &cFetched), hr == S_OK)
	{
		IPropertyBag *pBag = 0;

		hr = pM->BindToStorage(0, 0, IID_IPropertyBag, (void **)&pBag);
		if (SUCCEEDED(hr))
		{
			VARIANT var;
			var.vt = VT_BSTR;
			hr = pBag->Read(L"DevicePath", &var, NULL);

			CStringW visName = var.bstrVal;
			visName = visName.MakeLower();
			if (visName.Find(L"usb#") < 0)
				continue;
			int i = visName.Find(L"vid_");
			ULONG vid = wcstol(visName.Mid(i + 4, 4), NULL, 16);
			i = visName.Find(L"pid_");

			ULONG pid = wcstol(visName.Mid(i + 4, 4), NULL, 16);
			ULONG vidpid = (vid<<16) | pid;

			wchar_t *ptr = wcsstr(var.bstrVal, L"vid_1bbd");

			if (ptr != nullptr && devCap->defaultVideoLogyCamID == -2)
			{
				devCap->defaultVideoLogyCamID = -1;
			}
			//hr = pBag->Read(L"Description", &var, NULL);
			hr = pBag->Read(L"FriendlyName", &var, NULL);

#ifdef DEBUG
			//sprintf(logMessage, " \nFunction : AddDevicesToMenu \t Msg : FriendlyName  %ls", var.bstrVal);
			//printLogMessage(logMessage);
#endif

			if (hr == NOERROR)
			{
				if (devCap->defaultVideoLogyCamID == -1)
					devCap->defaultVideoLogyCamID = uIndex;
				ASSERT(devCap->rgpmVideoMenu[uIndex] == 0);
				devCap->rgpmVideoMenu[uIndex] = pM;
				wcscpy(devCap->vis_camID[uIndex].rgpmVideoFriendlyName, var.bstrVal);//gcap.vis_camID[uIndex].
				devCap->vis_camID[uIndex].VidPid = vidpid;

				SysFreeString(var.bstrVal);

				pM->AddRef();
				uIndex++;
			}
			pBag->Release();
		}

		pM->Release();

	}
	pEm->Release();

	devCap->iNumVCapDevices = uIndex;
	if (devCap->iNumVCapDevices > 0)
		devCap->iSelectedDeviceIndex = 0;

	/*
	#ifdef DEBUG
	sprintf(logMessage, " \nFunction : AddDevicesToMenu \t Msg : IMoniker obj for vid Device found  %d", devCap->.iNumVCapDevices);
	printLogMessage(logMessage);
	#endif
	*/

EnumAudio:

	// enumerate all audio capture devices
	uIndex = 0;

	ASSERT(pCreateDevEnum != NULL);

	hr = pCreateDevEnum->CreateClassEnumerator(CLSID_AudioInputDeviceCategory, &pEm, 0);
	pCreateDevEnum->Release();
	if (hr != NOERROR)
		return;
	pEm->Reset();

	while (hr = pEm->Next(1, &pM, &cFetched), hr == S_OK)
	{
		IPropertyBag *pBag;
		hr = pM->BindToStorage(0, 0, IID_IPropertyBag, (void **)&pBag);
		if (SUCCEEDED(hr))
		{
			VARIANT var;
			var.vt = VT_BSTR;
			hr = pBag->Read(L"FriendlyName", &var, NULL);
			if (hr == NOERROR)
			{
				ASSERT(devCap->rgpmAudioMenu[uIndex] == 0);
				devCap->rgpmAudioMenu[uIndex] = pM;
				wcsncpy(devCap->rgpmAudioFriendlyName[uIndex], var.bstrVal, sizeof(var.bstrVal));
				SysFreeString(var.bstrVal);

				pM->AddRef();
				uIndex++;
			}
			pBag->Release();
		}
		pM->Release();
	}

	pEm->Release();
}

BOOL GetDevice::OnInitDialog()
{
	CDialog::OnInitDialog();
	devCap->fDeviceMenuPopulated = false;
	DeviceNameToMenu(); // enumerate devide list for extended control.

	// TODO:  Add extra initialization here
	for (int i = 0; i < devCap->iNumVCapDevices; i++)
	{
		m_DevNameList.AddString(devCap->vis_camID[i].rgpmVideoFriendlyName);
	}
	//m_DevNameList.UpdateData();
	for (int i = 0; i < devCap->iNumVCapDevices; i++)
	{
		int index = m_DevNameList.FindString(-1, devCap->vis_camID[i].rgpmVideoFriendlyName);
		m_DevNameList.SetItemData(index, i);
	}


	// Assume no selection for now.
	// gcap.iSelectedDeviceIndex = (UINT32)-1;

	if (devCap->iNumVCapDevices == 0)
	{
		// If there are no devices, disable the "OK" button.
		//EnableWindow(GetDlgItem(hwnd, IDOK), FALSE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void GetDevice::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	int sel = m_DevNameList.GetCurSel();
	
	if (sel != LB_ERR)
	{
		devCap->iSelectedDeviceIndex = (UINT32)m_DevNameList.GetItemData(sel);
		int j;
		for (j = 0; j < 5; j++){
			if (devCap->vis_camID[devCap->iSelectedDeviceIndex].VidPid == visCamID[j].VidPid){
				devCap->CamIndex = j;
				break;
			}
		}
		if (j >= 5){
			devCap->CamIndex = 0xff; //it's not VIS camera.
		}
	}
	CDialog::OnOK();
}


void GetDevice::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class

	CDialog::OnCancel();
}
