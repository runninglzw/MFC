#pragma once
#include "afxwin.h"
class CMemoryDC :
	public CDC
{
	CSize m_size;
public:
	CMemoryDC(void);
	~CMemoryDC(void);
	BOOL LoadmyBitmap(LPCSTR file, CDC * pdc=NULL)
	{
		//进程外加载位图
		HBITMAP hbitmap=(HBITMAP)LoadImage(NULL,file,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);//第一个参数为进程句柄，第二个为文件路径，3为加载的类型（Bitmap、Icon或ICursur）45为位图宽度和高度，最后一个表示从文件中加载
		if(!hbitmap)
			return FALSE;
		//bitmap的结构体，包含位图信息
		BITMAP bitmap;
		GetObject(hbitmap,sizeof(bitmap),&bitmap);//获得位图信息
		//将宽度和高度赋值给私有变量
		m_size.cx=bitmap.bmWidth;
		m_size.cy=bitmap.bmHeight;
		//创建内存区域
		CreateCompatibleDC(pdc);
		//内存区域绘制位图
		SelectObject(hbitmap);
		return TRUE;
	}
	int GetWidth(){return m_size.cx;}
	int GetHeight(){return m_size.cy;}
};

