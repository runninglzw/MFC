
// test10-1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test10-1.h"
#include "test10-1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest101Dlg 对话框



Ctest101Dlg::Ctest101Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest101Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest101Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO, m_com);
}

BEGIN_MESSAGE_MAP(Ctest101Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &Ctest101Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_ADD, &Ctest101Dlg::OnBnClickedAdd)
END_MESSAGE_MAP()


// Ctest101Dlg 消息处理程序

BOOL Ctest101Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list.InsertColumn(0,"姓名",0,300);
	m_list.InsertColumn(1,"国籍",0,300);
	images.Create(24,24,ILC_COLOR32|ILC_MASK,0,4);
	//images.Create(IDB_BITMAP1,20,5,RGB(255,255,255));
	int i=0;
	while(i<5)
	{
		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_BITMAP1+(i++));
		images.Add(&bitmap,RGB(0,0,0));
	}
	m_list.SetImageList(&images,LVSIL_SMALL);
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

void Ctest101Dlg::OnPaint()
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
HCURSOR Ctest101Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest101Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

//添加
void Ctest101Dlg::OnBnClickedAdd()
{
	CString str;
	GetDlgItemText(IDC_EDIT1,str);
	int i=m_list.GetItemCount();
	m_list.InsertItem(i,str,m_com.GetCurSel());
	m_com.GetWindowText(str);
	m_list.SetItemText(i,1,str);
	//更改图像可以使用SetItem（参数为LVITEM结构体）
}
