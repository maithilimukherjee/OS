#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // child process
        printf("child: sending SIGSTOP to parent (pid: %d)\n", getppid());
        kill(getppid(), SIGSTOP);
        printf("child: parent stopped. exiting.\n");
        exit(0);
    } else {
        // parent process
        printf("parent: waiting to be stopped by child...\n");

        // give child time to send signal
        sleep(2);

        printf("parent: if you see this, SIGSTOP didn't work yet.\n");
        pause(); // wait for signals
    }

    return 0;
}
