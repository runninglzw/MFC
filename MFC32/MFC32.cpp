// MFC32.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
#include "stdio.h"
/*class CMyApp : public CWinApp
{
	virtual BOOL InitApplication()
	{
		AfxMessageBox("由Win32工程转换而成的MFC软件工程");
		return TRUE;
	}
};
CMyApp theApp;*/
BOOL CALLBACK theProc(
HWND hwndDlg,
UINT UMsg,
WPARAM wParam,
LPARAM lParam
)
{
	switch(UMsg)
	{
		//窗体初始化消息
	case WM_INITDIALOG:
		//设置窗体位置
		MoveWindow(hwndDlg,100,80,400,300,FALSE);
		//设置窗体标题
		SetWindowText(hwndDlg,"测试");
		return TRUE;

	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDOK:
			return TRUE;
		case IDCANCEL:
			EndDialog(hwndDlg,IDCANCEL);
			return TRUE;
		}
		break;
		//鼠标消息
		case WM_LBUTTONDOWN:
			{
				int x=LOWORD(lParam);
				int y=HIWORD(lParam);
				char s[200];
				sprintf(s,"x=%d,y=%d",x,y);
				MessageBox(hwndDlg,s,"坐标",0);
			}
			return TRUE;
		//鼠标移动消息
		case WM_MOUSEMOVE:
			{
				int x=LOWORD(lParam);
				int y=HIWORD(lParam);
				char s[200];
				sprintf(s,"x=%d,y=%d",x,y);
				::SetWindowText(hwndDlg,s);
			}
			return TRUE;
			//绘图消息,也叫窗口刷新消息
		case WM_PAINT:
			OutputDebugString("绘图消息来临\n");
			//包含绘图操作的结构体
			PAINTSTRUCT ps;
			//绘图句柄HDC
			HDC hdc=::BeginPaint(hwndDlg,&ps);
			::Ellipse(hdc,0,0,300,200);
			::EndPaint(hwndDlg,&ps);

			return TRUE;
	}
	return FALSE;
}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	DialogBox(hInstance,(LPCTSTR)IDD_MAIN,NULL,theProc);
	return 0;
}



