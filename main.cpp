// BloodBankManagementSystem.cpp : This file contains the 'main' function.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <string>

using namespace std;

struct Donor {
    int id;
    string name;
    string blood_group;
    string contact_no;
    string address;
    string last_donation;
};

struct BloodRequest {
    int id;
    string paitent_name;
    string blood_group;
    string hospital_loc;
    string contact_no;
    string condition;
};

char choice;

void getChoice(void);
void navigation(char);
void homeMenu(void);
void managerMenu(void);
void addDonor();
void requestBlood();
void requestList();
void donorList();
void editDonor();
void deleteDonor();
void deleteRequest();
void searchDonor();
int autoDonorId();
void writeDonorId(int);
int autoRequestId();
void writeRequestId(int);

int main() {
    while(true){
        homeMenu();
    }

    return 0;
}

void getChoice() {
    cout << endl << " Enter your choice: ";
    choice = getch();
    navigation(choice);
}

void navigation(char option) {
    switch (option) {//option=1
        case 'A':
        case 'a':
        case '1':
        {
            addDonor();
            break;
        }
        case '2':
        {
            requestBlood();
            break;
        }
        case '3':
            requestList();
            break;
        case '4':
        case 'L':
        case 'l':
            donorList();
            break;
        case 'E':
        case 'e':
            editDonor();
            break;
        case 'D':
        case 'd':
            deleteDonor();
            break;
        case 'R':
        case 'r':
            deleteRequest();
            break;
        case 'S':
        case 's':
            searchDonor();
            break;
        case 'H':
        case 'h':
        {
            homeMenu();
            break;
        }
        case 'M':
        case 'm':
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

void homeMenu() {
    system("cls");

    cout << endl << " Welcome to Blood Bank Management System" << endl;

    cout << endl << " 1. Become a Donor";
    cout << endl << " 2. Request for Blood";
    cout << endl << " 3. See Blood Request List";
    cout << endl << " 4. See Blood Donor List" << endl;

    cout << endl << " M. Manage Blood Bank" << endl;

    cout << endl << " Q. Quit" << endl;

    getChoice();
}

void managerMenu() {
    system("cls");
    cout << endl << " Welcome to Blood Bank Management System" << endl;

    cout << endl << " A. Add a Donor";
    cout << endl << " E. Edit Donor Info";
    cout << endl << " D. Delete a Donor";
    cout << endl << " R. Delete a Request";
    cout << endl << " L. See Blood Donor List";
    cout << endl << " S. Search Donor/View Info" << endl;

    cout << endl << " H. Home Menu" << endl;

    cout << endl << " Q. Quit" << endl;

    getChoice();
}

int autoDonorId(){
    FILE* donorId;
    donorId=fopen("DonorLastId.txt","r");
    int lastId;
    fscanf(donorId,"%d",&lastId);
    fclose(donorId);
    return lastId;
}

int autoRequestId(){
    FILE* donorId;
    donorId=fopen("LastRequestId.txt","r");
    int lastId;
    fscanf(donorId,"%d",&lastId);
    fclose(donorId);
    return lastId;
}

void writeDonorId(int lastId){
    FILE* donorId;
    donorId=fopen("DonorLastId.txt","w");
    fprintf(donorId,"%d",lastId);
    fclose(donorId);
}

void writeRequestId(int lastId){
    FILE* donorId;
    donorId=fopen("LastRequestId.txt","w");
    fprintf(donorId,"%d",lastId);
    fclose(donorId);
}

void addDonor() {
    int autoId=autoDonorId();
    struct Donor donor;
    donor.id=autoId++;

    system("cls");
    cout << endl << "Input Donor information (No White Space Accepted)" << endl;
    cout << "\nDonor ID (auto)\t: " << donor.id;
    cout << "\nDonor Name\t: ";
    cin >> donor.name;
    cout << "Blood Group\t: ";
    cin >> donor.blood_group;
    cout << "Contact No\t: ";
    cin >> donor.contact_no;
    cout << "Address \t: ";
    cin >> donor.address;
    cout << "Last Donation Date: ";
    cin >> donor.last_donation;

    FILE* donorFile;
    donorFile=fopen("Donors.txt","a");
    if(donorFile==NULL){
        cout<<"Error in File Opening";
    }

    if(fprintf(donorFile,"%d %s %s %s %s %s\n",donor.id,donor.name.c_str(),donor.blood_group.c_str(),donor.contact_no.c_str(),donor.address.c_str(),donor.last_donation.c_str())){
        fclose(donorFile);
        writeDonorId(autoId);
    }

    system("cls");
    cout << endl << "* New donor information is saved maintaining the format below." << endl;
    cout << endl << " " << donor.id << " " << donor.name << " " << donor.blood_group << " " << donor.contact_no << " " << donor.address << " " << donor.last_donation << endl;
    cout << endl << endl << "> Pressing any key will take you to HOME MENU...";
    getch();

}

void requestBlood() {
    int autoId=autoRequestId();

    struct BloodRequest br;
    br.id = autoId++;

    system("cls");
    cout << endl << "Input Paitent information (No White Space Accepted)" << endl;
    cout << "\nRequest ID\t: " << br.id << endl;
    cout << "Paitent Name\t: ";
    cin >> br.paitent_name;
    cout << "Blood Group\t: ";
    cin >> br.blood_group;
    cout << "Contact No\t: ";
    cin >> br.contact_no;
    cout << "Hospital Location : ";
    cin >> br.hospital_loc;
    cout << "Paitent Condition : ";
    cin >> br.condition;

    FILE* requestFile;
    requestFile=fopen("BloodRequest.txt","a");
    if(requestFile==NULL){
        cout<<"Error in File Opening";
    }

    if(fprintf(requestFile,"%d %s %s %s %s %s\n",br.id,br.paitent_name.c_str(),br.blood_group.c_str(),br.contact_no.c_str(),br.hospital_loc.c_str(),br.condition.c_str())){
        fclose(requestFile);
        writeRequestId(autoId);
    }

    system("cls");
    cout << endl << "* New request information is saved maintaining the format below." << endl;
    cout << endl << " " << br.id << " " << br.paitent_name << " " << br.blood_group << " " << br.contact_no << " " << br.hospital_loc << " " << br.condition << endl;
    cout << endl << endl << "> Pressing any key will take you to HOME MENU...";
    getch();

}

void requestList(){
    system("cls");

    FILE* requestFile;
    requestFile=fopen("BloodRequest.txt","r");
    if(requestFile==NULL){
        cout<<"Error in File Opening";
    }

    struct BloodRequest br[100];

    cout << endl << " Request Info Template:\n ID PaitentName BloodGroup ContactNo HospitalLocation Condition \n";
    cout << endl << " Blood Request List" << endl << " ==================\n" << endl;
    int i=0;
    while(fscanf(requestFile,"%d %s %s %s %s %s\n",&br[i].id,br[i].paitent_name.c_str(),br[i].blood_group.c_str(),br[i].contact_no.c_str(),br[i].hospital_loc.c_str(),br[i].condition.c_str())!=EOF){
        cout << " " << br[i].id << " " << br[i].paitent_name.c_str() << " " << br[i].blood_group.c_str() << " " << br[i].contact_no.c_str() << " " << br[i].hospital_loc.c_str() << " " << br[i].condition.c_str() << endl;
        i++;
    }

    fclose(requestFile);
    getch();

}

void donorList(){
    system("cls");

    FILE* donorFile;
    donorFile=fopen("Donors.txt","r");
    if(donorFile==NULL){
        cout<<"Error in File Opening";
    }

    struct Donor donor[100];

    cout << endl << " Donor Info Template:\n ID Name BloodGroup ContactNo Address LastDonation \n";
    cout << endl << " Registered Donor List" << endl << " =====================\n" << endl;
    int i=0;
    while(fscanf(donorFile,"%d %s %s %s %s %s\n",&donor[i].id,donor[i].name.c_str(),donor[i].blood_group.c_str(),donor[i].contact_no.c_str(),donor[i].address.c_str(),donor[i].last_donation.c_str())!=EOF){
        cout << " " << donor[i].id << " " << donor[i].name.c_str() << " " << donor[i].blood_group.c_str() << " " << donor[i].contact_no.c_str() << " " << donor[i].address.c_str() << " " << donor[i].last_donation.c_str() << endl;
        i++;
    }

    fclose(donorFile);
    getch();
}

void editDonor(){
    system("cls");

    FILE* donorFile;
    FILE* tempFile;
    donorFile=fopen("Donors.txt","r");
    tempFile=fopen("TEMP.txt","a");
    if(donorFile==NULL){
        cout<<"Error in File Opening";
    }

    int donorId,flag=0;
    cout << "Edit Donor" << endl;
    cout << "Enter Donor ID:" << " ";
    cin >> donorId;

    struct Donor donor[100];

    int i=0;
    while(fscanf(donorFile,"%d %s %s %s %s %s\n",&donor[i].id,donor[i].name.c_str(),donor[i].blood_group.c_str(),donor[i].contact_no.c_str(),donor[i].address.c_str(),donor[i].last_donation.c_str())!=EOF){
        if(donor[i].id==donorId){
            cout << endl << "Donor Template\t: ID Name BloodGroup ContactNo Address LastDonation";
            cout << endl << "Donor Old Info\t:";
            cout << " " << donor[i].id << " " << donor[i].name.c_str() << " " << donor[i].blood_group.c_str() << " " << donor[i].contact_no.c_str() << " " << donor[i].address.c_str() << " " << donor[i].last_donation.c_str() << endl;
            cout << "Input New Info\t: " << donor[i].id << " ";
            cin >> donor[i].name >> donor[i].blood_group >> donor[i].contact_no >> donor[i].address >> donor[i].last_donation;
            fprintf(tempFile,"%d %s %s %s %s %s\n",donor[i].id,donor[i].name.c_str(),donor[i].blood_group.c_str(),donor[i].contact_no.c_str(),donor[i].address.c_str(),donor[i].last_donation.c_str());
            flag=1;
        } else {
            fprintf(tempFile,"%d %s %s %s %s %s\n",donor[i].id,donor[i].name.c_str(),donor[i].blood_group.c_str(),donor[i].contact_no.c_str(),donor[i].address.c_str(),donor[i].last_donation.c_str());
        }
        i++;
    }
    fclose(tempFile);
    fclose(donorFile);

    if(flag==0){
        cout << endl << "No match data found" << endl;
        getch();
    } else {
        cout << endl << "Data modified successfully" << endl;
        getch();
    }

    remove("Donors.txt");
    rename("TEMP.txt","Donors.txt");
}

void deleteDonor(){
    system("cls");

    FILE* donorFile;
    FILE* tempFile;
    donorFile=fopen("Donors.txt","r");
    tempFile=fopen("TEMP.txt","a");
    if(donorFile==NULL){
        cout<<"Error in File Opening";
    }

    int donorId,flag=0;
    cout << "Delete Donor" << endl;
    cout << "Enter Donor ID:" << " ";
    cin >> donorId;

    struct Donor donor[100];

    int i=0;
    while(fscanf(donorFile,"%d %s %s %s %s %s\n",&donor[i].id,donor[i].name.c_str(),donor[i].blood_group.c_str(),donor[i].contact_no.c_str(),donor[i].address.c_str(),donor[i].last_donation.c_str())!=EOF){
        if(donor[i].id==donorId){
            cout << endl << "Donor Info\t:";
            cout << " " << donor[i].id << " " << donor[i].name.c_str() << " " << donor[i].blood_group.c_str() << " " << donor[i].contact_no.c_str() << " " << donor[i].address.c_str() << " " << donor[i].last_donation.c_str() << endl;

            flag=1;
        } else {
            fprintf(tempFile,"%d %s %s %s %s %s\n",donor[i].id,donor[i].name.c_str(),donor[i].blood_group.c_str(),donor[i].contact_no.c_str(),donor[i].address.c_str(),donor[i].last_donation.c_str());
        }
        i++;
    }
    fclose(tempFile);
    fclose(donorFile);

    if(flag==0){
        cout << endl << "No match data found" << endl;
        getch();
    } else {
        cout << endl << "Data deleted successfully" << endl;
        getch();
    }

    remove("Donors.txt");
    rename("TEMP.txt","Donors.txt");
}

void searchDonor(){
    system("cls");

    FILE* donorFile;
    donorFile=fopen("Donors.txt","r");
    if(donorFile==NULL){
        cout<<"Error in File Opening";
    }

    string sword;
    int flag=0;
    cout << "Search Donor (by ID/Name/Address/Blood Group)" << endl << "[No white space is allowed]" << endl;
    cout << endl << "Enter Search Keyword: ";
    cin >> sword;

    struct Donor donor[100];

    int i=0;
    cout << endl << "Donor Info" << endl << "==========" << endl;
    while(fscanf(donorFile,"%d %s %s %s %s %s\n",&donor[i].id,donor[i].name.c_str(),donor[i].blood_group.c_str(),donor[i].contact_no.c_str(),donor[i].address.c_str(),donor[i].last_donation.c_str())!=EOF){
        if(to_string(donor[i].id)==sword || donor[i].name.c_str()==sword || donor[i].address.c_str()==sword || donor[i].blood_group.c_str()==sword){

            cout << endl << "Donor ID \t: " << donor[i].id << endl;
            cout << "Donor Name \t: " << donor[i].name.c_str() << endl;
            cout << "Blood Group \t: " << donor[i].blood_group.c_str() << endl;
            cout << "Contact No \t: " << donor[i].contact_no.c_str() << endl;
            cout << "Address \t: " << donor[i].address.c_str() << endl;
            cout << "Last Donation \t: " << donor[i].last_donation.c_str() << endl;

            flag=1;
        }
        i++;
    }
    fclose(donorFile);

    if(flag==0){
        cout << endl << "No match data found" << endl;
        getch();
    } else {
        cout << endl << "Search completed." << endl << "Press any key to continue...";
        getch();
    }

}

void deleteRequest(){
    system("cls");

    FILE* requestFile;
    requestFile=fopen("BloodRequest.txt","r");
    if(requestFile==NULL){
        cout<<"Error in File Opening";
    }
    FILE* tempFile;
    tempFile=fopen("TEMP.txt","a");

    int reqId,flag=0;
    cout << "Delete Blood Request" << endl;
    cout << "Enter Request ID:" << " ";
    cin >> reqId;

    struct BloodRequest br[100];

    int i=0;
    while(fscanf(requestFile,"%d %s %s %s %s %s\n",&br[i].id,br[i].paitent_name.c_str(),br[i].blood_group.c_str(),br[i].contact_no.c_str(),br[i].hospital_loc.c_str(),br[i].condition.c_str())!=EOF){
        if(br[i].id==reqId){
            cout << endl << "Donor Info\t:";
            cout << " " << br[i].id << " " << br[i].paitent_name.c_str() << " " << br[i].blood_group.c_str() << " " << br[i].contact_no.c_str() << " " << br[i].hospital_loc.c_str() << " " << br[i].condition.c_str() << endl;

            flag=1;
        } else {
            fprintf(tempFile,"%d %s %s %s %s %s\n",br[i].id,br[i].paitent_name.c_str(),br[i].blood_group.c_str(),br[i].contact_no.c_str(),br[i].hospital_loc.c_str(),br[i].condition.c_str());
        }
        i++;
    }
    fclose(tempFile);
    fclose(requestFile);

    if(flag==0){
        cout << endl << "No match data found" << endl;
        getch();
    } else {
        cout << endl << "Data deleted successfully" << endl;
        getch();
    }

    remove("BloodRequest.txt");
    rename("TEMP.txt","BloodRequest.txt");
}



