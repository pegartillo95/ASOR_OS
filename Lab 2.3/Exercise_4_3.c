#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	sigset_t s_set;

	if(sigemptyset(&s_set) == -1){
		perror("Failed to create the empty set");
	}
	if(sigaddset(&s_set, 2) == -1){
		perror("Failed to add SIGINT");
	}
	if(sigaddset(&s_set, 20) == -1){
		perror("Failed to add SIGTSTP");
	}

	sigprocmask(SIG_BLOCK, &s_set, NULL);

	sleep(20);

	sigset_t p_signals;

	sigpending(&p_signals);

	if(sigismember(&p_signals, 2) == 1){
		printf("SIGINT signal\n");
	}
	else if(sigismember(&p_signals, 20) == 1){
		printf("SIGTSTP signal\n");
		sleep(1);
		sigset_t new_set;
		sigemptyset(&new_set);
		sigaddset(&new_set, 20);
		sigprocmask(SIG_UNBLOCK, &new_set, NULL);
	}

	return 0;
}