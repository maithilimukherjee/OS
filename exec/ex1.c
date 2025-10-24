#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"/bin/ls", "-l", NULL}; // program and arguments

    printf("before execv: this will print\n");

    // replace current process with /bin/ls
    if (execv("/bin/ls", args) == -1) {
        perror("execv failed");
        exit(1);
    }

    // this will NOT print if execv succeeds
    printf("after execv: you won't see me if execv worked!\n");

    return 0;
}
