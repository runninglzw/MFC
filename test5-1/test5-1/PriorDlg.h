#pragma once


// CPriorDlg 对话框

class CPriorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPriorDlg)

public:
	CPriorDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPriorDlg();

// 对话框数据
	enum { IDD = IDD_PRIOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDel();
	afx_msg void OnBnClickedModify();
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnDestroy();
	void Readuesr(CListCtrl * p);
};
