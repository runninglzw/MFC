#pragma once
#include "afxwin.h"
class CMemoryDC :
	public CDC
{
	CSize m_size;
public:
	CMemoryDC(void);
	CMemoryDC(int cx,int cy,CDC *pdc=NULL)
	{
		Create(cx,cy,pdc);
	}

	BOOL Create(int cx,int cy,CDC *pdc=NULL)
	{
		//创建空白位图
		CBitmap bmp;
		if(!bmp.CreateCompatibleBitmap(pdc,cx,cy))
			return FALSE;
		m_size.cx=cx;
		m_size.cy=cy;
		CreateCompatibleDC(pdc);
		SelectObject(&bmp);
		return TRUE;
	}
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
	//设置透明色（一般为背景透明）
	void BitTrans(
		int  xdest,//目标起点x
		int  ydest,//目标起点y
		int width,//目标宽度
		int height,//目标高度
		CDC *pdc,//目标dc
		int xsource,//来源起点x
		int ysource,//来源起点y
		COLORREF colortrans//透明色
		)
	{
		CMemoryDC dcImage;//临时DC
		CBitmap bmp;
		bmp.CreateBitmap(width,height,1,1,NULL);
		//创建单色掩码位图
		CDC dcMark;//掩码DC
		dcMark.CreateCompatibleDC(pdc);
		dcMark.SelectObject(bmp);
		//将载入位图的内存DC中的位图，拷贝到临时DC中
		dcImage.BitBlt(0,0,width,height,this,xsource,ysource,SRCCOPY);
		//设置临时DC透明色
		dcImage.SetBkColor(colortrans);
		//掩码DC透明区域为白色其他为黑色
		dcMark.BitBlt(0,0,width,height,&dcImage,0,0,SRCCOPY);
		//临时透明区域为黑色，其他区域保持不变
		dcImage.SetBkColor(RGB(0,0,0));
		dcImage.SetTextColor(RGB(255,255,255));
		dcImage.BitBlt(0,0,width,height,&dcMark,0,0,SRCAND);
		//目标DC透明部分保持屏幕不变，其他部分为黑色
		pdc->SetBkColor(RGB(255,255,255));
		pdc->SetTextColor(RGB(0,0,0));
		pdc->BitBlt(xdest,ydest,width,height,&dcMark,0,0,SRCAND);
		pdc->BitBlt(xdest,ydest,width,height,&dcImage,0,0,SRCPAINT);

	}
};

