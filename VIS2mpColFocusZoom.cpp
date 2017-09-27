// VIS2mpColFocusZoom.cpp : implementation file
//

#include "stdafx.h"
#include "VIS2mpColFocusZoom.h"
#include "afxdialogex.h"


// VIS2mpColFocusZoom dialog

IMPLEMENT_DYNAMIC(VIS2mpColFocusZoom, CDialog)

VIS2mpColFocusZoom::VIS2mpColFocusZoom(CWnd* pParent /*=NULL*/)
	: CDialog(VIS2mpColFocusZoom::IDD, pParent)
{

}

VIS2mpColFocusZoom::~VIS2mpColFocusZoom()
{
}

void VIS2mpColFocusZoom::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_FOCUS_MODE, c_FocusMode);
	DDX_Control(pDX, IDC_COMBO_FOCUS_ZOOMTRC, c_ZoomTrack);
	DDX_Control(pDX, IDC_BTN_FOCUS_START, c_butFocusStart);
	DDX_Control(pDX, IDC_BTN_FOCUS_NEAR, c_butFocusNear);
	DDX_Control(pDX, IDC_BTN_FOCUS_FAR, c_butFocusFar);
	DDX_Control(pDX, IDC_SLD_DIG_ZOOM_POS, c_sldDigZoom);
	DDX_Control(pDX, IDC_EDIT_DIG_ZOOM_POS, c_edtDigZoom);
	DDX_Control(pDX, IDC_BTN_ZOOM_IN, c_butZoomIn);
	DDX_Control(pDX, IDC_BTN_ZOOM_OUT, c_butZoomOut);
}


BEGIN_MESSAGE_MAP(VIS2mpColFocusZoom, CDialog)
END_MESSAGE_MAP()


// VIS2mpColFocusZoom message handlers
