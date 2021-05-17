cmake_minimum_required(VERSION 3.15)
project(irc_chat)

set(CMAKE_CXX_STANDARD 17)

add_executable(server server.cpp database.h database.cpp)
add_executable(client client.cpp)