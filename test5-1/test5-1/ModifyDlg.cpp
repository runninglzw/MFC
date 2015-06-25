// ModifyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test5-1.h"
#include "ModifyDlg.h"
#include "afxdialogex.h"


// CModifyDlg 对话框

IMPLEMENT_DYNAMIC(CModifyDlg, CDialogEx)

CModifyDlg::CModifyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CModifyDlg::IDD, pParent)
	, m_bumen(_T(""))
	, m_birth(COleDateTime::GetCurrentTime())
	, m_name(_T(""))
	, m_pay(0)
	, m_id(0)
{

}

CModifyDlg::~CModifyDlg()
{
}

void CModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBOBUMEN, m_bumen);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_birth);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_PAY, m_pay);
	DDX_Text(pDX, IDC_ID, m_id);
}


BEGIN_MESSAGE_MAP(CModifyDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CModifyDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CModifyDlg 消息处理程序


void CModifyDlg::OnBnClickedOk()
{
	if(IDYES==AfxMessageBox("确定修改该信息？",MB_YESNO))
		CDialogEx::OnOK();
}
