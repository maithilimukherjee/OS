#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid > 0) {
        // parent process
        printf("parent process (pid: %d) exiting...\n", getpid());
        exit(0); // parent exits immediately
    } else {
        // child process
        printf("child process (pid: %d) sleeping...\n", getpid());
        sleep(5); // sleep to give time for parent to exit
        printf("child process (pid: %d) now orphaned. My parent pid is: %d\n", getpid(), getppid());
        sleep(5); // just to observe
    }

    return 0;
}
