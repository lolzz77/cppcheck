#include <stdio.h>
#include <pthread.h>
#include <vector>
int main()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    std::vector<int> items;
    items.push_back(1);
    items.push_back(2);
    items.push_back(3);
    std::vector<int>::iterator iter;
    for (iter = items.begin(); iter != items.end();) {
        if (*iter == 2) {
            iter = items.erase(iter);
        } else {
            ++iter;
        }
    }
}
