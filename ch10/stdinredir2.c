#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    int fd;
    int newfd;
    char line[100];

    fgets(line, 100, stdin); printf("%s", line);
    fgets(line, 100, stdin); printf("%s", line);
    fgets(line, 100, stdin); printf("%s", line);

    fd = open("data", O_RDONLY);
    newfd = dup2(fd, 0);
    if(newfd != 0){
        fprintf(stderr, "Could not duplicate fd to 0\n");
        exit(1);
    }

    close(fd);

    fgets(line, 100, stdin); printf("%s", line);
    fgets(line, 100, stdin); printf("%s", line);
    fgets(line, 100, stdin); printf("%s", line);
}