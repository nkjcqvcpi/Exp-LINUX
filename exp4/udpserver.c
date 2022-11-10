#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int main() {
    socklen_t client_len = 0;
    char buf[32];
    int bufSize = 32;
    char fileName[8];
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(9739);
    int server_len = sizeof(server_addr);
    if (bind(sockfd, (struct sockaddr *) &server_addr, server_len) != 0) return 1;
    signal(SIGCHLD, SIG_IGN);
    int flag = 1;
    while (flag) {
        recvfrom(sockfd, fileName, bufSize, 0, (struct sockaddr *) &client_addr, &client_len);
        printf("Filename: %s \n", fileName);
        FILE *rfp = fopen(fileName, "wb");
        ssize_t length;
        while ((length = recvfrom(sockfd, buf, bufSize, 0, (struct sockaddr *) &client_addr, &client_len))) {
            if (!strcmp(buf, "\a")) { flag = 0; break; }
            else fwrite(buf, 1, length, rfp);
        }
        fclose(rfp);
    }
    close(sockfd);
    FILE *rfp = fopen(fileName, "rb");
    while (fgets(buf, bufSize, rfp) != NULL) printf("%s", buf);
    fclose(rfp);
    return 0;
}
