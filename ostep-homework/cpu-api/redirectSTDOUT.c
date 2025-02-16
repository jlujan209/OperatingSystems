#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(int*argc, char* argv[]) {
    int rc = fork();

    if (rc < 0) {
        printf("Fork Failed");
    } else if (rc == 0) {
        printf("Child Process:\n");
        close(STDOUT_FILENO);
        printf("Testing after closing standard output");
    } else {
        int rc_wait = wait(NULL);
        printf("Parent Process:\n");
        printf("RC: %d, RC_WAIT: %d", rc, rc_wait);
    }

    return 0;
}