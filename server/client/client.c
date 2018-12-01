#include <signal.h>
#include <zconf.h>
#include <stdio.h>
#include "../communication/pipe.h"
#include "../model/order.h"
#include "../model/boolean.h"
#include "../print/print.h"
#include <malloc.h>
#include <stdlib.h>

void signalFromParent(int i) {
    fprintf(stderr, "Message from parent!!!\n");
    exit(0);
}

void startClient(int parentProcessId, int childToParent[2], int parentToChild[2]) {
    printf("Client started!\n");
    signal(SIGKILL, signalFromParent);
    while (true) {
        struct Order *orders = malloc(2 * sizeof(struct Order));
        int result = receiveOrders(orders, parentToChild);
        if (result) {
            printOrder(orders[0]);
            printOrder(orders[1]);
            kill(parentProcessId, SIGUSR1);
            free(orders);
        }
    }
}
