// ModDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test9-2.h"
#include "ModDlg.h"
#include "afxdialogex.h"


// CModDlg 对话框

IMPLEMENT_DYNAMIC(CModDlg, CDialogEx)

CModDlg::CModDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CModDlg::IDD, pParent)
{

}

CModDlg::~CModDlg()
{
}

void CModDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}


BEGIN_MESSAGE_MAP(CModDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CModDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CModDlg::OnBnClickedCancel)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CModDlg::OnSelchangeTab1)
END_MESSAGE_MAP()


// CModDlg 消息处理程序

//确认修改
void CModDlg::OnBnClickedOk()
{
	//将界面更新到内存（m_p1）中
	m_p1.UpdateData();
	m_p2.UpdateData();
	m_p3.UpdateData();
	CDialogEx::OnOK();
}


void CModDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


BOOL CModDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//m_tab中插入菜单项
	m_tab.InsertItem(0,"账号");
	m_tab.InsertItem(1,"姓名");
	m_tab.InsertItem(2,"性别");
	//创建子页
	m_p1.Create(IDD_DIALOG1,this);
	m_p2.Create(IDD_DIALOG2,this);
	m_p3.Create(IDD_DIALOG3,this);
	//获得m_tab的放置位置
	CRect rect,rt;
	m_tab.GetWindowRect(rect);
	ScreenToClient(rect);
	//获得标头的位置
	m_tab.GetItemRect(0,rt);
	//获得子页位置
	rect.top+=rt.Height();
	//高度和宽度都缩小3
	rect.DeflateRect(3,3);
	//子页移动到rect位置
	m_p1.MoveWindow(rect,FALSE);
	m_p2.MoveWindow(rect,FALSE);
	m_p3.MoveWindow(rect,FALSE);
	m_p1.MoveWindow(rect,FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control

}

//m_tab标头更改时发生
void CModDlg::OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	int sel=m_tab.GetCurSel();
	CWnd *ps[]={&m_p1,&m_p2,&m_p3};
	int i=0;
	while(i<sizeof(ps)/sizeof(ps[0]))
		ps[i++]->ShowWindow(i==sel?SW_SHOW:SW_HIDE);
	*pResult = 0;
}
