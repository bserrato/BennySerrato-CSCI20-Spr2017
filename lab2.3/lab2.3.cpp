//Created By: Benny Serrato
//Created On: 2/28/2017
//This program will use numbers that user inputs to get a number between the numbers inputed

#include<cstdlib>
#include<iostream>
#include<ctime>
using namespace std;

void NumberSwap(int smallestNumber, int largestNumber);//declaration of the number swap function
void NumberGenerator(int& smallestNumber, int& largestNumber);// declaration of the random number generator function

int main(){
    int userInputOne;//initial variable for the smallest number input
    int userInputTwo;//initial varibale for the largest number input
    cout << "Please enter your smallest number: " ;
    cin >> userInputOne;// User input for the smallest number for the random generator
    cout << "Now please enter your largest number: ";
    cin >> userInputTwo;// User input for the largest number for the random generator
    NumberGenerator(userInputOne, userInputTwo);//call of the number generator function with the parameters of User input
    return 0;
}

/* Function for the number swap in the program*/ 
void NumberSwap (int smallestNumber, int largestNumber){
    int swapNumberSmall;
    int swapNumberLarge;
    
    swapNumberSmall = smallestNumber;//Storing the variable value of smallest number for swapping purposes
    
    smallestNumber = largestNumber;//Swapping variable values using the swapNumberSmall variable
    largestNumber = swapNumberSmall;//Swapping variable values using the swapNumberLarge variable
    return;
}

/* Function for the random number generator in the program */
void NumberGenerator (int& smallestNumber, int& largestNumber){
    int finalResult;// variable to get the result of the random number generator
    
    NumberSwap(smallestNumber, largestNumber);//Call of the number swap function
    srand(time(0));//Using computer time to get a random number every time the program in run
    finalResult = (rand() % (largestNumber - smallestNumber)) + smallestNumber; // Using finalResult variable to get the result of the random number generator
    cout << "A random number between " << smallestNumber << " and " << largestNumber << " is " << finalResult;//Outcome of the program for the random number generator
    return;
    
}