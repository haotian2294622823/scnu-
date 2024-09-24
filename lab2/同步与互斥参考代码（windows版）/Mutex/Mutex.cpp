//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "iostream.h"
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
  HANDLE hMutex;
  hMutex=CreateMutex(NULL,false,"TestMutex");
  cout << "Create Mutex OK. "<<endl;

  STARTUPINFO si1,si2 ;
  PROCESS_INFORMATION pi1,pi2;
  BOOL fCreated;

  cin.get();
  cout << "CreateProcess1"<<endl;
  ZeroMemory(&si1,sizeof(STARTUPINFO));
  si1.cb=sizeof(STARTUPINFO);
  fCreated=CreateProcess(".\\process.exe",
           NULL,  NULL, NULL,
           FALSE, CREATE_NEW_CONSOLE,
           NULL,  NULL,
           &si1,   &pi1 );

  //cin.get();
  cout << "CreateProcess2"<<endl;
  ZeroMemory(&si2,sizeof(STARTUPINFO));
  si2.cb=sizeof(STARTUPINFO);
  fCreated=CreateProcess(".\\process.exe",
           NULL,  NULL, NULL,
           FALSE, CREATE_NEW_CONSOLE,
           NULL,  NULL,
           &si2,   &pi2 );

  cin.get();

  CloseHandle(hMutex);
  cout << "Test Over. "<<endl;

  cin.get();
  return 0;
}
//---------------------------------------------------------------------------
 