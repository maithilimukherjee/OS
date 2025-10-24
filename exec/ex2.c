#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("before execl: this will print\n");

    // execl(path, arg0, arg1, ..., NULL)
    if (execl("/bin/ls", "ls", "-l", NULL) == -1) {
        perror("execl failed");
        exit(1);
    }

    // this line won't execute if execl succeeds
    printf("after execl: you won't see this if execl worked\n");

    return 0;
}
