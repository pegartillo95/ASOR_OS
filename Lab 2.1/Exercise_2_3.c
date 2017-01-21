#include <unistd.h>
#include <stdio.h>


int main(){

	printf("Maximum number of child processes: %ld \n",sysconf(_SC_CHILD_MAX));
	printf("Maximum number of open files: %ld \n",sysconf(_SC_OPEN_MAX));
	printf("Maximum length of the host name: %ld \n",sysconf(_SC_HOST_NAME_MAX));

	return 1;
}