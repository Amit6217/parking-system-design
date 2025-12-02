#include "Vehicle.h"

Vehicle::Vehicle(const std::string &number, SlotType type)
    : m_number(number), m_type(type) {}

const std::string &Vehicle::getNumber() const {
    return m_number;
}

SlotType Vehicle::getType() const {
    return m_type;
}


