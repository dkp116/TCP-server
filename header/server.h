#pragma once
#include <netinet/in.h>
#include <sys/socket.h>

int create_server_socket();
sockaddr_in create_server_address(int port);
int hold_connection(int client_socket);