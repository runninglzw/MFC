// InsertPeople.cpp : 实现文件
//

#include "stdafx.h"
#include "test5-1.h"
#include "InsertPeople.h"
#include "afxdialogex.h"


// CInsertPeople 对话框

IMPLEMENT_DYNAMIC(CInsertPeople, CDialogEx)

CInsertPeople::CInsertPeople(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInsertPeople::IDD, pParent)
{

}

CInsertPeople::~CInsertPeople()
{
}

void CInsertPeople::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInsertPeople, CDialogEx)
END_MESSAGE_MAP()


// CInsertPeople 消息处理程序
