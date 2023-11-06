#include <stdio.h>
#include <pthread.h>

// Test library configuration for libsigc++.cfg
//
// Usage:
// $ cppcheck --check-library --library=libsigc++ --enable=style,information --inconclusive --error-exitcode=1 --disable=missingInclude --inline-suppr test/cfg/libsigc++.cpp
// =>
// No warnings about bad library configuration, unmatched suppressions, etc. exitcode=0
//

#include <sigc++/sigc++.h>

struct struct1 : public sigc::trackable {
    void func1(int) const {}
};

void valid_code()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    const struct1 my_sruct1;
    sigc::slot<void, int> sl = sigc::mem_fun(my_sruct1, &struct1::func1);
    if (sl) {}
}

void ignoredReturnValue()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    const struct1 my_sruct1;
    // cppcheck-suppress ignoredReturnValue
    sigc::mem_fun(my_sruct1, &struct1::func1);
}
