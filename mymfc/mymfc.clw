; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMymfcDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mymfc.h"

ClassCount=4
Class1=CMymfcApp
Class2=CMymfcDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MYMFC_DIALOG

[CLS:CMymfcApp]
Type=0
HeaderFile=mymfc.h
ImplementationFile=mymfc.cpp
Filter=N

[CLS:CMymfcDlg]
Type=0
HeaderFile=mymfcDlg.h
ImplementationFile=mymfcDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=mymfcDlg.h
ImplementationFile=mymfcDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MYMFC_DIALOG]
Type=1
Class=CMymfcDlg
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_NUMBER,edit,1350631552
Control7=IDC_NAME,edit,1350631552
Control8=IDC_GONGZI,edit,1350631552
Control9=IDC_LIST,SysListView32,1350762505
Control10=IDC_ADD,button,1342242816
Control11=IDC_DEL,button,1342242816
Control12=IDC_MOD,button,1342242816

