#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

	mode_t oldMask, newMask;

	oldMask = umask(0132);

	printf("Mask before creating the file: %o\n", (int) oldMask);

	if(open(argv[1], O_WRONLY|O_CREAT|O_TRUNC) == -1){
		perror("Error while opening\n");
		return 1;
	}

	newMask = umask(oldMask);

	printf("New mask: %o\n", (int) newMask);

	return 0;
}