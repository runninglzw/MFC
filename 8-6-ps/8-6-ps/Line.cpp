#include "stdafx.h"
#include "Line.h"


CLine::CLine(void)
{
	m_second.x=m_second.y=-1;
}


CLine::~CLine(void)
{
}
void CLine::ONLButtonDown(UINT flags, CPoint point)
{
	m_first=point;
}
void CLine::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_second=point;
}
//绘制线代码
void CLine::OnDraw(CDC* pDC)
{
	pDC->MoveTo(m_first);
	pDC->LineTo(m_second);
}
void CLine::OnMouseMove(UINT nflags, CPoint point,CDC *pdc)
{
	if(!pdc)
		return;
	//判断左键是否按下,按下则开始绘图
	if(nflags & MK_LBUTTON)
	{
		//如果是第二次绘制图形，则把第一次绘制的擦掉
		pdc->SetROP2(R2_NOT);
		//如果第二次绘制，擦掉第一次绘制的(设置seirop后再绘制一次就相当于擦掉了)
		if(m_second.x>-1)
		{
			pdc->MoveTo(m_first);
			pdc->LineTo(m_second);
		}
		pdc->MoveTo(m_first);
		pdc->LineTo(point);
		m_second=point;
	}
}
