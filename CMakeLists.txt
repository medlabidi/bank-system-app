cmake_minimum_required(VERSION 3.28)
project(bank_app C)

set(CMAKE_C_STANDARD 11)

add_executable(bank_app
        functions.h
        variables.h
        functions.c
)
target_include_directories(bank_app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})