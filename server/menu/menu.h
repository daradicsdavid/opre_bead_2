#ifndef OP_BEAD_MENU_H
#define OP_BEAD_MENU_H

#include "../model/order.h"
#include "../model/boolean.h"

void printMainMenu();

boolean askMainMenu(int *command);

void printFilterMenu();

boolean askFilterMenu(int *command);

#endif //OP_BEAD_MENU_H
