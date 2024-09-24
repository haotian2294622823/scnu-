// philosophers_eating_problemDoc.cpp : implementation of the CPhilosophers_eating_problemDoc class
//

#include "stdafx.h"
#include "philosophers_eating_problem.h"

#include "philosophers_eating_problemDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPhilosophers_eating_problemDoc

IMPLEMENT_DYNCREATE(CPhilosophers_eating_problemDoc, CDocument)

BEGIN_MESSAGE_MAP(CPhilosophers_eating_problemDoc, CDocument)
	//{{AFX_MSG_MAP(CPhilosophers_eating_problemDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPhilosophers_eating_problemDoc construction/destruction

CPhilosophers_eating_problemDoc::CPhilosophers_eating_problemDoc()
{
	// TODO: add one-time construction code here

}

CPhilosophers_eating_problemDoc::~CPhilosophers_eating_problemDoc()
{
}

BOOL CPhilosophers_eating_problemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPhilosophers_eating_problemDoc serialization

void CPhilosophers_eating_problemDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPhilosophers_eating_problemDoc diagnostics

#ifdef _DEBUG
void CPhilosophers_eating_problemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPhilosophers_eating_problemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPhilosophers_eating_problemDoc commands
