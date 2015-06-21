
// test5-1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test5-1.h"
#include "test5-1Dlg.h"
#include "afxdialogex.h"
#include "logindlg.h"
#include "Priordlg.h"
#include "InfoDlg.h"
//extern Ctest51App theApp;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest51Dlg 对话框



Ctest51Dlg::Ctest51Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest51Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//从配置文件读取前景色和背景色
	//Ctrlbk=theApp.GetProfileInt("Settings","CtrlColor",RGB(0,0,0));
}

void Ctest51Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctest51Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &Ctest51Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDRELOGIN, &Ctest51Dlg::OnBnClickedRelogin)
	ON_BN_CLICKED(IDSEARCH, &Ctest51Dlg::OnBnClickedSearch)
	ON_BN_CLICKED(IDINFO, &Ctest51Dlg::OnBnClickedInfo)
	ON_BN_CLICKED(IDCOLOR, &Ctest51Dlg::OnBnClickedColor)
	//	ON_WM_CTLCOLOR()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDCOLOR2, &Ctest51Dlg::OnBnClickedColor2)
END_MESSAGE_MAP()


// Ctest51Dlg 消息处理程序

BOOL Ctest51Dlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();
	CString title=theApp.info.name;
	SetWindowText(title);
	GetDlgItem(IDSEARCH)->EnableWindow(theApp.info.prior);//普通用户无法添加账户
	//设置前景色和背景色
	theApp.Ctrlbk=GetProfileInt("Settings","CtrlColor",RGB(128,128,128));
	theApp.Textbk=GetProfileInt("Settings","TextColor",RGB(155,0,0));
	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ctest51Dlg::OnPaint()
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
HCURSOR Ctest51Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest51Dlg::OnBnClickedCancel()
{
	EndDialog(IDCANCEL);
	//CDialogEx::OnCancel();
}

//重新登录
void Ctest51Dlg::OnBnClickedRelogin()
{
	ShowWindow(SW_HIDE);
	CLoginDlg login;
	int result=login.DoModal();
	if(IDCANCEL==result)
		OnCancel();
	else
	{
		CString title=theApp.info.name;
		SetWindowText(title);
		GetDlgItem(IDSEARCH)->EnableWindow(theApp.info.prior);//普通用户无法添加账户
		ShowWindow(SW_SHOW);
	}
}

//增加账户
void Ctest51Dlg::OnBnClickedSearch()
{
	ShowWindow(SW_HIDE);
	CPriorDlg prior;
	prior.DoModal();
	ShowWindow(SW_SHOW);
}

//员工信息的增删改查
void Ctest51Dlg::OnBnClickedInfo()
{
	ShowWindow(SW_HIDE);
	CInfoDlg info;
	info.DoModal();
	ShowWindow(SW_SHOW);
}

//设置背景色的方法
void Ctest51Dlg::OnBnClickedColor()
{
	CColorDialog dlg;
	if(IDCANCEL==dlg.DoModal())
		return ;
	COLORREF col=dlg.GetColor();
	theApp.Ctrlbk=col;
	//实时更新
	Invalidate();
}

//设置字体颜色的方法
void Ctest51Dlg::OnBnClickedColor2()
{
	CColorDialog dlg;
	if(IDCANCEL==dlg.DoModal())
		return ;
	COLORREF col=dlg.GetColor();
	theApp.Textbk=col;
	//实时更新
	Invalidate();
}

//设置背景色具体实现 参考：  http://www.cnblogs.com/staring-hxs/archive/2013/01/09/2853126.html
HBRUSH Ctest51Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	//OnCtlColor能改变Static等子控件的颜色，对于Button必须设置其属性Owner Draw为True,才能改变Button按钮背景色（CButton 文本的字体颜色并不能通过SetBkColor来改变，需要自己重绘CButton，在DrawItem中进行实现。
	if(nCtlColor==CTLCOLOR_DLG)
	{
		pDC->SetBkColor(theApp.Ctrlbk);
		HBRUSH b=CreateSolidBrush(theApp.Ctrlbk);
		//返回设置的颜色
		return b;
	}
	else if(nCtlColor==CTLCOLOR_BTN)
	{
		pDC->SetTextColor(theApp.Textbk);
	}

	//if(pWnd->GetDlgCtrlID()==IDC_ADD)
	//
	//{
	//	pDC->SetTextColor(theApp.Textbk);
	//}
	return hbr;
}


