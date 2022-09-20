#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

/*
    socket()
    fill server fields
    connect()
    send file contents
    close()
*/

void main() {
    struct sockaddr_in server;
    char name[100], contents[100];
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = 8080;
    connect(sockfd, (struct sockaddr*)&server, sizeof(server));
    printf("Enter the name of the file: ");
    gets(name); // do not use fgets() here
    send(sockfd, name, 100, 0);
    FILE *fp = fopen(name, "r");
    fgets(contents, 100, fp);
    send(sockfd, contents, 100, 0);
    close(sockfd);
}