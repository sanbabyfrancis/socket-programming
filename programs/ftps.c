#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

/*
    socket()
    fill server and client fields
    bind()
    listen()
    accept()
    receive file contents
    close()
*/

void main() {
    struct sockaddr_in server, client;
    char name[100], contents[100];
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = 8080;
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = INADDR_ANY;
    client.sin_port = 8080;
    socklen_t len = sizeof(client);
    bind(sockfd, (struct sockaddr*)&server, sizeof(server));
    listen(sockfd, 5);
    int clientfd = accept(sockfd, (struct sockaddr*)&client, &len);
    recv(clientfd, name, 100, 0);
    printf("Name of the file received: %s\n", name);
    recv(clientfd, contents, 100, 0);
    printf("The file contents: %s\n", contents);
    close(clientfd);
}