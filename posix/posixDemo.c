#include <stdio.h>      // For printf() and perror()
#include <unistd.h>     // For sleep() function
#include <stdlib.h>     // For exit() and EXIT_SUCCESS/FAILURE
#include <string.h>     // For string functions like strcpy()
#include <pthread.h>    // For POSIX threads (pthread_create, pthread_join, etc.)

// Function prototype for the thread routine
void *thread_function(void *arg);

// Global variable (shared between main thread and new thread)
char message[] = "Hello World";

int main()
{
    int res;                 // To store return codes from thread functions
    pthread_t a_thread;      // Thread identifier variable
    void *thread_result;     // Used to hold value returned by thread_function()

    // Create a new thread
    // Parameters:
    // &a_thread → where to store thread ID
    // NULL → use default thread attributes
    // thread_function → function to be executed by the new thread
    // (void *)message → pass the string "Hello World" as an argument
    res = pthread_create(&a_thread, NULL, thread_function, (void *)message);

    // Check if thread creation failed
    if (res != 0)
    {
        perror("\nThread creation failed");  // Print the error message
        exit(EXIT_FAILURE);                  // Exit if failed
    }

    // Main thread continues here
    printf("\nWaiting for thread to finish...\n");

    // Wait for the created thread to finish and collect its return value
    res = pthread_join(a_thread, &thread_result);

    // Check if thread join failed
    if (res != 0)
    {
        perror("\nThread join failed\n");
        exit(EXIT_FAILURE);
    }

    // Print the message returned by the thread
    printf("Thread joined, it returned \"%s\"\n", (char *)thread_result);

    // Print the updated global message (changed by the thread)
    printf("Message is now %s\n", message);

    // Exit program successfully
    exit(EXIT_SUCCESS);
}

// Function that runs inside the created thread
void *thread_function(void *arg)
{
    // Print what argument (message) was passed to this thread
    printf("\nThread_function is running. Argument was %s\n", (char *)arg);

    // Sleep for 3 seconds to simulate some work
    sleep(3);

    // Modify the shared global variable 'message'
    strcpy(message, "Bye!");

    // Exit the thread and return a string to main()
    pthread_exit("Thank you for the CPU time");
}
