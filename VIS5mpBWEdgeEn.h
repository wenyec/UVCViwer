#pragma once
#include "resource.h"
#include "winmain.h"
#include "afxwin.h"
#include "afxcmn.h"

// VIS5mpBWEdgeEn dialog

class VIS5mpBWEdgeEn : public CDialog
{
	DECLARE_DYNAMIC(VIS5mpBWEdgeEn)

public:
	VIS5mpBWEdgeEn(CWnd* pParent = NULL);   // standard constructor
	virtual ~VIS5mpBWEdgeEn();

// Dialog Data
	enum { IDD = IDD_ENHANCE_CONTROL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void saveEnhanceInitSetting();
	_capstuff *devCap;
	EXT_KS_TREE *camNodeTree;
private:
	CComboBox c_EdgeEnhanceM;
	CComboBox c_MainFreq;
	CComboBox c_MirrorCtrl;
	CSliderCtrl c_sldEdgeLevel;
	CSliderCtrl c_sldEdgeGainEnd;
	CSliderCtrl c_sldEdgeGainStart;
	CEdit txt_edtEdgeLevel;
	CEdit txt_edtEdgeGainEnd;
	CEdit txt_edtEdgeGainStart;

	void VIS5mpBWEdgeEn::OnStartEndChange();
public:
	afx_msg void OnCbnSelchangeComboEdgeenhnContl();
	afx_msg void OnCbnSelchangeComboMainFeq();
	afx_msg void OnCbnSelchangeComboMirrorMode();
	afx_msg void OnNMReleasedcaptureSldEdgegainLvl(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnNMReleasedcaptureSldGainEndLvl(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldGainStartLvl(NMHDR *pNMHDR, LRESULT *pResult);
//	virtual void OnCancel();
	afx_msg void OnNMReleasedcaptureSldGainEndLvl(NMHDR *pNMHDR, LRESULT *pResult);
	virtual void OnCancel();
};
