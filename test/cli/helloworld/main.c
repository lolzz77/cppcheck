#include <stdio.h>
#include <pthread.h>
#include <stdio.h>

int main(void) {
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    (void)printf("Hello world!\n");
    x = 3 / 0; // ERROR
    return 0;
}

#ifdef SOME_CONFIG
void foo();
#endif
