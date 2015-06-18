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
	GetDlgItemText(IDC_EDIT2,u.pass,sizeof(u.pass));
	//c语言中比较两个字符串用strcmp，不能用==
	if(!strcmp(u.name,"")||!strcmp(u.pass,""))
	{
		AfxMessageBox("账号和密码不允许为空！");
		return ;
	}
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
	
	p->SetItemText(count,1,u.pass);
	//获得combobox控件，并把它的值赋给第三列
	CComboBox * combo=(CComboBox *)GetDlgItem(IDC_COMBO1);
	u.prior=combo->GetCurSel();
	if(u.prior==0)
		p->SetItemText(count,2,"普通");
	else if(u.prior==1)
		p->SetItemText(count,2,"管理员");

}

//删除账户
void CPriorDlg::OnBnClickedDel()
{
	//获得列表控件
	CListCtrl *p=(CListCtrl *)GetDlgItem(IDC_LIST1);
	//获得删除的行号
	//int index=p->GetSelectionMark();
	//获得删除链表的头结点
	POSITION pos=p->GetFirstSelectedItemPosition();
	//获得删除的行号
	int index=p->GetNextSelectedItem(pos);
	//判断是否有选中的
	if(index<0)
	{
		AfxMessageBox("请选择一项！");
	}
	//判断选中的是否是admin
	else if(p->GetItemText(index,0)=="admin")
		AfxMessageBox("不允许删除admin");
	else
	{
		CString str;
		str.Format("确定要删除%s么？",p->GetItemText(index,0));
		if(IDYES==AfxMessageBox(str,MB_YESNO))
			p->DeleteItem(index);
	}
}

//修改账户信息
void CPriorDlg::OnBnClickedModify()
{
	//获得列表控件
	CListCtrl *p=(CListCtrl *)GetDlgItem(IDC_LIST1);
	//获得删除的行号
	//int index=p->GetSelectionMark();
	//获得删除链表的头结点
	POSITION pos=p->GetFirstSelectedItemPosition();
	//获得删除的行号
	int index=p->GetNextSelectedItem(pos);
	//判断是否有选中的
	if(index<0)
	{
		AfxMessageBox("请选择一项！");
	}
	//判断选中的是否是admin
	else if(p->GetItemText(index,0)=="admin")
		AfxMessageBox("不允许修改admin");
	else
	{
		CString str;
		str.Format("确定要修改%s么？",p->GetItemText(index,0));
		//确认修改
		if(IDYES==AfxMessageBox(str,MB_YESNO))
		{
			//获得密码内容
			CString pass;
			GetDlgItemText(IDC_EDIT2,pass);
			//进行密码修改
			p->SetItemText(index,1,pass);
			//获得权限内容
			CComboBox *combo=(CComboBox *)GetDlgItem(IDC_COMBO1);
			int prior=combo->GetCurSel();
			p->SetItemText(index,2,prior?"管理员":"普通");
		}
	}
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
	if(!file.Open("./users.dat",CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("写入文件错误！");
		return;
	}
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



