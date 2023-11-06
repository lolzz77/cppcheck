#include <stdio.h>
#include <pthread.h>

// Test library configuration for kde.cfg
//
// Usage:
// $ cppcheck --check-library --library=kde --enable=style,information --inconclusive --error-exitcode=1 --disable=missingInclude --inline-suppr test/cfg/kde.cpp
// =>
// No warnings about bad library configuration, unmatched suppressions, etc. exitcode=0
//

#include <cstdio>
#include <KDE/KGlobal>
#include <KDE/KConfigGroup>

class k_global_static_testclass1 {};
K_GLOBAL_STATIC(k_global_static_testclass1, k_global_static_testinstance1);

void valid_code(const KConfigGroup& cfgGroup)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    const k_global_static_testclass1 * pk_global_static_testclass1 = k_global_static_testinstance1;
    printf("%p", pk_global_static_testclass1);

    bool entryTest = cfgGroup.readEntry("test", false);
    if (entryTest) {}
}

void ignoredReturnValue(const KConfigGroup& cfgGroup)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    // cppcheck-suppress ignoredReturnValue
    cfgGroup.readEntry("test", "default");
    // cppcheck-suppress ignoredReturnValue
    cfgGroup.readEntry("test");
}
