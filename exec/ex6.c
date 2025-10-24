#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"env", NULL};
    char *env[] = {"MYVAR=123", NULL};

    printf("before execve\n");
    if (execve("/usr/bin/env", args, env) == -1) {
        perror("execve failed");
        exit(1);
    }
    return 0;
}
