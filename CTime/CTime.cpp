// CTime.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Mytime.h"
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
    CMytime t=CMytime::GetCurrentTime();
	int year=t.GetYear();
	return 0;
}



 