#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid > 0) {
        // parent process
        printf("parent (pid: %d) waiting for child to avoid zombie...\n", getpid());
        int status;
        wait(&status); // wait for child to exit
        printf("child collected, parent exiting. no zombie!\n");
    } else {
        // child process
        printf("child (pid: %d) exiting immediately...\n", getpid());
        exit(0); // child exits
    }

    return 0;
}
