#include <gtest/gtest.h>

#include <netinet/in.h>

#include "server.h"

TEST(SocketTest, CreatesSocket)
{
    int socket_fd = create_server_socket();

    EXPECT_NE(socket_fd, -1);

    close(socket_fd);
}

TEST(ServerAddressTest, CreatesIPv4Address)
{
    sockaddr_in address = create_server_address(8080);

    EXPECT_EQ(address.sin_family, AF_INET);
}

TEST(ServerAddressTest, UsesAnyAddress)
{
    sockaddr_in address = create_server_address(8080);

    EXPECT_EQ(address.sin_addr.s_addr, INADDR_ANY);
}

TEST(ServerAddressTest, UsesCorrectPort)
{
    sockaddr_in address = create_server_address(8080);

    EXPECT_EQ(ntohs(address.sin_port), 8080);
}

