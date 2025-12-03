#ifndef PARKINGSYSTEM_H
#define PARKINGSYSTEM_H

#include <memory>
#include <vector>
#include "ParkingLot.h"
#include "PricingStrategy.h"
#include "PaymentService.h"
#include "Booking.h"

class ParkingSystem {
public:
    explicit ParkingSystem(std::unique_ptr<PricingStrategy> strategy);

    Booking *bookSlot(const Vehicle &vehicle);
    Booking *findBooking(int id);
    void exitAndPay(int bookingId);

private:
    ParkingLot m_lot;
    std::unique_ptr<PricingStrategy> m_pricing;
    PaymentService m_payment;
    std::vector<Booking> m_bookings;
    int m_nextBookingId{1};

    void initializeDemoData();
};

#endif 


