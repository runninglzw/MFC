#pragma once
#include "layer.h"
class CElli :
	public CLayer
{
	CRect m_rect;
	void ONLButtonDown(UINT flags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnDraw(CDC* pDC);
	void OnMouseMove(UINT nflags, CPoint point,CDC *pdc);
public:
	CElli(void);
	~CElli(void);
};

