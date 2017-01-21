#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	int fd = open(argv[1] ,O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU|S_IRWXG|S_IRWXO);

	 if(fd == -1){
	 	perror("Failed to open the file");
	 }
	 write(fd, argv[0], strlen(argv[0]));

	return 0;
}