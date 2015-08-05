
// test12-1_SDI.h : test12-1_SDI 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// Ctest121_SDIApp:
// 有关此类的实现，请参阅 test12-1_SDI.cpp
//

class Ctest121_SDIApp : public CWinApp
{
public:
	Ctest121_SDIApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ctest121_SDIApp theApp;
