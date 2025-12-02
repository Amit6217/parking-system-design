#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "SlotType.h"

class Vehicle {
public:
    Vehicle(const std::string &number, SlotType type);

    const std::string &getNumber() const;
    SlotType getType() const;

private:
    std::string m_number;
    SlotType m_type;
};

#endif // VEHICLE_H


