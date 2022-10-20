#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 10

typedef struct ThreadData {
    int threadId;
    char name[20];
} ThreadData;
typedef char caracter;

void * holaMundo(void *arg) {
    ThreadData *myData = (ThreadData *)arg;
    printf("Hola desde el hilo y mi id es %d \n", myData->threadId);
    pthread_exit(NULL);
}

int main() {
    ThreadData ThreadData[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++) {
    pthread_t threadId;
    ThreadData[i].threadId = i;
    pthread_create(&threadId, NULL, holaMundo, (void *) &ThreadData[i]);
    }
    pthread_exit(NULL);
    printf("NUNCA LLEGA");
}