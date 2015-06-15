
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
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// Ctest46Dlg 消息处理程序

BOOL Ctest46Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//获得配置文件的数据
	int left=theApp.GetProfileInt("WindowRect","left",-1);
	int top=theApp.GetProfileInt("WindowRect","top",-1);
	int right=theApp.GetProfileInt("WindowRect","right",-1);
	int bottom=theApp.GetProfileInt("WindowRect","bottom",-1);
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
	//加载进程图标
	//HICON hicon=theApp.LoadIcon(IDI_ICON1);
	//加载系统图标
	//HICON hicon=::LoadIcon(NULL,IDI_HAND);
	HICON hicon=theApp.LoadStandardIcon(IDI_HAND);
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

//设置光标
BOOL Ctest46Dlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	HCURSOR hcur=theApp.LoadStandardCursor(IDC_WAIT);
	SetCursor(hcur);
	return TRUE;
	//return CDialogEx::OnSetCursor(pWnd, nHitTest, message);
}

//鼠标移动时设置光标
void Ctest46Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	HCURSOR hcur=theApp.LoadStandardCursor(IDC_IBEAM);
	SetCursor(hcur);
	CDialogEx::OnMouseMove(nFlags, point);
}


void Ctest46Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	CRect rect;
	//获得窗口的矩形
	GetWindowRect(rect);
	//将矩形位置写入到配置文件中
	theApp.WriteProfileInt("WindowRect","left",rect.left);
	theApp.WriteProfileInt("WindowRect","top",rect.top);
	theApp.WriteProfileInt("WindowRect","right",rect.right);
	theApp.WriteProfileInt("WindowRect","bottom",rect.bottom);

	// TODO: 在此处添加消息处理程序代码
}
