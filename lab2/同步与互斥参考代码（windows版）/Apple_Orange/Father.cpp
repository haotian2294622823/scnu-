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
     cout<<"��ͼ����ƻ��"<<endl;
     cin.get();
     WaitForSingleObject(hSem_Empty_Plate,INFINITE);

     /*************************************/
     /************�������*****************/
     /*************************************/

     cout<<"�ɹ�����ƻ������׼��ͨ�����"<<endl;
     cin.get();
     ReleaseSemaphore(hSem_Apple,1,NULL);

     cout<<"ͨ����ϣ�׼����ƻ��"<<endl;
     cin.get();
    }

  cin.get();
  return 0;
}
//---------------------------------------------------------------------------

