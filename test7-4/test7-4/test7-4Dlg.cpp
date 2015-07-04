
// test7-4Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test7-4.h"
#include "test7-4Dlg.h"
#include "afxdialogex.h"
#include "MemDC.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest74Dlg 对话框



Ctest74Dlg::Ctest74Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest74Dlg::IDD, pParent)
{
	m_back.LoadmyBitmap("C:\\Users\\liuzhenwei\\Desktop\\图标\\back.bmp");
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest74Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctest74Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// Ctest74Dlg 消息处理程序

BOOL Ctest74Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MINIMIZE);
	SetTimer(0,200,NULL);
	//获取屏幕的宽度和高度
	int cx=GetSystemMetrics(SM_CXSCREEN);
	int cy=GetSystemMetrics(SM_CYSCREEN);
	MoveWindow(0,0,cx,cy,FALSE);
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ctest74Dlg::OnPaint()
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
HCURSOR Ctest74Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//闪烁问题：界面更新有超过一次以上的输出，并且重叠面积越大，输出次数越多，闪烁越严重（下面有两次输出）
//解决方法：将所有的打印都打印到内存中，然后再打印到屏幕上
void Ctest74Dlg::OnTimer(UINT_PTR nIDEvent)
{
	CClientDC dc(this);

	CRect rect;
	GetClientRect(&rect);
	//声明一个内存区，先打印到内存中
	CMemoryDC mdc(rect.Width(),rect.Height(),&dc);
	mdc.FillSolidRect(0,0,rect.Width(),rect.Height(),RGB(0,255,0));
	mdc.BitBlt(0,0,m_back.GetWidth(),m_back.GetHeight(),&m_back,0,0,SRCCOPY);
	//现在开始打印到屏幕上
	dc.BitBlt(0,0,mdc.GetWidth(),mdc.GetHeight(),&mdc,0,0,SRCCOPY);
	CDialogEx::OnTimer(nIDEvent);
}
