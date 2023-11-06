#include <stdio.h>
#include <pthread.h>
/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2023 Cppcheck team.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * This does not match the standard cppchek test code,
 * because I haven't figured that out yet.
 * This code does compile and run, and does demonstrate
 * the issues that the threadsafety.py addon is supposed to find.
 * It does not use threads !
 */

#include <stdio.h>
#include <time.h>
#include <string.h>

void threadsafety_static()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    // cppcheck-suppress threadsafety-threadsafety
    static unsigned int nCount = 0;

    nCount++;
    printf("%d\n", nCount);
}

void threadsafety_call()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    time_t now = time(nullptr);
    // cppcheck-suppress threadsafety-unsafe-call
    printf("%s\n", ctime(&now));
}

// cppcheck --addon=threadsafety
// should *not* find any problems with this function.
void threadsafety_safecall()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    char haystack[] = "alphabet";
    char needle[] = "Alph";
    char* found = strcasestr(haystack, needle);
    printf("%s %sin %s\n", needle, found ? "" : "not ", haystack);
}

int main() {
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    threadsafety_static();
    
    threadsafety_call();

    threadsafety_safecall();

    threadsafety_static();

    return 0;
}
