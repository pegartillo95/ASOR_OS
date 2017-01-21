#include <sys/utsname.h>
#include <stdio.h>


int main(){

	struct utsname unameData;

	uname(&unameData);

	printf("Name of the system: %s \n", unameData.sysname);
	printf("Network node hostname: %s \n", unameData.nodename);
	printf("Kernel release: %s \n", unameData.release);
	printf("Kernel version: %s \n", unameData.version);
	printf("Machine hardware name: %s \n", unameData.machine);

	return 1;
}