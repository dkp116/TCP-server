cmake_minimum_required(VERSION 3.20)

project(tcp_server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main application
add_executable(tcp_server
    src/main.cpp
)

# GoogleTest
find_package(GTest CONFIG REQUIRED)

# Enable CTest
enable_testing()

# Tests
add_executable(tcp_server_tests
    tests/test_main.cpp
)

target_link_libraries(tcp_server_tests PRIVATE
    GTest::gtest_main
)

# Automatically discover GoogleTest tests
include(GoogleTest)
gtest_discover_tests(tcp_server_tests)

