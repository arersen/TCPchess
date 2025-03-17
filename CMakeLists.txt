cmake_minimum_required(VERSION 3.10)

project(TCPchess C)

set(CMAKE_C_COMPILER gcc)

set(CMAKE_C_STANDARD 11)

set(SOURCES
	main.c
	window/window.c
	chess/gui.c

)

set(HEADERS
	main.h
	window/window.h
	chess/gui.h
)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_check_modules(GLFW3 REQUIRED glfw3)

include_directories(${GLFW3_INCLUDE_DIRS})
link_directories(${GLFW3_LIBRARY_DIRS})

add_executable(TCPchess ${SOURCES} ${HEADERS})

target_include_directories(TCPchess PRIVATE include)
target_link_libraries(TCPchess PRIVATE OpenGL::GL ${GLFW3_LIBRARIES}  GLEW::GLEW)
target_compile_options(TCPchess PRIVATE -g  -Wall -Wextra -O2)
