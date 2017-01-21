#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char *argv[]){

	int fd = open(argv[1], O_WRONLY|O_CREAT, S_IRWXU|S_IRWXG|S_IRWXO);

	if(fd == -1){
		printf("The file couldnt be created\n");
	}

	struct flock act_lock;

	if(fcntl(fd, F_GETLK, &act_lock) == -1){
		printf("The fcntl function failed\n");
	}

	if(act_lock.l_type == F_UNLCK){
		act_lock.l_type = F_WRLCK;
		act_lock.l_whence = SEEK_CUR;
		act_lock.l_start = 0;
		act_lock.l_len = 0;
		act_lock.l_pid = getpid();


		if(fcntl(fd, F_SETLK, &act_lock) == -1){
			printf("Failed to lock\n");
		}

		time_t raw_time;
		time(&raw_time);
		write(fd, "hello\n", 7);
		sleep(10);

		act_lock.l_type = F_UNLCK;
		if(fcntl(fd, F_SETLK, &act_lock) == -1){
			printf("Failed to unlock\n");
		}
		
	}


	return 0;
}