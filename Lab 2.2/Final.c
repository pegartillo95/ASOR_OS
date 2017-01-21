#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int accSize = 0;
	DIR *pDir;
	struct dirent *pDirent;

	pDir = opendir(argv[1]);

	if(pDir == NULL){
		perror("Error in opendir()");
		return 1;
	}

	while((pDirent = readdir(pDir)) != NULL){
		printf("%s", pDirent->d_name);
		if(pDirent->d_type == DT_DIR){
			printf("/\n");
		}
		else if(pDirent->d_type == DT_LNK){
			printf("->\n");
		}
		else if(pDirent->d_type == DT_REG){
			printf("\n");
		}

		accSize += pDirent->d_reclen;
	}
	
	printf("Total size: %d\n", accSize);

	return 0;
}