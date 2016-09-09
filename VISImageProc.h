#pragma once
#include "resource.h"
#include "winmain.h"
#include "afxwin.h"
#include "afxcmn.h"

// VISImageProc dialog

class VISImageProc : public CDialog
{
	DECLARE_DYNAMIC(VISImageProc)

public:
	VISImageProc(CWnd* pParent = NULL);   // standard constructor
	virtual ~VISImageProc();

// Dialog Data
	enum { IDD = IDD_VIDEO_QUALITY_CONTROL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void saveImageInitSetting();
	_capstuff *devCap;
	EXT_KS_TREE *camNodeTree;

private:
	CSliderCtrl c_sldBrightness;
	CSliderCtrl c_sldContrast;
	CSliderCtrl c_sldHue;
	CSliderCtrl c_sldSaturation;
private:
	CSliderCtrl c_sldSharpness;
private:
	CSliderCtrl c_sldWBLBlue;
private:
	CSliderCtrl c_sldWBLRed;

private:
	CComboBox c_WBLMode;
	CEdit txt_edtBrightness;
	CEdit txt_edtContrast;
	CEdit txt_edtHue;
	CEdit txt_edtSaturation;
	CEdit txt_edtSharpness;
	CEdit txt_edtWBLBlue;
	CEdit txt_edtWBLRed;
public:
	afx_msg void OnCbnSelchangeComboWhtblcmode();
	afx_msg void OnNMReleasedcaptureSldBrightness(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldContrast(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldHue(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldSaturation(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldSharpness(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldWhtcom(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSldWhtcomRed(NMHDR *pNMHDR, LRESULT *pResult);
	virtual void OnCancel();
};
