#ifndef BOOKING_H
#define BOOKING_H

#include <ctime>
#include "Vehicle.h"

class ParkingSlot;

class Booking {
public:
    Booking(int id, const Vehicle &vehicle, ParkingSlot *slot);

    int getId() const;
    ParkingSlot *getSlot() const;
    const Vehicle &getVehicle() const;

    std::time_t getStartTime() const;
    void close(std::time_t endTime, double amount);
    double getAmount() const;

private:
    int m_id;
    Vehicle m_vehicle;
    ParkingSlot *m_slot;
    std::time_t m_startTime;
    std::time_t m_endTime{};
    double m_amount{};
};

#endif // BOOKING_H


