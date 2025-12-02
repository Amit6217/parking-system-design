#include "ParkingLot.h"

void ParkingLot::addFloor(const ParkingFloor &floor) {
    m_floors.push_back(floor);
}

ParkingSlot *ParkingLot::findFreeSlot(SlotType type) {
    for (auto &floor : m_floors) {
        ParkingSlot *slot = floor.findFreeSlot(type);
        if (slot != nullptr) {
            return slot;
        }
    }
    return nullptr;
}


