#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#define Max 5
#define Buffer 5 
sem_t e;
sem_t f;
int in = 0;
int out = 0;
int buffer[Buffer];
pthread_mutex_t m;
void *prod(void *pno)
{ 
 int item;
 for(int i = 0; i < Max; i++) {
 item = rand();
 sem_wait(&e);
 pthread_mutex_lock(&m);
 buffer[in] = item;
 printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[in],in);
 in = (in+1)%Buffer;
 pthread_mutex_unlock(&m);
 sem_post(&f);
 }
}
void *cons(void *cno)
{ 
 for(int i = 0; i < Max; i++) {
 sem_wait(&f);
 pthread_mutex_lock(&m);
 int item = buffer[out];
 printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, 
out);
 out = (out+1)%Buffer;
 pthread_mutex_unlock(&m);
 sem_post(&e);
 }
}
int main()
{ 
 pthread_t pro[5],con[5];
 pthread_mutex_init(&m, NULL);
 sem_init(&e,0,Buffer);
 sem_init(&f,0,0);
 int a[5] = {1,2,3,4,5};
 for(int i = 0; i < 5; i++) {
 pthread_create(&pro[i], NULL, (void *)prod, (void *)&a[i]);
 }
 for(int i = 0; i < 5; i++) {
 pthread_create(&con[i], NULL, (void *)cons, (void *)&a[i]);
 }
 for(int i = 0; i < 5; i++) {
 pthread_join(pro[i], NULL);
 }
 for(int i = 0; i < 5; i++) {
 pthread_join(con[i], NULL);
 }
 pthread_mutex_destroy(&m);
 sem_destroy(&e);
 sem_destroy(&f);
 return 0;
 
}
