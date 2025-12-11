#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void copier(int fdsrc, int fddst) {
    char buffer[4096];
    ssize_t n;
    
    while ((n = read(fdsrc, buffer, sizeof(buffer))) > 0) {
        write(fddst, buffer, n);
    }
}

int main(void) {
    int tube[2];
    pid_t pid;
    
    // Create the pipe
    if (pipe(tube) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    
    if (pid == 0) {
        // Child process: read from pipe and write to stdout
        close(tube[1]);  // Close write end
        copier(tube[0], STDOUT_FILENO);
        close(tube[0]);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process: read from stdin and write to pipe
        close(tube[0]);  // Close read end
        copier(STDIN_FILENO, tube[1]);
        close(tube[1]);
        wait(NULL);  // Wait for child to terminate
        exit(EXIT_SUCCESS);
    }
}