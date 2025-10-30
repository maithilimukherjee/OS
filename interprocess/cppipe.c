#include <unistd.h>     // For fork(), pipe(), read(), write(), sleep()
#include <stdlib.h>     // For exit(), EXIT_SUCCESS / EXIT_FAILURE
#include <stdio.h>      // For printf(), fprintf()
#include <string.h>     // For memset(), strlen()

// Program: Communication between child and parent using a pipe
int main()
{
    int data_processed;         // To store number of bytes read/written
    int file_pipes[2];          // Array to hold two file descriptors: [0] = read end, [1] = write end
    const char some_data[] = "Hello World";  // The data that parent will send
    char buffer[BUFSIZ + 1];    // Buffer for reading data (extra +1 for null terminator)
    pid_t fork_result;          // Used to store the result of fork() (child or parent ID)

    // Initialize the buffer with null ('\0') to make it empty
    memset(buffer, '\0', sizeof(buffer));

    // Create a pipe: file_pipes[0] for reading, file_pipes[1] for writing
    // pipe() returns 0 if successful
    if (pipe(file_pipes) == 0)
    {
        // Create a new process (child)
        fork_result = fork();

        // If fork() returns -1 → creation failed
        if (fork_result == -1)
        {
            fprintf(stderr, "Fork failure"); // Print error to stderr
            exit(EXIT_FAILURE);
        }
        // If fork_result == 0 → this code runs in the CHILD process
        else if (fork_result == 0)
        {
            sleep(2); // Delay child so that parent writes first

            // Child reads data from the pipe's read end (file_pipes[0])
            data_processed = read(file_pipes[0], buffer, BUFSIZ);

            // Print how many bytes were read and what data it got
            printf("Read %d bytes: %s\n", data_processed, buffer);

            // Exit child process successfully
            exit(EXIT_SUCCESS);
        }
        // If fork_result > 0 → this code runs in the PARENT process
        else
        {
            // Parent writes data to the pipe's write end (file_pipes[1])
            data_processed = write(file_pipes[1], some_data, strlen(some_data));

            // Print how many bytes were written
            printf("Wrote %d bytes\n", data_processed);
        }
    }

    // Exit main program successfully
    exit(EXIT_SUCCESS);
}
