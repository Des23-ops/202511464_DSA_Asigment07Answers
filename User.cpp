#include "User.h"

User::User()
{
}

User::User(string name, string email, string phone)
{
    this->name = name;
    this->email = email;
    this->phone = phone;
}

string User::getName()
{
    return name;
}

string User::getEmail()
{
    return email;
}

string User::getPhone()
{
    return phone;
}

void User::setName(string name)
{
    this->name = name;
}

void User::setEmail(string email)
{
    this->email = email;
}

void User::setPhone(string phone)
{
    this->phone = phone;
}
