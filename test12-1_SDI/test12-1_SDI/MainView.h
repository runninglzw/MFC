#pragma once
#include "afxcview.h"
class CMainView :
	public CListView
{
public:
	CMainView(void);
	~CMainView(void);
	virtual void OnInitialUpdate();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnEditAdd();
	afx_msg void OnEditDel();
	afx_msg void OnEditMod();
};

