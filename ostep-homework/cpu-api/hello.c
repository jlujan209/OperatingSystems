#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int*argc, char*argv[]) {
    
    int rc = fork();

    if (rc < 0) {
        printf("Fork Failed");
    }
    else if (rc == 0) {
        printf("Hello\n");
    } 
    else {
        int number;
        printf("Parent Process First\n");
        // Parent process was first until this IO request, in which we switch to the child process
        scanf("%d", &number);
        printf("Goodbye\n");
    }
    
    return 0;
}