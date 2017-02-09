//Created By:Benny Serrato
//Created On: 2/5/17
//This program will convert the inputed coins into cash and charge a percentage of the amount inserted as a fee

#include <iostream>
using namespace std;

int main(){
    double percentageFee = .109; //the percentage taken as fee
    int userInsert = 0; //the amount of coins inserted into the machine
    int inQuarters = 0; //Calculate how much quarters the User inputed
    int inDimes = 0; //Calculate how much dimes the User inputed
    int inNickels = 0; //Calculate how much nickels the User inputed
    int inPennies = 0; //Calculate how much pennies the User inputed
    double cashBack = 0.0; //Calculating final amount given to User
    double moneyConversion = 0; //converting the cents into a decimal 
    
    cout << "Hello Welcome to Coin Star please insert the coins you wish to convert into cash" << endl;//Beginning of program
    cin >> userInsert;// Amount user inserted
    
    inQuarters = userInsert / 25;//Finding how many quarters the user inputed
    
    cout << "Quarters: You have inserted " << inQuarters << endl;//Output of how many quarters
    
    inDimes = (userInsert % 25) / 10;//Finding how many dimes the user inputed
    
    cout << "Dimes: You have inserted " << inDimes << endl;//Output of how many dimes
    
    inNickels = ((userInsert % 25) % 10) / 5;//Finding how many nickels the user inputed
    
    cout << "Nickels: You have inserted " << inNickels << endl;//Output of how many nickels 
    
    inPennies = (((userInsert % 25) % 10) % 5) / 1;//Finding how many pennies the user inputed
    
    cout << "Pennies: You have inserted " << inPennies << endl;//Output of how many pennies the user inputed
    
    moneyConversion = static_cast<double>(userInsert) / 100;// Money conversion from numbers to cents 
    cashBack = (static_cast<double>(userInsert) - static_cast<double>(userInsert * percentageFee)) / 100;//The amount given back to the user after the percentage fee
    
    cout << "Your total is $" << moneyConversion << endl;//The intial total of the money from the user
    cout << "After the fee, you will get $" << cashBack << " back in cash" << endl;//Total after the percentage fee taken out of the intial total
    cout << "Thank you for using Coin Star. Have a Good Day!";//End of the program 
    return 0;
}


