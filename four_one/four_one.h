// four_one.h : main header file for the FOUR_ONE application
//

#if !defined(AFX_FOUR_ONE_H__4189D285_8415_4B21_8FEF_DF21ADCBDFE4__INCLUDED_)
#define AFX_FOUR_ONE_H__4189D285_8415_4B21_8FEF_DF21ADCBDFE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFour_oneApp:
// See four_one.cpp for the implementation of this class
//

class CFour_oneApp : public CWinApp
{
public:
	CFour_oneApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFour_oneApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFour_oneApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FOUR_ONE_H__4189D285_8415_4B21_8FEF_DF21ADCBDFE4__INCLUDED_)
