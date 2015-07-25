// Page2.cpp : 实现文件
//

#include "stdafx.h"
#include "test9-2.h"
#include "Page2.h"
#include "afxdialogex.h"


// CPage2 对话框

IMPLEMENT_DYNAMIC(CPage2, CDialogEx)

CPage2::CPage2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage2::IDD, pParent)
	, m_name(_T(""))
{

}

CPage2::~CPage2()
{
}

void CPage2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, m_name);
}


BEGIN_MESSAGE_MAP(CPage2, CDialogEx)
	ON_BN_CLICKED(IDOK, &CPage2::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CPage2::OnBnClickedCancel)
END_MESSAGE_MAP()


// CPage2 消息处理程序


void CPage2::OnBnClickedOk()
{
	//回车相当于点击父窗口的下一步
	GetParent()->PostMessage(WM_COMMAND,IDNEXT);
	//CDialogEx::OnOK();
}


void CPage2::OnBnClickedCancel()
{
	// 按Esc相当于点击父窗口的取消按钮，在此之前子窗口必须获得焦点
	GetParent()->PostMessage(WM_COMMAND,IDCANCEL);
	//CDialogEx::OnCancel();
}
