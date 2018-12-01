#include <stdio.h>
#include <string.h>
#include "../model/order.h"


void printOrder(struct Order order) {
    printf("Megrendelő: %s ,", order.name);
    printf("Email cím: %s ,", order.email);
    printf("Telefonszám : %s ,", order.phone);
    printf("Kért teljesítmény: %d ,", order.performanceRequirement);
    struct tm *timeInfo;
    timeInfo = localtime(&order.time);
    printf("Rendelés leadásának ideje: %s", asctime(timeInfo));
}

void printOrders(struct Order orders[], int orderNumber) {
    printf("\n");
    for (int i = 0; i < orderNumber; ++i) {
        printOrder(orders[i]);
    }
    printf("\n");
}

void printSelectOrder(struct Order orders[], int orderNumber) {
    if (orderNumber == 0) {
        printf("Jelenleg nincs rendelés a rendszerben!");
    }
    for (int i = 0; i < orderNumber; ++i) {
        printf("(%d) ", i);
        printOrder(orders[i]);
    }
    printf("Adja meg a kívánt rendelés sorszámát:");
}