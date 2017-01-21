#include <sched.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	int policy;
	struct sched_param parameters;

	policy = sched_getscheduler(0);
	sched_getparam(0,&parameters);


	if(policy == SCHED_FIFO){
		printf("Fifo scheduling policy\n");
		printf("Actual scheduler priority: %d\n", parameters.sched_priority);
		printf("Maximum priority: %d\n", sched_get_priority_max(SCHED_FIFO));
		printf("Minimum priority: %d\n", sched_get_priority_min(SCHED_FIFO));
	}
	else if(policy == SCHED_RR){
		printf("Round robin scheduling policy\n");
		printf("Actual scheduler priority: %d\n", parameters.sched_priority);
		printf("Maximum priority: %d\n", sched_get_priority_max(SCHED_RR));
		printf("Minimum priority: %d\n", sched_get_priority_min(SCHED_RR));
	}
	else if(policy == SCHED_OTHER){
		printf("Standard round-robin time sharing scheduling policy\n");
		printf("Actual scheduler priority: %d\n", parameters.sched_priority);
		printf("Maximum priority: %d\n", sched_get_priority_max(SCHED_OTHER));
		printf("Minimum priority: %d\n", sched_get_priority_min(SCHED_OTHER));
	}
	

	return 1;
}