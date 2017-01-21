#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

	uid_t real_user = getuid();
	uid_t effective_user =geteuid();

	printf("Real user: %d\nActual user: %d\n", real_user,effective_user);

	return 1;
}