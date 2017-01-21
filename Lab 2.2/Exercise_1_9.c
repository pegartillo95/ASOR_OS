#include <stdio.h>
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]){

	struct stat status;

	if(stat(argv[1], &status) == -1){
		printf("The stat function failed\n");
	}

	printf("Mayor number: %u\n", major(status.st_dev));
	printf("Minor number: %u\n", minor(status.st_dev));
	printf("Inode number: %ld\n", status.st_ino);
	printf("File type: ");
	if((status.st_mode & S_IFMT) == S_IFREG) 
		printf("Regular file \n");
	else if((status.st_mode & S_IFMT) == S_IFDIR) 
		printf("Directory \n");
	else if((status.st_mode & S_IFIFO) == S_IFDIR) 
		printf("FIFO \n");
	printf("Last modification time in seconds: %s\n", ctime(&status.st_atime));

	return 0;
}