#include <stdio.h>
#include <pthread.h>

// Test library configuration for libcurl.cfg
//
// Usage:
// $ cppcheck --check-library --library=libcurl --enable=style,information --inconclusive --error-exitcode=1 --disable=missingInclude --inline-suppr test/cfg/libcurl.c
// =>
// No warnings about bad library configuration, unmatched suppressions, etc. exitcode=0
//

#include <curl/curl.h>
#include <stdio.h>

void validCode()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    CURL *curl = curl_easy_init();
    if (curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            printf("error");
        } else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            printf("%ld", response_code);
            char * pStr = curl_easy_escape(curl, "a", 1);
            if (pStr)
                printf("%s", pStr);
            curl_free(pStr);
            curl_easy_reset(curl);
        }
        curl_easy_cleanup(curl);
    }
}

void ignoredReturnValue(CURL * handle)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    // cppcheck-suppress ignoredReturnValue
    curl_easy_strerror(1);
}

void resourceLeak_curl_easy_init()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    const CURL *curl = curl_easy_init();
    printf("%p", curl);
    // cppcheck-suppress resourceLeak
}

void resourceLeak_curl_easy_duphandle(CURL * handle)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    const CURL *curl = curl_easy_duphandle(handle);
    printf("%p", curl);
    // cppcheck-suppress resourceLeak
}

void memleak_curl_easy_escape(CURL * handle)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    const char * pStr = curl_easy_escape(handle, "a", 1);
    if (pStr)
        printf("%s", pStr);
    // cppcheck-suppress memleak
}

void nullPointer(CURL * handle)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    char * buf[10] = {0};
    size_t len;

    curl_easy_recv(handle, buf, 10, &len);
    // cppcheck-suppress nullPointer
    curl_easy_recv(handle, buf, 10, NULL);
    curl_easy_send(handle, buf, 10, &len);
    // cppcheck-suppress nullPointer
    curl_easy_send(handle, buf, 10, NULL);
}

void uninitvar(CURL * handle)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    const char * bufInit[10] = {0};
    const char * bufUninit;
    size_t len;

    curl_easy_send(handle, bufInit, 10, &len);
    // cppcheck-suppress uninitvar
    curl_easy_send(handle, bufUninit, 10, &len);
}
