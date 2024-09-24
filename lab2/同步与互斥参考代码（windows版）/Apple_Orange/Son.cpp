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
     cout<<"试图取出苹果"<<endl;
     cin.get();
     WaitForSingleObject(hSem_Apple,INFINITE);

     /*************************************/
     /************具体操作*****************/
     /*************************************/

     cout<<"成功取出苹果，并准备通告老爹老妈"<<endl;
     cin.get();
     ReleaseSemaphore(hSem_Empty_Plate,1,NULL);

     cout<<"通告完毕，正在吃苹果"<<endl;
     cin.get();
    }

  cin.get();
  return 0;
}
//---------------------------------------------------------------------------

