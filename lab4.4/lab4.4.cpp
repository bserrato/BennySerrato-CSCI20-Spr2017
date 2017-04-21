//Created By: Benny Serrato
//Created On: 4/20/17
//This program will create usernames using the user's name

#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

int main(){
    const int FIRST_NAME = 10;//size of the cstring for first name
    const int LAST_NAME = 20;//size of the cstring for last name
    char firstName[FIRST_NAME];//cstring for the first name
    char lastName[LAST_NAME];//cstring for the last name
    char storeName[2];//will store the first two letters of the first name
    int stringLength = 0;//will store the amount of characters in the first and last names
    cout << "Please enter your name in the order said." << endl;
    
    cout << "First Name:";
    cin >> firstName;//user entering their first name
    stringLength = strlen(firstName);//Amount of character in the first name
    while(stringLength > FIRST_NAME){//check if the name fits inside the cstring if not it will prompt user to enter a name again
        cout << "Your first name is too big!" << endl; 
        cout << "Please type in a shorter name that contains atleast 10 letters."<< endl;
        cout << "First Name:";
        cin >> firstName;//user reentering their first name
        stringLength = strlen(firstName);//determines if the name is to large for the cstring
    }
    cout << "Last Name: ";
    cin >> lastName;
    stringLength = strlen(lastName);
    while(stringLength > LAST_NAME){//check if the name fits inside the c string
        cout << "Your last name is too big!" << endl; 
        cout << "Please type in a shorter name that contains atleast 20 letters."<< endl;
        cout << "Last Name:";
        cin >> lastName;//user reentering their last name
        stringLength = strlen(lastName);//determines if the name is to large for the cstring
    }
    cout << endl;
    while(strcmp(firstName, lastName) == 0){
        cout << "Sorry you cannot have the same name for your first and last name." << endl;
        cout << "First Name: ";
        cin >> firstName;//user reentering their first name
        stringLength = strlen(firstName);//determines if the name is to large for the cstring
        while(stringLength > FIRST_NAME){//check if the name fits inside the c string
            cout << "Your first name is too big!" << endl; 
            cout << "Please type in a shorter name that contains atleast 10 letters."<< endl;
            cout << "First Name:";
            cin >> firstName;//user reentering their first name
            stringLength = strlen(firstName);//determines if the name is to large for the cstring
        }
        cout << "Last Name: ";
        cin >> lastName;
        stringLength = strlen(lastName);
        while(stringLength > FIRST_NAME){//check if the name fits inside the c string
            cout << "Your last name is too big!" << endl; 
            cout << "Please type in a shorter name that contains atleast 20 letters."<< endl;
            cout << "Last Name:";
            cin >> lastName;//user reentering their last name
            stringLength = strlen(lastName);//determines if the name is to large for the cstring
        }
    }
    for(int i = 0; i < FIRST_NAME ; i++){//Converts any upper case in the first name to lowercase for usernames
          firstName[i] = tolower(firstName[i]);
    }
    for(int i = 0; i < LAST_NAME; i++){//Converts any uppercase in the last name to lowercase for usernames
            lastName[i] = tolower(lastName[i]);
    }
    for(int i = 0; i < 2; i++){//stores the first two letters of the first name for user name purposes
        storeName[i] = firstName[i];
    }
    
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << endl;
    cout << "Here are three names to choose from:" << endl;
    /* first of the user names*/
    cout << storeName << lastName << endl;
    /* second of the user names*/
    cout << firstName << lastName << endl;
    /*Third of the user names */
    cout << storeName[0] <<  lastName << endl;
    
    return 0;
}