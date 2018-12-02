#ifndef OP_BEAD_PIPE_H
#define OP_BEAD_PIPE_H

#include "../model/order.h"

int setupPipes(int parentToChild[], int childToParent[]);

void sendOrders(struct Order *orders, int orderNumber, int pipe[]);

int receiveOrders(struct Order **orders, int pipe[], int *numberOfOrders);

void sendReceipt(int finishedOrders, int *pipe);

int receiveReceipt(int *pipe, int *finishedOrders);
#endif //OP_BEAD_PIPE_H