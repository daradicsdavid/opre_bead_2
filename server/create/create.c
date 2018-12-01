#include "../model/order.h"
#include "../read/read.h"

void readOrder(struct Order *order) {
    readName(order);
    readEmail(order);
    readPhone(order);
    readPerformanceRequirement(order);
    time(&order->time);
}

void createOrder(struct Order orders[], int *orderNumber) {
    struct Order order;
    readOrder(&order);
    orders[*orderNumber] = order;
    (*orderNumber)++;

}


