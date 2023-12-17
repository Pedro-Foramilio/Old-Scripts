#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <unistd.h>

#define CONNECTION_PORT 3500

int main()
{   
    int socket_descriptor;
    int client_socket;
    char storage_buffer[80];
    int length_of_address;
    int option_value = 1;

    struct sockaddr_in server_address;
    struct sockaddr_in connection_address;

    char* message = "This is a message from the server";

    socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_descriptor < 0)
    {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }

    int status = setsockopt(socket_descriptor, SOL_SOCKET, SO_REUSEADDR, 
                            &option_value, sizeof(option_value));

    if (status < 0)
    {
        perror("Couldnt set options!");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(CONNECTION_PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_zero[8] = '\0';

    status = bind(socket_descriptor, (struct sockaddr *)&server_address, 
                    sizeof(struct sockaddr));

    if (status < 0)
    {
        perror("Couldnt bind socket!");
        exit(EXIT_FAILURE);
    }

    status = listen(socket_descriptor, 4);

    if (status < 0)
    {
        perror("Couldnt listen socket!");
        exit(EXIT_FAILURE);
    }

    length_of_address = sizeof(connection_address);

    client_socket = accept(socket_descriptor, (struct sockaddr*)&connection_address,
                            &length_of_address);

    if (client_socket < 0)
    {
        perror("Couldnt connect");
        exit(EXIT_FAILURE);
    }

    ssize_t data_size = recv(client_socket, storage_buffer, sizeof(storage_buffer), 0);

    if (data_size < 0)
    {
        perror("Error recieving data");
        exit(EXIT_FAILURE);
    }
    else
    {
        storage_buffer[data_size] = '\0';
        printf("Received: \n %s\n----\n", storage_buffer);
    }

    if (send(client_socket, message, strlen(message), 0) == -1)
    {
        perror("Sending data to client failed");
    }
    
    close(socket_descriptor);
    close(client_socket);

    return 0;
}
