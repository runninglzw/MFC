// AddDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test12-1_SDI.h"
#include "AddDlg.h"
#include "afxdialogex.h"


// CAddDlg 对话框

IMPLEMENT_DYNAMIC(CAddDlg, CDialogEx)

CAddDlg::CAddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddDlg::IDD, pParent)
	, m_id(_T(""))
	, m_name(_T(""))
	, m_pay(_T(""))
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_pay);
}


BEGIN_MESSAGE_MAP(CAddDlg, CDialogEx)
END_MESSAGE_MAP()


// CAddDlg 消息处理程序
