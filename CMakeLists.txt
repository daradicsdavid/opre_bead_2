cmake_minimum_required(VERSION 3.12)
project(opre_bead_2)

set(CMAKE_C_STANDARD 99)

add_executable(opre_bead_2 main.c server/model/order.h server/client/client.h server/client/client.c server/communication/pipe.h server/communication/pipe.c server/server.c server/server.h server/create/create.c server/create/create.h server/print/print.h server/print/print.c server/read/read.h server/read/read.c server/update/update.c server/update/update.h server/model/boolean.h server/file/file.h server/file/file.c server/select/select.c server/select/select.h server/delete/delete.c server/delete/delete.h server/filter/filter.c server/filter/filter.h server/menu/menu.c server/menu/menu.h server/simulation/simulatedOrders.c server/simulation/simulatedOrders.h)