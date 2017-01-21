#include <sys/types.h>
#include <stdio.h>
#include <string.h>


int main(){
	int i = 0;

	/*Number of existing errors are 133*/
	for (i; i < 255; i++) {
		printf("%d ", i);
		printf("%s \n",strerror(i));
	}

	
	return 1;
}