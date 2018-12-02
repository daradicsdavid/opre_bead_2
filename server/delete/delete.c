#include <memory.h>
#include <stdio.h>
#include "../model/order.h"
#include "../print/print.h"


void deleteOrder(struct Order orders[], int *orderNumber, int deleteIndex) {
    int j = 0;
    for (int i = 0; i < *orderNumber; i++) {
        if (deleteIndex == i) {
            continue;
        }
        orders[j] = orders[i];
        j++;
    }
    (*orderNumber)--;
}

void deleteFinishedOrders(struct Order orders[], int *numberOfOrders, struct Order finishedOrders[],
                          int numberOfFinishedOrders, struct Order doneOrders[], int *numberOfDoneOrders) {
    for (int i = 0; i < numberOfFinishedOrders; ++i) {
        int indexToDelete = -1;
        for (int j = 0; j < *numberOfOrders; ++j) {
            if (strcmp(finishedOrders[i].name, orders[j].name) == 0) {
                indexToDelete = j;
            }
        }
        if (indexToDelete != -1) {
            doneOrders[(*numberOfDoneOrders)] = orders[indexToDelete];
            (*numberOfDoneOrders)++;
            deleteOrder(orders, numberOfOrders, indexToDelete);
        }
    }

    printf("After delete!\n");
    printf("%i \n", *numberOfOrders);
}