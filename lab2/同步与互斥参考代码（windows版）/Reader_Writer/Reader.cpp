//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "iostream.h"
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
  int count=0;  //记录正在读的读者数
  int i=0;
  HANDLE rMutex;
  rMutex=OpenMutex(MUTEX_ALL_ACCESS,false,"rMutex"); //打开rWutex互斥体
  HANDLE wMutex;
  wMutex=OpenMutex(MUTEX_ALL_ACCESS,false,"wMutex"); //打开wWutex互斥体

  cout<< "以下用读者进程循环方式模拟多个读者进程。 " <<endl;
  while (i<5)
  {
    WaitForSingleObject(rMutex,INFINITE);
    if (count==0)   //如果还没有读者，开始，并阻塞以后的写者
    {
      WaitForSingleObject(wMutex,INFINITE);
    }
    count = count + 1;
    ReleaseMutex(rMutex);
    cout<< i ;
    cout<< " 号读者正在读数据！" <<endl;
    Sleep(1000);

    WaitForSingleObject(rMutex,INFINITE);
    count = count - 1;
    if (count==0)   //如果没有读者了，唤醒可能阻塞的写者
    {
      ReleaseMutex(wMutex);
    }
    ReleaseMutex(rMutex);
    i++;
    Sleep(2000);
  }
  //现在模拟一口气有多个读者几乎同时到
  i=0; //i清零
   while (i<4)
  {
    WaitForSingleObject(rMutex,INFINITE);
    if (count==0)   //如果还没有读者，开始，并阻塞以后的写者
    {
      WaitForSingleObject(wMutex,INFINITE);
    }
    count = count + 1;
    ReleaseMutex(rMutex);
    cout<< i ;
    cout<< " 号读者正在读数据！现在count值为";
    cout<< count<<endl;
    Sleep(100);
    i++;
  }
    i=0;
    while (i<4)
   {
    WaitForSingleObject(rMutex,INFINITE);
    count = count - 1;
    cout<< "现在count值为";
    cout<< count<<endl;
    if (count==0)   //如果没有读者了，唤醒可能阻塞的写者
    {
      ReleaseMutex(wMutex);
    }
    ReleaseMutex(rMutex);
    Sleep(3000);
    i++;
   }

  cin.get();
  return 0;
}
//---------------------------------------------------------------------------
 