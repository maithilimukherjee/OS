#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *args[] = {"ls", "-l", NULL};
    printf("before execvp\n");
    if (execvp("ls", args) == -1) {
        perror("execvp failed");
        exit(1);
    }
    printf("after execvp\n"); // won't run if execvp works
    return 0;
}
