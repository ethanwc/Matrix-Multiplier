cmake_minimum_required(VERSION 3.10)
project(matrix2 C)

set(CMAKE_C_STANDARD 99)

SET(GCC_COVERAGE_COMPILE_FLAGS "-pthread -I. -Wall -Wno-int-conversion -D_GNU_SOURCE")


add_executable(matrix2 pcmatrix.c pcmatrix.h matrix.h matrix.c counter.c counter.h prodcons.c prodcons.h)