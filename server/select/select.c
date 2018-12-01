#include "../model/order.h"
#include "../print/print.h"
#include "../read/read.h"

int selectOrder(struct Order orders[], int orderNumber) {
    printSelectOrder(orders, orderNumber);
    int selectedOrderNumber;
    readInt(&selectedOrderNumber);
    if (selectedOrderNumber < 0 || selectedOrderNumber > orderNumber - 1) {
        return 0;
    }
    return selectedOrderNumber;
}