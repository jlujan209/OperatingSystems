#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int*argc, char*argv[]) {
    int fd[2];

    if (pipe(fd) == -1) {
        printf("Error: could not create a pipe\n");
        exit(-1);
    }

    int childOnePID = fork();

    if (childOnePID < 0) {
        printf("Fork Failed");
        exit(1);
    } else if (childOnePID == 0) {
        printf("Child One writing to pipe (\"Hello World\")\n");
        char toSend[]= "Hello World";
        write(fd[1], toSend, strlen(toSend));
        exit(0);
    } else {
        int childTwoPID = fork();

        if (childTwoPID < 0) {
            printf("Fork Failed");
            exit(1);
        } else if (childTwoPID == 0) {
            printf("\n\nChild Two Receiving Data....\n");
            char toReceive[BUFSIZ];
            int status;
            waitpid(childOnePID, &status, 0);
            read(fd[0], toReceive, BUFSIZ);
            printf("Data received from Child One: %s\n", toReceive);
        }
    }

    return 0;
}