#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Program to demonstrate communication between
// parent and child using a pipe
int main() {
    int file_pipes[2];             // Array to hold read and write ends of pipe
    pid_t fork_result;             // To store process ID returned by fork()
    const char message[] = "Hello from parent to child!";
    char buffer[100];              // Buffer to store message read by child

    // Step 1: Create the pipe
    if (pipe(file_pipes) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    // Step 2: Create a child process using fork()
    fork_result = fork();

    if (fork_result == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    // Step 3A: Child process block
    if (fork_result == 0) {
        // Close the write end (child will only read)
        close(file_pipes[1]);

        // Read data from pipe
        read(file_pipes[0], buffer, sizeof(buffer));

        printf("Child received message: %s\n", buffer);

        // Close the read end
        close(file_pipes[0]);
        exit(EXIT_SUCCESS);
    }
    // Step 3B: Parent process block
    else {
        // Close the read end (parent will only write)
        close(file_pipes[0]);

        // Write message to the pipe
        write(file_pipes[1], message, strlen(message) + 1);

        printf("Parent sent message: %s\n", message);

        // Close the write end
        close(file_pipes[1]);
        exit(EXIT_SUCCESS);
    }
}
