#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <vector>
#include "ParkingFloor.h"

class ParkingLot {
public:
    void addFloor(const ParkingFloor &floor);
    ParkingSlot *findFreeSlot(SlotType type);

private:
    std::vector<ParkingFloor> m_floors;
};

#endif // PARKINGLOT_H


