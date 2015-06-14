
// test4-6Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test4-6.h"
#include "test4-6Dlg.h"
#include "afxdialogex.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest46Dlg 对话框


Ctest46Dlg::Ctest46Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest46Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest46Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctest46Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// Ctest46Dlg 消息处理程序

BOOL Ctest46Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//SetWindowText(theApp.m_lpCmdLine);
	CString str;
	str.Format("m_nCmdShow=%d",theApp.m_nCmdShow);
	SetWindowText(str);
	AfxMessageBox("看标题！");
	SetDlgItemText(IDC_APPNAME,theApp.m_pszAppName);
	SetDlgItemText(IDC_EXENAME,theApp.m_pszExeName);
	SetDlgItemText(IDC_HELPNAME,theApp.m_pszHelpFilePath);
	SetDlgItemText(IDC_REGISTNAME,theApp.m_pszRegistryKey);
	SetDlgItemText(IDC_PROFILE,theApp.m_pszProfileName);
	//加载图标
	HICON hicon=theApp.LoadIcon(IDI_ICON1);
	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(hicon, TRUE);			// 设置大图标
	//SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ctest46Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ctest46Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

