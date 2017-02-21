//Created By: Benny Serrato
//Created On: 2/21/2017
//This program will use User Input to get information about windchill using the user inputed windspeed and temperature.
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {

double windChillOld = 0;//defaut amount for the old style windchill formula
double windChillNew = 0;//default amount  for the old style windchill formula
int userVelocity = 0; //default amount for the user inputed windspeed
double tempFahrenheit = 0;//default amount for the user inputed temperature
double differenceNewOld = 0; //default amount of the difference between old style windchill and new style wind chill formulas

cout << "Please enter a windspeed you wish to be calculated : ";//
cin >> userVelocity;// User input for the windspeed 

cout << "Please enter a temperature in Fahrenheits to be calculated : ";
cin >> tempFahrenheit;//User input for the temperature

windChillOld = 0.081 * (3.71 * sqrt(userVelocity) + 5.81 - (0.25 * userVelocity)) * (tempFahrenheit - 91.4) + 91.4;// Formula for the old style windchill 
windChillNew = (35.74 + 0.6215 * tempFahrenheit) - (35.75 * pow(userVelocity , 0.16)) + (0.4275 * tempFahrenheit * pow(userVelocity , 0.16)); // Formula for the new style windchill
differenceNewOld = windChillNew - windChillOld;// Different between the New and Old style of windchill

/* Output for the program for windchill */ 
cout << "Windspeed(velocity)" << "     " << "Old Formula" << "     "  << "New Formula" << "     " << "Difference" << endl; 
cout <<  "       " << userVelocity << "                 " << windChillOld << "         " << windChillNew << "         " << differenceNewOld;

return 0;
}