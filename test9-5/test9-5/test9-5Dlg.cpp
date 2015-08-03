
// test9-5Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test9-5.h"
#include "test9-5Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest95Dlg 对话框



Ctest95Dlg::Ctest95Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest95Dlg::IDD, pParent)
{
	changed=false;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest95Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_TREE, m_tree);
}

BEGIN_MESSAGE_MAP(Ctest95Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Ctest95Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Ctest95Dlg::OnBnClickedCancel)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, &Ctest95Dlg::OnSelchangedTree)
	ON_BN_CLICKED(IDC_BUTTON1, &Ctest95Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Ctest95Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Ctest95Dlg 消息处理程序

BOOL Ctest95Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list.InsertColumn(0,"工号",0,80);
	m_list.InsertColumn(1,"姓名",0,80);
	m_list.InsertColumn(2,"工资",0,80);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	HTREEITEM treeroot=m_tree.InsertItem("总公司");
	HTREEITEM tree1=m_tree.InsertItem("华为",treeroot);
	m_tree.InsertItem("行政部",tree1);
	m_tree.InsertItem("研发部",tree1);
	HTREEITEM tree2=m_tree.InsertItem("腾讯",treeroot);
	m_tree.InsertItem("行政部",tree2);
	m_tree.InsertItem("研发部",tree2);
	//展开跟结点
	m_tree.Expand(treeroot,TVE_EXPAND);
	m_tree.Expand(tree1,TVE_EXPAND);
	m_tree.Expand(tree2,TVE_EXPAND);
	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ctest95Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文


		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ctest95Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest95Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void Ctest95Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
//获得路径
CString Ctest95Dlg::GetPath(HTREEITEM item)
{
	CString str;
	while(item)
	{
		str=m_tree.GetItemText(item)+"\\"+str;
		item=m_tree.GetParentItem(item);//获得父节点

	}
	return str;
}
//获得深度
int Ctest95Dlg::GetDepth(HTREEITEM item)
{
	int res=0;
	while(item)
	{
		item=m_tree.GetParentItem(item);
		res++;
	}
	return res;
}
//更改选中项
void Ctest95Dlg::OnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	if(changed)
	{
		if(IDYES==AfxMessageBox("是否保存？",MB_YESNO))
			Save();
	}
	changed=false;
	HTREEITEM item=pNMTreeView->itemNew.hItem;//获得当前结点
	CString str=GetPath(item);
	int depth=GetDepth(item);
	//如果是叶子节点，添加和删除按钮才能生效
	GetDlgItem(IDC_ADD)->EnableWindow(3==depth);
	GetDlgItem(IDC_DEL)->EnableWindow(3==depth);
	SetDlgItemText(IDC_TEXT,str);
	Load();
	*pResult = 0;
}

//添加
void Ctest95Dlg::OnBnClickedButton1()
{
	int count=m_list.GetItemCount();
	int i=0;
	CString str;
	//获得工号
	GetDlgItemText(IDC_ID,str);
	//判断工号是否存在
	while(i<count)
	{
		if(str==m_list.GetItemText(i,0))
		{
			AfxMessageBox("已经存在该工号！");
			return ;
		}
		i++;
	}
	//如果工号不存在则插入
	m_list.InsertItem(i,str);
	GetDlgItemText(IDC_NAME,str);
	m_list.SetItemText(i,1,str);
	GetDlgItemText(IDC_PAY,str);
	m_list.SetItemText(i,2,str);
	changed=true;

}

//删除
void Ctest95Dlg::OnBnClickedButton2()
{
	changed=true;
}
void Ctest95Dlg::Save()
{
	CString path;
	GetDlgItemText(IDC_TEXT,path);
	CFile file;
	if(!file.Open(path+"mem.dat",CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("文件保存失败！");
		return ;
	}
	Info temp;
	int i=0,count=m_list.GetItemCount();
	while(i<count)
	{
		temp.id=atoi(m_list.GetItemText(i,0));
		strcpy_s(temp.name,m_list.GetItemText(i,1));
		temp.pay= atof(m_list.GetItemText(i,2));
		file.Write(&temp,sizeof(temp));
		i++;
	}
}
void Ctest95Dlg::Load()
{
	m_list.DeleteAllItems();
	CString path;
	GetDlgItemText(IDC_TEXT,path);
	CFile file;
	if(!file.Open(path+"mem.dat",CFile::modeRead))
	{
		AfxMessageBox("文件打开失败！");
		return ;
	}
	Info temp;
	CString str;
	int i=0;
	while(file.Read(&temp,sizeof(temp))   ==sizeof(temp))
	{
		str.Format("%d",temp.id);
		m_list.InsertItem(i,str);
		m_list.SetItemText(i,1,temp.name);
		str.Format("%0.2lf",temp.pay);
		m_list.SetItemText(i,2,str);
		i++;
	}

}