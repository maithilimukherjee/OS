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
        pid_t ppid = getppid();
        printf("child: sending SIGSTOP to parent (pid: %d)\n", ppid);
        kill(ppid, SIGSTOP);
        printf("child: parent stopped.\n");

        sleep(3); // wait a bit before resuming
        printf("child: sending SIGCONT to parent (pid: %d)\n", ppid);
        kill(ppid, SIGCONT);
        printf("child: parent resumed. exiting.\n");
        exit(0);
    } else {
        // parent process
        printf("parent: waiting to be stopped by child...\n");

        // wait for signals
        while (1) {
            printf("parent: running...\n");
            sleep(1);
        }
    }

    return 0;
}
