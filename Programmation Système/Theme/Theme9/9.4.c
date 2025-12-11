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
    return 0;
}
