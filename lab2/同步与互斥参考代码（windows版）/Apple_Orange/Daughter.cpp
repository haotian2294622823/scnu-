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
     cout<<"��ͼȡ������"<<endl;
     cin.get();
     WaitForSingleObject(hSem_Orange,INFINITE);

     /*************************************/
     /************�������*****************/
     /*************************************/

     cout<<"�ɹ�ȡ�����ӣ���׼��ͨ�������ϵ�"<<endl;
     cin.get();
     ReleaseSemaphore(hSem_Empty_Plate,1,NULL);

     cout<<"ͨ����ϣ����ڳԽ���"<<endl;
     cin.get();
    }

  cin.get();
  return 0;
}
//---------------------------------------------------------------------------

