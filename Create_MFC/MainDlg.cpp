// MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog


CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMainDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	//{{AFX_MSG_MAP(CMainDlg)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainDlg message handlers

void CMainDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	str.Format("x=%d,y=%d",point.x,point.y);
	if(MK_CONTROL & nFlags)
		str+="按下了Control键！";
	if(MK_SHIFT & nFlags)
		str+="按下了Shift键！";
	AfxMessageBox(str);
	CDialog::OnLButtonDown(nFlags, point);
}
//nFlags为
void CMainDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	str.Format("x=%d,y=%d",point.x,point.y);
	if(MK_CONTROL & nFlags)
		str+="按下了Control键！";
	if(MK_SHIFT & nFlags)
		str+="按下了Shift键！";
	if(MK_LBUTTON & nFlags)
		str+="按下了左键！";
	if(MK_RBUTTON & nFlags)
		str+="按下了右键！";
	SetWindowText(str);
	CDialog::OnMouseMove(nFlags, point);
}



BOOL CMainDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetWindowText("初始化");
	HICON hicon=::LoadIcon(::AfxGetInstanceHandle(),(LPCTSTR)IDI_ICON1);
	SetIcon(hicon,FALSE);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
