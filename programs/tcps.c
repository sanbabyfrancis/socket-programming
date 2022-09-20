#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

/*
    socket()
    fill server and client fields
    bind()
    listen()
    accept()
    recv()
    close()
*/

void main() {
    struct sockaddr_in server, client;
    char buffer[100];
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = 8080;
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = INADDR_ANY;
    client.sin_port = 8080;
    bind(sockfd, (struct sockaddr*)&server, sizeof(server));
    listen(sockfd, 5);
    socklen_t len = sizeof(client);
    int clientfd = accept(sockfd, (struct sockaddr*)&client, &len);
    recv(clientfd, buffer, 100, 0);
    printf("Message received is: %s", buffer);
    close(clientfd);
}