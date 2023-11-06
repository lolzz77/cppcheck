#include <stdio.h>
#include <pthread.h>
#include "limits.h"
#include "stdio.h"

#define PRINT_DEF(d, f) \
    fprintf(stdout, ";"#d"=%"#f, d)

int main(void)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    PRINT_DEF(CHAR_BIT, d);
    PRINT_DEF(SCHAR_MIN, d);
    PRINT_DEF(SCHAR_MAX, d);
    PRINT_DEF(UCHAR_MAX, d);
    PRINT_DEF(CHAR_MIN, d);
    PRINT_DEF(CHAR_MAX, d);
    PRINT_DEF(MB_LEN_MAX, d);
    PRINT_DEF(SHRT_MIN, d);
    PRINT_DEF(SHRT_MAX, d);
    PRINT_DEF(USHRT_MAX, d);
    PRINT_DEF(INT_MIN, d);
    PRINT_DEF(INT_MAX, d);
    PRINT_DEF(UINT_MAX, u);
    PRINT_DEF(LONG_MIN, ld);
    PRINT_DEF(LONG_MAX, ld);
    PRINT_DEF(ULONG_MAX, ld);
#if (__STDC_VERSION__ >= 199901L) || (__cplusplus >= 201103L)
    PRINT_DEF(LLONG_MIN, lld);
    PRINT_DEF(LLONG_MAX, lld);
    PRINT_DEF(ULLONG_MAX, llu);
#endif

    return 0;
}
