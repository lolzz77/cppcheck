#include <stdio.h>
#include <pthread.h>
namespace {
    template<typename T>
    T f() {
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
        return T();
    }
}

// cppcheck-suppress unusedFunction
int g(int i) {
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    if (i == 0)
        return f<char>();
    if (i == 1)
        return f<short>();
    return f<int>();
}