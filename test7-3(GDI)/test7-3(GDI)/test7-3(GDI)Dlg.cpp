
// test7-3(GDI)Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test7-3(GDI).h"
#include "test7-3(GDI)Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ctest73GDIDlg 对话框



Ctest73GDIDlg::Ctest73GDIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest73GDIDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest73GDIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctest73GDIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_NCPAINT()
END_MESSAGE_MAP()


// Ctest73GDIDlg 消息处理程序

BOOL Ctest73GDIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Ctest73GDIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ctest73GDIDlg::OnPaint()
{
	//if (IsIconic())
	//{
	//绘制客户区永久图形
		CPaintDC dc(this); // 用于绘制的设备上下文

		//SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		//int cxIcon = GetSystemMetrics(SM_CXICON);
		//int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		//int x = (rect.Width() - cxIcon + 1) / 2;
		//int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		//dc.DrawIcon(x, y, m_hIcon);
		dc.Ellipse(rect);
	//}
	//else
	//{
	//	CDialogEx::OnPaint();
	//}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ctest73GDIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest73GDIDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	//绘制客户区临时图形
	CClientDC cdc(this);
	cdc.Rectangle(point.x-10,point.y-10,point.x+10,point.y+10);

	CDialogEx::OnLButtonDown(nFlags, point);
}

//绘制非客户区
void Ctest73GDIDlg::OnNcPaint()
{
	//在OnNcPaint()中CWindowDC绘图永久有效，在其他消息中只是临时的
	CWindowDC cdc(this);
	CRect rect;
	GetWindowRect(rect);
	//转化为非客户区坐标系
	rect.OffsetRect(-rect.left,-rect.top);//横向移动屏幕坐标系的x和纵向移动屏幕坐标系的y值
	rect.top-=20;
	cdc.FillSolidRect(rect,RGB(255,0,0));//填充矩形颜色为红色
	//cdc.Rectangle(rect);
	//或者使用如下方法转换为非客户区坐标系
	//cdc.Rectangle(0,0,rect.Width(),rect.Height());
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnNcPaint()
}
