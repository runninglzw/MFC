// Cpage3.cpp : 实现文件
//

#include "stdafx.h"
#include "test9-4.h"
#include "Cpage3.h"
#include "afxdialogex.h"


// Cpage3 对话框

IMPLEMENT_DYNAMIC(Cpage3, CPropertyPage)

Cpage3::Cpage3()
	: CPropertyPage(Cpage3::IDD)
	, m_sex(_T(""))
{

}

Cpage3::~Cpage3()
{
}

void Cpage3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SEX, m_sex);
}


BEGIN_MESSAGE_MAP(Cpage3, CPropertyPage)
END_MESSAGE_MAP()


// Cpage3 消息处理程序


BOOL Cpage3::OnSetActive()
{
	//最后一页设置完成按钮和返回按钮
	CPropertySheet *sheet=(CPropertySheet *)GetParent();
	sheet->SetWizardButtons(1|4);

	return CPropertyPage::OnSetActive();
}
