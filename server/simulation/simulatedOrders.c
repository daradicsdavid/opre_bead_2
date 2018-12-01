#include <malloc.h>
#include <memory.h>
#include "../model/order.h"

struct Order *generateSimulatedOrders() {
    struct Order *orders = malloc(2 * sizeof(struct Order));
    strcpy((orders + 0)->name, "name1");
    strcpy((orders + 0)->email, "email1");
    strcpy((orders + 0)->phone, "phone1");
    (orders + 0)->performanceRequirement = 1;
    time(&(orders + 0)->time);

    strcpy((orders + 1)->name, "name2");
    strcpy((orders + 1)->email, "email2");
    strcpy((orders + 1)->phone, "phone2");
    (orders + 1)->performanceRequirement = 2;
    time(&(orders + 1)->time);
    return orders;
}