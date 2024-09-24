#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#define SIGNAL 1  
sem_t printer_sem;//��ӡ���ź���
pthread_mutex_t mutex;//������

void* user(void* arg){
	int user_id=*((int*)arg);//��¼�û�id
	//�����ӡ��
	printf("�û���%d ���ڵȴ�\n ",user_id);
	sem_wait(&printer_sem); //�ȴ���ӡ
	pthread_mutex_lock(&mutex);//�ٽ��� ���⿪ʼ
	printf("�û���%d ����ʹ��\n ",user_id);
	sleep(3);
	printf("�û���%d ��ɽ���\n ",user_id);
	pthread_mutex_unlock(&mutex);//�˳��ٽ���
	sem_post(&printer_sem);
	return NULL;
	
	
}
int main(){
	//��ʼ���ź�����������
	sem_init(&printer_sem,0,SIGNAL);
	pthread_mutex_init(&mutex,NULL);
	pthread_t users[5];//����û�
	int user_ids[5];
	
	for(int i=0;i<5;i++){
		user_ids[i]=i+1; 
		pthread_create(&users[i],NULL,user,&user_ids[i]);
	} 
	
	// �ȴ������߳̽���
    for (int i = 0; i < 5; i++) {
        pthread_join(users[i], NULL);
    }
	//�ͷ�
	sem_destroy(&printer_sem);
	pthread_mutex_destroy(&mutex);
	return 0; 
	}

