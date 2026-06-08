#include "Vehicle.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>

Vehicle::Vehicle()
{
}

Vehicle::Vehicle(string plateNumber,
                 string vehicleType,
                 int year,
                 VehicleOwner owner)
{
    this->plateNumber = plateNumber;
    this->vehicleType = vehicleType;
    this->year = year;
    this->owner = owner;
}

bool Vehicle::validEmail(string email)
{
    return email.find('@') != string::npos &&
           email.find('.') != string::npos;
}

bool Vehicle::validPhone(string phone)
{
    if(phone.length() != 13)
        return false;

    if(phone.substr(0,4) != "+250")
        return false;

    for(int i=4;i<13;i++)
    {
        if(!isdigit(phone[i]))
            return false;
    }

    return true;
}

bool Vehicle::validPlate(string plate)
{
    if(plate.length() != 7)
        return false;

    if(plate[0] != 'R')
        return false;

    return true;
}

void Vehicle::registerVehicle()
{
    string plate;
    string type;
    int year;
    string ownerName;
    string email;
    string phone;

    cout<<"\nPlate Number: ";
    cin>>plate;

    while(!validPlate(plate))
    {
        cout<<"Invalid Plate. Re-enter: ";
        cin>>plate;
    }

    cout<<"Vehicle Type: ";
    cin>>type;

    cout<<"Year: ";
    cin>>year;

    cout<<"Owner Name: ";
    cin.ignore();
    getline(cin,ownerName);

    cout<<"Email: ";
    getline(cin,email);

    while(!validEmail(email))
    {
        cout<<"Invalid Email. Re-enter: ";
        getline(cin,email);
    }

    cout<<"Phone: ";
    getline(cin,phone);

    while(!validPhone(phone))
    {
        cout<<"Invalid Phone. Re-enter: ";
        getline(cin,phone);
    }

    ofstream file("records.txt",ios::app);

    file<<plate<<","
        <<type<<","
        <<year<<","
        <<ownerName<<","
        <<email<<","
        <<phone
        <<endl;

    file.close();

    cout<<"\nRecord Saved Successfully.\n";
}

void Vehicle::showVehicleRegistry()
{
    ifstream file("records.txt");

    string line;

    cout<<left
        <<setw(12)<<"Plate"
        <<setw(15)<<"Type"
        <<setw(10)<<"Year"
        <<setw(20)<<"Owner"
        <<setw(25)<<"Email"
        <<setw(15)<<"Phone"
        <<endl;

    while(getline(file,line))
    {
        stringstream ss(line);

        string plate,type,year,owner,email,phone;

        getline(ss,plate,',');
        getline(ss,type,',');
        getline(ss,year,',');
        getline(ss,owner,',');
        getline(ss,email,',');
        getline(ss,phone,',');

        cout<<left
            <<setw(12)<<plate
            <<setw(15)<<type
            <<setw(10)<<year
            <<setw(20)<<owner
            <<setw(25)<<email
            <<setw(15)<<phone
            <<endl;
    }

    file.close();
}

void Vehicle::findVehicleByPlate()
{
    string target;

    cout<<"\nEnter Plate Number: ";
    cin>>target;

    ifstream file("records.txt");

    string line;

    bool found=false;

    while(getline(file,line))
    {
        stringstream ss(line);

        string plate;

        getline(ss,plate,',');

        if(plate==target)
        {
            cout<<"\nRecord is found:\n";
            cout<<line<<endl;

            found=true;
        }
    }

    file.close();

    if(!found)
    {
        cout<<"\nVehicle is Not Found.\n";
    }
}
