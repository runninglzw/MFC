// mymfcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mymfc.h"
#include "mymfcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMymfcDlg dialog

CMymfcDlg::CMymfcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMymfcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMymfcDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMymfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMymfcDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMymfcDlg, CDialog)
	//{{AFX_MSG_MAP(CMymfcDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_MOD, OnMod)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMymfcDlg message handlers
CListCtrl m_listctrl;
BOOL CMymfcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//LONG styles;
    //styles=GetWindowLong(m_listctrl.m_hWnd,GWL_STYLE);
    //SetWindowLong(m_listctrl.m_hWnd,GWL_STYLE,styles | LVS_REPORT);
	CListCtrl *p=(CListCtrl *)GetDlgItem(IDC_LIST); 
	p->InsertColumn(0,"工号",LVCFMT_LEFT,120,-1);
	p->InsertColumn(1,"姓名",0,160);
	p->InsertColumn(2,"工资",0,160);

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMymfcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMymfcDlg::OnPaint() 
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
HCURSOR CMymfcDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMymfcDlg::OnAdd() 
{
	CString str;
	GetDlgItemText(IDC_NUMBER,str);
	CListCtrl *p=(CListCtrl *)GetDlgItem(IDC_LIST);
	//获取当前列表的数目
	int count=p->GetItemCount();
	//插入一项到列表中
	p->InsertItem(count,str);
	GetDlgItemText(IDC_NAME,str);
	//插入之后就不必插入，而是设置值
	p->SetItemText(count,1,str);
	GetDlgItemText(IDC_GONGZI,str);
	p->SetItemText(count,2,str);
}

void CMymfcDlg::OnDel() 
{
	CListCtrl *p=(CListCtrl *)GetDlgItem(IDC_LIST);
	//点了之后不可以
	//int index=p->GetSelectionMark();
	POSITION pos=p->GetFirstSelectedItemPosition();
	int index=p->GetNextSelectedItem(pos);
	if(index<0)
	{
		MessageBox("请先选择一行！");
		return;
	}
	if(AfxMessageBox("是否删除？",MB_YESNO)==IDYES)
		p->DeleteItem(index);
	
}

void CMymfcDlg::OnMod() 
{
		CListCtrl *p=(CListCtrl *)GetDlgItem(IDC_LIST);
	//点了之后不可以
	//int index=p->GetSelectionMark();
	POSITION pos=p->GetFirstSelectedItemPosition();
	int index=p->GetNextSelectedItem(pos);//选中的行
	if(index<0)
	{
		MessageBox("请先选择一行！");
		return;
	}
	if(AfxMessageBox("是否修改？",MB_YESNO)==IDYES)
	{
		CString str;
		GetDlgItemText(IDC_NAME,str);
		
		p->SetItemText(index,1,str);//修改index行，1列，修改为str
		GetDlgItemText(IDC_GONGZI,str);
		p->SetItemText(index,2,str);
	}
}
