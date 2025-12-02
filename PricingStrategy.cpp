#include "PricingStrategy.h"

HourlyPricingStrategy::HourlyPricingStrategy(double carRatePerHour, double bikeRatePerHour)
    : m_carRatePerHour(carRatePerHour), m_bikeRatePerHour(bikeRatePerHour) {}

double HourlyPricingStrategy::calculateCharge(double hours, SlotType type) {
    if (type == SlotType::CAR) {
        return hours * m_carRatePerHour;
    }
    return hours * m_bikeRatePerHour;
}

FlatRatePricingStrategy::FlatRatePricingStrategy(double flatRate)
    : m_flatRate(flatRate) {}

double FlatRatePricingStrategy::calculateCharge(double, SlotType) {
    return m_flatRate;
}


