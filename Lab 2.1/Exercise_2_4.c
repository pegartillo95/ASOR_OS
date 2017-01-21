#include <unistd.h>
#include <stdio.h>


int main(){

	const char path = "./Exercise_1_1.c";

	printf("Maximum length of a filename: %ld \n",pathconf(&path, _PC_NAME_MAX));
	printf("Maximum length of a path: %ld \n",pathconf(&path, _PC_PATH_MAX));

	return 1;
}