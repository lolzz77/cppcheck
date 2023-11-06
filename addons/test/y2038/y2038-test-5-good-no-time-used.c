#include <stdio.h>
#include <pthread.h>
/*
 * C file that does not use any time functionality -> no errors should
 * be reported.
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    if (argc > 1) {
        printf("Hello");
    }
    return 0;
}
