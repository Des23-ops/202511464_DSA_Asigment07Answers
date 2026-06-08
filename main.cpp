#include "Vehicle.h"
#include <iostream>
int main()
{
    Vehicle vehicle;

    int choice;

    do
    {
        cout<<"\t==VEHICLE REGISTRATION SYSTEM==";
        

        cout<<"\n\t\t1. Register Vehicle";
        cout<<"\n\t\t2. Display Vehicles";
        cout<<"\n\t\t3. Search Vehicle";
        cout<<"\n\t\t4. Exit";

        cout<<"\n\t\tChoice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                vehicle.registerVehicle();
                break;

            case 2:
                vehicle.showVehicleRegistry();
                break;

            case 3:
                vehicle.findVehicleByPlate();
                break;

            case 4:
                cout<<"\033[31mProgram Closed\033[0m\n";
                break;

            default:
                cout<<"Invalid Choice.\n";
        }

    }
	while(choice!=4);

    return 0;
}
