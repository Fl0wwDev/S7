#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void display_signal(int signal){
    printf("LE SIGNAL RECUUU %d\n", signal);
    psignal(signal, "le signal est");
    exit(0);
}

int main(int argc, char const *argv[])
{
    /* code */
    signal(SIGILL, display_signal);
    raise(SIGILL);
    signal(SIGINT, display_signal);
    while(1){
        getchar();
    }

    return 0;
}
