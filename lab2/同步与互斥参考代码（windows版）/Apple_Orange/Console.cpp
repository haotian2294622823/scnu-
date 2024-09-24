//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include "iostream.h"
/*
HANDLE CreateSemaphore(
    LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,	// pointer to security attributes
    LONG lInitialCount,	// initial count
    LONG lMaximumCount,	// maximum count
    LPCTSTR lpName 	// pointer to semaphore-object name
   );
*/

int main(int argc, char* argv[])
{
  //������ͬ���ź���
  HANDLE hSem_Empty_Plate;
  hSem_Empty_Plate=CreateSemaphore(NULL,1,1,"Sem_Empty_Plate");

  //ƻ��ͬ���ź���
  HANDLE hSem_Apple;
  hSem_Apple=CreateSemaphore(NULL,0,1,"Sem_Apple");

  //����ͬ���ź���
  HANDLE hSem_Orange;
  hSem_Orange =CreateSemaphore(NULL,0,1,"Sem_Orange");


  cout << "Semaphore OK. "<<endl;

  cin.get();
  CloseHandle(hSem_Empty_Plate);
  CloseHandle(hSem_Apple);
  CloseHandle(hSem_Orange);
  cout << "Semaphore Over. "<<endl;

  //���ֻ�������
  cin.get();
  return 0;
}
//---------------------------------------------------------------------------

