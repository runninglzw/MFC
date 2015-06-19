#pragma once


// CInsertPeople 对话框
#include "InfoDlg.h"
class CInsertPeople : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertPeople)

public:
	CInfoDlg* infodlg;
	CInsertPeople(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInsertPeople();
	//CInfoDlg *infodlg;
// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
