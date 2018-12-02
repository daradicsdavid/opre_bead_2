#include <signal.h>
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
    signal(SIGKILL, signalFromParent);
    while (1) {
        struct Order *orders;
        int numberOfOrders;
        int result = receiveOrders(&orders, parentToChild, &numberOfOrders);
        if (result) {
            for (int i = 0; i < numberOfOrders; ++i) {
                printOrder(orders[i]);
                kill(parentProcessId, SIGUSR1);
            }
            sendReceipt(numberOfOrders, childToParent);
            free(orders);
        } else {
            break;
        }
    }
}
