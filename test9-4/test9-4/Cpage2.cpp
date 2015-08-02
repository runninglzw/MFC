// Cpage2.cpp : 实现文件
//

#include "stdafx.h"
#include "test9-4.h"
#include "Cpage2.h"
#include "afxdialogex.h"


// Cpage2 对话框

IMPLEMENT_DYNAMIC(Cpage2, CPropertyPage)

Cpage2::Cpage2()
	: CPropertyPage(Cpage2::IDD)
	, m_name(_T(""))
{

}

Cpage2::~Cpage2()
{
}

void Cpage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, m_name);
}


BEGIN_MESSAGE_MAP(Cpage2, CPropertyPage)
END_MESSAGE_MAP()


// Cpage2 消息处理程序


BOOL Cpage2::OnSetActive()
{
		//第二页设置下一步按钮和返回按钮
	CPropertySheet *sheet=(CPropertySheet *)GetParent();
	sheet->SetWizardButtons(1|2);

	return CPropertyPage::OnSetActive();
}
