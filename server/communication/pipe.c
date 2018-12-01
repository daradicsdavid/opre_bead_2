#include <zconf.h>
#include <stdio.h>
#include <string.h>
#include "../model/order.h"
#include "../model/boolean.h"

int setupPipes(int parentToChild[], int childToParent[]) {
    if (pipe(parentToChild) == -1) {
        fprintf(stderr, "Pipe Failed");
        return 0;
    }
    if (pipe(childToParent) == -1) {
        fprintf(stderr, "Pipe Failed");
        return 0;
    }
    return 1;
}

void sendOrders(struct Order *orders, int orderNumber, int *pipe) {
    close(pipe[0]);
    // Write concatenated string and close writing end
    write(pipe[1], &orderNumber, sizeof(int));
    write(pipe[1], orders, orderNumber * sizeof(struct Order));
}

int receiveOrders(struct Order *orders, int *pipe) {
    close(pipe[1]);
    int orderNumber;
    int result = read(pipe[0], &orderNumber, sizeof(orderNumber));
    if (result == 0) {
        return false;
    }
    result = read(pipe[0], orders, orderNumber * sizeof(struct Order));
    return true;
}
