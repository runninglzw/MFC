
// test9-2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test9-2.h"
#include "test9-2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest92Dlg 对话框



Ctest92Dlg::Ctest92Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest92Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

//void Ctest92Dlg::DoDataExchange(CDataExchange* pDX)
//{
//	CDialogEx::DoDataExchange(pDX);
//}

BEGIN_MESSAGE_MAP(Ctest92Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Ctest92Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDNEXT, &Ctest92Dlg::OnBnClickedNext)
	ON_BN_CLICKED(IDCANCEL, &Ctest92Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDBEFOR, &Ctest92Dlg::OnBnClickedBefor)
END_MESSAGE_MAP()


// Ctest92Dlg 消息处理程序

BOOL Ctest92Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_sel=0;//当前页为Page1
	m_p1.Create(IDD_DIALOG1,this);
	m_p2.Create(IDD_DIALOG2,this);
	m_p3.Create(IDD_DIALOG3,this);
	CRect rect,rt;
	//获得客户区
	GetClientRect(rect);
	//获得OK按钮的区域
	GetDlgItem(IDOK)->GetWindowRect(rt);//这里必须是GetWindowRect而不是GEtClientRect
	//将客户区域的底部设置为IDOK的顶部
	ScreenToClient(rt);
	rect.bottom=rt.top;
	//第一个对话框移到该区域
	m_p1.MoveWindow(rect);//由于m_p1的visible为true，则一开始显示m_p1
	m_p2.MoveWindow(rect);
	m_p3.MoveWindow(rect);
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

void Ctest92Dlg::OnPaint()
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
HCURSOR Ctest92Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest92Dlg::OnBnClickedOk()
{
	m_p1.UpdateData();
	m_p2.UpdateData();
	m_p3.UpdateData();
	EndDialog(IDOK);
	//CDialogEx::OnOK();
}

//下一步
void Ctest92Dlg::OnBnClickedNext()
{
	m_sel++;
	SelectPage();
}


void Ctest92Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

//上一步
void Ctest92Dlg::OnBnClickedBefor()
{
	m_sel--;
	SelectPage();
}
void Ctest92Dlg::SelectPage()
{
	CWnd *ps[]={&m_p1,&m_p2,&m_p3};
	int i=0;
	while(i<(sizeof(ps)/sizeof(ps[0])))
		ps[i++]->ShowWindow(m_sel==i?SW_SHOW:SW_HIDE);//如果当前窗口和选择选中的窗口一致则显示，负责隐藏
	//设置上一步和下一步按钮的可见性
	GetDlgItem(IDBEFOR)->EnableWindow(m_sel!=0);//上一步是0则隐藏，其他都显示
	GetDlgItem(IDNEXT)->EnableWindow(m_sel!=2);//下一步是2则隐藏，其他都显示
}


void Ctest92Dlg::DoDataExchange(CDataExchange* pDX)
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialogEx::DoDataExchange(pDX);
}
