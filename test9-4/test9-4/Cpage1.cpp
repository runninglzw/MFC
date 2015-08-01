// Cpage1.cpp : 实现文件
//

#include "stdafx.h"
#include "test9-4.h"
#include "Cpage1.h"
#include "afxdialogex.h"


// Cpage1 对话框

IMPLEMENT_DYNAMIC(Cpage1, CPropertyPage)

Cpage1::Cpage1()
	: CPropertyPage(Cpage1::IDD)
{

}

Cpage1::~Cpage1()
{
}

void Cpage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cpage1, CPropertyPage)
END_MESSAGE_MAP()


// Cpage1 消息处理程序


BOOL Cpage1::OnSetActive()
{		
	//第一页设置下一步按钮，返回按钮禁用
	CPropertySheet *sheet=(CPropertySheet *)GetParent();
	sheet->SetWizardButtons(2);

	return CPropertyPage::OnSetActive();
}
