#include <stdio.h>
#include <pthread.h>
int a[2];

int main()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    return a[0];
}
