#pragma once
#include "layer.h"
class CElli :
	public CLayer
{
	CRect m_rect;
	void ONLButtonDown(UINT flags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnDraw(CDC* pDC);
public:
	CElli(void);
	~CElli(void);
};

