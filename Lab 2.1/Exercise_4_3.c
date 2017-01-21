#include <stdio.h>
#include <time.h>

int main(){

	const time_t t = time(NULL);

	/*char time_str = ctime(&t);*/

	printf("%s\n",ctime(&t));

	return 1;
}