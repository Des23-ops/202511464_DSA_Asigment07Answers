#include "VehicleOwner.h"

VehicleOwner::VehicleOwner()
{
}

VehicleOwner::VehicleOwner(string name,
                           string email,
                           string phone)
    : User(name, email, phone)
{
}
