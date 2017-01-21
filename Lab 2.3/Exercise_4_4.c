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

	if(sigaction(2, &sa, NULL) == -1){
		perror("Should never happen since I should be able to set SIGINT");
	}
	if(sigaction(20, &sa, NULL) == -1){
		perror("Should never happen since I should be able to set SIGTSTP");
	}
	while(1){
		sleep(2);
	}

	return 0;
}

void handle_signal(int signal){

	switch(signal){
		case SIGINT:
			count_SIGINT++;
			break;
		case SIGTSTP:
			count_SIGTSTP++;
			break;
	}
	if(count_SIGINT + count_SIGTSTP == 10){
		printf("Caught %d SIGINT signals\n", count_SIGINT);
		printf("Caught %d SIGTSTP signals\n", count_SIGTSTP);
		exit(0);
	}
}