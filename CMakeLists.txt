cmake_minimum_required(VERSION 3.14)
project(linux_programming C)

set(CMAKE_C_STANDARD 99)

add_executable(linux_programming main.c lib/error_functions.h lib/tlpi_hdr.h lib/error_functions.c lib/ename.h lib/get_num.h lib/get_num.c example/va_list.c io/file_io.h)