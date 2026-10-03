#include "server.h"
#include <netinet/in.h>
#include <sys/socket.h>

int create_server_socket()
{
    return socket(AF_INET, SOCK_STREAM, 0);
}

sockaddr_in create_server_address(int port)
{
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    return address;
}

void hold_connection(int client_socket)
{
    char buffer[1024];
    while (true)
    {
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received == -1)
        {
            std::cerr << "Failed to receive data\n";
            break;
        }
        if (bytes_received == 0)
        {
            std::cout << "Client disconnected\n";
            break;
        }
        std::cout << "Received: ";
        std::cout.write(buffer, bytes_received);
        std::cout << '\n';
    }
}