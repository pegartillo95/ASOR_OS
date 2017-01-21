#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

	/*S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH|S_IXOTH*/

	if(open(argv[1], O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH|S_IXOTH) == -1){
		printf("Error while opening\n");
	}

	return 0;
}