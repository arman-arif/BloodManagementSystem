#ifndef MAINMENU_H
#define MAINMENU_H
#include <iostream>
#include <cstdlib>
#include "AddDonor.h"
#include "RequestBlood.h"

using namespace std;

class MainMenu
{
    public:
        char choice;

        void navigation(char);
        void homeMenu(void);
        void managerMenu(void);
        void getChoice(void);

};

#endif // MAINMENU_H
