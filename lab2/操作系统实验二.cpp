#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#define SIGNAL 1  
sem_t printer_sem;//打印机信号量
pthread_mutex_t mutex;//互斥锁

void* user(void* arg){
	int user_id=*((int*)arg);//记录用户id
	//请求打印机
	printf("用户：%d 正在等待\n ",user_id);
	sem_wait(&printer_sem); //等待打印
	pthread_mutex_lock(&mutex);//临界区 互斥开始
	printf("用户：%d 正在使用\n ",user_id);
	sleep(3);
	printf("用户：%d 完成结束\n ",user_id);
	pthread_mutex_unlock(&mutex);//退出临界区
	sem_post(&printer_sem);
	return NULL;
	
	
}
int main(){
	//初始化信号量及互斥锁
	sem_init(&printer_sem,0,SIGNAL);
	pthread_mutex_init(&mutex,NULL);
	pthread_t users[5];//五个用户
	int user_ids[5];
	
	for(int i=0;i<5;i++){
		user_ids[i]=i+1; 
		pthread_create(&users[i],NULL,user,&user_ids[i]);
	} 
	
	// 等待所有线程结束
    for (int i = 0; i < 5; i++) {
        pthread_join(users[i], NULL);
    }
	//释放
	sem_destroy(&printer_sem);
	pthread_mutex_destroy(&mutex);
	return 0; 
	}

