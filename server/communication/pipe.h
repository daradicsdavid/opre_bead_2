#ifndef OP_BEAD_PIPE_H
#define OP_BEAD_PIPE_H

#include "../model/order.h"

int setupPipes(int parentToChild[], int childToParent[]);

void sendOrders(struct Order *orders, int orderNumber, int pipe[]);

int receiveOrders(struct Order *orders, int pipe[]);

#endif //OP_BEAD_PIPE_H