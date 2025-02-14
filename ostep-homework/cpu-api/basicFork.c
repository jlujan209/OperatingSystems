#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    
    int x = 10;

    int rc = fork();

    if (rc < 0) {
        printf("Fork Failed");
        exit(1);
    } else if (rc == 0) {
        printf("Child Process:\n");
        printf("Initial X: %d\n", x);
        x = -10;
        printf("After Change X: %d\n", x);
        printf("\n\n");
    } else {
        printf("Parent process:\n");
        printf("Initial X: %d\n", x);
        x = 20;
        printf("After Change X: %d\n", x);
        printf("\n\n");
    }

    return 0;
}

