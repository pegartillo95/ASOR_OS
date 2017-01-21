#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	fd_set fdSet;
	struct timeval tv;
	int high_fd;

	int retval;

	int fd1 = open(argv[1] ,O_NONBLOCK, S_IRWXU|S_IRWXG|S_IRWXO);
	int fd2 = open(argv[2] ,O_NONBLOCK, S_IRWXU|S_IRWXG|S_IRWXO);


	if(fd1 > fd2){
		high_fd = fd1;
	}
	else{
		high_fd = fd2;
	}

	while(1){
		retval = 0;

		FD_ZERO(&fdSet);
		FD_SET(fd1, &fdSet);
		FD_SET(fd2, &fdSet);

		retval = select(high_fd+1,&fdSet,NULL,NULL,NULL);


		if(retval == -1){
			perror("select()");
		}
		else if(retval == 1){
			char buffer[256];
			if(FD_ISSET(fd1,&fdSet)){
				printf("Read info from %s", argv[1]);
				while(read(fd1, &buffer, 256) != 0){
					printf("%s", buffer);
				}
			}
			else if(FD_ISSET(fd2, &fdSet)){
				printf("Read info from %s", argv[2]);
				while(read(fd2, &buffer, 256) != 0){
					printf("%s", buffer);
				}
			}
		}


	}


	return 0;
}