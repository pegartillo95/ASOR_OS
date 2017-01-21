#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	int PID = getpid();

	printf("PID: %d\n", PID);
	printf("PGID: %d\n", getpgid(PID));
	printf("SID: %d\n", getsid(PID));

	char cwd[400]; 
	getcwd(cwd, 400);

	printf("Current directory name: %s\n", cwd);
	

	return 0;
}