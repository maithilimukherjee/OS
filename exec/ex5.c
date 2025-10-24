#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *env[] = {"MYVAR=42", "PATH=/usr/bin", NULL};

    printf("before execle\n");
    if (execle("/usr/bin/env", "env", NULL, env) == -1) {
        perror("execle failed");
        exit(1);
    }
    return 0;
}
