#include "stdafx.h"
#include "MainView.h"
#include "AddDlg.h"


CMainView::CMainView(void)
{
}


CMainView::~CMainView(void)
{
}

//类似于oninitialdialog
void CMainView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();
	CListCtrl& list=GetListCtrl();
	list.ModifyStyle(0,LVS_REPORT);
	list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	list.InsertColumn(0,"工号",0,200);
	list.InsertColumn(1,"姓名",0,200);
	list.InsertColumn(2,"工资",0,200);
	// TODO: 在此添加专用代码和/或调用基类
}
BEGIN_MESSAGE_MAP(CMainView, CListView)
	ON_COMMAND(ID_EDIT_ADD, &CMainView::OnEditAdd)
	ON_COMMAND(ID_EDIT_DEL, &CMainView::OnEditDel)
	ON_COMMAND(ID_EDIT_MOD, &CMainView::OnEditMod)
END_MESSAGE_MAP()


void CMainView::OnEditAdd()
{
	CAddDlg dlg;
	if(IDCANCEL==dlg.DoModal())
		return;
	CListCtrl &list=GetListCtrl();
	int count=list.GetItemCount();
	list.InsertItem(count,dlg.m_id);
	list.SetItemText(count,1,dlg.m_name);
	list.SetItemText(count,2,dlg.m_pay);
}


//void CMainView::OnEditDel()
//{
//	// TODO: 在此添加命令处理程序代码
//}


//void CMainView::OnEditMod()
//{
//	// TODO: 在此添加命令处理程序代码
//}
