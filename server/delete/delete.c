#include "../model/order.h"


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