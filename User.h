#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User
{
protected:
    string name;
    string email;
    string phone;

public:
    User();
    User(string name, string email, string phone);

    string getName();
    string getEmail();
    string getPhone();

    void setName(string name);
    void setEmail(string email);
    void setPhone(string phone);
};

#endif
