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
  wMutex=OpenMutex(MUTEX_ALL_ACCESS,false,"wMutex"); //��wWutex������
  cout<< "������д�߽���ѭ����ʽģ����д�߽��̡� " <<endl;
  while (true)
  {

    WaitForSingleObject(wMutex,INFINITE);
    cout<< i ;
    cout<< " ��д������д���ݣ���ʱ1�롣 " <<endl;
    Sleep(1000);
    ReleaseMutex(wMutex);
    i++;
    Sleep(1000);
  }
  return 0;
}
//---------------------------------------------------------------------------
 