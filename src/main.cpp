#include <iostream>

#include "server.h"

#include <unistd.h>

int main()
{
    int server_socket = create_server_socket();

    if (server_socket == -1)
    {
        std::cerr << "Failed to create socket\n";
        return 1;
    }

    std::cout << "Socket created successfully\n";

    close(server_socket);

    return 0;
}