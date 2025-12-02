#include <iostream>
#include <memory>
#include "ParkingSystem.h"

int main() {
    // Choose pricing strategy: hourly or flat
    std::unique_ptr<PricingStrategy> strategy =
        std::make_unique<HourlyPricingStrategy>(50.0, 20.0); // Rs/hr

    ParkingSystem system(std::move(strategy));

    while (true) {
        std::cout << "\n=== Parking System Menu ===\n";
        std::cout << "1. Book Slot\n";
        std::cout << "2. Exit & Pay\n";
        std::cout << "3. Exit Program\n";
        std::cout << "Enter choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int typeInput;
            std::string number;

            std::cout << "Enter vehicle number: ";
            std::cin >> number;
            std::cout << "Enter type (1=CAR, 2=BIKE): ";
            std::cin >> typeInput;

            SlotType type = (typeInput == 1) ? SlotType::CAR : SlotType::BIKE;
            Vehicle vehicle(number, type);
            system.bookSlot(vehicle);
        } else if (choice == 2) {
            int id;
            std::cout << "Enter booking ID: ";
            std::cin >> id;
            system.exitAndPay(id);
        } else {
            break;
        }
    }

    return 0;
}


