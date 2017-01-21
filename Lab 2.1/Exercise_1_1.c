#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int main(){
	
	if(setuid(0) == -1){
		printf("The setuid function has returned an error\n");
	}

	
	return 1;
}