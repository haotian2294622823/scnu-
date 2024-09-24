// philosophers_eating_problem.h : main header file for the PHILOSOPHERS_EATING_PROBLEM application
//

#if !defined(AFX_PHILOSOPHERS_EATING_PROBLEM_H__25E099D3_9CC3_49D7_BBF9_5C1A5F7FAA97__INCLUDED_)
#define AFX_PHILOSOPHERS_EATING_PROBLEM_H__25E099D3_9CC3_49D7_BBF9_5C1A5F7FAA97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPhilosophers_eating_problemApp:
// See philosophers_eating_problem.cpp for the implementation of this class
//

class CPhilosophers_eating_problemApp : public CWinApp
{
public:
	CPhilosophers_eating_problemApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhilosophers_eating_problemApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPhilosophers_eating_problemApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PHILOSOPHERS_EATING_PROBLEM_H__25E099D3_9CC3_49D7_BBF9_5C1A5F7FAA97__INCLUDED_)
