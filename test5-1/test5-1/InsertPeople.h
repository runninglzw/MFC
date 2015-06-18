#pragma once


// CInsertPeople 对话框

class CInsertPeople : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertPeople)

public:
	CInsertPeople(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInsertPeople();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
