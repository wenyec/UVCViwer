#pragma once
#include "resource.h"
#include "winmain.h"
#include "afxwin.h"
#include "afxcmn.h"

// VIS5MPColSupWBL dialog

class VIS5MPColSupWBL : public CDialog
{
	DECLARE_DYNAMIC(VIS5MPColSupWBL)

public:
	void saveColSupWBLInitSetting();
	_capstuff *devCap;
	EXT_KS_TREE *camNodeTree;

	VIS5MPColSupWBL(CWnd* pParent = NULL);   // standard constructor
	virtual ~VIS5MPColSupWBL();

// Dialog Data
	enum { IDD = IDD_WBL_COLORSUPP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:

	CComboBox cb_WBLMode;
	CButton c_bP2WOn;
	CSliderCtrl c_sldWBLComBlue;
	CSliderCtrl c_sldWBLComRed;
	CEdit c_edtWBLComBlue;
	CEdit c_edtWBLComRed;
	CButton c_bColSupEnable;
	CSliderCtrl c_sldColSupGain;
	CSliderCtrl c_sldColSupAGCStart;
	CSliderCtrl c_sldColSupAGCEnd;
	CEdit c_edtColSupGain;
	CEdit c_edtColSupGainStart;
	CEdit c_edtColSupGainEnd;
	CSliderCtrl c_sldColSupEdgeGain;
	CSliderCtrl c_sldHighLowLightGain;
	CEdit c_edtColSupEdgeGain;
	CEdit c_edtHighLowLightGain;

	//void getRegVal(BYTE Regadd, int data);
	//void setRegVal(BYTE Regadd, int data);

public:
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	afx_msg void OnBnClickedColorSuppressionEnabl();
	afx_msg void OnBnClickedWblP2wEnabl();
	afx_msg void OnNMReleasedcaptureSldColsuppGainVal(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldColsuppGainendVal(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldColsuppGainstrVal(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldEdgeColsupGain(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldHightlowColsupGain(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldWhtcom(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldWhtcomRed(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeComboWhtblcmode2();
};
