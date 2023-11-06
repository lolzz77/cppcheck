#include <stdio.h>
#include <pthread.h>
int main()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    int a[3];
    int i;
    for (i = 0; i < 3; i++)
        a[i] = 0;
    return a[0];
}
