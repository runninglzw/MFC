
// test9-4Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test9-4.h"
#include "test9-4Dlg.h"
#include "afxdialogex.h"
#include "Cpage1.h"
#include "Cpage2.h"
#include "Cpage3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest94Dlg 对话框



Ctest94Dlg::Ctest94Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest94Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest94Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(Ctest94Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDADD, &Ctest94Dlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDADD2, &Ctest94Dlg::OnBnClickedAdd2)
//	ON_NOTIFY(HDN_DIVIDERDBLCLICK, 0, &Ctest94Dlg::OnHdnDividerdblclickList1)
//	ON_NOTIFY(HDN_ITEMDBLCLICK, 0, &Ctest94Dlg::OnHdnItemdblclickList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &Ctest94Dlg::OnDblclkList1)
END_MESSAGE_MAP()


// Ctest94Dlg 消息处理程序

BOOL Ctest94Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list.InsertColumn(0,"账号",0,80);
	m_list.InsertColumn(1,"姓名",0,80);
	m_list.InsertColumn(2,"性别",0,80);
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

void Ctest94Dlg::OnPaint()
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
HCURSOR Ctest94Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//添加：使用分页向导
void Ctest94Dlg::OnBnClickedAdd()
{
	CPropertySheet sheet("用户资料注册");
	Cpage1 p1;
	Cpage2 p2;
	Cpage3 p3;
	sheet.AddPage(&p1);
	sheet.AddPage(&p2);
	sheet.AddPage(&p3);
	sheet.SetWizardMode();
	if(IDCANCEL==sheet.DoModal())
		return;
	int count=m_list.GetItemCount();
	m_list.InsertItem(count,p1.m_id);
	m_list.SetItemText(count,1,p2.m_name);
	m_list.SetItemText(count,2,p3.m_sex);
	

	// TODO: 在此添加控件通知处理程序代码
}

//修改
void Ctest94Dlg::OnBnClickedAdd2()
{

	if(!m_list.GetSelectedCount())
	{
		AfxMessageBox("请选中一行!");
		return;
	}
	CPropertySheet sheet("用户资料修改");
	Cpage1 p1;
	Cpage2 p2;
	Cpage3 p3;
	sheet.AddPage(&p1);
	sheet.AddPage(&p2);
	sheet.AddPage(&p3);
	int select=m_list.GetSelectionMark();
	p1.m_id=m_list.GetItemText(select,0);
	p2.m_name=m_list.GetItemText(select,1);
	p3.m_sex=m_list.GetItemText(select,2);
	if(IDCANCEL==sheet.DoModal())
		return;
	m_list.SetItemText(select,0,p1.m_id);
	m_list.SetItemText(select,1,p2.m_name);
	m_list.SetItemText(select,2,p3.m_sex);
}




//双击list时候响应
void Ctest94Dlg::OnDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	OnBnClickedAdd2();
	*pResult = 0;
}
