#ifndef OP_BEAD_FILTER_H
#define OP_BEAD_FILTER_H

#include "../model/order.h"

void filterOrdersByName(struct Order orders[], int orderNumber, char *nameFilter);

void filterOrdersByPerformanceRequirement(struct Order orders[], int orderNumber, int performanceRequirementFilter);

#endif //OP_BEAD_FILTER_H
