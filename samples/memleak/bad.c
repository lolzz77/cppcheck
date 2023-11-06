#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int main()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    int result;
    char *a = malloc(10);
    a[0] = 0;
    result = a[0];
    return result;
}
