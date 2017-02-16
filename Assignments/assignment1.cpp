//Created By: Benny Serrato
//Created On : 2/16/17
//This program with calculate gross pay and also give net pay after taxes
#include <iostream>
#include <string>
using namespace std;
/* Holds base variables for the whole program*/
struct nameWages{
double hourlyRate; //variable used for the rate of user being paid per hour
double hoursWorked; // variable used for hours the user has worked
string firstName; //First name of the user
string lastName; //Last name of the user
};

int main (){
nameWages userWork;//Name for what the variables struct is being used for
double grossWage; //The total amount the user has earned before taxes 
double netPay; //Total amount the user has earned after taxes
int healthTax = 130; //Charge of health insurance
double taxAmount = 0.17; //Percentage taken out of wages for taxes

cout << "Enter your first name:";
cin >> userWork.firstName; //User inputing their first name
cout << "Enter your last name:";
cin >> userWork.lastName; //User inputing their last name
cout << "Please enter your hourly rate " << userWork.firstName << ": "; 
cin >> userWork.hourlyRate; //User inputing their hourly rate
cout << "Please enter your hours worked: "; 
cin >> userWork.hoursWorked; //user inputing their hours worked

grossWage = (userWork.hourlyRate * userWork.hoursWorked); //Calculation for their gross pay
netPay = (grossWage - healthTax) - (grossWage * taxAmount); //Calculation for their net pay

cout << endl;//Line spacing for the outcome

/* Outcome of what the User has inputed*/
cout << userWork.firstName << " " << userWork.lastName << ":" << endl; 
cout << "Rate: $" << userWork.hourlyRate << endl; 
cout << "Hours Worked: " << userWork.hoursWorked << endl; 
cout << "Gross Pay: $" << grossWage << endl; 
cout << "Net Pay: $" << netPay << endl; 

return 0;
}