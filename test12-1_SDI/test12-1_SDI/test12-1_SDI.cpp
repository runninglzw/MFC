
// test12-1_SDI.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "test12-1_SDI.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest121_SDIApp

BEGIN_MESSAGE_MAP(Ctest121_SDIApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &Ctest121_SDIApp::OnAppAbout)
END_MESSAGE_MAP()


// Ctest121_SDIApp 构造

Ctest121_SDIApp::Ctest121_SDIApp()
{
	// TODO: 将以下应用程序 ID 字符串替换为唯一的 ID 字符串；建议的字符串格式
	//为 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("test12-1_SDI.AppID.NoVersion"));

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的一个 Ctest121_SDIApp 对象

Ctest121_SDIApp theApp;


// Ctest121_SDIApp 初始化

BOOL Ctest121_SDIApp::InitInstance()
{


	// 若要创建主窗口，此代码将创建新的框架窗口
	// 对象，然后将其设置为应用程序的主窗口对象
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// 创建并加载框架及其资源
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);


	//自己创建框架
	//HICON icon=LoadIcon(IDR_MAINFRAME);
	////注册窗口
	//LPCSTR szclass=AfxRegisterWndClass(CS_DBLCLKS|CS_HREDRAW|CS_VREDRAW,NULL,NULL,icon);
	////使用本框架创建窗口
	//pFrame->Create(szclass,"员工信息管理",WS_OVERLAPPEDWINDOW,CFrameWnd::rectDefault,NULL,MAKEINTRESOURCE(IDR_MAINFRAME));
	//pFrame->SendMessageToDescendants(WM_INITIALUPDATE,0,0,TRUE,TRUE);
	//pFrame->SetIcon(icon,FALSE);



	// 唯一的一个窗口已初始化，因此显示它并对其进行更新
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

int Ctest121_SDIApp::ExitInstance()
{
	//TODO: 处理可能已添加的附加资源
	return CWinApp::ExitInstance();
}

// Ctest121_SDIApp 消息处理程序


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

// 用于运行对话框的应用程序命令
void Ctest121_SDIApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// Ctest121_SDIApp 消息处理程序



