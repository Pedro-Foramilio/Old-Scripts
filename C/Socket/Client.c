#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <unistd.h>

#define CONNECTION_PORT 3500

int main()
{
    struct sockaddr_in server_address;
    char* message = "This is a message from the client";
    char recieve_buffer[100];
    int socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_descriptor < 0)
   {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
   }

    int status = 0;
    
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(CONNECTION_PORT);
    server_address.sin_addr.s_addr =INADDR_ANY;
    server_address.sin_zero[8]='\0';

    status = connect(socket_descriptor, (struct sockaddr *)&server_address,
                        sizeof(server_address));

    if(status < 0)
    {
        perror("Couldn't connect with the server");
        exit(EXIT_FAILURE);
    }

    write(socket_descriptor, message, strlen(message));
    read(socket_descriptor, recieve_buffer, 100);

    printf("Message from server:\n %s\n---\n", recieve_buffer);

    close(socket_descriptor);
    return 0;
}