#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main() {
    int fd, fd1;
    pid_t child;
    char buf[1024], rbuf[1024];
    long bytes_read;

    child = fork();
    if (child == 0) {
        while (strcmp(buf, "quit") != 0) {
            fd1 = open("yourfifo", O_RDWR);
            scanf("%s", buf);
            write(fd1, buf, sizeof(buf));
            close(fd1);
        }
    }else {
        while (strcmp(rbuf, "quit") != 0) {
            fd = open("myfifo", O_RDWR);
            bytes_read = read(fd, rbuf, sizeof(rbuf));
            rbuf[bytes_read] = '\0';
            printf("%s\n", rbuf);
            close(fd);
        }
    }
    return 0;
}