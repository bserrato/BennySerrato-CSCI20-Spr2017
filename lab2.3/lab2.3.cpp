//Created By: Benny Serrato
//Created On: 2/28/2017
//This program will use numbers that user inputs to get a number between the numbers inputed

#include<cstdlib>
#include<iostream>
#include<ctime>
using namespace std;

void NumberSwap(int& smallestNumber, int& largestNumber);//declaration of the number swap function
int NumberGenerator(int& smallestNumber, int& largestNumber);// declaration of the random number generator function

int main(){
    int userInputOne;//initial variable for the smallest number input
    int userInputTwo;//initial varibale for the largest number input
    int finalOutcome;//intial variable for the final outcome
    cout << "Please enter your smallest number: " ;
    cin >> userInputOne;// User input for the smallest number for the random generator
    cout << "Now please enter your largest number: ";
    cin >> userInputTwo;// User input for the largest number for the random generator
    finalOutcome = NumberGenerator(userInputOne, userInputTwo);
    cout << "A random number between " << userInputOne << " and " << userInputTwo << " is " << finalOutcome;//Outcome of the program for the random number generatorNumberGenerator(userInputOne, userInputTwo);//call of the number generator function with the parameters of User input
    return 0;
}

/* Function for the number swap in the program*/ 
void NumberSwap (int& smallestNumber, int& largestNumber){
    int swapNumberSmall;
    
    swapNumberSmall = smallestNumber;//Storing the variable value of smallest number for swapping purposes
    
    smallestNumber = largestNumber;//Setting smallest number to have the largest number value
    largestNumber = swapNumberSmall;//Swapping variable values using the swapNumberLarge variable
    return;
}

/* Function for the random number generator in the program */
int NumberGenerator (int& smallestNumber, int& largestNumber){
    int finalResult;// variable to get the result of the random number generator
    
    NumberSwap(smallestNumber, largestNumber);//Call of the number swap function
    srand(time(0));//Using computer time to get a random number every time the program in run
    finalResult = (rand() % (smallestNumber - largestNumber)) + largestNumber; // Using finalResult variable to get the result of the random number generator
    return finalResult;
}