// InfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test5-1.h"
#include "InfoDlg.h"
#include "afxdialogex.h"
#include "insertpeople.h"
#include "ModifyDlg.h"


// CInfoDlg 对话框

IMPLEMENT_DYNAMIC(CInfoDlg, CDialogEx)

CInfoDlg::CInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInfoDlg::IDD, pParent)
{

}

CInfoDlg::~CInfoDlg()
{
}

void CInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CInfoDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CInfoDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_ADD, &CInfoDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_QUIT, &CInfoDlg::OnBnClickedQuit)
	ON_BN_CLICKED(IDC_MODIFY, &CInfoDlg::OnBnClickedModify)
	ON_BN_CLICKED(IDC_DEL, &CInfoDlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_OPEN, &CInfoDlg::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_SAVE, &CInfoDlg::OnBnClickedSave)
END_MESSAGE_MAP()


// CInfoDlg 消息处理程序


void CInfoDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void CInfoDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnCancel();
}


BOOL CInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	p.SubclassDlgItem(IDC_LIST1,this);
	p.InsertColumn(0,"工号",0,60);
	p.InsertColumn(1,"姓名",0,60);
	p.InsertColumn(2,"生日",0,100);
	p.InsertColumn(3,"部门",0,100);
	p.InsertColumn(4,"工资",0,100);
	return TRUE;
}

//添加成员
void CInfoDlg::OnBnClickedAdd()
{
	CInsertPeople dlg;
	//设置InsertPeople对话框的infodlg指针（指向CInfoDlg），这样在InsertPeople对话框中就可以给CInfoDlg中的列表控件赋值了
	dlg.infodlg=this;
	dlg.DoModal();
}

//退出
void CInfoDlg::OnBnClickedQuit()
{
	CDialogEx::OnCancel();
}

//修改员工信息
void CInfoDlg::OnBnClickedModify()
{
	POSITION pos=p.GetFirstSelectedItemPosition();
	if(p.GetSelectedCount()==0)
	{
		AfxMessageBox("请选中一行修改！");
		return;
	}
	//获得行数
	int sel=p.GetNextSelectedItem(pos);
	//给修改对话框中的变量赋值，该对话框初始化时变量会给控件赋值
	CModifyDlg dlg;
	dlg.m_id=atoi(p.GetItemText(sel,0));
	dlg.m_name=p.GetItemText(sel,1);
	dlg.m_birth.ParseDateTime(p.GetItemText(sel,2));
	dlg.m_bumen=p.GetItemText(sel,3);
	dlg.m_pay=(float)atof(p.GetItemText(sel,4));
	if(IDCANCEL==dlg.DoModal())
	{
		return;
	}
	//点了确定后对话框绑定的控件会赋值给变量，将变量赋值给list控件更新即可
	CString str;
	str.Format("%d",dlg.m_id);
	p.SetItemText(sel,0,str);
	p.SetItemText(sel,1,dlg.m_name);
	p.SetItemText(sel,2,dlg.m_birth.Format(VAR_DATEVALUEONLY));//或者使用dlg.m_birth.Format("%Y%m%d")
	p.SetItemText(sel,3,dlg.m_bumen);
	str.Format("%0.2f",dlg.m_pay);
	p.SetItemText(sel,4,str);
}

//删除员工信息
void CInfoDlg::OnBnClickedDel()
{
	// TODO: 在此添加控件通知处理程序代码
}

//打开文件读取员工信息
void CInfoDlg::OnBnClickedOpen()
{
	CFileDialog dlg(TRUE);
	if(IDCANCEL==dlg.DoModal())
		return;
	//获得文件路径
	CString filepath=dlg.GetPathName();
	//开始将list中的数据写入文件
	CFile file;
	if(!file.Open(filepath,CFile::shareDenyNone|CFile::modeRead))
	{
		AfxMessageBox("文件打开失败！");
		return ;
	}
	//删除列表中所有数据
	p.DeleteAllItems();
	int i=0;
	info mes;
	while(file.Read(&mes,sizeof(mes))>0)
	{
		//读取文件中的数据到list中
		CString str;
		str.Format("%d",mes.nnum);
		p.InsertItem(i,str);
		p.SetItemText(i,1,mes.strname);
		p.SetItemText(i,2,mes.birth);
		p.SetItemText(i,3,mes.strdepartment);
		str.Format("%0.1f",mes.pay);
		p.SetItemText(i,4,str);
		i++;
	}
}

//将员工信息保存到文件中
void CInfoDlg::OnBnClickedSave()
{
	LPCSTR filter="员工信息(*.dat)|*.dat|所有文件(*.*)|*.*||";
	CFileDialog dlg(FALSE,"dat","员工信息",OFN_OVERWRITEPROMPT,filter);//第一个参数指示以另存为的形式打开，第二个表示默认后缀名，第三个表示默认文件名，第四个表示格式，第五个表示保存类型的可选项
	if(IDCANCEL==dlg.DoModal())
		return;
	//获得文件路径
	CString filepath=dlg.GetPathName();
	//开始将list中的数据写入文件
	CFile file;
	if(!file.Open(filepath,CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("数据保存失败！");
		return ;
	}
	int i=0,count=p.GetItemCount();
	while(i<count)
	{
		//将list中的数据写入结构体，然后将结构体写入文件
		info mes;
		mes.nnum=atoi(p.GetItemText(i,0));
		p.GetItemText(i,1,mes.strname,sizeof(mes.strname));
		p.GetItemText(i,2,mes.birth,sizeof(mes.birth));
		p.GetItemText(i,3,mes.strdepartment,sizeof(mes.strdepartment));
		mes.pay=atof(p.GetItemText(i,4));
		file.Write(&mes,sizeof(mes));
		i++;
	}
	file.Close();
}
