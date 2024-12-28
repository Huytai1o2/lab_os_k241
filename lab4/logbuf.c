#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_LOG_LENGTH 10
#define MAX_BUFFER_SLOT 5

char *logbuf[MAX_BUFFER_SLOT];
int buffer_count = 0;
pthread_mutex_t buffer_lock;
pthread_cond_t buffer_full;

// Write log data to the buffer
int wrlog(char *new_data) {
    pthread_mutex_lock(&buffer_lock);
    
    // Wait if the buffer is full
    while (buffer_count == MAX_BUFFER_SLOT) {
        pthread_cond_wait(&buffer_full, &buffer_lock);
    }
    
    // Add log to the buffer
    logbuf[buffer_count] = (char *)malloc(MAX_LOG_LENGTH * sizeof(char));
    strncpy(logbuf[buffer_count], new_data, MAX_LOG_LENGTH);
    buffer_count++;
    
    pthread_mutex_unlock(&buffer_lock);
    return 0;
}

// Flush the buffer
int flushlog() {
    pthread_mutex_lock(&buffer_lock);
    
    // Print and clear the buffer
    printf("Flushing log buffer:\n");
    for (int i = 0; i < buffer_count; i++) {
        printf("Slot %d: %s\n", i, logbuf[i]);
        free(logbuf[i]); // Free allocated memory
        logbuf[i] = NULL;
    }
    buffer_count = 0;

    // Signal that buffer has space
    pthread_cond_broadcast(&buffer_full);
    pthread_mutex_unlock(&buffer_lock);
    return 0;
}

// Periodic flush task
void *periodic_flush(void *arg) {
    while (1) {
        sleep(2); // Simulate periodic flush
        flushlog();
    }
    return NULL;
}

int main() {
    pthread_t flush_thread;

    // Initialize mutex and condition variable
    pthread_mutex_init(&buffer_lock, NULL);
    pthread_cond_init(&buffer_full, NULL);

    // Start periodic flush thread
    pthread_create(&flush_thread, NULL, periodic_flush, NULL);

    // Simulate writing logs
    char data[MAX_LOG_LENGTH];
    for (int i = 0; i < 30; i++) {
        snprintf(data, MAX_LOG_LENGTH, "%d", i);
        wrlog(data);
        usleep(10000); // Simulate log generation delay
    }

    // Cleanup
    pthread_join(flush_thread, NULL);
    pthread_mutex_destroy(&buffer_lock);
    pthread_cond_destroy(&buffer_full);

    return 0;
}
