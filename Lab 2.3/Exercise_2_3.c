#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	int pid;

	pid = fork();

	if(pid == -1){
		perror("Failed to fork\n");
	}
	else if(pid == 0){
		printf("DAEMON start\n");

		int PID = getpid();

		printf("parent PPID: %d\n", getppid());
		printf("parent PGID: %d\n", getpgid(PID));
		printf("parent SID: %d\n", getsid(PID));

		printf("DAEMON end\n");
	}
	else{
		printf("PARENT start\n");
		sleep(4);
		printf("my own ID %d\n", getpid());
		printf("PARENT end\n");
	}

	return 0;
}