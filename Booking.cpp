#include "Booking.h"
#include "ParkingSlot.h"

Booking::Booking(int id, const Vehicle &vehicle, ParkingSlot *slot)
    : m_id(id), m_vehicle(vehicle), m_slot(slot) {
    m_startTime = std::time(nullptr);
    if (m_slot) {
        m_slot->occupy();
    }
}

int Booking::getId() const {
    return m_id;
}

ParkingSlot *Booking::getSlot() const {
    return m_slot;
}

const Vehicle &Booking::getVehicle() const {
    return m_vehicle;
}

std::time_t Booking::getStartTime() const {
    return m_startTime;
}

void Booking::close(std::time_t endTime, double amount) {
    m_endTime = endTime;
    m_amount = amount;
    if (m_slot) {
        m_slot->freeSlot();
    }
}

double Booking::getAmount() const {
    return m_amount;
}


