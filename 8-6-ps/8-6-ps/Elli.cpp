#include "stdafx.h"
#include "Elli.h"


CElli::CElli(void)
{
	m_rect.SetRect(-1,-1,-1,-1);
}


CElli::~CElli(void)
{
}
void CElli::ONLButtonDown(UINT flags, CPoint point)
{
	m_rect.TopLeft()=point;
}
void CElli::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_rect.BottomRight()=point;
	m_rect.NormalizeRect();//如果出现左值（left）大于右值（right）等不正常情况，调整为正常情况
}
void CElli::OnDraw(CDC* pDC)
{
	pDC->Ellipse(m_rect);
}
void CElli::OnMouseMove(UINT nflags, CPoint point,CDC *pdc)
{
	if(!pdc)
		return;
	if(nflags & MK_LBUTTON)
	{
		//空填充
		pdc->SelectStockObject(NULL_BRUSH);
		//将先前的绘图擦掉
		pdc->SetROP2(R2_NOT);
		if(m_rect.right>-1)
		{
			pdc->Ellipse(m_rect);
		}
		m_rect.BottomRight()=point;
		pdc->Ellipse(m_rect);
	}
}