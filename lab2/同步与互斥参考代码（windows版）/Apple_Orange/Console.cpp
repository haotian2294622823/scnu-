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
  //空盘子同步信号量
  HANDLE hSem_Empty_Plate;
  hSem_Empty_Plate=CreateSemaphore(NULL,1,1,"Sem_Empty_Plate");

  //苹果同步信号量
  HANDLE hSem_Apple;
  hSem_Apple=CreateSemaphore(NULL,0,1,"Sem_Apple");

  //桔子同步信号量
  HANDLE hSem_Orange;
  hSem_Orange =CreateSemaphore(NULL,0,1,"Sem_Orange");


  cout << "Semaphore OK. "<<endl;

  cin.get();
  CloseHandle(hSem_Empty_Plate);
  CloseHandle(hSem_Apple);
  CloseHandle(hSem_Orange);
  cout << "Semaphore Over. "<<endl;

  //保持环境存在
  cin.get();
  return 0;
}
//---------------------------------------------------------------------------

