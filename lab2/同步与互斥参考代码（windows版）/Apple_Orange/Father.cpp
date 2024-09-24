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
  HANDLE hSem_Apple;
  hSem_Apple=OpenSemaphore(SEMAPHORE_ALL_ACCESS,FALSE,"Sem_Apple");

  int i;
  for (i=0;i<20;i++)
   {
     cout<<"试图放入苹果"<<endl;
     cin.get();
     WaitForSingleObject(hSem_Empty_Plate,INFINITE);

     /*************************************/
     /************具体操作*****************/
     /*************************************/

     cout<<"成功放入苹果，并准备通告儿子"<<endl;
     cin.get();
     ReleaseSemaphore(hSem_Apple,1,NULL);

     cout<<"通告完毕，准备削苹果"<<endl;
     cin.get();
    }

  cin.get();
  return 0;
}
//---------------------------------------------------------------------------

