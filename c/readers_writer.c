#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
sem_t w;
pthread_mutex_t m;
int cn = 1;
int num = 0;
void *writer(void *wn)
{ 
 sem_wait(&w);
 cn = cn*2;
 printf("Writer %d modified cn to %d\n",(*((int *)wn)),cn);
 sem_post(&w);
}
void *reader(void *rn)
{ 
 pthread_mutex_lock(&m);
 num++;
 if(num == 1) {
 sem_wait(&w); 
 }
 pthread_mutex_unlock(&m);
 printf("Reader %d: read cn as %d\n",*((int *)rn),cn);
 pthread_mutex_lock(&m);
 num--;
 if(num == 0) {
 sem_post(&w); 
 }
 pthread_mutex_unlock(&m);
}
int main()
{ 
 pthread_t read[10],write[5];
 pthread_mutex_init(&m, NULL);
 sem_init(&w,0,1);
 int a[10] = {1,2,3,4,5,6,7,8,9,10};
 for(int i = 0; i < 10; i++) {
 pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
 }
 for(int i = 0; i < 5; i++) {
 pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
 }
 for(int i = 0; i < 10; i++) {
 pthread_join(read[i], NULL);
 }
 for(int i = 0; i < 5; i++) {
 pthread_join(write[i], NULL);
 }
 pthread_mutex_destroy(&m);
 sem_destroy(&w);
 
return 0;
}
