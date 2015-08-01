#pragma once


// Cpage2 对话框

class Cpage2 : public CPropertyPage
{
	DECLARE_DYNAMIC(Cpage2)

public:
	Cpage2();
	virtual ~Cpage2();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
