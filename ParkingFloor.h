#ifndef PARKINGFLOOR_H
#define PARKINGFLOOR_H

#include <vector>
#include "ParkingSlot.h"

class ParkingFloor {
public:
    explicit ParkingFloor(int floorNo);

    void addSlot(const ParkingSlot &slot);
    ParkingSlot *findFreeSlot(SlotType type);

private:
    int m_floorNo;
    std::vector<ParkingSlot> m_slots;
};

#endif // PARKINGFLOOR_H


