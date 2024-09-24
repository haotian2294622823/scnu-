// philosophers_eating_problemView.cpp : implementation of the CPhilosophers_eating_problemView class
//

#include "stdafx.h"
#include "philosophers_eating_problem.h"


#include "philosophers_eating_problemDoc.h"
#include "philosophers_eating_problemView.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


HWND main_window;
DWORD Thread1ID,Thread2ID,Thread3ID,Thread4ID,Thread5ID;//���������߳�ID��
HANDLE h_Mutex1,h_Mutex2,h_Mutex3,h_Mutex4,h_Mutex5;//�������滥���������
HANDLE Comman_Mutex;

int philosophers[5][2]={0,0,0,0,0,0,0,0,0,0};
int chopsticks[5]={1,1,1,1,1};


//typedef unsigned (__stdcall *PTHREAD_START) (void *);

//#define chBEGINTHREADEX(psa,cbStack,pfnStartAddr,pvParam,fdwCreate,pdwThreadID)
//((HANDLE) _beginthreadex((void *)(psa),(unsigned )(cbStack),(PTHREAD_START)(pfnStartAddr),
// (void *)(pvParam),(unsigned )(fdwCreate),(unsigned *)(pdwThreadID)))





DWORD WINAPI Thread1(PVOID pvParam)//��1���̺߳���
{
//	for(int k=0;k<5;++k)
//   AfxMessageBox("My  Thread  1");
WPARAM wparam;//�����ĸ���ѧ��
LPARAM lparam;//�����ĸ����ӡ������0�����ǿ��ӣ������0����ô˵����ѧ�ҷ������ߵĿ��ӡ�
	while(1)
	{   
		Sleep(1000);
		WaitForSingleObject(h_Mutex5,INFINITE);
      //  AfxMessageBox("��ѧ��1�õ�����5,�ȴ�����1");
        wparam=1;
		lparam=5;
        ::PostMessage (main_window,WM_MYMSG,wparam,lparam);
		WaitForSingleObject(h_Mutex1,INFINITE);
	//	AfxMessageBox("��ѧ��1�õ�����1,��ʼ����");
		wparam=1;
        lparam=1;
        ::PostMessage (main_window,WM_MYMSG,wparam,lparam);
        Sleep(5000);
   

		wparam=1;
		lparam=0;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);

		ReleaseMutex(h_Mutex5);
		ReleaseMutex(h_Mutex1);

      //  AfxMessageBox("��ѧ��1�ò���ϣ����¿���5��1");
	}

	return  0;

}

DWORD WINAPI Thread2(PVOID pvParam)//��2���̺߳���
{
WPARAM wparam;//�����ĸ���ѧ��
LPARAM lparam;//�����ĸ����ӡ������0�����ǿ��ӣ������0����ô˵����ѧ�ҷ������ߵĿ��ӡ�

		while(1)
	{
		Sleep(1000);
		WaitForSingleObject(h_Mutex2,INFINITE);
      //  AfxMessageBox("��ѧ��2�õ�����2,�ȴ�����1");
        wparam=2;
		lparam=2;
        ::PostMessage (main_window,WM_MYMSG,wparam,lparam);
		WaitForSingleObject(h_Mutex1,INFINITE);
	//	AfxMessageBox("��ѧ��2�õ�����1,��ʼ����");
        wparam=2;
		lparam=1;
        ::PostMessage (main_window,WM_MYMSG,wparam,lparam);
	
        Sleep(5000);
       // AfxMessageBox("��ѧ��2�ò���ϣ����¿���2��1");
        wparam=2;
        lparam=0;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);
	    
		ReleaseMutex(h_Mutex2);
		ReleaseMutex(h_Mutex1);
	}
	

	return  0;

}

DWORD WINAPI Thread3(PVOID pvParam)//��3���̺߳���
{
WPARAM wparam;//�����ĸ���ѧ��
LPARAM lparam;//�����ĸ����ӡ������0�����ǿ��ӣ������0����ô˵����ѧ�ҷ������ߵĿ��ӡ�
		while(1)
	{
        Sleep(1000);
		WaitForSingleObject(h_Mutex2,INFINITE);
      //  AfxMessageBox("��ѧ��3�õ�����2,�ȴ�����3");
		wparam=3;
		lparam=2;
        ::PostMessage (main_window,WM_MYMSG,wparam,lparam);

		WaitForSingleObject(h_Mutex3,INFINITE);
	//	AfxMessageBox("��ѧ��3�õ�����3,��ʼ����");
        wparam=3;
		lparam=3;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);
        Sleep(5000);

	

       // AfxMessageBox("��ѧ��3�ò���ϣ����¿���2��3");
		wparam=3;
		lparam=0;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);
	    
		ReleaseMutex(h_Mutex2);
		ReleaseMutex(h_Mutex3);
	}

	return  0;

}

DWORD WINAPI Thread4(PVOID pvParam)//��4���̺߳���
{
WPARAM wparam;//�����ĸ���ѧ��
LPARAM lparam;//�����ĸ����ӡ������0�����ǿ��ӣ������0����ô˵����ѧ�ҷ������ߵĿ��ӡ�
	 while(1)
	{
       Sleep(1000);
		WaitForSingleObject(h_Mutex4,INFINITE);
        //AfxMessageBox("��ѧ��4�õ�����4,�ȴ�����3");
		wparam=4;
		lparam=4;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);

		WaitForSingleObject(h_Mutex3,INFINITE);
		//AfxMessageBox("��ѧ��4�õ�����3,��ʼ����");
		wparam=4;
		lparam=3;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);
        Sleep(5000);

	

        //AfxMessageBox("��ѧ��4�ò���ϣ����¿���4��3");
		wparam=4;
		lparam=0;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);
	    
		ReleaseMutex(h_Mutex4);
		ReleaseMutex(h_Mutex3);
	}

	return  0;

}


DWORD WINAPI Thread5(PVOID pvParam)//��5���̺߳���
{
WPARAM wparam;//�����ĸ���ѧ��
LPARAM lparam;//�����ĸ����ӡ������0�����ǿ��ӣ������0����ô˵����ѧ�ҷ������ߵĿ��ӡ�
		while(1)
	{
        Sleep(1000);
		WaitForSingleObject(h_Mutex4,INFINITE);
        //AfxMessageBox("��ѧ��5�õ�����4,�ȴ�����5");
		wparam=5;
		lparam=4;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);

		WaitForSingleObject(h_Mutex5,INFINITE);
		//AfxMessageBox("��ѧ��5�õ�����5,��ʼ����");
		wparam=5;
		lparam=5;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);
        Sleep(5000);

	

        //AfxMessageBox("��ѧ��5�ò���ϣ����¿���4��5");
		wparam=5;
		lparam=0;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);
	    
		ReleaseMutex(h_Mutex4);
		ReleaseMutex(h_Mutex5);
	}

	return  0;

}
/////////////////////////////////////////////////////////////////////////////
// CPhilosophers_eating_problemView

IMPLEMENT_DYNCREATE(CPhilosophers_eating_problemView, CView)

BEGIN_MESSAGE_MAP(CPhilosophers_eating_problemView, CView)
	//{{AFX_MSG_MAP(CPhilosophers_eating_problemView)
	ON_COMMAND(IDM_BEGIN, OnBegin)	

	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_MESSAGE(WM_MYMSG,OnMYMSG)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPhilosophers_eating_problemView construction/destruction

CPhilosophers_eating_problemView::CPhilosophers_eating_problemView()
{
	// TODO: add construction code here

}

CPhilosophers_eating_problemView::~CPhilosophers_eating_problemView()
{
}

BOOL CPhilosophers_eating_problemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	
	static CBrush brush(RGB(0,0,255));
    SetClassLong(this->m_hWnd,GCL_HBRBACKGROUND,(LONG)(HBRUSH)brush);



	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPhilosophers_eating_problemView drawing

void CPhilosophers_eating_problemView::OnDraw(CDC* pDC)
{

	WaitForSingleObject(Comman_Mutex,INFINITE);//���뻥����

	CPhilosophers_eating_problemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

    CPen blue_pen(PS_SOLID,1,RGB(35,180,250));
    CPen yellow_pen(PS_SOLID,3,RGB(253,179,50));
	pDC->SelectObject (&blue_pen);//����һ����ɫ���ʣ�
//	pDC->SetBkColor (RGB(255,0,0));

	

	CRect client_rect;
	GetClientRect(&client_rect);//��ÿͻ�����С��

    pt=client_rect.CenterPoint ();//pt�������ֿͻ������е㡣

    CBrush blue_brush,red_brush;
	blue_brush.CreateSolidBrush (RGB(35,180,250));//����һ����ɫ��ˢ����ѡ��CDC��
	pDC->SelectObject (&blue_brush);
	pDC->Ellipse (pt.x -200,pt.y -200,pt.x +200,pt.y +200);//����һ��Բ�͵���ɫ���ӡ�
    
    red_brush.CreateSolidBrush (RGB(248,95,160));
	pDC->SelectObject (&red_brush);//����һ����ɫ��ˢ��������ɫ��Բ�δ�����ѧ�ҡ�
    pDC->SetBkColor (RGB(248,95,160));//�������ֱ���Ϊ��ɫ��
   


	double pi = 3.1415926535;

    for(int i=0;i<5;i++)//ѭ������5����ѧ�ҵ�Բ��
	{
		CString name;
		name.Format ("��ѧ��%d",i+1);//���������ѧ�����֡�
		double SIN=sin(2*pi*i/5);
		double COS=cos(2*pi*i/5);
     //		CPoint small_pt=(pt.x+250*COS,pt.y-250*SIN);
 
    
	 //   pDC->Ellipse (small_pt.x -50,small_pt.y -50,small_pt.x +50,small_pt.y +50);
	     pDC->Ellipse (pt.x+250*COS-50,pt.y-250*SIN-50,pt.x+250*COS +50,pt.y-250*SIN+50);
         pDC->TextOut (pt.x+250*COS-20 ,pt.y-250*SIN-5 ,name);


	}
     
	pDC->SelectObject (&yellow_pen);//���ϻ�ɫ���ʡ�
	

	//�����ǹ����ģ�ÿ�ζ��ظ���������ľ͸���2�������������

	for(int j=0;j<5;j++)//����ѭ�����5�����ӡ�
	{
		if(chopsticks[j]==1)
		{
        CString name;
		name.Format ("����%d",(j+1)%6);
	    double SIN=sin(2*pi*(2*j+1)/10);
		double COS=cos(2*pi*(2*j+1)/10);

		pDC->MoveTo (pt.x +100*COS,pt.y -100*SIN);
		pDC->LineTo (pt.x +200*COS,pt.y -200*SIN);
		pDC->TextOut (pt.x +100*COS,pt.y -100*SIN,name);
		}

	}

	for(int a=0;a<5;++a)//���滭ÿ����ѧ������Ŀ��ӡ�
	{
        if(philosophers[a][0]!=0)//���ֲ�Ϊ��
		{
			CString name;
			name.Format ("����%d",philosophers[a][0]);
            double SIN=sin(2*pi*a/5-0.035);
		    double COS=cos(2*pi*a/5-0.035);
			pDC->MoveTo (pt.x +100*COS,pt.y -100*SIN);
		    pDC->LineTo (pt.x +200*COS,pt.y -200*SIN);
		    pDC->TextOut (pt.x +115*COS,pt.y -115*SIN,name);
		}
		if(philosophers[a][1]!=0)//���ֲ�Ϊ��
		{	
			CString name;
			name.Format ("����%d",philosophers[a][1]);
            double SIN=sin(2*pi*a/5+0.035);
		    double COS=cos(2*pi*a/5+0.035);
			pDC->MoveTo (pt.x +100*COS,pt.y -100*SIN);
		    pDC->LineTo (pt.x +200*COS,pt.y -200*SIN);
		    pDC->TextOut (pt.x +155*COS,pt.y -155*SIN,name);
		}

	}
	ReleaseMutex(Comman_Mutex); //�뿪������
}

/////////////////////////////////////////////////////////////////////////////
// CPhilosophers_eating_problemView printing

BOOL CPhilosophers_eating_problemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPhilosophers_eating_problemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPhilosophers_eating_problemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPhilosophers_eating_problemView diagnostics

#ifdef _DEBUG
void CPhilosophers_eating_problemView::AssertValid() const
{
	CView::AssertValid();
}

void CPhilosophers_eating_problemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPhilosophers_eating_problemDoc* CPhilosophers_eating_problemView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPhilosophers_eating_problemDoc)));
	return (CPhilosophers_eating_problemDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPhilosophers_eating_problemView message handlers

void CPhilosophers_eating_problemView::OnBegin() 
{
	// TODO: Add your command handler code here

	main_window=this->m_hWnd ;//���������ھ����

	h_Mutex1=CreateMutex(NULL,FALSE,NULL);//�����������ʿ���1�Ļ������
    h_Mutex2=CreateMutex(NULL,FALSE,NULL);//�����������ʿ���2�Ļ������
    h_Mutex3=CreateMutex(NULL,FALSE,NULL);//�����������ʿ���3�Ļ������
    h_Mutex4=CreateMutex(NULL,FALSE,NULL);//�����������ʿ���4�Ļ������
    h_Mutex5=CreateMutex(NULL,FALSE,NULL);//�����������ʿ���5�Ļ������
    
	Comman_Mutex=CreateMutex(NULL,FALSE,NULL);////�������������������Ļ������

	m_thread_handle1=::CreateThread(NULL,0,Thread1,0,0,&Thread1ID);//������1���߳�,�����߳̾��
	m_thread_handle2=::CreateThread(NULL,0,Thread2,0,0,&Thread2ID);//������2���߳�,�����߳̾��
	m_thread_handle3=::CreateThread(NULL,0,Thread3,0,0,&Thread3ID);//������3���߳�,�����߳̾��
	m_thread_handle4=::CreateThread(NULL,0,Thread4,0,0,&Thread4ID);//������4���߳�,�����߳̾��
	m_thread_handle5=::CreateThread(NULL,0,Thread5,0,0,&Thread5ID);//������5���߳�,�����߳̾��

}




void CPhilosophers_eating_problemView::OnMYMSG(WPARAM wParam, LPARAM lParam)
{
    WaitForSingleObject(Comman_Mutex,INFINITE); //���뻥����

	if(lParam!=0 )//������ӡ�
	{
		if(philosophers[wParam-1][0]==0)//��������ǿյġ�
           philosophers[wParam-1][0]=lParam;//������ѧ�ҵ�������
		else
			philosophers[wParam-1][1]=lParam;//������ѧ�ҵ�������

		chopsticks[lParam-1]=0;//��ʾ�˿��ӱ����ߡ�

	}

	else //�ͷ������ֵĿ��ӡ�
	{

        chopsticks[philosophers[wParam-1][0]-1]=1;
		chopsticks[philosophers[wParam-1][1]-1]=1;

		philosophers[wParam-1][0]=0;
        philosophers[wParam-1][1]=0;
	}
	ReleaseMutex(Comman_Mutex);//�뿪������

    Invalidate(FALSE);//ʹ�ͻ����ػ���




}
