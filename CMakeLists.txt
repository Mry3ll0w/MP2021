cmake_minimum_required(VERSION 3.17)
project(MP2021 C)

set(CMAKE_C_STANDARD 99)

add_executable(MP2021 main.c lib/admin.h lib/core.h lib/participante.h lib/cronista.h lib/cronista.c lib/core.c lib/participante.c)