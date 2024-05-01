cmake_minimum_required(VERSION 3.28)
project(bank_app C)

set(CMAKE_C_STANDARD 11)

add_executable(bank_app main.c
        variables.h
        functions.c
)
