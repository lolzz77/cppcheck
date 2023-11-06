#include <stdio.h>
#include <pthread.h>
struct Dummy {
 int x;
};
void func() {
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
  // cppcheck-suppress threadsafety-threadsafety-const
  static const Dummy dummy;
}
