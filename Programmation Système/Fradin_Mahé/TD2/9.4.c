#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

pid_t;
pid_t_fils; 

void traite(){
    printf("Le pid:", getpid());
}

void sigurs1(int signal){
    printf("signal sigurs1");
}

void sigarlm(int){
    printf("signal sigarlm");
}

int main(int argc, char const *argv[])
{
    /* code */

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid ==0){
        signal(SIGUSR1, sigurs1);
        signal(SIGALRM, sigarlm);
        alarm(1);
        while(1){
            getchar();
        }
    }
    else {
        pid_t_fils = pid;
        signal(SIGALRM, sigarlm);
        alarm(60);
    }
    return 0;
}
