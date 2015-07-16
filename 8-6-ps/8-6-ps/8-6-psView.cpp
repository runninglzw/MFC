
// 8-6-psView.cpp : CMy86psView 类的实现
//

#include "stdafx.h"
#include "Elli.h"
#include "Line.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "8-6-ps.h"
#endif

#include "8-6-psDoc.h"
#include "8-6-psView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy86psView

IMPLEMENT_DYNCREATE(CMy86psView, CView)

BEGIN_MESSAGE_MAP(CMy86psView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DRAW_MOVE, &CMy86psView::OnDrawMove)
	ON_UPDATE_COMMAND_UI(ID_DRAW_MOVE, &CMy86psView::OnUpdateDrawMove)
	ON_COMMAND(ID_LINE, &CMy86psView::OnLine)
	ON_UPDATE_COMMAND_UI(ID_LINE, &CMy86psView::OnUpdateLine)
	ON_COMMAND(ID_ELLI, &CMy86psView::OnElli)
	ON_UPDATE_COMMAND_UI(ID_ELLI, &CMy86psView::OnUpdateElli)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy86psView 构造/析构

CMy86psView::CMy86psView()
{
	// TODO: 在此处添加构造代码

}

CMy86psView::~CMy86psView()
{
}

BOOL CMy86psView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy86psView 绘制

void CMy86psView::OnDraw(CDC* pDC)
{
	select=0;
	CMy86psDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//绘制图形
	int i=0,count=m_list.GetCount();
	CLayer *layer=NULL;
	//循环绘制lisi中的图形
	while(i<count)
	{
		layer=m_list[i++];
		//调用类的ondraw绘制
		layer->OnDraw(pDC);
	}
}

void CMy86psView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy86psView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy86psView 诊断

#ifdef _DEBUG
void CMy86psView::AssertValid() const
{
	CView::AssertValid();
}

void CMy86psView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy86psDoc* CMy86psView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy86psDoc)));
	return (CMy86psDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy86psView 消息处理程序


void CMy86psView::OnDrawMove()
{
	// TODO: 在此添加命令处理程序代码
}


void CMy86psView::OnUpdateDrawMove(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
}


void CMy86psView::OnLine()
{
	select=ID_LINE;
}


void CMy86psView::OnUpdateLine(CCmdUI *pCmdUI)
{
	pCmdUI->SetRadio(select==ID_LINE);
}


void CMy86psView::OnElli()
{
	select=ID_ELLI;
}


void CMy86psView::OnUpdateElli(CCmdUI *pCmdUI)
{
	pCmdUI->SetRadio(select==ID_ELLI);//为true'则该按钮为选中状态
}


void CMy86psView::OnLButtonDown(UINT nFlags, CPoint point)
{
	//判断选择了那种绘图类
	CLayer *layer=NULL;
	switch(select)
	{
	case ID_LINE:
		layer=new CLine();
		break;
	case ID_ELLI:
		layer=new CElli();
		break;
	}
	//如果有绘图类，则将类加入m_list中
	if(layer)
	{
		//开始绘制
		layer->ONLButtonDown(nFlags,point);
		//加入绘图类集合
		m_list.Add(layer);
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy86psView::OnLButtonUp(UINT nFlags, CPoint point)
{
	int count=m_list.GetCount();
	if(!count)
		return;
	//找到list中的最后的绘图类
	CLayer *layer=m_list[count-1];
	//结束绘制
	layer->OnLButtonUp(nFlags, point);
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void CMy86psView::OnMouseMove(UINT nFlags, CPoint point)
{
	int count=m_list.GetCount();
	if(!count)
		return;
	//临时绘图对象dc
	CClientDC dc(this);
	CLayer *layer=m_list[count-1];
	layer->OnMouseMove(nFlags,point,&dc);

	CView::OnMouseMove(nFlags, point);
}
//添加选中状态：直线判断点到直线的距离，曲线判断每一个点和当前鼠标的point是否相等，椭圆判断point是否在该椭圆中