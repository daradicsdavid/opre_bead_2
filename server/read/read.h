#ifndef OP_BEAD_READ_H
#define OP_BEAD_READ_H

#include "../model/order.h"
#include "../model/boolean.h"


int readString(char str[]);

void readInt(int *integer);

boolean readYesNo(char *question);

void readName(struct Order *order);

void readEmail(struct Order *order);

void readPhone(struct Order *order);

void readPerformanceRequirement(struct Order *order);

#endif //OP_BEAD_READ_H
