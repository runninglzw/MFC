
// test9-5Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"

struct Info
{
	int id;
	char name[20];
	double pay;
};
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

	bool changed;//部门的员工信息是否被修改
	afx_msg void OnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult);
	CString GetPath(HTREEITEM item);
	int GetDepth(HTREEITEM item);
	void Save();
	void Load();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
