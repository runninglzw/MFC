
// test5-1.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// Ctest51App:
// 有关此类的实现，请参阅 test5-1.cpp
//

class Ctest51App : public CWinApp
{
public:
	Ctest51App();
	user info;
	//前景色和背景色
	COLORREF Ctrlbk,Textbk;

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern Ctest51App theApp;