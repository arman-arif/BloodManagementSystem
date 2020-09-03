#include "MainMenu.h"

//using namespace std;

void MainMenu::getChoice()
{
    cout << endl << " Enter your choice: ";
    cin >> choice;
    navigation(choice);
}

void MainMenu::navigation(char option)
{
    switch(option){
        case 'A':
        case '1':
        {
            AddDonor add;
            break;
        }
        case '2':
        {
            RequestBlood req;
            break;
        }

        case '3':
            cout << "Request List";
            break;
        case '4':
        case 'L':
            cout << "Donor List";
            break;
        case 'E':
            cout << "Edit Donor";
            break;
        case 'D':
            cout << "Delete Donor";
            break;
        case 'S':
            cout << "Search Donor";
            break;
        case 'H':
        {
            homeMenu();
            break;
        }
        case 'M':
        {
            managerMenu();
            break;
        }
        case 'Q':
        case 'q':
        case '0':
            exit(0);
            break;
        default:
        {
            cout << " Wrong input! Try again." << endl;
            getChoice();
        }

    }
}

void MainMenu::homeMenu()
{
    system("cls");
    extern string hellow;
    cout << hellow;
    cout << endl << " Welcome to Blood Bank Management System" << endl;

    cout << endl << " 1. Become a Donor";
    cout << endl << " 2. Request for Blood";
    cout << endl << " 3. See Blood Request List";
    cout << endl << " 4. See Blood Donor List" << endl;

    cout << endl << " M. Manage Blood Bank" << endl;

    cout << endl << " Q. Quit" << endl;

    getChoice();
}

void MainMenu::managerMenu()
{
    system("cls");
    cout << endl << " Welcome to Blood Bank Management System" << endl;

    cout << endl << " A. Add a Donor";
    cout << endl << " E. Edit Donor Info";
    cout << endl << " D. Delete a Donor";
    cout << endl << " L. See Blood Donor List";
    cout << endl << " S. Search Donor/View Info" << endl;

    cout << endl << " H. Home Menu" << endl;

    cout << endl << " Q. Quit" << endl;

    getChoice();
}
