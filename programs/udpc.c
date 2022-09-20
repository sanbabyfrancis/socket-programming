#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

/*
    socket()
    fill server fields
    sendto()
*/

void main() {
    struct sockaddr_in server;
    char buffer[100];
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = 8080;
    printf("Enter message to be sent: ");
    fgets(buffer, 100, stdin);
    sendto(sockfd, buffer, 100, 0, (struct sockaddr*)&server, sizeof(server));
}