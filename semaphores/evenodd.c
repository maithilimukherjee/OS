#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Declare semaphores for synchronization
sem_t sem_even;  // Controls even thread
sem_t sem_odd;   // Controls odd thread

// Function prototypes
void* print_even(void* arg);
void* print_odd(void* arg);

int main() {
    pthread_t even_thread, odd_thread;

    // Initialize semaphores
    // sem_even starts unlocked (1) — even thread runs first (to print 0)
    // sem_odd starts locked (0) — odd thread waits
    sem_init(&sem_even, 0, 1);
    sem_init(&sem_odd, 0, 0);

    // Create the threads
    pthread_create(&even_thread, NULL, print_even, NULL);
    pthread_create(&odd_thread, NULL, print_odd, NULL);

    // Wait for both threads to finish
    pthread_join(even_thread, NULL);
    pthread_join(odd_thread, NULL);

    // Destroy semaphores (cleanup)
    sem_destroy(&sem_even);
    sem_destroy(&sem_odd);

    printf("\nAll numbers printed in sequence successfully.\n");
    return 0;
}

// Function for printing even numbers (0, 2, 4, ..., 10)
void* print_even(void* arg) {
    for (int i = 0; i <= 10; i += 2) {
        sem_wait(&sem_even);   // Wait for its turn
        printf("%d ", i);      // Print even number
        fflush(stdout);        // Ensure immediate print
        sem_post(&sem_odd);    // Signal odd thread to run next
    }
    return NULL;
}

// Function for printing odd numbers (1, 3, 5, ..., 9)
void* print_odd(void* arg) {
    for (int i = 1; i < 10; i += 2) {
        sem_wait(&sem_odd);    // Wait for its turn
        printf("%d ", i);      // Print odd number
        fflush(stdout);
        sem_post(&sem_even);   // Signal even thread to run next
    }
    return NULL;
}
