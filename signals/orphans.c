#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if(pid<0)
    {
        printf("Fork failed.\n");
        exit(1);
    }

    if(pid == 0)
    { 
        printf("child process: my pid is %d and my parent pid is %d\n", getpid(), getppid());
        sleep(5); // Sleep to allow parent to terminate first
        printf("after 5 seconds: ");
        printf("child process: my pid is %d and my parent pid is %d\n", getpid(), getppid());
        printf("child sill alive after parent got killed by sigkill");
    }

    else {
        // parent process
        printf("parent process pid: %d, child pid: %d\n", getpid(), pid);
        sleep(2); // give child a head start
        printf("parent sending SIGKILL to itself...\n");
        kill(getpid(), SIGKILL); // parent kills itself brutally

        // this line never executes
        printf("this line will never be printed.\n");
    }

    return 0;
}