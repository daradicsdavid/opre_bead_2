#include <string.h>
#include <stdio.h>
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