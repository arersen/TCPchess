cmake_minimum_required(VERSION 3.10)

project(TCPchess C)

set(CMAKE_C_COMPILER gcc)

set(CMAKE_C_STANDARD 11)

set(SOURCES
	main.c
	other.c

)

set(HEADERS
	main.h
	other.h
)

add_executable(TCPchess ${SOURCES} ${HEADERS})

target_include_directories(TCPchess PRIVATE include)

target_compile_options(TCPchess PRIVATE -g  -Wall -Wextra -O2)
