#pragma once


// Cpage1 对话框

class Cpage1 : public CPropertyPage
{
	DECLARE_DYNAMIC(Cpage1)

public:
	Cpage1();
	virtual ~Cpage1();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	CString m_id;
};
