#pragma once
#include "resource.h"
#include "winmain.h"
#include "afxwin.h"
#include "afxcmn.h"

// VIS5mpBWGam2DN dialog

class VIS5mpBWGam2DN : public CDialog
{
	DECLARE_DYNAMIC(VIS5mpBWGam2DN)

public:
	VIS5mpBWGam2DN(CWnd* pParent = NULL);   // standard constructor
	virtual ~VIS5mpBWGam2DN();

// Dialog Data
	enum { IDD = IDD_3D_NOISE_REDUCTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	_capstuff *devCap;
	EXT_KS_TREE *camNodeTree;
private:
	CComboBox c_GammaSet;
	CButton c_2DNRenable;
	CSliderCtrl c_sld2DNRLevel;
	CSliderCtrl c_sld2DNRGainend;
	CSliderCtrl c_sld2DNRGainstart;
	CEdit txt_edt2DNRLevel;
	CEdit txt_edt2DNRGainEnd;
	CEdit txt_edt2DNRGainStart;
public:
	void saveGammaInitSetting();
//	afx_msg void OnCbnEditchangeComboGammaMode();
	afx_msg void OnNMReleasedcaptureSld2dNoiseReduVal(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSld2dNrGainendVal(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSld2dNrGainstrVal(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeComboGammaMode();
	void GainStartnEndChange();
	afx_msg void OnBnClicked2dnrEnabl();
	virtual void OnCancel();
};
