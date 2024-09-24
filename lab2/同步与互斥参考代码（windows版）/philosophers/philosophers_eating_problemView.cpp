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
DWORD Thread1ID,Thread2ID,Thread3ID,Thread4ID,Thread5ID;//用来保存线程ID。
HANDLE h_Mutex1,h_Mutex2,h_Mutex3,h_Mutex4,h_Mutex5;//用来保存互斥对象句柄。
HANDLE Comman_Mutex;

int philosophers[5][2]={0,0,0,0,0,0,0,0,0,0};
int chopsticks[5]={1,1,1,1,1};


//typedef unsigned (__stdcall *PTHREAD_START) (void *);

//#define chBEGINTHREADEX(psa,cbStack,pfnStartAddr,pvParam,fdwCreate,pdwThreadID)
//((HANDLE) _beginthreadex((void *)(psa),(unsigned )(cbStack),(PTHREAD_START)(pfnStartAddr),
// (void *)(pvParam),(unsigned )(fdwCreate),(unsigned *)(pdwThreadID)))





DWORD WINAPI Thread1(PVOID pvParam)//第1个线程函数
{
//	for(int k=0;k<5;++k)
//   AfxMessageBox("My  Thread  1");
WPARAM wparam;//发送哪个哲学家
LPARAM lparam;//发送哪个筷子。如果非0，则是筷子，如果是0，那么说明哲学家放下两边的筷子。
	while(1)
	{   
		Sleep(1000);
		WaitForSingleObject(h_Mutex5,INFINITE);
      //  AfxMessageBox("哲学家1拿到筷子5,等待筷子1");
        wparam=1;
		lparam=5;
        ::PostMessage (main_window,WM_MYMSG,wparam,lparam);
		WaitForSingleObject(h_Mutex1,INFINITE);
	//	AfxMessageBox("哲学家1拿到筷子1,开始进餐");
		wparam=1;
        lparam=1;
        ::PostMessage (main_window,WM_MYMSG,wparam,lparam);
        Sleep(5000);
   

		wparam=1;
		lparam=0;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);

		ReleaseMutex(h_Mutex5);
		ReleaseMutex(h_Mutex1);

      //  AfxMessageBox("哲学家1用餐完毕，放下筷子5和1");
	}

	return  0;

}

DWORD WINAPI Thread2(PVOID pvParam)//第2个线程函数
{
WPARAM wparam;//发送哪个哲学家
LPARAM lparam;//发送哪个筷子。如果非0，则是筷子，如果是0，那么说明哲学家放下两边的筷子。

		while(1)
	{
		Sleep(1000);
		WaitForSingleObject(h_Mutex2,INFINITE);
      //  AfxMessageBox("哲学家2拿到筷子2,等待筷子1");
        wparam=2;
		lparam=2;
        ::PostMessage (main_window,WM_MYMSG,wparam,lparam);
		WaitForSingleObject(h_Mutex1,INFINITE);
	//	AfxMessageBox("哲学家2拿到筷子1,开始进餐");
        wparam=2;
		lparam=1;
        ::PostMessage (main_window,WM_MYMSG,wparam,lparam);
	
        Sleep(5000);
       // AfxMessageBox("哲学家2用餐完毕，放下筷子2和1");
        wparam=2;
        lparam=0;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);
	    
		ReleaseMutex(h_Mutex2);
		ReleaseMutex(h_Mutex1);
	}
	

	return  0;

}

DWORD WINAPI Thread3(PVOID pvParam)//第3个线程函数
{
WPARAM wparam;//发送哪个哲学家
LPARAM lparam;//发送哪个筷子。如果非0，则是筷子，如果是0，那么说明哲学家放下两边的筷子。
		while(1)
	{
        Sleep(1000);
		WaitForSingleObject(h_Mutex2,INFINITE);
      //  AfxMessageBox("哲学家3拿到筷子2,等待筷子3");
		wparam=3;
		lparam=2;
        ::PostMessage (main_window,WM_MYMSG,wparam,lparam);

		WaitForSingleObject(h_Mutex3,INFINITE);
	//	AfxMessageBox("哲学家3拿到筷子3,开始进餐");
        wparam=3;
		lparam=3;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);
        Sleep(5000);

	

       // AfxMessageBox("哲学家3用餐完毕，放下筷子2和3");
		wparam=3;
		lparam=0;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);
	    
		ReleaseMutex(h_Mutex2);
		ReleaseMutex(h_Mutex3);
	}

	return  0;

}

DWORD WINAPI Thread4(PVOID pvParam)//第4个线程函数
{
WPARAM wparam;//发送哪个哲学家
LPARAM lparam;//发送哪个筷子。如果非0，则是筷子，如果是0，那么说明哲学家放下两边的筷子。
	 while(1)
	{
       Sleep(1000);
		WaitForSingleObject(h_Mutex4,INFINITE);
        //AfxMessageBox("哲学家4拿到筷子4,等待筷子3");
		wparam=4;
		lparam=4;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);

		WaitForSingleObject(h_Mutex3,INFINITE);
		//AfxMessageBox("哲学家4拿到筷子3,开始进餐");
		wparam=4;
		lparam=3;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);
        Sleep(5000);

	

        //AfxMessageBox("哲学家4用餐完毕，放下筷子4和3");
		wparam=4;
		lparam=0;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);
	    
		ReleaseMutex(h_Mutex4);
		ReleaseMutex(h_Mutex3);
	}

	return  0;

}


DWORD WINAPI Thread5(PVOID pvParam)//第5个线程函数
{
WPARAM wparam;//发送哪个哲学家
LPARAM lparam;//发送哪个筷子。如果非0，则是筷子，如果是0，那么说明哲学家放下两边的筷子。
		while(1)
	{
        Sleep(1000);
		WaitForSingleObject(h_Mutex4,INFINITE);
        //AfxMessageBox("哲学家5拿到筷子4,等待筷子5");
		wparam=5;
		lparam=4;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);

		WaitForSingleObject(h_Mutex5,INFINITE);
		//AfxMessageBox("哲学家5拿到筷子5,开始进餐");
		wparam=5;
		lparam=5;
		::PostMessage (main_window,WM_MYMSG,wparam,lparam);
        Sleep(5000);

	

        //AfxMessageBox("哲学家5用餐完毕，放下筷子4和5");
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

	WaitForSingleObject(Comman_Mutex,INFINITE);//进入互斥区

	CPhilosophers_eating_problemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

    CPen blue_pen(PS_SOLID,1,RGB(35,180,250));
    CPen yellow_pen(PS_SOLID,3,RGB(253,179,50));
	pDC->SelectObject (&blue_pen);//设置一个蓝色画笔；
//	pDC->SetBkColor (RGB(255,0,0));

	

	CRect client_rect;
	GetClientRect(&client_rect);//获得客户区大小。

    pt=client_rect.CenterPoint ();//pt用来保持客户区的中点。

    CBrush blue_brush,red_brush;
	blue_brush.CreateSolidBrush (RGB(35,180,250));//创建一个蓝色画刷，并选进CDC。
	pDC->SelectObject (&blue_brush);
	pDC->Ellipse (pt.x -200,pt.y -200,pt.x +200,pt.y +200);//画出一个圆型的蓝色桌子。
    
    red_brush.CreateSolidBrush (RGB(248,95,160));
	pDC->SelectObject (&red_brush);//创建一个红色画刷，画出红色的圆形代表哲学家。
    pDC->SetBkColor (RGB(248,95,160));//设置文字背景为红色。
   


	double pi = 3.1415926535;

    for(int i=0;i<5;i++)//循环画出5个哲学家的圆。
	{
		CString name;
		name.Format ("哲学家%d",i+1);//用来输出哲学家名字。
		double SIN=sin(2*pi*i/5);
		double COS=cos(2*pi*i/5);
     //		CPoint small_pt=(pt.x+250*COS,pt.y-250*SIN);
 
    
	 //   pDC->Ellipse (small_pt.x -50,small_pt.y -50,small_pt.x +50,small_pt.y +50);
	     pDC->Ellipse (pt.x+250*COS-50,pt.y-250*SIN-50,pt.x+250*COS +50,pt.y-250*SIN+50);
         pDC->TextOut (pt.x+250*COS-20 ,pt.y-250*SIN-5 ,name);


	}
     
	pDC->SelectObject (&yellow_pen);//换上黄色画笔。
	

	//上面是公共的，每次都重复。而下面的就根据2个数组来输出。

	for(int j=0;j<5;j++)//下面循环输出5根筷子。
	{
		if(chopsticks[j]==1)
		{
        CString name;
		name.Format ("筷子%d",(j+1)%6);
	    double SIN=sin(2*pi*(2*j+1)/10);
		double COS=cos(2*pi*(2*j+1)/10);

		pDC->MoveTo (pt.x +100*COS,pt.y -100*SIN);
		pDC->LineTo (pt.x +200*COS,pt.y -200*SIN);
		pDC->TextOut (pt.x +100*COS,pt.y -100*SIN,name);
		}

	}

	for(int a=0;a<5;++a)//下面画每个哲学家手里的筷子。
	{
        if(philosophers[a][0]!=0)//左手不为空
		{
			CString name;
			name.Format ("筷子%d",philosophers[a][0]);
            double SIN=sin(2*pi*a/5-0.035);
		    double COS=cos(2*pi*a/5-0.035);
			pDC->MoveTo (pt.x +100*COS,pt.y -100*SIN);
		    pDC->LineTo (pt.x +200*COS,pt.y -200*SIN);
		    pDC->TextOut (pt.x +115*COS,pt.y -115*SIN,name);
		}
		if(philosophers[a][1]!=0)//右手不为空
		{	
			CString name;
			name.Format ("筷子%d",philosophers[a][1]);
            double SIN=sin(2*pi*a/5+0.035);
		    double COS=cos(2*pi*a/5+0.035);
			pDC->MoveTo (pt.x +100*COS,pt.y -100*SIN);
		    pDC->LineTo (pt.x +200*COS,pt.y -200*SIN);
		    pDC->TextOut (pt.x +155*COS,pt.y -155*SIN,name);
		}

	}
	ReleaseMutex(Comman_Mutex); //离开互斥区
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

	main_window=this->m_hWnd ;//保存主窗口句柄；

	h_Mutex1=CreateMutex(NULL,FALSE,NULL);//创建用来访问筷子1的互斥对象
    h_Mutex2=CreateMutex(NULL,FALSE,NULL);//创建用来访问筷子2的互斥对象
    h_Mutex3=CreateMutex(NULL,FALSE,NULL);//创建用来访问筷子3的互斥对象
    h_Mutex4=CreateMutex(NULL,FALSE,NULL);//创建用来访问筷子4的互斥对象
    h_Mutex5=CreateMutex(NULL,FALSE,NULL);//创建用来访问筷子5的互斥对象
    
	Comman_Mutex=CreateMutex(NULL,FALSE,NULL);////创建用来互斥访问数组的互斥对象

	m_thread_handle1=::CreateThread(NULL,0,Thread1,0,0,&Thread1ID);//创建第1个线程,返回线程句柄
	m_thread_handle2=::CreateThread(NULL,0,Thread2,0,0,&Thread2ID);//创建第2个线程,返回线程句柄
	m_thread_handle3=::CreateThread(NULL,0,Thread3,0,0,&Thread3ID);//创建第3个线程,返回线程句柄
	m_thread_handle4=::CreateThread(NULL,0,Thread4,0,0,&Thread4ID);//创建第4个线程,返回线程句柄
	m_thread_handle5=::CreateThread(NULL,0,Thread5,0,0,&Thread5ID);//创建第5个线程,返回线程句柄

}




void CPhilosophers_eating_problemView::OnMYMSG(WPARAM wParam, LPARAM lParam)
{
    WaitForSingleObject(Comman_Mutex,INFINITE); //进入互斥区

	if(lParam!=0 )//拿起筷子。
	{
		if(philosophers[wParam-1][0]==0)//如果左手是空的。
           philosophers[wParam-1][0]=lParam;//放在哲学家的左手中
		else
			philosophers[wParam-1][1]=lParam;//放在哲学家的右手中

		chopsticks[lParam-1]=0;//表示此筷子被拿走。

	}

	else //释放左右手的筷子。
	{

        chopsticks[philosophers[wParam-1][0]-1]=1;
		chopsticks[philosophers[wParam-1][1]-1]=1;

		philosophers[wParam-1][0]=0;
        philosophers[wParam-1][1]=0;
	}
	ReleaseMutex(Comman_Mutex);//离开互斥区

    Invalidate(FALSE);//使客户区重画。




}
