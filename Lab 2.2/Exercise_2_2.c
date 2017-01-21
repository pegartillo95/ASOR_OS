#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	int fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU|S_IRWXG|S_IRWXO);
	if(fd == -1){
		printf("Failed open\n");
	}

	if(dup2(fd,1) == -1){
		printf("Failed to do dup2 the standard input\n");
	}

	if(dup2(1,2) == -1){
		printf("Failed to do dup2 the error input\n");
	}

	printf("This is a standard output and should be at file\n");

	perror("This is an error and should be at the file\n");

	return 0;
}