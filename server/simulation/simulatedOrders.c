#include <malloc.h>
#include <memory.h>
#include "../model/order.h"

struct Order *generateSimulatedOrders(int *numberOfOrders) {
    (*numberOfOrders) = 5;
    struct Order *orders = malloc((*numberOfOrders) * sizeof(struct Order));
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
    (orders + 1)->time -= 60 * 60 * 24 * 8;

    strcpy((orders + 2)->name, "name3");
    strcpy((orders + 2)->email, "email3");
    strcpy((orders + 2)->phone, "phone3");
    (orders + 2)->performanceRequirement = 3;
    time(&(orders + 2)->time);

    strcpy((orders + 3)->name, "name4");
    strcpy((orders + 3)->email, "email4");
    strcpy((orders + 3)->phone, "phone4");
    (orders + 3)->performanceRequirement = 4;
    time(&(orders + 3)->time);
    (orders + 3)->time -= 60 * 60 * 24 * 8;

    strcpy((orders + 4)->name, "name5");
    strcpy((orders + 4)->email, "email5");
    strcpy((orders + 4)->phone, "phone5");
    (orders + 4)->performanceRequirement = 5;
    time(&(orders + 4)->time);

    return orders;
}