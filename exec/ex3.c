#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("before execlp\n");
    if (execlp("ls", "ls", "-l", NULL) == -1) {
        perror("execlp failed");
        exit(1);
    }
    printf("after execlp\n"); // won't run if execlp works
    return 0;
}
