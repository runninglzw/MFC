// four_oneDlg.cpp : implementation file
//

#include "stdafx.h"
#include "four_one.h"
#include "four_oneDlg.h"
#include "AboutDlg.h"
#include "ChatDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFour_oneDlg dialog

CFour_oneDlg::CFour_oneDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFour_oneDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFour_oneDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFour_oneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFour_oneDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFour_oneDlg, CDialog)
	//{{AFX_MSG_MAP(CFour_oneDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_CREATE()
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFour_oneDlg message handlers
//子窗口已经就绪，可以操作子窗口
BOOL CFour_oneDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFour_oneDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFour_oneDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFour_oneDlg::OnButton1() 
{
	CAboutDlg dlg;
	dlg.DoModal();
}

void CFour_oneDlg::OnButton2() 
{
	//在堆内申请空间
	CChatDlg *pdlg=new CChatDlg;
	pdlg->Create(IDD_CHAT_DLG,GetDesktopWindow());//GetDesktopWindow()代表在任务栏显示该窗口
	pdlg->ShowWindow(SW_SHOW);


}
//窗口还未显示，只有父窗口没有子窗口
int CFour_oneDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}
//管理所有系统菜单和系统按钮消息
void CFour_oneDlg::OnSysCommand(UINT nID, LPARAM lParam) 
{
	/*
	switch(nID)
	{
		//当点击了关闭按钮，不进行关闭而是隐藏窗口
	case SC_CLOSE:
		ShowWindow(SW_MINIMIZE);
		return;
	}*/
	CDialog::OnSysCommand(nID, lParam);
}
//点击关闭按钮时调用，然后调用OnCancel() ，这两个函数都可以阻止窗口关闭，最后调用nDestory(),这个函数窗口关闭已经无法阻止了
void CFour_oneDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnClose();
}

void CFour_oneDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
void CFour_oneDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}
//窗口已经不可见，但是还有最后一口气，可以获取窗口中的内容
void CFour_oneDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	CString str;
	GetDlgItemText(IDC_BUTTON1,str);
	// TODO: Add your message handler code here
	
}
