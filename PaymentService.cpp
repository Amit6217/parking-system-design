#include "PaymentService.h"
#include <iostream>

bool PaymentService::process(double amount) {
    std::cout << "Processing payment of Rs. " << amount << "...\n";
    std::cout << "Payment successful.\n";
    return true;
}


