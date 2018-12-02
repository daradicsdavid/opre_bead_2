#include <signal.h>
#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include "communication/pipe.h"
#include "simulation/simulatedOrders.h"
#include "print/print.h"
#include "filter/filter.h"
#include "delete/delete.h"
#include "file/file.h"

void signalFromChild(int i) {
    signal(SIGUSR1, signalFromChild); /* reset signal */
    printf("Child finished an order!\n");
}

void startSimulationServer(int childPid, int *childToParent, int *parentToChild) {
    int numberOfOrders = 0;
    struct Order *orders = generateSimulatedOrders(&numberOfOrders);
    struct Order doneOrders[50];
    int numberOfDoneOrders = readDoneOrdersFromFile(doneOrders);

    signal(SIGUSR1, signalFromChild);
    while (numberOfOrders > 0) {
        int selectedOrdersSize = 0;
        struct Order *ordersToSend = selectOrdersToSend(orders, numberOfOrders, &selectedOrdersSize);
        sendOrders(ordersToSend, selectedOrdersSize, parentToChild);
        int finishedOrders = 0;
        if (receiveReceipt(childToParent, &finishedOrders)) {
            if (finishedOrders == selectedOrdersSize) {
                deleteFinishedOrders(orders, &numberOfOrders, ordersToSend, finishedOrders, doneOrders,
                                     &numberOfDoneOrders);
            }
        }
        free(ordersToSend);

    }
    for (int i = 0; i < numberOfDoneOrders; ++i) {
        printOrder(doneOrders[i]);
    }
    writeDoneOrdersToFile(doneOrders, numberOfDoneOrders);
    free(orders);
    free(doneOrders);
    sleep(3);
    kill(childPid, SIGKILL);
}

