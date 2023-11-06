#include <stdio.h>
#include <pthread.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
#ifdef 0
    // cppcheck-suppress zerodiv
    int i = 1/0;
    printf("i = %d\n", i);
#endif
    return 0;
}
