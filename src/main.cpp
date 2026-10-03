#include <iostream>

#include "server.h"

#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main()
{
    int server_socket = create_server_socket();

    if (server_socket == -1)
    {
        std::cerr << "Failed to create socket\n";
        return 1;
    }

    std::cout << "Socket created successfully\n";

    auto server_address = create_server_address(8080);

    auto bind_result = bind(server_socket, reinterpret_cast<sockaddr *>(&server_address), sizeof(server_address));

    int listen_result = listen(server_socket, 4);

    int client_socket = accept(server_socket, nullptr, nullptr);

    hold_connection(client_socket);

    close(server_socket);

    return 0;
}