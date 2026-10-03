#include "server.h"

#include <sys/socket.h>

int create_server_socket()
{
    return socket(AF_INET, SOCK_STREAM, 0);
}