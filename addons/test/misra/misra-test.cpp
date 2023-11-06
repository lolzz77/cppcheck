#include <stdio.h>
#include <pthread.h>
// #8441
class C {
    int a;
    int b;
    C(void) : a(1), b(1) { c; }
};

class misra_21_1_C {
    public:
       misra_21_1_C operator=(const misra_21_1_C &);
};

class C2 {
public:
	C2(void);
private:
	void* f;
};
C2::C2(void) : f(NULL) {}

static void test_misra_21_1_crash(void)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    auto misra_21_1_C a, b; // 12.3
    a = b;
}
