//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "iostream.h"
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
  HANDLE rMutex;  //用于互斥访问count的信号量
  HANDLE wMutex;  //用于读写互斥和写写互斥的信号量
  rMutex=CreateMutex(NULL,false,"rMutex");
  cout << "首先创建用于互斥访问count的信号量. "<<endl;
  Sleep(2000); //2秒后创建wMutex信号量
  wMutex=CreateMutex(NULL,false,"wMutex");
  cout << "接着创建用于读写互斥和写写互斥的信号量. "<<endl;
  Sleep(2000); //2秒后创建读写进程
  cout << "准备创建读写进程. "<<endl;
  Sleep(2000);

  STARTUPINFO sReader,sWriter ;
  PROCESS_INFORMATION pReader,pWriter;
  BOOL fCreated;

  cout << "创建读者进程！！"<<endl;   //创建读者进程
  ZeroMemory(&sReader,sizeof(STARTUPINFO));
  sReader.cb=sizeof(STARTUPINFO);
  fCreated=CreateProcess(".\\Reader.exe",
           NULL,  NULL, NULL,
           FALSE, CREATE_NEW_CONSOLE,
           NULL,  NULL,
           &sReader,  &pReader );

  cout << "创建写者进程！！"<<endl;   //创建写者进程
  ZeroMemory(&sWriter,sizeof(STARTUPINFO));
  sWriter.cb=sizeof(STARTUPINFO);
  fCreated=CreateProcess(".\\Writer.exe",
           NULL,  NULL, NULL,
           FALSE, CREATE_NEW_CONSOLE,
           NULL,  NULL,
           &sWriter,  &pWriter );

  cin.get();
  return 0;
}
//---------------------------------------------------------------------------
 