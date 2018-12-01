#include <stdio.h>

#include "../model/order.h"


int readFromFile(struct Order orders[]) {


    FILE *ptr = fopen("orders.dat", "rb");
    if (!ptr) return 0;

    int n = 0;
    for (n = 0; !feof(ptr); ++n) {
        if (fread(&orders[n], sizeof(struct Order), 1, ptr) != 1) break;
    }

    fclose(ptr);
    return n;
}

void writeToFile(struct Order orders[], int orderNumber) {
    FILE *ptr = fopen("orders.dat", "wb");
    if (!ptr) return;
    fwrite(orders, sizeof(struct Order), (size_t) orderNumber, ptr);
    fclose(ptr);
}