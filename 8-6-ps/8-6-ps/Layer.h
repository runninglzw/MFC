#pragma once
class CLayer
{
public:
	CLayer(void);
	~CLayer(void);
	virtual void ONLButtonDown(UINT flags, CPoint point) = 0;
	virtual void OnLButtonUp(UINT nFlags, CPoint point) = 0;
	//virtual void OnMouseMove(UINT nFlags, CPoint point,CDC *pdc)=0;
	virtual void OnDraw(CDC* pDC)=0;
	virtual void OnMouseMove(UINT nflags, CPoint point, CDC * pdc) = 0;
};

