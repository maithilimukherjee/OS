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
        printf("parent (pid: %d) sleeping to let child become zombie...\n", getpid());
        sleep(10); // parent sleeps, does NOT call wait()
        printf("parent exiting now...\n");
    } else {
        // child process
        printf("child (pid: %d) exiting immediately...\n", getpid());
        exit(0); // child exits
    }

    return 0;
}
