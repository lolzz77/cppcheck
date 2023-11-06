#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>

/*
 * Do not define _TIME_BITS but have _USE_TIME_BITS64 defined
 */

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
