#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "resource.h"


// VIS2mpColFocusZoom dialog

class VIS2mpColFocusZoom : public CDialog
{
	DECLARE_DYNAMIC(VIS2mpColFocusZoom)

public:
	VIS2mpColFocusZoom(CWnd* pParent = NULL);   // standard constructor
	virtual ~VIS2mpColFocusZoom();

// Dialog Data
	enum { IDD = IDD_ZOOM_CONTROL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CComboBox c_FocusMode;
	CComboBox c_ZoomTrack;
	CButton c_butFocusStart;
	CButton c_butFocusNear;
	CButton c_butFocusFar;
	CSliderCtrl c_sldDigZoom;
public:
	CEdit c_edtDigZoom;
private:
	CButton c_butZoomIn;
	CButton c_butZoomOut;
};
