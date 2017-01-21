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
		printf("Failed to do dup2\n");
	}

	printf("This should be at file\n");

	return 0;
}