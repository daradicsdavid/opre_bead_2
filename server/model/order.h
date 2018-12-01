#ifndef OP_BEAD_ORDER_H
#define OP_BEAD_ORDER_H

#include <time.h>

#define STR_LENGTH 50

struct Order {
    time_t time;
    char name[STR_LENGTH];
    char email[STR_LENGTH];
    char phone[STR_LENGTH];
    int performanceRequirement;
};

#endif //OP_BEAD_ORDER_H
