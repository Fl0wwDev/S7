#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mqueue.h>
#include <sys/fcntl.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char const *argv[])
{   
    /* code */
    mq = mq_open("/q", O_CREAT | O_RDWR, 0644, &attr);
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid > 0) {
            exit(1);
        }
    return 0;
}
