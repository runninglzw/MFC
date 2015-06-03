; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFour_oneDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "four_one.h"

ClassCount=4
Class1=CFour_oneApp
Class2=CFour_oneDlg

ResourceCount=4
Resource2=IDD_FOUR_ONE_DIALOG
Resource1=IDR_MAINFRAME
Class3=CAboutDlg
Resource3=IDD_ABOUT
Class4=CChatDlg
Resource4=IDD_CHAT_DLG

[CLS:CFour_oneApp]
Type=0
HeaderFile=four_one.h
ImplementationFile=four_one.cpp
Filter=N

[CLS:CFour_oneDlg]
Type=0
HeaderFile=four_oneDlg.h
ImplementationFile=four_oneDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CFour_oneDlg



[DLG:IDD_FOUR_ONE_DIALOG]
Type=1
Class=CFour_oneDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816

[DLG:IDD_ABOUT]
Type=1
Class=CAboutDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342177294
Control3=IDC_STATIC,static,1342308352

[CLS:CAboutDlg]
Type=0
HeaderFile=AboutDlg.h
ImplementationFile=AboutDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CAboutDlg

[DLG:IDD_CHAT_DLG]
Type=1
Class=CChatDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552

[CLS:CChatDlg]
Type=0
HeaderFile=ChatDlg.h
ImplementationFile=ChatDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT2

