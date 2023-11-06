#include <stdio.h>
#include <pthread.h>
#include "B.hpp"

int main()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    B b();
    return 0;
}
