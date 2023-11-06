#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>

/*
 * Define _TIME_BITS unequal to 64 to trigger error
 */

#define _TIME_BITS 62

#include "y2038-inc.h"

int main(int argc, char **argv)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    clockid_t my_clk_id = CLOCK_REALTIME;
    struct timespec *my_tp;

    return clock_gettime(my_clk_id, &my_tp);
}
