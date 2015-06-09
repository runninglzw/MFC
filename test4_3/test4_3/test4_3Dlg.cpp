
// test4_3Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "resource.h"
#include "test4_3.h"
#include "test4_3Dlg.h"
#include "afxdialogex.h"
#include "MyButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest4_3Dlg 对话框


CWnd edit;
CMyButton button,button2;
Ctest4_3Dlg::Ctest4_3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest4_3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest4_3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctest4_3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Ctest4_3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Ctest4_3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Ctest4_3Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Ctest4_3Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Ctest4_3Dlg::OnBnClickedButton5)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON6, &Ctest4_3Dlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// Ctest4_3Dlg 消息处理程序

BOOL Ctest4_3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//获得本窗口编辑框控件的句柄
	HWND hwnd=::GetDlgItem(m_hWnd,IDC_EDIT1);
	//将edit对象与该句柄相关联，就可以操纵该句柄对应的控件
	edit.Attach(hwnd);
	//另一种关联的方法，通过子类button可以接收窗口消息(MouseMove消息等)
	HWND hwnd2=::GetDlgItem(m_hWnd,IDC_BUTTON2);
	button.SubclassWindow(hwnd2);
	//第三种关联方法，不需要句柄，只需要父窗口和控件id
	button2.SubclassDlgItem(IDC_BUTTON1,this);
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

void Ctest4_3Dlg::OnPaint()
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
HCURSOR Ctest4_3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest4_3Dlg::OnBnClickedButton1()
{
	DestroyWindow();
}

CWnd list;
void Ctest4_3Dlg::OnBnClickedButton2()
{
	if(!list)
	{
		list.Create(_T("syslistview32"),NULL,WS_CHILD|WS_VISIBLE,CRect(10,80,200,200),this,8888);//_T()以unicode方式保存
	}
}


void Ctest4_3Dlg::OnBnClickedButton3()
{
	CWnd *p=GetDlgItem(IDOK);
	//if(p)
	HWND hwnd=p->GetSafeHwnd();//安全的获取句柄，指针为空也不会出错
	if(hwnd)
		p->DestroyWindow();
}

//将句柄转换为CWnd
void Ctest4_3Dlg::OnBnClickedButton4()
{
	HWND hwnd=::GetDlgItem(m_hWnd,IDOK);
	CWnd *p=FromHandle(hwnd);
	p->SetWindowText(_T("通过临时对象Set"));
}


void Ctest4_3Dlg::OnBnClickedButton5()
{
	edit.SetWindowText(_T("通过全局对象Set"));
}


void Ctest4_3Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	//退出之前必须取消关联窗口对象，与Attach对应
	edit.Detach();
	button.UnsubclassWindow();
}


void Ctest4_3Dlg::OnBnClickedButton6()
{
	//定义一个矩形区域
	CRect rect;
	//获得该控件矩形区域(屏幕坐标)
	edit.GetWindowRect(rect);
	//是把屏幕坐标转换为窗口坐标
	ScreenToClient(rect);
	edit.MoveWindow(rect);
	//实时更新
	Invalidate();

}
