#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int*argc, char*argv[]) {
  int rc = fork();

  if (rc < 0) {
    printf("Failed to Fork");
  } else if ( rc == 0 ) {
    printf("Child Process\n");
    printf("Calling exec()\n");
    char* args[] = {"/bin/ls", NULL};
    execv(args[0], args);
  } else {
    printf("Parent process\n\n");
  }
  
  return 0;
}
