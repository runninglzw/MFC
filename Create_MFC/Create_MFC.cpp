// Create_MFC.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
#include "MainDlg.h"//第一个窗口派生类所在的头文件
#include "Dialog2.h"
//消息映射机制
//必须使用类向导建立一个窗口类的派生类（CWnd）例如：查看->建立类向导->new class对应一个Dialog类等
//必须使用派生类定义对象，用来接收用户界面操作消息例如：CMainDlg dlg;
//在窗口派生类中，每一种消息都与一个类成员函数关联例如：void CMainDlg::OnLButtonDown(UINT nFlags, CPoint point) 
//消息映射函数，通过类向导（classWizard）建立例如：查看->建立类向导->在Messages中选中之后add Function
class CMyApp : public CWinApp
{
	virtual BOOL InitApplication()
	{
		CMainDlg dlg;
		dlg.DoModal();
		Dialog2 dlg2;
		dlg2.DoModal();
		//AfxMessageBox("由Win32工程转换而成的MFC软件工程");
		return TRUE;
	}
};
CMyApp theApp;

/*int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.

	return 0;
}*/



