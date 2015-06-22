
// test5-6_NOtepaidDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test5-6_NOtepaid.h"
#include "test5-6_NOtepaidDlg.h"
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


// Ctest56_NOtepaidDlg 对话框



Ctest56_NOtepaidDlg::Ctest56_NOtepaidDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest56_NOtepaidDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest56_NOtepaidDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctest56_NOtepaidDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Ctest56_NOtepaidDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Ctest56_NOtepaidDlg::OnBnClickedCancel)
	ON_COMMAND(ID_OPEN, &Ctest56_NOtepaidDlg::OnOpen)
	ON_COMMAND(IDCANCEL, &Ctest56_NOtepaidDlg::OnCancel)
	ON_COMMAND(ID_FONT, &Ctest56_NOtepaidDlg::OnFont)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// Ctest56_NOtepaidDlg 消息处理程序

BOOL Ctest56_NOtepaidDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_edit.SubclassDlgItem(IDC_EDIT1,this);
	GetClientRect(&m_rect);//获得对话框矩形区域
	
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

	ShowWindow(SW_MAXIMIZE);

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Ctest56_NOtepaidDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Ctest56_NOtepaidDlg::OnPaint()
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
HCURSOR Ctest56_NOtepaidDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest56_NOtepaidDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void Ctest56_NOtepaidDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void Ctest56_NOtepaidDlg::OnOpen()
{
	LPCSTR fileter="文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,fileter);
	//显示系统对话框来选择文件
	if(IDCANCEL==dlg.DoModal())
		return;
	//选中文件之后打开该文件进行读取
	CFile file;
	if(!file.Open(dlg.GetPathName(),CFile::modeRead|CFile::shareDenyNone))
	{
		AfxMessageBox("无法打开文件！");
		return;
	}
	//获得文件的状态信息
	CFileStatus status;
	file.GetStatus(status);
	//声明一个数组保存变量
	char *data=new char[status.m_size+1];
	//读取文件
	int last=file.Read(data,status.m_size);
	//设置结束标记
	data[last]='\0';
	SetDlgItemText(IDC_EDIT1,data);
	delete []data;
	
}


void Ctest56_NOtepaidDlg::OnCancel()
{
	CDialogEx::OnCancel();
}


void Ctest56_NOtepaidDlg::OnFont()
{
	//用LOGFONT保存字体信息
	LOGFONT lfont;
	if(m_font.GetSafeHandle())
		m_font.GetLogFont(&lfont);//将CFont类中的信息传给lfont
	//弹出设置字体对话框
	CFontDialog dlg(&lfont);//初始化系统对话框，该系统对话框打开的时候当前字体信息已经被选中
	if(IDCANCEL==dlg.DoModal())
	{
		return;
	}

	dlg.GetCurrentFont(&lfont);
	//声明一个字体实类，并设置给编辑框,必须设置一个全局的变量，否则生命期不够
	m_font.DeleteObject();//清除原来信息
	m_font.CreateFontIndirect(&lfont);//实例化字体信息（LOGFONT->CFont），和.GetLogFont(&lfont)是反函数(CFont->LOGFONT)
	m_edit.SetFont(&m_font);//设置字体

}

//对话框大小变化处理事件，用来更改编辑框的大小
void Ctest56_NOtepaidDlg::OnSize(UINT nType, int cx, int cy)
{
	
	CWnd *edit;
	edit=GetDlgItem(IDC_EDIT1);
	//如果是最小化，则什么都不做
	if(nType==SIZE_MINIMIZED)
		return;
	if(edit)//判断是否为空，因为对话框创建时会调用此函数，而当时控件还未创建
	{
		CRect rect;
		edit->GetWindowRect(&rect);//获得控件变化前的大小
	    ScreenToClient(&rect);////将控件大小转换为在对话框中的区域坐标
		//cx/m_editWidth()为横向变化的比例,按left，right等扩大新的矩形区域
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top=rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();

		edit->MoveWindow(rect);
	}
	//设置更改后的对话框大小给m_rect
	GetClientRect(&m_rect);
	CDialogEx::OnSize(nType, cx, cy);
}
