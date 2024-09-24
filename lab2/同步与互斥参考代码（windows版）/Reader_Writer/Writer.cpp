//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "iostream.h"
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
  int i=0;
  HANDLE wMutex;
  wMutex=OpenMutex(MUTEX_ALL_ACCESS,false,"wMutex"); //打开wWutex互斥体
  cout<< "以下用写者进程循环方式模拟多个写者进程。 " <<endl;
  while (true)
  {

    WaitForSingleObject(wMutex,INFINITE);
    cout<< i ;
    cout<< " 号写者正在写数据！需时1秒。 " <<endl;
    Sleep(1000);
    ReleaseMutex(wMutex);
    i++;
    Sleep(1000);
  }
  return 0;
}
//---------------------------------------------------------------------------
 