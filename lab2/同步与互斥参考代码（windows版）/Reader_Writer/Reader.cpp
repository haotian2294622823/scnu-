//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "iostream.h"
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
  int count=0;  //��¼���ڶ��Ķ�����
  int i=0;
  HANDLE rMutex;
  rMutex=OpenMutex(MUTEX_ALL_ACCESS,false,"rMutex"); //��rWutex������
  HANDLE wMutex;
  wMutex=OpenMutex(MUTEX_ALL_ACCESS,false,"wMutex"); //��wWutex������

  cout<< "�����ö��߽���ѭ����ʽģ�������߽��̡� " <<endl;
  while (i<5)
  {
    WaitForSingleObject(rMutex,INFINITE);
    if (count==0)   //�����û�ж��ߣ���ʼ���������Ժ��д��
    {
      WaitForSingleObject(wMutex,INFINITE);
    }
    count = count + 1;
    ReleaseMutex(rMutex);
    cout<< i ;
    cout<< " �Ŷ������ڶ����ݣ�" <<endl;
    Sleep(1000);

    WaitForSingleObject(rMutex,INFINITE);
    count = count - 1;
    if (count==0)   //���û�ж����ˣ����ѿ���������д��
    {
      ReleaseMutex(wMutex);
    }
    ReleaseMutex(rMutex);
    i++;
    Sleep(2000);
  }
  //����ģ��һ�����ж�����߼���ͬʱ��
  i=0; //i����
   while (i<4)
  {
    WaitForSingleObject(rMutex,INFINITE);
    if (count==0)   //�����û�ж��ߣ���ʼ���������Ժ��д��
    {
      WaitForSingleObject(wMutex,INFINITE);
    }
    count = count + 1;
    ReleaseMutex(rMutex);
    cout<< i ;
    cout<< " �Ŷ������ڶ����ݣ�����countֵΪ";
    cout<< count<<endl;
    Sleep(100);
    i++;
  }
    i=0;
    while (i<4)
   {
    WaitForSingleObject(rMutex,INFINITE);
    count = count - 1;
    cout<< "����countֵΪ";
    cout<< count<<endl;
    if (count==0)   //���û�ж����ˣ����ѿ���������д��
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
 