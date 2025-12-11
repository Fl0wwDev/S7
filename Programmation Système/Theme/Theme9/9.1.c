#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


static int counter = 0;

void signal_handler(int signal){
    counter++;
    printf("signal numéro %d\n", counter);
    
    if (counter >= 5){
        printf("STOPPPPPPP");
        exit(0);
    }

}


int main(int argc, char const *argv[])
{
    signal(SIGINT, signal_handler);

    while (1){
        getchar();
    }
    return 0;
}
