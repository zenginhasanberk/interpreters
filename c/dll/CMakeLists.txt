cmake_minimum_required(VERSION 3.28)
project(interpreters_dll C)

set(CMAKE_C_STANDARD 11)

add_executable(interpreters_dll main.c
        doubly_linked_list.h
        doubly_linked_list.c)
