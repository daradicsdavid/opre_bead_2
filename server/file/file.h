#ifndef OP_BEAD_FILE_H
#define OP_BEAD_FILE_H


#include "../model/order.h"


int readFromFile(struct Order *orders);

void writeToFile(struct Order orders[], int orderNumber);

#endif //OP_BEAD_FILE_H
