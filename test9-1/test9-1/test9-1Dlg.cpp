
// test9-1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test9-1.h"
#include "test9-1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest91Dlg 对话框



Ctest91Dlg::Ctest91Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest91Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest91Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN1, m_sp1);
	DDX_Control(pDX, IDC_RICHEDIT21, m_richedit);
}

BEGIN_MESSAGE_MAP(Ctest91Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// Ctest91Dlg 消息处理程序

BOOL Ctest91Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_sp1.SetBuddy(GetDlgItem(IDC_EDIT2));//设置关联控件
	m_sp1.SetRange32(0,100);//设置范围
	CHARFORMAT cf={sizeof(cf)};//字体的结构体
	cf.dwMask=CFM_COLOR|CFM_SIZE;//将开关设置为颜色和字体大小
	cf.crTextColor=RGB(0,255,0);//指定颜色为绿色
	cf.yHeight=300;
	m_richedit.SetDefaultCharFormat(cf);//用字体结构体初始化控件
	m_richedit.SetWindowText("HELLO\r\n");

	cf.dwMask=CFM_COLOR|CFM_FACE|CFM_BOLD|CFM_UNDERLINE|CFM_SIZE;//分别是颜色，字体，加粗，下划线，大小
	//打开开关后必须设置才能生效
	cf.crTextColor=RGB(255,0,0);
	//设为黑体
	strcpy_s(cf.szFaceName,"宋体");
	//设为粗体和下划线
	cf.dwEffects=CFE_BOLD|CFE_UNDERLINE;

	//将文字结尾替换成指定字符串
	int len=m_richedit.GetWindowTextLength();
	//设置光标位置
	m_richedit.SetSel(len,-1);
	m_richedit.ReplaceSel("【提示】 警惕聊托");
	m_richedit.SetSel(len-1,-1);
	//去除选中状态
	m_richedit.SetSel(-1,-1);
	//将接下来的文字设置成刚才定义的样式,必须选中文字
	m_richedit.SetWordCharFormat(cf);
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

void Ctest91Dlg::OnPaint()
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
HCURSOR Ctest91Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

