// InfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test5-1.h"
#include "InfoDlg.h"
#include "afxdialogex.h"


// CInfoDlg 对话框

IMPLEMENT_DYNAMIC(CInfoDlg, CDialogEx)

CInfoDlg::CInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInfoDlg::IDD, pParent)
{

}

CInfoDlg::~CInfoDlg()
{
}

void CInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CInfoDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CInfoDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CInfoDlg 消息处理程序


void CInfoDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void CInfoDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnCancel();
}
