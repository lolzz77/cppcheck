#include <stdio.h>
#include <pthread.h>
#include <stddef.h>
#include <stdint.h>

uint32_t ui32Good (int abc)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    uint32_t ui32good;
    int32_t i32good;
    uint32_t badui32;
    int32_t badi32;

    uint32_t a;  // Short
    return 5;
}

uint16_t ui16Good (int a)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    return 5;
}

uint16_t ui16bad_underscore (int a)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    return 5;
}

uint32_t u32Bad (int a)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    uint32_t ui32good;
    int32_t i32good;
    uint32_t badui32;
    int32_t badi32;
    int * intpointer=NULL;
    int ** intppointer=NULL;
    int *** intpppointer=NULL;
    return 5;
}

uint16_t Badui16 (int a)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    return 5;
}

void * Pointer()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    return NULL;
}

void ** PPointer()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    return NULL;
}
