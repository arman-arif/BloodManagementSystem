#include "AddDonor.h"

AddDonor::AddDonor()
{

    system("cls");
    cout << endl << "Donor Name\t: ";
    cin >> donor_name;
    cout << endl << "Blood Group\t: ";
    cin >> blood_group;
    cout << endl << "Contact No\t: ";
    cin >> contact_no;
    cout << endl << "Address \t: ";
    cin >> address;
    cout << endl << "Last Donation Date: ";
    cin >> last_donation;
}
