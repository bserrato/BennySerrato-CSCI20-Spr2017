//Created by: Benny Serrato
//Created On: 3/2/2017
//

#include<ctime>
#include<cstdlib>
#include<iostream>
using namespace std;

void InputSwap (int firstNumber, int secondNumber);//declaration of the swapping function
int NumberGenerator(int& firstNumber, int& secondNumber);//declaration of the random number generator function
double PoundsToKilograms (double& randomNumber);//declaration of converting pounds to kilograms function
double KilogramsToPounds (double& kiloNumber);//declaration of the coverting kilograms function

int main(){
    int UserInputOne;//Starting point of UserInputOne scope
    int UserInputTwo;//Starting point of UserInputTwo scope 
    double kiloConvert;//Starting point of kiloConvert scope
    double poundConvert;//Starting point of poundConvert scope
    double randomResult;//Starting point of randomResult scope
    
    cout << "Please enter your minimum number that would be picked: ";
    cin >> UserInputOne;//User input for the minimus number
    
    cout << "Now enter your maximum number that would be picked: ";
    cin >> UserInputTwo;//User input for the maximum number
    
    
    randomResult = NumberGenerator(UserInputOne, UserInputTwo);//randomResult to store the result of the function call of NumberGenerator
    
    /*Outcome of the program */ 
    cout << "A number between " << UserInputOne << " and " << UserInputTwo << " is "<< randomResult << endl;
    cout << endl;
    
    cout << "Starting Pounds: " << randomResult << endl;
    
    kiloConvert = PoundsToKilograms(randomResult);//kiloConvert store the result of the function call of PoundsToKilograms
    cout <<"Kilograms: "<< kiloConvert << endl;
    
    poundConvert = KilogramsToPounds(kiloConvert);//poundConvert stores the result of the function call of KilogramsToPounds
    cout << "Ending Pounds:" << poundConvert;
    
}/*End of all local variable scope*/ 

void InputSwap (int firstNumber, int secondNumber){
    int numFirst = firstNumber;//Start of the numFirst scope
    
    firstNumber = secondNumber;
    secondNumber = numFirst;
    
    return;
}//End of scope for local variable of InputSwap functions

/*Definition of NumberGenerator function*/
int NumberGenerator(int& firstNumber, int& secondNumber){
    int finalResult;//Start of the finalResult scope
    
    InputSwap(firstNumber,secondNumber);//call of the number swap
    srand(time(0));//Gets random number every time using computer time
    
    finalResult = (rand() % (secondNumber - firstNumber)) + firstNumber;//Stores data of  the random number
    
    return finalResult;//Returns the stored data of finalResult
}//End of scope for local variable of NumberGenerator functions

/*Definition of PoundsToKilograms function*/
double PoundsToKilograms (double& randomNumber){
    double kiloResult;//Start of kiloResult scope
    
    kiloResult = randomNumber / 2.20462;//Stores the data of the kilogram conversion
    
    return kiloResult;//Returns the stored data of kiloResult
}//End of scope for local variable of PoundsToKilograms functions

/*Definition of KilogramsToPounds function*/
double KilogramsToPounds (double& kiloNumber){
    double poundResult;//Start of poundResult scope
    poundResult = kiloNumber * 2.20462;
    
    return poundResult;
}//End of scope for local variable of KilogramsToPounds functions