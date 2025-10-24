#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// custom handler for SIGINT (Ctrl + C)
void custom_handler(int sig) {
    printf("\ncustom handler: ctrl + c pressed! process won't exit yet.\n");
    printf("press again in 5 seconds to quit normally.\n");
}

int main() {
    // step 1: set custom handler
    signal(SIGINT, custom_handler);

    printf("try pressing ctrl + c now (custom handler active)\n");
    sleep(5);

    // step 2: restore default handler
    printf("\nrestoring default ctrl + c behavior...\n");
    signal(SIGINT, SIG_DFL);

    printf("press ctrl + c again now (will terminate)\n");

    // infinite loop so user can test again
    while (1) {
        printf("running...\n");
        sleep(2);
    }

    return 0;
}
