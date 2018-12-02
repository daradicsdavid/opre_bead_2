#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <malloc.h>
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

int receiveOrders(struct Order **orders, int *pipe, int *numberOfOrders) {
    close(pipe[1]);
    int result = read(pipe[0], numberOfOrders, sizeof(int));
    if (result == 0) {
        return false;
    }
    *orders = malloc((*numberOfOrders) * sizeof(struct Order));
    read(pipe[0], *orders, (*numberOfOrders) * sizeof(struct Order));
    return true;
}

void sendReceipt(int finishedOrders, int *pipe) {
    close(pipe[0]);
    // Write concatenated string and close writing end
    write(pipe[1], &finishedOrders, sizeof(int));
}

int receiveReceipt(int *pipe, int *finishedOrders) {
    close(pipe[1]);
    int result = read(pipe[0], finishedOrders, sizeof(int));
    if (result == 0) {
        return false;
    }
    return true;
}