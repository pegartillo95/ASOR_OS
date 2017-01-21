#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	char outstr[200];
	time_t t;
	struct tm *lt;

	t = time(NULL);
	lt = localtime(&t);
	if(lt == NULL){
		perror("localtime");
		exit(EXIT_FAILURE);
	}

	if(strftime(outstr,sizeof(outstr), "%A, %H:%M", lt) == 0){
		fprintf(stderr, "strftime returned 0");
		exit(EXIT_FAILURE);
	}

	printf("Today is %s\n", outstr);

	return 1;
}