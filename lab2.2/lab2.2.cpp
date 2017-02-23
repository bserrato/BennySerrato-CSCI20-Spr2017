//Created By: Benny Serrato
//Created On: 2/23/2017
//This program with use a function to generate a random number between 1 and 100
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
/* Function for generating a random number between 1 - 100*/
void NumberGenerator() {
    srand(time(0));//Using current time to get a random number every time the program is ran
    
    cout << (rand() % 100) +1;// The random number generated between 1 - 100
    
    return;
}

int main(){
    cout << "Your Random number is ";
    NumberGenerator();//Calling the function NumberGenerator
}