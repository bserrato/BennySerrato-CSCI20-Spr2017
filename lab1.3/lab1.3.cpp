//Created By: Benny Serrato
//Created On: 2/2/2017

#include <iostream>
using namespace std;

int main(){
    int currentYear = 2016; //Current year for population
    int yearInputed = 0; //Years the User wants for population after 2016
    int currentPopulation = 324472966; //The Current Populatuion of the United Stats
    int yearsSeconds = 31536000; //Amount of seconds in a year
    int birthUs = 0; //Finding births in the United States with the inputed time
    int deathsUs = 0; //Finding deaths in the United States with the inputed time
    int migrationUs = 0; //Finding the migrations in the United States with the inputed time
    int netGain = 0; //Find the net gain of a person per year    
    int populationGain = 0; //Finding the population gain per year
    int populationYears = 0; //Finding the population of User inputed years after 2016 
    
    birthUs = yearsSeconds / 8; //Amount of births per year
    deathsUs = yearsSeconds / 11; //Amount of deaths per year
    migrationUs = yearsSeconds / 29; //Amount of migrations per year
    netGain = yearsSeconds / 15; //Amount of net gain per year
    populationGain = (birthUs - deathsUs) + (migrationUs + netGain); //The gain of population per year
    
    cout << "The current United States population is 324472967" << endl;
    cout << "Input years after 2016 to calucate the United States population after in the years inputed after 2016: " << endl;
    cin >> yearInputed;
    
    populationYears = currentPopulation + (yearInputed * populationGain); //The population of User inputed years after 2016
   
    cout << "The poputaion of the United States after " << yearInputed << " years is:" << endl;
    cout << populationYears;
   
    return 0;
}