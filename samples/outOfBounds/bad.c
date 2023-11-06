#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
int main()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    char str[5];
    strcpy(str, "0123456789abcdef");
    return 0;
}
