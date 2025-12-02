#include "ParkingSlot.h"

ParkingSlot::ParkingSlot(int id, SlotType type)
    : m_id(id), m_type(type), m_free(true) {}

bool ParkingSlot::isAvailable() const {
    return m_free;
}

void ParkingSlot::occupy() {
    m_free = false;
}

void ParkingSlot::freeSlot() {
    m_free = true;
}

int ParkingSlot::getId() const {
    return m_id;
}

SlotType ParkingSlot::getType() const {
    return m_type;
}


