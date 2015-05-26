// TestMFC.h : main header file for the TESTMFC application
//

#if !defined(AFX_TESTMFC_H__AFCC439E_FA9D_4846_8926_26120B6C4822__INCLUDED_)
#define AFX_TESTMFC_H__AFCC439E_FA9D_4846_8926_26120B6C4822__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestMFCApp:
// See TestMFC.cpp for the implementation of this class
//

class CTestMFCApp : public CWinApp
{
public:
	CTestMFCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestMFCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestMFCApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTMFC_H__AFCC439E_FA9D_4846_8926_26120B6C4822__INCLUDED_)
