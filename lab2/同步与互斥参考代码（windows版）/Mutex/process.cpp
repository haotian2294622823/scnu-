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
     cout<< "ִ��P������׼�������ٽ���������" <<endl;
     WaitForSingleObject(hMutex,INFINITE);
     cout<< " �����ٽ�����8�룡 " <<endl;
     Sleep(8000);
     cout<< "ִ��V���������������ȴ����̡�����" <<endl;
     ReleaseMutex(hMutex);
     Sleep(3000);

   }
   }
  cin.get();
  return 0;
}
//---------------------------------------------------------------------------
