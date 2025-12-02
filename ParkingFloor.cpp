#include "ParkingFloor.h"

ParkingFloor::ParkingFloor(int floorNo)
    : m_floorNo(floorNo) {}

void ParkingFloor::addSlot(const ParkingSlot &slot) {
    m_slots.push_back(slot);
}

ParkingSlot *ParkingFloor::findFreeSlot(SlotType type) {
    for (auto &slot : m_slots) {
        if (slot.getType() == type && slot.isAvailable()) {
            return &slot;
        }
    }
    return nullptr;
}


