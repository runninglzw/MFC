// second.cpp : Defines the entry point for the application.
//

#include "stdafx.h"


#include "resource.h"
BOOL CALLBACK MainProc(
   HWND   hwndDlg,
   UINT   uMsg,
   WPARAM wParam,
   LPARAM lParam
)
{
	OutputDebugString("测试运行！\n");
	if(WM_COMMAND==uMsg)
	{
		if(LOWORD(wParam)==IDCANCEL)
		{
			EndDialog(hwndDlg,IDCANCEL);
			return TRUE;
		}
		if(LOWORD(wParam)==IDOK)
		{
			int left=GetDlgItemInt(hwndDlg,IDC_LEFT,NULL,TRUE);
			int right=GetDlgItemInt(hwndDlg,IDC_RIGHT,NULL,TRUE);
			int result=left+right;
			SetDlgItemInt(hwndDlg,IDC_RESULT,result,TRUE);
		}
	}
	//if(WM_DESTROY==uMsg)
		//PostQuitMessage(0);
	return FALSE;
}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	//HWND hwnd= ::FindWindow(NULL,"面试 - 记事本");
	//MessageBox(hwnd,"hello","提示",MB_OK);
	DialogBox(hInstance,(LPCSTR)IDD_DIALOG1,NULL,MainProc);
	return 0;
}



