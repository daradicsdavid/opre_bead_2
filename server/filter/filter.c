#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "../model/order.h"
#include "../print/print.h"
#include "../model/boolean.h"

void filterOrdersByName(struct Order orders[], int orderNumber, char *nameFilter) {
    boolean found = false;
    for (int i = 0; i < orderNumber; ++i) {
        if (strstr(orders[i].name, nameFilter) != NULL) {
            if (!found) {
                printf("Keresés eredménye:\n");
            }
            printOrder(orders[i]);
            found = true;
        }
    }
    if (!found) {
        printf("\nNincs a követelménynek megfelelő találat.\n\n");
    } else {
        printf("\n");
    }

}

void filterOrdersByPerformanceRequirement(struct Order orders[], int orderNumber, int performanceRequirementFilter) {
    boolean found = false;
    for (int i = 0; i < orderNumber; ++i) {
        if (orders[i].performanceRequirement == performanceRequirementFilter) {
            if (!found) {
                printf("Keresés eredménye:\n");
            }
            printOrder(orders[i]);
            found = true;
        }
    }
    if (!found) {
        printf("\nNincs a követelménynek megfelelő találat.\n\n");
    } else {
        printf("\n");
    }
}

struct Order *selectOrdersToSend(struct Order *orders, int numberOfOrders, int *selectedOrdersSize) {
    (*selectedOrdersSize) = 0;
    struct Order *selected = malloc(numberOfOrders * sizeof(struct Order));
    int i = 0;
    time_t now;
    time(&now);
    while (i < numberOfOrders && (*selectedOrdersSize) < 2) {
        if ((*selectedOrdersSize) == 0) {
            selected[(*selectedOrdersSize)++] = orders[i];
        }
        if (difftime(now, orders[i].time) > 60 * 60 * 24 * 7) {
            selected[(*selectedOrdersSize)++] = orders[i];
        }
        i++;
    }
    return selected;
}