cmake_minimum_required(VERSION 3.12)
project(opre_bead_2)

set(CMAKE_C_STANDARD 99)

add_executable(opre_bead_2 main.c client/client.c client/client.h communication/pipe.h communication/pipe.c server/server.c server/server.h)