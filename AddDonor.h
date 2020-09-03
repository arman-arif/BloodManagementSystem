#ifndef ADDDONOR_H
#define ADDDONOR_H
#include <iostream>
#include <cstdlib>

using namespace std;

class AddDonor
{
    public:
        AddDonor();

    private:
        string donor_name;
        string blood_group;
        string contact_no;
        string address;
        string last_donation;
};

#endif // ADDDONOR_H
