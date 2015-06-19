// InfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test5-1.h"
#include "InfoDlg.h"
#include "afxdialogex.h"
#include "insertpeople.h"


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
	ON_BN_CLICKED(IDC_ADD, &CInfoDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_QUIT, &CInfoDlg::OnBnClickedQuit)
	ON_BN_CLICKED(IDC_MODIFY, &CInfoDlg::OnBnClickedModify)
	ON_BN_CLICKED(IDC_DEL, &CInfoDlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_OPEN, &CInfoDlg::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_SAVE, &CInfoDlg::OnBnClickedSave)
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


BOOL CInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	p.SubclassDlgItem(IDC_LIST1,this);
	p.InsertColumn(0,"工号",0,60);
	p.InsertColumn(1,"姓名",0,60);
	p.InsertColumn(2,"生日",0,100);
	p.InsertColumn(3,"部门",0,100);
	p.InsertColumn(4,"工资",0,100);
	return TRUE;
}

//添加成员
void CInfoDlg::OnBnClickedAdd()
{
	CInsertPeople dlg;
	//设置InsertPeople对话框的infodlg指针（指向CInfoDlg），这样在InsertPeople对话框中就可以给CInfoDlg中的列表控件赋值了
	dlg.infodlg=this;
	dlg.DoModal();
}

//退出
void CInfoDlg::OnBnClickedQuit()
{
	CDialogEx::OnCancel();
}

//修改员工信息
void CInfoDlg::OnBnClickedModify()
{
	// TODO: 在此添加控件通知处理程序代码
}

//删除员工信息
void CInfoDlg::OnBnClickedDel()
{
	// TODO: 在此添加控件通知处理程序代码
}

//打开文件读取员工信息
void CInfoDlg::OnBnClickedOpen()
{
	// TODO: 在此添加控件通知处理程序代码
}

//将员工信息保存到文件中
void CInfoDlg::OnBnClickedSave()
{
	// TODO: 在此添加控件通知处理程序代码
}
