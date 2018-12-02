#ifndef OP_BEAD_DELETE_H
#define OP_BEAD_DELETE_H

#include "../model/order.h"
#include "../model/boolean.h"


int deleteOrder(struct Order orders[], int *orderNumber, int deleteIndex);

void deleteFinishedOrders(struct Order orders[], int *numberOfOrders, struct Order finishedOrders[],
                          int numberOfFinishedOrders, struct Order doneOrders[], int *numberOfDoneOrders);

#endif //OP_BEAD_DELETE_H
