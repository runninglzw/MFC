// MainDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test9-2.h"
#include "test9-2Dlg.h"
#include "MainDlg.h"
#include "afxdialogex.h"


// CMainDlg 对话框

IMPLEMENT_DYNAMIC(CMainDlg, CDialogEx)

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainDlg::IDD, pParent)
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMainDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMainDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDADD, &CMainDlg::OnBnClickedAdd)
END_MESSAGE_MAP()


// CMainDlg 消息处理程序


void CMainDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CMainDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


BOOL CMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list.InsertColumn(0,"账号",0,80);
	m_list.InsertColumn(1,"姓名",0,80);
	m_list.InsertColumn(2,"性别",0,80);
	return TRUE;
}

//添加按钮
void CMainDlg::OnBnClickedAdd()
{
	Ctest92Dlg dlg;
	if(IDCANCEL==dlg.DoModal())
		return;
	int i=m_list.GetItemCount();
	m_list.InsertItem(i,dlg.m_p1.m_id);
}
