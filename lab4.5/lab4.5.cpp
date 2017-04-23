//Created By: Benny Serrato
//Created On: 4/23/2017
//This program will create usernames using the user's name using strings

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(){
    string firstName;
    string lastName;
    
    cout << "Please enter your name in the order said." << endl;
    cout << "First Name:";
    cin >> firstName;
     while(firstName.length() > 10){
        cout << "Your first name is too big!" << endl; 
        cout << "Please type in a shorter name that contains atleast 10 letters."<< endl;
        cout << "First Name:";
        cin >> firstName;//prompts user to input their first name again 
    }
    cout << "Last Name: ";
    cin >> lastName;
    while(lastName.length() > 20){
        cout << "Your last name is too big!" << endl; 
        cout << "Please type in a shorter name that contains atleast 20 letters."<< endl;
        cout << "Last Name:";
        cin >> lastName;//prompts user to input their last name again
    }
    while(firstName == lastName){
        cout << "Sorry you cannot have the same name for your first and last name." << endl;
        cout << "First Name: ";
        cin >> firstName;//prompts user to input their first name again 
        while(firstName.length() > 10){
            cout << "Your first name is too big!" << endl; 
            cout << "Please type in a shorter name that contains atleast 10 letters."<< endl;
            cout << "First Name:";
            cin >> firstName;//prompts user to input their first name again 
        }
        cout << "Last Name: ";
        cin >> lastName;//prompts user to input their last name again
        while(lastName.length() > 20){
            cout << "Your last name is too big!" << endl; 
            cout << "Please type in a shorter name that contains atleast 20 letters."<< endl;
            cout << "Last Name:";
            cin >> lastName;//prompts user to input their last name again
        }
    }
     for(int i = 0; i < firstName.length(); i++){//Converts any upper case in the first name to lowercase for usernames
          firstName.at(i) = tolower(firstName.at(i));
    }
    for(int i = 0; i < lastName.length(); i++){//Converts any uppercase in the last name to lowercase for usernames
            lastName.at(i) = tolower(lastName.at(i));
    }
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << endl;
    cout << "Here are three names to choose from:" << endl;
    
    /*first of the user names*/
    cout << firstName.substr(0,2) <<lastName << endl;
    /*second of the user names*/
    cout << firstName << lastName << endl;
    /*third of the user names*/
    cout << firstName.at(0) <<lastName << endl;
    return 0;
}
    