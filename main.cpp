#include <iostream>
#include <memory>
#include "ParkingSystem.h"

using namespace std;

int main() {
    // Choose pricing strategy: hourly or flat
    unique_ptr<PricingStrategy> strategy =
        make_unique<HourlyPricingStrategy>(50.0, 20.0); // Rs/hr

    ParkingSystem system(move(strategy));

    while (true) {
        cout << "\n=== Parking System Menu ===\n";
        cout << "1. Book Slot\n";
        cout << "2. Exit & Pay\n";
        cout << "3. Exit Program\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            int typeInput;
            string number;

            cout << "Enter vehicle number: ";
            cin >> number;
            cout << "Enter type (1=CAR, 2=BIKE): ";
            cin >> typeInput;

            SlotType type = (typeInput == 1) ? SlotType::CAR : SlotType::BIKE;
            Vehicle vehicle(number, type);
            system.bookSlot(vehicle);
        } else if (choice == 2) {
            int id;
            cout << "Enter booking ID: ";
            cin >> id;
            system.exitAndPay(id);
        } else {
            break;
        }
    }

    return 0;
}



