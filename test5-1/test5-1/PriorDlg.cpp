// PriorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test5-1.h"
#include "PriorDlg.h"
#include "afxdialogex.h"


// CPriorDlg 对话框

IMPLEMENT_DYNAMIC(CPriorDlg, CDialogEx)

CPriorDlg::CPriorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPriorDlg::IDD, pParent)
{

}

CPriorDlg::~CPriorDlg()
{
}

void CPriorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPriorDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CPriorDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CPriorDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_ADD, &CPriorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DEL, &CPriorDlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_MODIFY, &CPriorDlg::OnBnClickedModify)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CPriorDlg::OnCbnSelchangeCombo1)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CPriorDlg 消息处理程序


void CPriorDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void CPriorDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

//添加账户
void CPriorDlg::OnBnClickedAdd()
{
	user u;
	//获得账号名
	GetDlgItemText(IDC_EDIT1,u.name,sizeof(u.name));//c语言函数，空间有限
	//获得list控件
	CListCtrl *p=(CListCtrl *)GetDlgItem(IDC_LIST1);
	//list中的账号数
	int count=p->GetItemCount(),i=0;
	//遍历list中的账号
	while(i<count)
	{
		//如果含有该账号则不添加
		if(p->GetItemText(i,0)==u.name)
		{
			AfxMessageBox("已经含有该账号！");
			return;
		}
		i++;
	}
	//没有该账号则进行添加,在list中添加一行，先insertitem(行号，值),在setItemtext（行号，列号，值）
	p->InsertItem(count,u.name);
	GetDlgItemText(IDC_EDIT2,u.pass,sizeof(u.pass));
	p->SetItemText(count,1,u.pass);
	//获得combobox控件，并把它的值赋给第三列
	CComboBox * combo=(CComboBox *)GetDlgItem(IDC_COMBO1);
	u.prior=combo->GetCurSel();
	if(u.prior==0)
		p->SetItemText(count,2,"普通");
	else if(u.prior==1)
		p->SetItemText(count,2,"管理员");

}

//删除
void CPriorDlg::OnBnClickedDel()
{
	// TODO: 在此添加控件通知处理程序代码
}

//修改
void CPriorDlg::OnBnClickedModify()
{
	// TODO: 在此添加控件通知处理程序代码
}
//将文件信息读入列表
void CPriorDlg::Readuesr(CListCtrl * p)
{
	CFile file;
	if(!file.Open("./users.dat",CFile::modeRead|CFile::shareDenyNone))
	{
		AfxMessageBox("读取信息失败！");
		return ;
	}
	p->DeleteAllItems();
	user u;
	int i=0;
	//读取数据插入到list中
	while(file.Read(&u,sizeof(u))>0)
	{
		p->InsertItem(i,u.name);
		p->SetItemText(i,1,u.pass);
		p->SetItemText(i,2,u.prior?"管理员":"普通");
		i++;
	}
	file.Close();
}
BOOL CPriorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CListCtrl *p=(CListCtrl *)GetDlgItem(IDC_LIST1);
	p->InsertColumn(0,"账号",0,150);//第三个参数为对齐设置，0为左对齐
	p->InsertColumn(1,"密码",0,150);
	p->InsertColumn(2,"权限",0,150);
	Readuesr(p);
	CComboBox *combo=(CComboBox *)GetDlgItem(IDC_COMBO1);
	combo->AddString("普通");
	combo->AddString("管理员");
	combo->SetCurSel(0);
	Invalidate();
	return TRUE;
}


void CPriorDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CPriorDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	CFile file;
	if(!file.Open("./users.dat",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite))
	{
		AfxMessageBox("写入文件错误！");
		return;
	}
	file.SeekToEnd();
	user u;
	CListCtrl *p=(CListCtrl *)GetDlgItem(IDC_LIST1);
	int count=p->GetItemCount(),i=0;
	while(i<count)
	{
		p->GetItemText(i,0,u.name,sizeof(u.name));
		p->GetItemText(i,1,u.pass,sizeof(u.pass));
		u.prior=(p->GetItemText(i,2)=="管理员");
		file.Write(&u,sizeof(u));
		i++;
	}
	file.Close();
}



