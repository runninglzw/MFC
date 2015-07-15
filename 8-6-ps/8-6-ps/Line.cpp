#include "stdafx.h"
#include "Line.h"


CLine::CLine(void)
{
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
//»æÖÆÏß´úÂë
void CLine::OnDraw(CDC* pDC)
{
	pDC->MoveTo(m_first);
	pDC->LineTo(m_second);
}
