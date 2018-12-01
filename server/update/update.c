#include "../model/order.h"
#include "../read/read.h"


void updateOrder(struct Order *order) {
    boolean updateNameAnswer = readYesNo("Szeretné megváltoztatni a nevét?\n");
    if (updateNameAnswer) {
        readName(order);
    }
    boolean updateEmailAnswer = readYesNo("Szeretné megváltoztatni az email címét?\n");
    if (updateEmailAnswer) {
        readEmail(order);
    }
    boolean updatePhoneAnswer = readYesNo("Szeretné megváltoztatni a telefonszámát?\n");
    if (updatePhoneAnswer) {
        readPhone(order);
    }
    boolean updatePerformanceRequirementAnswer = readYesNo(
            "Szeretné megváltoztatni a rendszer teljesítmény követelményét?\n");
    if (updatePerformanceRequirementAnswer) {
        readPerformanceRequirement(order);
    }
}
