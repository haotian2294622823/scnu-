// philosophers_eating_problemDoc.h : interface of the CPhilosophers_eating_problemDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PHILOSOPHERS_EATING_PROBLEMDOC_H__237378DB_3AFA_4766_9EC7_C053F24E5BC5__INCLUDED_)
#define AFX_PHILOSOPHERS_EATING_PROBLEMDOC_H__237378DB_3AFA_4766_9EC7_C053F24E5BC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPhilosophers_eating_problemDoc : public CDocument
{
protected: // create from serialization only
	CPhilosophers_eating_problemDoc();
	DECLARE_DYNCREATE(CPhilosophers_eating_problemDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhilosophers_eating_problemDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPhilosophers_eating_problemDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPhilosophers_eating_problemDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PHILOSOPHERS_EATING_PROBLEMDOC_H__237378DB_3AFA_4766_9EC7_C053F24E5BC5__INCLUDED_)
