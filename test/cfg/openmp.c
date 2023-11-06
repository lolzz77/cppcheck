#include <stdio.h>
#include <pthread.h>

// Test library configuration for openmp.cfg
//
// Usage:
// $ cppcheck --check-library --library=openmp --enable=style,information --inconclusive --error-exitcode=1 --disable=missingInclude --inline-suppr test/cfg/openmp.c
// =>
// No warnings about bad library configuration, unmatched suppressions, etc. exitcode=0
//

#include <omp.h>
#include <stdio.h>

void validCode()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    int arr[20] = { 0 };
    #pragma omp parallel for
    for (int i = 0; i < 20; ++i) {
        // cppcheck-suppress unreadVariable
        arr[i] = i * i;
    }

    char * pChars = (char *) omp_target_alloc(4, 1);
    printf("pChars: %p", pChars);
    omp_target_free(pChars, 1);
}

void memleak_omp_target_alloc()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    const char * pChars = (char *) omp_target_alloc(2, 0);
    printf("pChars: %p", pChars);
    // cppcheck-suppress memleak
}
