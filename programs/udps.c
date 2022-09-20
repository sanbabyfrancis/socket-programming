#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

/*  
    socket()
    fill server and client fields
    bind()
    recvfrom()
*/

void main() {
    struct sockaddr_in server, client;
    char buffer[100];
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = 8080;
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = INADDR_ANY;
    client.sin_port = 8080;
    socklen_t len = sizeof(client);
    bind(sockfd, (struct sockaddr*)&server, sizeof(server));
    recvfrom(sockfd, buffer, 100, 0, (struct sockaddr*)&client, &len);
    printf("Message received is: %s", buffer);
}