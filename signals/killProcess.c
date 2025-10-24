#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    printf("enter the process id to kill: ");
    scanf("%d", &pid);

    if(kill(pid,SIGKILL) == 0)
    {
        printf("Process with id %d killed successfully.\n", pid);
    }
    else
    {
        perror("Error killing process");
    }
}
