// Page1.cpp : 实现文件
//

#include "stdafx.h"
#include "test9-2.h"
#include "Page1.h"
#include "afxdialogex.h"


// CPage1 对话框

IMPLEMENT_DYNAMIC(CPage1, CDialogEx)

CPage1::CPage1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage1::IDD, pParent)
	, m_id(_T(""))
{

}

CPage1::~CPage1()
{
}

//void CPage1::DoDataExchange(CDataExchange* pDX)
//{
//	CDialogEx::DoDataExchange(pDX);
//	//  DDX_Text(pDX, IDC_ID, m_id);
//	//  DDX_Text(pDX, IDC_ID, m_id);
//	//  DDX_Control(pDX, IDC_ID, m_id);
//	DDX_Text(pDX, IDC_ID, m_id);
//}


BEGIN_MESSAGE_MAP(CPage1, CDialogEx)
	ON_BN_CLICKED(IDOK, &CPage1::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CPage1::OnBnClickedCancel)
END_MESSAGE_MAP()


// CPage1 消息处理程序


void CPage1::OnBnClickedOk()
{
	//回车相当于点击父窗口的下一步，在这之前子窗口必须获得焦点
	GetParent()->PostMessage(WM_COMMAND,IDNEXT);
	//CDialogEx::OnOK();
}


void CPage1::OnBnClickedCancel()
{
	// 按Esc相当于点击父窗口的取消按钮，在此之前子窗口必须获得焦点
	GetParent()->PostMessage(WM_COMMAND,IDCANCEL);
	//CDialogEx::OnCancel();
}


void CPage1::DoDataExchange(CDataExchange* pDX)
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ID, m_id);
}
