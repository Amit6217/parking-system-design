## Parking Management System (C++ OOAD Mini Project)

This is a simple **Parking Management System** implemented in **C++** for an Object Oriented Analysis and Design (OOAD) project.  
It demonstrates:

- **Use-Case Modeling**
- **Class Design**
- **Sequence Diagrams**
- **SOLID principles**
- **GRASP principles**
- **Design Pattern**

---

## Features

- **Book Slot**: User enters vehicle number and type (CAR / BIKE), system allocates a free slot and creates a booking ID.
- **Exit & Pay**: User enters booking ID at exit, system calculates charge based on parking duration and pricing strategy, then simulates payment.
- **Pricing Strategies**:
  - `HourlyPricingStrategy` – charges per hour with different rates for car and bike.
  - `FlatRatePricingStrategy` – same fixed price regardless of time.

---

## Project Structure

- `SlotType.h` – enum for `CAR` / `BIKE`.
- `Vehicle.h`, `Vehicle.cpp` – represents a vehicle.
- `ParkingSlot.h`, `ParkingSlot.cpp` – single parking slot.
- `ParkingFloor.h`, `ParkingFloor.cpp` – collection of slots on one floor.
- `ParkingLot.h`, `ParkingLot.cpp` – collection of floors.
- `PricingStrategy.h`, `PricingStrategy.cpp` – abstract pricing and concrete strategies (**Strategy Pattern**).
- `PaymentService.h`, `PaymentService.cpp` – simulates payment.
- `Booking.h`, `Booking.cpp` – ticket/booking for a parked vehicle.
- `ParkingSystem.h`, `ParkingSystem.cpp` – facade/controller that coordinates everything.
- `main.cpp` – console menu UI.
- `diagrams/` – UML images (use-case, class diagram, sequence diagrams).

---

## How to Compile (Windows, g++ / MinGW)

Open **PowerShell** in the project folder (for example `C:\Users\...\ooad`) and run a **single command line**:

```bash
g++ main.cpp Vehicle.cpp ParkingSlot.cpp ParkingFloor.cpp ParkingLot.cpp PricingStrategy.cpp PaymentService.cpp Booking.cpp ParkingSystem.cpp -o ParkingSystem.exe
```

To run the program:

```bash
./ParkingSystem.exe
```

---

## UML Diagrams

The project is accompanied by the following UML diagrams (stored under the `diagrams/` folder or generated from PlantUML text):

- **Use-Case Diagram** – shows actors (Driver, Admin, Payment Service) and use cases (Book Slot, Exit & Pay, Configure Parking).
- **Class Diagram** – shows all main classes and relationships (`ParkingSystem`, `ParkingLot`, `ParkingFloor`, `ParkingSlot`, `Vehicle`, `Booking`, `PricingStrategy`, `PaymentService`).
- **Sequence Diagrams**:
  - **Book Slot**
  - **Exit & Pay**

These diagrams correspond directly to the C++ classes and flows implemented in the code.

---

## Design Pattern: Strategy

- `PricingStrategy` is an **abstract base class** with `calculateCharge(hours, type)`.
- `HourlyPricingStrategy` and `FlatRatePricingStrategy` are **concrete strategies**.
- `ParkingSystem` keeps a `unique_ptr<PricingStrategy>` and delegates price calculation to it.

This allows you to change the pricing algorithm **without modifying** the rest of the system, which demonstrates the **Open/Closed Principle (OCP)** and good **low coupling / high cohesion**.

---

## How to Use the Program

1. **Start the program**:
   ```bash
   ./ParkingSystem.exe
   ```
2. Choose:
   - `1` – **Book Slot**
     - Enter vehicle number.
     - Enter vehicle type (1 = CAR, 2 = BIKE).
     - System prints booking ID and allocated slot.
   - `2` – **Exit & Pay**
     - Enter booking ID.
     - System calculates duration and charge, processes payment, and frees the slot.
   - `3` – Exit program.



