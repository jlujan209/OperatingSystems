#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(int*argc, char*argv[]){
    int fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    const char *data = "Hello World";

    int rc = fork();

    if (rc < 0) {
        printf("Fork Failed");
        exit(1);
    } else if (rc == 0) {
        const char *data = "Child Process says Hello World!\n";
        ssize_t bytes_written = write(fd, data, strlen(data));
        if (bytes_written == -1) {
            perror("Error writing to file");
            close(fd);
            return 1;
        }

        if (close(fd) == -1) {
            perror("Error closing file");
            return 1;
        }
    } else {
        wait(NULL);
        const char *data = "Parent Process says Hello World!\n";
        ssize_t bytes_written = write(fd, data, strlen(data));
        if (bytes_written == -1) {
            perror("Error writing to file");
            close(fd);
            return 1;
        }

        if (close(fd) == -1) {
            perror("Error closing file");
            return 1;
        }
    }

    return 0;
}