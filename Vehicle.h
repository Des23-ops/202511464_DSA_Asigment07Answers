#ifndef vehicle_h
#define vehicle_h

#include "VehicleOwner.h"
#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
private:
    string plateNumber;
    string vehicleType;
    int year;

    VehicleOwner owner;

public:
    Vehicle();

    Vehicle(string plateNumber,
            string vehicleType,
            int year,
            VehicleOwner owner);

    void registerVehicle();

    void showVehicleRegistry();

    void findVehicleByPlate();

    bool validEmail(string email);

    bool validPhone(string phone);

    bool validPlate(string plate);
};

#endif
