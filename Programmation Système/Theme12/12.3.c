#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

void * foo(void * arg);

void spawnThreads( unsigned int n) {
   int threads = n, ret = -1;
   pthread_t * thread = malloc(sizeof(pthread_t)*threads);
   pid_t tid;
   int i;
   for(i = 0; i < threads; i++) {
       ret = pthread_create(&thread[i], NULL, foo, NULL);

       if( ret != 0) {
           printf("pthread error!\n");
       }

       tid = syscall(SYS_gettid);
       printf("%d %d\n", i, tid);
       printf("I just created thread %d\n", i);

       pthread_join(thread[i],NULL);
   }
   free(thread);
}

void * foo(void * arg) {
    return NULL;
}

int main() {
    spawnThreads(10);
    return 0;
}
