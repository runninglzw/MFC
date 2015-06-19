// InsertPeople.cpp : 实现文件
//

#include "stdafx.h"
#include "test5-1.h"
#include "InsertPeople.h"
#include "afxdialogex.h"


// CInsertPeople 对话框

IMPLEMENT_DYNAMIC(CInsertPeople, CDialogEx)

CInsertPeople::CInsertPeople(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInsertPeople::IDD, pParent)
{

}

CInsertPeople::~CInsertPeople()
{
}

void CInsertPeople::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInsertPeople, CDialogEx)
	ON_BN_CLICKED(IDOK, &CInsertPeople::OnBnClickedOk)
END_MESSAGE_MAP()


// CInsertPeople 消息处理程序

//添加一个员工信息
void CInsertPeople::OnBnClickedOk()
{
	//创建list控件（infodlg->p）的引用
	CListCtrl &list=infodlg->p;
	//获得要插入的id
	CString id;
	GetDlgItemText(IDC_EDIT1,id);
	//遍历list中是否有，没有则插入
	int i=0,count=list.GetItemCount();
	while(i<count)
	{
		if(id==list.GetItemText(i,0))
		{
			CString str;
			str.Format("工号%s已经存在",id);
			AfxMessageBox(str);
			return ;
		}
		i++;
	}
	if(IDNO==AfxMessageBox("确定添加该记录么？",MB_YESNO))
		return;
	//插入一行
	list.InsertItem(i,id);
	//获得姓名并插入
	GetDlgItemText(IDC_EDIT2,id);
	list.SetItemText(i,1,id);
	//获得年龄并插入
	GetDlgItemText(IDC_DATETIMEPICKER1,id);
	list.SetItemText(i,2,id);
	//获得年龄并插入
	GetDlgItemText(IDC_COMBOBUMEN,id);
	list.SetItemText(i,3,id);
	//获得工资并插入
	GetDlgItemText(IDC_EDIT5,id);
	list.SetItemText(i,4,id);
	//清空列表控件并设置焦点
	SetDlgItemText(IDC_EDIT1,"");
	SetDlgItemText(IDC_EDIT2,"");
	SetDlgItemText(IDC_DATETIMEPICKER1,"");
	SetDlgItemText(IDC_COMBOBUMEN,"");
	SetDlgItemText(IDC_EDIT5,"");
	//设置焦点
	GetDlgItem(IDC_EDIT1)->SetFocus();

}

//插入员工之前进行控件的初始化
BOOL CInsertPeople::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//初始化控件中的数值
	//SetDlgItemText(IDC_DATETIMEPICKER1,"1994/5/12");用这个方法初始化不行
	CDateTimeCtrl *ptime=(CDateTimeCtrl *)GetDlgItem(IDC_DATETIMEPICKER1);
	CTime time(1994,5,12,0,0,0);
	ptime->SetTime(&time);
	SetDlgItemText(IDC_COMBOBUMEN,"开发部");
	return TRUE;
}
