#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	struct stat status;

	if(stat(argv[1], &status) == -1){
		printf("The stat function failed\n");
	}

	if((status.st_mode & S_IFMT) == S_IFREG){
		if(link(argv[1], argv[2]) == -1){
			printf("The link function failed\n");
		}
		if(symlink(argv[1], argv[3]) == -1){
			printf("The link function failed\n");
		}
	}

	return 0;
}