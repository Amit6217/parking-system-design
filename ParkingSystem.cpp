#include "ParkingSystem.h"
#include <iostream>
#include <cmath>

ParkingSystem::ParkingSystem(std::unique_ptr<PricingStrategy> strategy)
    : m_pricing(std::move(strategy)) {
    initializeDemoData();
}

void ParkingSystem::initializeDemoData() {
    ParkingFloor floor1(1);
    floor1.addSlot(ParkingSlot(1, SlotType::CAR));
    floor1.addSlot(ParkingSlot(2, SlotType::CAR));
    floor1.addSlot(ParkingSlot(3, SlotType::BIKE));
    floor1.addSlot(ParkingSlot(4, SlotType::BIKE));
    m_lot.addFloor(floor1);
}

Booking *ParkingSystem::bookSlot(const Vehicle &vehicle) {
    ParkingSlot *slot = m_lot.findFreeSlot(vehicle.getType());
    if (slot == nullptr) {
        std::cout << "No free slot available for this vehicle type.\n";
        return nullptr;
    }

    m_bookings.emplace_back(m_nextBookingId++, vehicle, slot);
    Booking &booking = m_bookings.back();

    std::cout << "Slot " << slot->getId()
              << " booked. Booking ID: " << booking.getId() << '\n';

    return &booking;
}

Booking *ParkingSystem::findBooking(int id) {
    for (auto &booking : m_bookings) {
        if (booking.getId() == id) {
            return &booking;
        }
    }
    return nullptr;
}

void ParkingSystem::exitAndPay(int bookingId) {
    Booking *booking = findBooking(bookingId);
    if (booking == nullptr) {
        std::cout << "Booking not found.\n";
        return;
    }

    std::time_t end = std::time(nullptr);
    double hours = std::difftime(end, booking->getStartTime()) / 3600.0;
    if (hours < 0.5) {
        hours = 0.5; // minimum 30 minutes
    }

    double amount = m_pricing->calculateCharge(hours, booking->getVehicle().getType());

    if (m_payment.process(amount)) {
        booking->close(end, amount);
        std::cout << "Vehicle " << booking->getVehicle().getNumber()
                  << " exited. Amount paid: Rs. " << amount << "\n";
    }
}


