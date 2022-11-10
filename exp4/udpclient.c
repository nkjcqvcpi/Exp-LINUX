#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    struct sockaddr_in server_addr;
    char buf[32];
    size_t length;
    int bufSize = 32;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(9739);
    int server_len = sizeof(server_addr);
    char fileName[8] = "IOT2019";
    FILE *sfp = fopen("../实验4/IOT2019", "rb");
    sendto(sockfd, fileName, strlen(fileName), 0, (struct sockaddr *) &server_addr, server_len);
    while ((length = fread(buf, 1, bufSize, sfp)) > 0)
        sendto(sockfd, buf, length, 0, (struct sockaddr *) &server_addr, server_len);
    fclose(sfp);
    sendto(sockfd, "\a", bufSize, 0, (struct sockaddr *) &server_addr, server_len);
    close(sockfd);
    return 0;
}
