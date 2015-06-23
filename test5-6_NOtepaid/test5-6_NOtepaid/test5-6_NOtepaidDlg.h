
// test5-6_NOtepaidDlg.h : 头文件
//

#pragma once


// Ctest56_NOtepaidDlg 对话框
class Ctest56_NOtepaidDlg : public CDialogEx
{
// 构造
public:
	Ctest56_NOtepaidDlg(CWnd* pParent = NULL);	// 标准构造函数
	CEdit m_edit;//绑定编辑框信息
    CFont m_font;//保存字体信息
	CRect m_rect;//保存对话框变化前的大小

// 对话框数据
	enum { IDD = IDD_TEST56_NOTEPAID_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnOpen();
	afx_msg void OnCancel();
	afx_msg void OnFont();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnAbout();
	afx_msg void OnCut();
	afx_msg void OnCopy();
	afx_msg void OnChexiao();
	afx_msg void OnNewfile();
};
