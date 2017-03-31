//Created By:Benny Serrato
//Created On: 3/30/2017
//This program will have the user play a guessing game that will end once user guesses the right number

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    srand(time(0));
    int userNumber;
    int randomNumber = (rand() % 50) + 1;//starting random number 
    cout << "Enter a number between 1 and 50 to begin the guessing game:";
    cin >> userNumber;//User's first guess
     while(userNumber < 1){
                cout << "The number must be between 1 and 50" << endl;
                cin >> userNumber;
                    while(userNumber > 50){
                    cout << "The number must be between 1 and 50" << endl;
                    cin >> userNumber;
                    }
                }
    
        cout << randomNumber;//testing corrections
        while(randomNumber != userNumber){//To keep the game running until user guesses the number correctly
        for(int userChances = 9; userChances >= 0; userChances--){//for loop to figure out how many tries the user has left
            if(userNumber > randomNumber){
                    cout << "Too High" << endl;
                    if(userChances > 1){//if statement  to see if user has more than one try in the game
                    cout << "You have " << userChances << " chances" << endl;
                    cin >> userNumber;
                }else if(userChances == 1){//if statement to see if user has only one chance left
                    cout << "You only have " << userChances << " chance" << endl;
                    cin >> userNumber;
                }else{//if user has no more chances left in which the program will reset random number and chances
                    cout << "You have no chances left. Random number was " << randomNumber << endl;
                    cout << "Reseting guessing game." << endl;
                    randomNumber = (rand() % 50) + 1;
                    cout << randomNumber;
                    cin >> userNumber;
                }
                    }else if(userNumber < randomNumber){
                cout << "Too Low" << endl;
                if(userChances > 1){//if statement  to see if user has more than one try in the game
                    cout << "You have " << userChances << " chances" << endl;
                    cin >> userNumber;
                }else if(userChances == 1){//if statement to see if user has only one chance left
                    cout << "You only have " << userChances << " chance" << endl;
                    cin >> userNumber;
                }else{//if user has no more chances left in which the program will reset random number and chances
                    cout << "You have no chances left. Random number was " << randomNumber << endl;
                    cout << "Reseting guessing game." << endl;
                    randomNumber = (rand() % 50) + 1;
                    cout << randomNumber;
                    cin >> userNumber;
                }
        }else{//when user guesses the number correctly inside the for loop
            while(randomNumber != userNumber){
            cout << "Correct! Congratulations " << endl;//Once user correctly guesses the random number
                
            }
        }
        }
        }
            cout << "Correct! Congratulations " << endl;//Once user correctly guesses the random number
}
