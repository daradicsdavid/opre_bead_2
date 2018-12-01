#include <signal.h>
#include <stdio.h>
#include <zconf.h>
#include <malloc.h>
#include "communication/pipe.h"
#include "simulation/simulatedOrders.h"
#include "print/print.h"

void signalFromChild(int i) {
    signal(SIGUSR1, signalFromChild); /* reset signal */
    printf("Message from child!!!\n");
}

void startSimulationServer(int childPid, int *childToParent, int *parentToChild) {
    kill(childPid, SIGKILL);
    struct Order *orders = generateSimulatedOrders();
    struct Order *doneOrders[50];
    signal(SIGUSR1, signalFromChild);
    for (int i = 0; i < 4; ++i) {
        printf("Sending orders \n");
        sendOrders(orders, 2, parentToChild);
        sleep(3);
    }
    free(orders);
    kill(childPid, SIGKILL);
    printf("Child pid: %i \n", childPid);
}

