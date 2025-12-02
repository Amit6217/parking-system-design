#include "PaymentService.h"
#include <iostream>

using namespace std;

bool PaymentService::process(double amount) {
    cout << "Processing payment of Rs. " << amount << "...\n";
    cout << "Payment successful.\n";
    return true;
}



