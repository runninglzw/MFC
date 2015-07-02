
// test7-3(GDI)Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test7-3(GDI).h"
#include "test7-3(GDI)Dlg.h"
#include "afxdialogex.h"
#include "Resource.h"
#include "MemDC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CMemoryDC m_dc;
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
	ON_WM_PAINT()
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
	ON_WM_NCHITTEST()
	ON_BN_CLICKED(IDADOUT, &Ctest73GDIDlg::OnBnClickedAdout)
	ON_WM_TIMER()
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
	SetTimer(0,500,NULL);
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

		//使用画笔CPen
		CPen p1(PS_DASHDOTDOT,1,RGB(255,0,0));//第一个参数代表虚线，第二个为宽度，第三个为颜色，虚线宽度必须为1
		//设置dc的画笔
		dc.SelectObject(&p1);//返回值为旧的CPen类，缺省为黑色单线
		//获取系统画刷
		CBrush cb;
		cb.CreateSysColorBrush(COLOR_INFOTEXT);
		//设置为系统颜色画刷
		dc.SelectObject(&cb);
		//绘制椭圆图形
		dc.Ellipse(rect);
		//绘制三角形
		CPen p2(PS_SOLID,5,RGB(0,255,0));
		dc.SelectObject(&p2);
		//绘制画刷
		CBrush brush(HS_DIAGCROSS,RGB(255,0,155));//第一个参数为格式，第二个为颜色
		//dc.SelectObject(&brush);
		CPoint points[]={CPoint(140,40),CPoint(100,80),CPoint(180,80)};
		dc.Polygon(points,3);
		rect.bottom=40;
		//填充标题栏矩形的颜色
		dc.FillSolidRect(rect,RGB(0,0,200));

		//平铺Bitmap步骤：1.加载Bitmap2.申请一个内存区域3.将内存区域和Bitmap绑定4.将绑定好的绘制在对话框中
		//第一步
		CBitmap bt;
		bt.LoadBitmap(IDB_BITMAP1);
		//获得BITMAP结构体，包含Bitmap图像的信息（高度和宽度等）
		BITMAP bitmap;
		bt.GetBitmap(&bitmap);
		//第二步
		CDC cdc;
		cdc.CreateCompatibleDC(&dc);
		//第三步
		cdc.SelectObject(&bt);
		//使用椭圆区域绘制
		CRgn rgn;
		rgn.CreateEllipticRgn(300,40,300+bitmap.bmWidth,40+bitmap.bmHeight);
		dc.SelectObject(&rgn);
		//第四步
		dc.BitBlt(300,40,bitmap.bmWidth,bitmap.bmHeight,&cdc,0,0,SRCCOPY);
		//拉伸或者扩大位图
		CRgn rgn2;
		rgn2.CreateRectRgn(300,200,300+bitmap.bmWidth/2,200+bitmap.bmHeight/2);//由于先前绑定了一个椭圆区域，想要压缩或者扩展必须新绑定一个矩形区域，和压缩后大小一致
		dc.SelectObject(&rgn2);
		cdc.SetStretchBltMode(HALFTONE);
		dc.StretchBlt(300,200,bitmap.bmWidth/2,bitmap.bmHeight/2,&cdc,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);


		//绘制标题
		CString str="测试CDC类";
		dc.SetTextColor(RGB(255,0,0));
		dc.DrawText(str,rect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		//arc绘制椭圆的线（一半），chord为封闭的，连接椭圆两点
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
	//CWindowDC cdc(this);
	//CRect rect;
	//GetWindowRect(rect);
	////转化为非客户区坐标系
	//rect.OffsetRect(-rect.left,-rect.top);//横向移动屏幕坐标系的x和纵向移动屏幕坐标系的y值
	//rect.top-=20;
	//cdc.FillSolidRect(rect,RGB(255,0,0));//填充矩形颜色为红色
	////cdc.Rectangle(rect);
	////或者使用如下方法转换为非客户区坐标系
	////cdc.Rectangle(0,0,rect.Width(),rect.Height());
	//// TODO: 在此处添加消息处理程序代码
	//// 不为绘图消息调用 CDialogEx::OnNcPaint()
}

//拖动系统标题栏才可以拖动，这里将客户区绘制的标题栏当成系统标题栏
LRESULT Ctest73GDIDlg::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UINT test=CDialogEx::OnNcHitTest(point);
	//获取标题框大小
	CRect rect;
	GetClientRect(rect);
	rect.bottom=40;
	//将拖动的点转化为客户区坐标系
	ScreenToClient(&point);
	//判断拖动的点是否在标题区
	if(rect.PtInRect(point))
	{
		if(HTCLIENT==test)//如果是客户区
			test=HTCAPTION;//变为标题栏，只有标题栏才可以拖动
	}
	return test;
}

//关于对话框，（加载进程外的位图）
void Ctest73GDIDlg::OnBnClickedAdout()
{
	CAboutDlg dlg;
	dlg.DoModal();
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	return TRUE;
}


void CAboutDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	//CMemoryDC m_dc;
	m_dc.LoadmyBitmap("C:\\Users\\liuzhenwei\\Desktop\\图标\\myapp.bmp",&dc);
	CRect rect;
	GetClientRect(rect);
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&m_dc,0,0,rect.Width(),rect.Height(),SRCCOPY);
}

//处理动态图
void Ctest73GDIDlg::OnTimer(UINT_PTR nIDEvent)
{
	static int i=1;
	CString str;
	str.Format("F:\\MFC学习\\test7-3(GDI)\\test7-3(GDI)\\res\\%d.bmp",i);
	CClientDC dc(this);
	CMemoryDC m_dc;
	m_dc.LoadmyBitmap(str);
	dc.BitBlt(0,0,m_dc.GetWidth(),m_dc.GetHeight(),&m_dc,0,0,SRCCOPY);
	i++;
	if(i>2)
		i=1;
	CDialogEx::OnTimer(nIDEvent);
}
