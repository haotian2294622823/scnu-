//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include "iostream.h"
int main(int argc, char* argv[])
{
  HANDLE hMutex;
  hMutex=OpenMutex(MUTEX_ALL_ACCESS,false,"TestMutex");
  int i,j;
  if(hMutex!=NULL)
  {
  for (i=0;i<1000;i++)
   {
     cout<< "执行P操作，准备进入临界区。。。" <<endl;
     WaitForSingleObject(hMutex,INFINITE);
     cout<< " 我在临界区呆8秒！ " <<endl;
     Sleep(8000);
     cout<< "执行V操作，唤醒其他等待进程。。。" <<endl;
     ReleaseMutex(hMutex);
     Sleep(3000);

   }
   }
  cin.get();
  return 0;
}
//---------------------------------------------------------------------------
