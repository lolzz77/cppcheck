#include <stdio.h>
#include <pthread.h>

// Test library configuration for sqlite3.cfg
//
// Usage:
// $ cppcheck --check-library --library=sqlite3 --enable=style,information --inconclusive --error-exitcode=1 --disable=missingInclude --inline-suppr test/cfg/sqlite3.c
// =>
// No warnings about bad library configuration, unmatched suppressions, etc. exitcode=0
//

#include <sqlite3.h>
#include <stdio.h>

void validCode()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    sqlite3 * db;

    int rc = sqlite3_open("/db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error opening sqlite3 db: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
    } else {
        sqlite3_close(db);
    }

    {
        char * buf = sqlite3_malloc(10);
        printf("size: %ull\n", sqlite3_msize(buf));
        sqlite3_free(buf);
    }
}

void memleak_sqlite3_malloc()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    char * buf = sqlite3_malloc(10);
    if (buf) {
        buf[0] = 0;
    }
    // cppcheck-suppress memleak
}

void resourceLeak_sqlite3_open()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    sqlite3 * db;

    sqlite3_open("/db", &db);
    // TODO: cppcheck-suppress resourceLeak
}

void ignoredReturnValue(const char * buf)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    // cppcheck-suppress leakReturnValNotUsed
    sqlite3_malloc(10);
    // cppcheck-suppress leakReturnValNotUsed
    sqlite3_malloc64(5);
    // cppcheck-suppress ignoredReturnValue
    sqlite3_msize(buf);
}
