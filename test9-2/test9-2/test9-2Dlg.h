
// test9-2Dlg.h : 头文件
//
#include"Page1.h"
#include"Page2.h"
#include"Page3.h"


#pragma once


// Ctest92Dlg 对话框
class Ctest92Dlg : public CDialogEx
{
// 构造

public:
	Ctest92Dlg(CWnd* pParent = NULL);	// 标准构造函数
	void SelectPage();
	CPage1 m_p1;
	CPage2 m_p2;
	CPage3 m_p3;
	int m_sel;
// 对话框数据
	enum { IDD = IDD_TEST92_DIALOG };

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
	afx_msg void OnBnClickedNext();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedBefor();
};
