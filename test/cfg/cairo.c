#include <stdio.h>
#include <pthread.h>

// Test library configuration for cairo.cfg
//
// Usage:
// $ cppcheck --check-library --library=cairo --enable=style,information --inconclusive --error-exitcode=1 --disable=missingInclude --inline-suppr test/cfg/cairo.c
// =>
// No warnings about bad library configuration, unmatched suppressions, etc. exitcode=0
//

#include <cairo.h>

void validCode(cairo_surface_t *target)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    cairo_t * cairo1 = cairo_create(target);
    cairo_move_to(cairo1, 1.0, 2.0);
    cairo_line_to(cairo1, 5.0, 6.0);
    cairo_destroy(cairo1);
}

void ignoredReturnValue(cairo_surface_t *target)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    // cppcheck-suppress ignoredReturnValue
    cairo_create(target);
    // cppcheck-suppress ignoredReturnValue
    cairo_status_to_string(CAIRO_STATUS_READ_ERROR);
}
