#include <stdio.h>      // For input/output functions like printf() and fgets()
#include <stdlib.h>     // For general functions like exit()
#include <unistd.h>     // For sleep() and POSIX operating system API
#include <string.h>     // For string functions like strncmp() and strlen()
#include <pthread.h>    // For using threads (pthread_create, pthread_join, etc.)
#include <semaphore.h>  // For using semaphores (sem_init, sem_wait, sem_post, etc.)

// Function prototype for the thread's main function
void *threadfunction(void *arg);

// Declare a binary semaphore (used for synchronization)
sem_t bin_sem;

// Define the maximum size of input text
#define WORK_SIZE 1024

// Shared buffer where the main thread stores user input
char work_area[WORK_SIZE];

int main()
{
    int res;                // Variable to store return codes of functions
    pthread_t a_thread;     // Thread identifier
    void *thread_result;    // Used to store the return value of the thread

    // Initialize semaphore 'bin_sem'
    // 0 → semaphore is shared between threads of one process (not between processes)
    // initial value = 0 → thread will wait until main() posts a signal
    res = sem_init(&bin_sem, 0, 0);
    if (res != 0)
    {
        perror("Semaphore initialization failed"); // Print error if failed
        exit(EXIT_FAILURE);                        // Exit the program
    }

    // Create a new thread that runs 'threadfunction'
    res = pthread_create(&a_thread, NULL, threadfunction, NULL);
    if (res != 0)
    {
        perror("Thread creation failed"); // Print error if thread can't be created
        exit(EXIT_FAILURE);
    }

    // Ask the user for input
    printf("Input some text. Enter 'end' to finish\n");

    // Keep reading user input until the first 3 letters are "end"
    while (strncmp("end", work_area, 3) != 0)
    {
        // Read a line of input from the user and store it in work_area
        fgets(work_area, WORK_SIZE, stdin);

        // Signal (unlock) the semaphore so that the thread can process the new input
        sem_post(&bin_sem);
    }

    // When user types "end", stop reading input and wait for the thread to finish
    printf("\nWaiting for thread to finish...\n");

    // Wait for the thread to complete its work
    res = pthread_join(a_thread, &thread_result);
    if (res != 0)
    {
        perror("Thread join failed"); // Print error if joining fails
        exit(EXIT_FAILURE);
    }

    // After thread has finished, clean up and exit
    printf("Thread joined. Exiting now.\n");

    // Destroy the semaphore before exiting
    sem_destroy(&bin_sem);

    // Exit the program successfully
    exit(EXIT_SUCCESS);
}

// The function that the thread will run
void *threadfunction(void *arg)
{
    // Wait for the main thread to post the semaphore (i.e., wait for input)
    sem_wait(&bin_sem);

    // Keep looping until the input starts with "end"
    while (strncmp("end", work_area, 3) != 0)
    {
        // Print how many characters the user entered (excluding newline)
        printf("You input %ld characters\n", strlen(work_area) - 1);

        // Wait again for the next input from main thread
        sem_wait(&bin_sem);
    }

    // Exit the thread when "end" is typed
    pthread_exit(NULL);
}
