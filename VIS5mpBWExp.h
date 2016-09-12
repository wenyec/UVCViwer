#pragma once
#include "resource.h"
//#include "afxwin.h"
#include "winmain.h"
#include "afxwin.h"
#include "afxcmn.h"

// VIS5mpBWExp dialog

class VIS5mpBWExp : public CDialog
{
	DECLARE_DYNAMIC(VIS5mpBWExp)

public:
	VIS5mpBWExp(CWnd* pParent = NULL);   // standard constructor
	virtual ~VIS5mpBWExp();

// Dialog Data
	enum { IDD = IDD_CAM_CONTROL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void saveCameraControlInitSetting();
	_capstuff *devCap;
	EXT_KS_TREE *camNodeTree;
private:
	CComboBox c_ExpMode;
	CComboBox c_ShutCtrl;
	CButton c_FineShuChk;
	CSliderCtrl c_sldShuLvl;
	CEdit tx_edtShuLvl;
	CSliderCtrl c_sldGainCtrl;
	CEdit tx_edtGainCtrl;
	CSliderCtrl c_sldAERefLvl;
	CEdit tx_edtAERefLvl;
	CSliderCtrl c_sldAEHystCtrl;
	CEdit tx_edtAEHystCtrl;
	CSliderCtrl c_sldSpedCtrl;
	CEdit tx_edtSpedCtrl;
	CComboBox c_BLKCompCtrl;
	CSliderCtrl c_sldBLKWgtCtrl;
	CEdit tx_edtBLKWgtCtrl;
	CComboBox c_BLKGrid;
	CSliderCtrl c_sldHPosCtrl;
	CEdit tx_edtHPosCtrl;
	CSliderCtrl c_sldVPosCtrl;
	CEdit tx_edtVPosCtrl;
	CSliderCtrl c_sldHSizeCtrl;
	CEdit tx_edtHSizeCtrl;
	CSliderCtrl c_sldVSizeCtrl;
	CEdit tx_edtVSizeCtrl;

	void VIS5mpBWExp::BLCRangeChange();
public:
	afx_msg void OnCbnSelchangeComboExposureMode();
	afx_msg void OnCbnSelchangeComboShutContl();
	afx_msg void OnBnClickedFineShutterEnable();
//	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnNMReleasedcaptureSldShutLvl(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldAeCtrlspeed(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldAgcLvl(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldAeRefLvl(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldAeHyster(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldBlcwlvl(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldHpos(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldVpos(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldHsize(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldVsize(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeComboBackLight();
	afx_msg void OnCbnSelchangeComboBlcGrid();
	virtual void OnCancel();
	CSliderCtrl c_sldAEMaxLvl;
private:
	CEdit tx_edtAEMaxLvl;
public:
	afx_msg void OnNMReleasedcaptureSldAeMaxLvl(NMHDR *pNMHDR, LRESULT *pResult);
};
