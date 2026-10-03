#include <gtest/gtest.h>

#include <unistd.h>

#include "server.h"

TEST(SocketTest, CreatesSocket)
{
    int socket_fd = create_server_socket();

    EXPECT_NE(socket_fd, -1);

    close(socket_fd);
}

