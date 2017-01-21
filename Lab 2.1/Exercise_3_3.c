#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main(){

	uid_t real_user = getuid();
	struct passwd *pwd = getpwuid(real_user);

	printf("User name: %s\nUser home directory: %s\n", pwd->pw_name, pwd->pw_dir);

	return 1;
}