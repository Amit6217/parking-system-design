#ifndef PRICINGSTRATEGY_H
#define PRICINGSTRATEGY_H

#include "SlotType.h"

class PricingStrategy {
public:
    virtual ~PricingStrategy() = default;
    virtual double calculateCharge(double hours, SlotType type) = 0;
};

class HourlyPricingStrategy : public PricingStrategy {
public:
    HourlyPricingStrategy(double carRatePerHour, double bikeRatePerHour);
    double calculateCharge(double hours, SlotType type) override;

private:
    double m_carRatePerHour;
    double m_bikeRatePerHour;
};

class FlatRatePricingStrategy : public PricingStrategy {
public:
    explicit FlatRatePricingStrategy(double flatRate);
    double calculateCharge(double hours, SlotType type) override;

private:
    double m_flatRate;
};

#endif // PRICINGSTRATEGY_H


