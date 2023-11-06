#include <stdio.h>
#include <pthread.h>


void validCode(int argInt)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    // if G_UNLIKELY is not defined this results in a syntax error
    if G_UNLIKELY(argInt == 1) {} else if (G_UNLIKELY(argInt == 2)) {}
}

