#include <stdio.h>
#include <pthread.h>

#define MAX_COUNT 10000
int count;

void *f_count(void *sid)
{
    int i;
    for (i = 0; i < MAX_COUNT; i++)
    {
        count = count + 1;
    }
    printf("Thread %s: holding %d \n", (char *)sid, count);
}

int main(int argc, char *argv[])
{
    printf("Hello world\n");
    pthread_t tid1, tid2;

    count = 0;
    // create two threads each of which will execute f_count

    pthread_create(&tid1, NULL, &f_count, "1");
    pthread_create(&tid2, NULL, &f_count, "2");

    // // wait for the threads to finish
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    getc(stdin);

    return 0;
}