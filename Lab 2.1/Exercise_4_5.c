#include <stdio.h>
#include <time.h>

int main(){

	const time_t t = time(NULL);

	struct tm *lt = localtime(&t);

	printf("We are in %d\n", (lt->tm_year)+1900);

	/*printf("We are in %d\n", (localtime(&t)->tm_year)+1900);*/

	return 1;
}