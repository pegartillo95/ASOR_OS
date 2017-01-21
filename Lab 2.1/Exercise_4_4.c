#include <stdio.h>
#include <sys/time.h>

int main(){

	struct timeval t_before;
	struct timeval t_after;

	gettimeofday(&t_before, NULL);
	int i = 0;
	for (i; i<10000;i++);

	gettimeofday(&t_after, NULL);

	suseconds_t ms = t_after.tv_usec - t_before.tv_usec;

	printf("Difference in microseconds: %ld\n", ms);

	return 1;
}