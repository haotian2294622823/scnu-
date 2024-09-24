//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include "iostream.h"
int main(int argc, char* argv[])
{
  HANDLE hSem_Empty_Plate;
  hSem_Empty_Plate=OpenSemaphore(SEMAPHORE_ALL_ACCESS,FALSE,"Sem_Empty_Plate");
  HANDLE hSem_Orange;
  hSem_Orange     =OpenSemaphore(SEMAPHORE_ALL_ACCESS,FALSE,"Sem_Orange");

  int i;
  for (i=0;i<20;i++)
   {
     cout<<"试图放入桔子"<<endl;
     cin.get();
     WaitForSingleObject(hSem_Empty_Plate,INFINITE);

     /*************************************/
     /************具体操作*****************/
     /*************************************/

     cout<<"成功放入桔子，并准备通告女儿"<<endl;
     cin.get();
     ReleaseSemaphore(hSem_Orange ,1,NULL);

     cout<<"通告完毕，准备剥桔子"<<endl;
     cin.get();
    }

  cin.get();
  return 0;
}
//---------------------------------------------------------------------------

