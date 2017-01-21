#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int count_SIGINT, count_SIGTSTP;
void handle_signal(int signal);

int main(int argc, char *argv[]){

	struct sigaction sa;
	sa.sa_handler = &handle_signal;
	sa.sa_flags = SA_RESTART;
	sigfillset(&sa.sa_mask);

	if(sigaction(SIGUSR1, &sa, NULL) == -1){
		perror("Should never happen since I should be able to set SIGUSR1");
	}

	int secs;
	sscanf(argv[1], "%d", &secs);

	sleep(secs);

	remove("Exercise_4_5");
	

	return 0;
}

void handle_signal(int signal){

	switch(signal){
		case SIGUSR1:
			exit(0);
	}
}