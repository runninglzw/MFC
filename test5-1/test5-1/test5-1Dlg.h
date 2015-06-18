
// test5-1Dlg.h : 头文件
//

#pragma once


// Ctest51Dlg 对话框
class Ctest51Dlg : public CDialogEx
{
// 构造
public:
	Ctest51Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TEST51_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedRelogin();
	afx_msg void OnBnClickedSearch();
	afx_msg void OnBnClickedInfo();
};
