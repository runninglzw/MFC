// mymfc.h : main header file for the MYMFC application
//

#if !defined(AFX_MYMFC_H__6760330E_C7D4_4773_B60A_C391128D2BFD__INCLUDED_)
#define AFX_MYMFC_H__6760330E_C7D4_4773_B60A_C391128D2BFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMymfcApp:
// See mymfc.cpp for the implementation of this class
//

class CMymfcApp : public CWinApp
{
public:
	CMymfcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMymfcApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMymfcApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMFC_H__6760330E_C7D4_4773_B60A_C391128D2BFD__INCLUDED_)
