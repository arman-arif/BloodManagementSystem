#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "MainMenu.h"
#include "AddDonor.h"

struct Donor {
    string donor_id;
    string donor_name;
    string blood_group;
    string contact_no;
    string address;
    string last_donation;
};

struct bloodRequest {
    string request_id;
    string paitent_name;
    string blood_group;
    string hospital_name;
    string contact_no;
    string cause;
};

string hellow="Hello, World!";

int main()
{
    MainMenu menu;
    menu.homeMenu();

    return 0;
}
