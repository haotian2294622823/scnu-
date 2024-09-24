// philosophers_eating_problemView.h : interface of the CPhilosophers_eating_problemView class
//
/////////////////////////////////////////////////////////////////////////////



#if !defined(AFX_PHILOSOPHERS_EATING_PROBLEMVIEW_H__EF0E84D3_BCDD_44DC_996C_1A7B2503976C__INCLUDED_)
#define AFX_PHILOSOPHERS_EATING_PROBLEMVIEW_H__EF0E84D3_BCDD_44DC_996C_1A7B2503976C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"math.h"

#define  WM_MYMSG  WM_USER+100

class CPhilosophers_eating_problemView : public CView
{
protected: // create from serialization only
	CPhilosophers_eating_problemView();
	DECLARE_DYNCREATE(CPhilosophers_eating_problemView)

// Attributes
public:
	CPhilosophers_eating_problemDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhilosophers_eating_problemView)
	public:
    virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void OnMYMSG(WPARAM wParam, LPARAM lParam);
	HANDLE m_thread_handle5;
	HANDLE m_thread_handle4;
	HANDLE m_thread_handle3;
	HANDLE m_thread_handle2;
	HANDLE m_thread_handle1;
	virtual ~CPhilosophers_eating_problemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPhilosophers_eating_problemView)
	afx_msg void OnBegin();
	//}}AFX_MSG
//	afx_msg void OnMYMSG(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	CPoint pt;
};

#ifndef _DEBUG  // debug version in philosophers_eating_problemView.cpp
inline CPhilosophers_eating_problemDoc* CPhilosophers_eating_problemView::GetDocument()
   { return (CPhilosophers_eating_problemDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PHILOSOPHERS_EATING_PROBLEMVIEW_H__EF0E84D3_BCDD_44DC_996C_1A7B2503976C__INCLUDED_)
