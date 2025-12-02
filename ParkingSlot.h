#ifndef PARKINGSLOT_H
#define PARKINGSLOT_H

#include "SlotType.h"

class ParkingSlot {
public:
    ParkingSlot(int id, SlotType type);

    bool isAvailable() const;
    void occupy();
    void freeSlot();

    int getId() const;
    SlotType getType() const;

private:
    int m_id;
    SlotType m_type;
    bool m_free;
};

#endif // PARKINGSLOT_H


