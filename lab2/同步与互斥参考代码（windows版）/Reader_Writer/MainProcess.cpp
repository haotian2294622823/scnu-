//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "iostream.h"
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
  HANDLE rMutex;  //���ڻ������count���ź���
  HANDLE wMutex;  //���ڶ�д�����дд������ź���
  rMutex=CreateMutex(NULL,false,"rMutex");
  cout << "���ȴ������ڻ������count���ź���. "<<endl;
  Sleep(2000); //2��󴴽�wMutex�ź���
  wMutex=CreateMutex(NULL,false,"wMutex");
  cout << "���Ŵ������ڶ�д�����дд������ź���. "<<endl;
  Sleep(2000); //2��󴴽���д����
  cout << "׼��������д����. "<<endl;
  Sleep(2000);

  STARTUPINFO sReader,sWriter ;
  PROCESS_INFORMATION pReader,pWriter;
  BOOL fCreated;

  cout << "�������߽��̣���"<<endl;   //�������߽���
  ZeroMemory(&sReader,sizeof(STARTUPINFO));
  sReader.cb=sizeof(STARTUPINFO);
  fCreated=CreateProcess(".\\Reader.exe",
           NULL,  NULL, NULL,
           FALSE, CREATE_NEW_CONSOLE,
           NULL,  NULL,
           &sReader,  &pReader );

  cout << "����д�߽��̣���"<<endl;   //����д�߽���
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
 