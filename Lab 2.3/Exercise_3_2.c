#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE 1024

void print_usage() {
  printf("Usage: execute <-e or -s> <program> [arguments]\n");
}

int start_daemon(char *command, char mode) {

  // Redirections
  int mystdout = open("daemon.out", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU|S_IRWXO|S_IRWXG);
  if (mystdout == -1) {
    perror("FAILURE!!");
    return 1;
  }
  dup2(mystdout, 1);

  int mystderr = open("daemon.err", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU|S_IRWXO|S_IRWXG);
  if (mystderr == -1) {
    perror("FAILURE!!");
    return 1;
  }
  dup2(mystderr, 2);

  if (mode == 'e') {
    return execl("/bin/sh", "sh", "-c", command, (char *) 0);
  } else if (mode == 's') {
    return system(command);
  } else {
    print_usage();
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  if (argc < 3) {
    print_usage();
    return 0;
  }

  char command[BUFSIZE];
  int argsize = argc - 2;
  int i;
  char *head = command;
  for (i = 0; i < argsize; i++) {
    head += sprintf(head, argv[i + 2]);
    head += sprintf(head, " ");
  }

  printf("%s\n", command);

  int pid = fork();
  if (pid == 0) {
    if (start_daemon(command, argv[1][1])) {
      perror("FAILURE!!");
      return 1;
    }
  }

  return 0;
}
