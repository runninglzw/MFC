
// 8-6-psView.h : CMy86psView 类的接口
//

#pragma once
#include "Layer.h"

class CMy86psView : public CView
{
protected: // 仅从序列化创建
	int select;
	CArray<CLayer*,CLayer*> m_list;
	CMy86psView();
	DECLARE_DYNCREATE(CMy86psView)

// 特性
public:
	CMy86psDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy86psView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawMove();
	afx_msg void OnUpdateDrawMove(CCmdUI *pCmdUI);
	afx_msg void OnLine();
	afx_msg void OnUpdateLine(CCmdUI *pCmdUI);
	afx_msg void OnElli();
	afx_msg void OnUpdateElli(CCmdUI *pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 8-6-psView.cpp 中的调试版本
inline CMy86psDoc* CMy86psView::GetDocument() const
   { return reinterpret_cast<CMy86psDoc*>(m_pDocument); }
#endif

