cmake_minimum_required(VERSION 3.20)

project(tcp_server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find source files
file(GLOB SRC_FILES CONFIGURE_DEPENDS
    src/*.cpp
)

# Don't include main.cpp in the reusable server code
list(FILTER SRC_FILES EXCLUDE REGEX ".*/main\\.cpp$")

# Find test files
file(GLOB TEST_FILES CONFIGURE_DEPENDS
    tests/*.cpp
)

# -------------------------
# Main application
# -------------------------

add_executable(tcp_server
    src/main.cpp
    ${SRC_FILES}
)

target_include_directories(tcp_server PRIVATE
    header
)

# -------------------------
# GoogleTest
# -------------------------

find_package(GTest CONFIG REQUIRED)

enable_testing()

# -------------------------
# Tests
# -------------------------

add_executable(tcp_server_tests
    ${TEST_FILES}
    ${SRC_FILES}
)

target_include_directories(tcp_server_tests PRIVATE
    header
)

target_link_libraries(tcp_server_tests PRIVATE
    GTest::gtest_main
)

# Discover GoogleTest tests
include(GoogleTest)
gtest_discover_tests(tcp_server_tests)

