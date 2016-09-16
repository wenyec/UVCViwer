#pragma once
#include "resource.h"
#include "afxwin.h"
#include "winmain.h"

// GetDevice dialog

class GetDevice : public CDialog
{
	DECLARE_DYNAMIC(GetDevice)

public:
	GetDevice(CWnd* pParent = NULL);   // standard constructor
	virtual ~GetDevice();

// Dialog Data
	enum { IDD = IDD_CHOOSE_DEVICE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_DevNameList;
	virtual BOOL OnInitDialog();
	_capstuff *devCap;
	VIS_CameraID *visCamID;
private:
	void DeviceNameToMenu();
	virtual void OnOK();
	virtual void OnCancel();
};
