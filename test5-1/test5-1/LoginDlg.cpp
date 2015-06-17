// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test5-1.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

	CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDlg::IDD, pParent)
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLoginDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


void CLoginDlg::OnBnClickedOk()
{
	CString strName,strPassword;
	GetDlgItemText(IDC_LOGIN,strName);
	GetDlgItemText(IDC_PASSWORD,strPassword);
	if(strName=="admin" && strPassword=="1")
		CDialogEx::OnOK();
	else
	{
		AfxMessageBox("用户名或者密码错误！");
		SetDlgItemText(IDC_LOGIN,"");
		SetDlgItemText(IDC_PASSWORD,"");
		//设置焦点
		GetDlgItem(IDC_LOGIN)->SetFocus();
	}
}


void CLoginDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
