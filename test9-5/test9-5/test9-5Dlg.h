
// test9-5Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"


// Ctest95Dlg 对话框
class Ctest95Dlg : public CDialogEx
{
// 构造
public:
	Ctest95Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TEST95_DIALOG };

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
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CListCtrl m_list;
	CTreeCtrl m_tree;
	afx_msg void OnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult);
	CString GetPath(HTREEITEM item);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
