cmake_minimum_required(VERSION 3.10)
project(matrix2 C)

set(CMAKE_C_STANDARD 99)

add_executable(matrix2 pcmatrix.c pcmatrix.h matrix.h matrix.c counter.c counter.h prodcons.c prodcons.h)