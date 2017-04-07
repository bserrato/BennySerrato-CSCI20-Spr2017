
#include<iostream>
#include<cstring>
using namespace std;

class OptionGame{//class is used to determine the option for the computer when ever a round begins
    public:
    void setComputerOption(int randomOption){//mutator to get a random option for the computer
                switch (randomOption){//switch statement to store random option
                    case 0://gives string of rock
                    storeOption_ = "rock";
                    break;
                    case 1://gives string of paper
                    storeOption_ = "paper";
                    break;
                    case 2://gives string of scissors
                    storeOption_ = "scissors";
                    break;
                    case 3://gives string of lizard
                    storeOption_ = "lizard";
                    break;
                    case 4://gives the string of spock
                    storeOption_ = "spock";
                    break;
                    default://to test if random number works 
                    cout << "ERROR";
                    
                }
    }
    string getComputerOption(){//accesor to return the computer's option
        return storeOption_;
    }
    private:
    string storeOption_;//stores the string for the computer option
};
int main(){
    srand(time(0));
    OptionGame threeRounds;//call of class for three rounds
    OptionGame fiveRounds;//call of class for five rounds
    OptionGame sevenRounds;//call of class for seven rounds
    string userOption;//will store user input for options of the game
    string computerOption;//will store computer input to not repeat the same option for another round
    int randomOption;//stores a random number to pick a random string option
    int gameRounds;//stores how many rounds will be played
    int winCount = 0;//stores the amount of wins the player gets
    
    cout << "Hello user please input how many rounds you wish to play from 3, 5, or 7:";
    cin >> gameRounds;//input for rounds
    
        if(gameRounds == 3){//if statment for three rounds
            cout << "Please have your input exactly like the game calls it too be." << endl;
            for(int numRounds = 1; numRounds <= 3; numRounds++){//for loop that will play three rounds
                cout << endl;
                cout << "Round " << numRounds << endl;
                cout << "rock, paper, scissors, lizard, spock!: ";
                cin >> userOption;//input for user option
                cout << endl;
                cout << "You chose " << userOption << endl;
                randomOption = rand() % 5;//random number for the class function
                threeRounds.setComputerOption(randomOption);//sets the random string option
              while(computerOption == threeRounds.getComputerOption()){//if the computer selects the same option for another round
                  randomOption = rand() % 5;
                  threeRounds.setComputerOption(randomOption);
              }
                cout << "Computer chose " << threeRounds.getComputerOption() <<endl;
                cout << endl;
                
                    while(userOption == threeRounds.getComputerOption()){//will continue to play the while loop until player and computer don't have the same option
                        computerOption = threeRounds.getComputerOption();
                        randomOption = rand() % 5;
                        cout << "Draw! Replay Round " << numRounds << ":";
                        cin >> userOption;
                        cout << "You chose " << userOption << endl;//to see what user inputed as their option
                        threeRounds.setComputerOption(randomOption);//setting the option for computer
                        while (computerOption == threeRounds.getComputerOption()){//while option for the computer is the same as last round
                           randomOption = rand() % 5;
                           threeRounds.setComputerOption(randomOption);
                        }
                        cout << "Computer chose " << threeRounds.getComputerOption() << endl;
                        cout << endl;
                    }
                /*Options of how the player could win the round */
                if(userOption == "scissors" && threeRounds.getComputerOption() == "paper" ){
                    cout << userOption << " cuts " << threeRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if (userOption == "paper" && threeRounds.getComputerOption() == "rock"){
                    cout << userOption << " covers " << threeRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if(userOption == "rock" && threeRounds.getComputerOption() == "lizard"){
                    cout << userOption << " crushes " << threeRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if (userOption == "lizard" && threeRounds.getComputerOption() == "spock"){
                    cout << userOption << " poisons " << threeRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if (userOption == "spock" && threeRounds.getComputerOption() == "scissors"){
                    cout << userOption << " smashes " << threeRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if (userOption == "scissors" && threeRounds.getComputerOption() == "lizard"){
                    cout << userOption << " decapitates " << threeRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if(userOption == "lizard" && threeRounds.getComputerOption() == "paper" ){
                    cout << userOption << " eats " << threeRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if(userOption == "paper" && threeRounds.getComputerOption() == "spock"){
                    cout << userOption << " disproves " << threeRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if(userOption == "spock" && threeRounds.getComputerOption() == "rock"){
                    cout << userOption << " vaporizes " << threeRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins  
                }else if(userOption == "rock" && threeRounds.getComputerOption() == "scissors"){
                    cout << userOption << " crushes " << threeRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else{//if computer beats user option
                    cout << threeRounds.getComputerOption() << " beats " << userOption << endl;
                    cout << "You lose Round " << numRounds << "!"<< endl; 
                }
                computerOption = threeRounds.getComputerOption();//to check so that computer does not select same option next round
            }
            cout << "You won " << winCount << " out of " << gameRounds << " rounds." << endl;//show player how many wins they got from how many rounds they played
            
        }else if(gameRounds == 5){//if statement for five rounds
            cout << "Please have your input exactly like the game calls it too be." << endl;
            for(int numRounds = 1; numRounds <= 5; numRounds++){//for loop for how many rounds will be played
                cout << endl;
                cout << "Round " << numRounds << endl;
                cout << "rock, paper, scissors, lizard, spock!: ";
                cin >> userOption;//user input for the options
                cout << endl;
                cout << "You chose " << userOption << endl;//to see what user chose
                randomOption = rand() % 5;
                fiveRounds.setComputerOption(randomOption);//class functions for the computer's options
              while(computerOption == fiveRounds.getComputerOption()){//while loop if the option the option chosen for the computer is the same as last round
                  randomOption = rand() % 5;
                  fiveRounds.setComputerOption(randomOption);
              }
                cout << "Computer chose " << fiveRounds.getComputerOption() <<endl;//to see what computer chose
                cout << endl;
                
                    while(userOption == fiveRounds.getComputerOption()){//while loop when user and computer have same option
                        computerOption = fiveRounds.getComputerOption();
                        randomOption = rand() % 5;
                        cout << "Draw! Replay Round " << numRounds << ":";
                        cin >> userOption;
                        cout << "You chose " << userOption << endl;
                        fiveRounds.setComputerOption(randomOption);
                        while (computerOption == fiveRounds.getComputerOption()){//so computer does not have same option as last round
                           randomOption = rand() % 5;
                           fiveRounds.setComputerOption(randomOption);
                        }
                        cout << "Computer chose " << fiveRounds.getComputerOption() << endl;
                        cout << endl;
                        
                }
                /*Options to determine if user wins*/
                if(userOption == "scissors" && fiveRounds.getComputerOption() == "paper" ){
                    cout << userOption << " cuts " << fiveRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if (userOption == "paper" && fiveRounds.getComputerOption() == "rock"){
                    cout << userOption << " covers " << fiveRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if(userOption == "rock" && fiveRounds.getComputerOption() == "lizard"){
                    cout << userOption << " crushes " << fiveRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if (userOption == "lizard" && fiveRounds.getComputerOption() == "spock"){
                    cout << userOption << " poisons " << fiveRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if (userOption == "spock" && fiveRounds.getComputerOption() == "scissors"){
                    cout << userOption << " smashes " << fiveRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if (userOption == "scissors" && fiveRounds.getComputerOption() == "lizard"){
                    cout << userOption << " decapitates " << fiveRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if(userOption == "lizard" && fiveRounds.getComputerOption() == "paper" ){
                    cout << userOption << " eats " << fiveRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if(userOption == "paper" && fiveRounds.getComputerOption() == "spock"){
                    cout << userOption << " disproves " << fiveRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if(userOption == "spock" && fiveRounds.getComputerOption() == "rock"){
                    cout << userOption << " vaporizes " << fiveRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if(userOption == "rock" && fiveRounds.getComputerOption() == "scissors"){
                    cout << userOption << " crushes " << fiveRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else{//if computer's option beats user's
                    cout << fiveRounds.getComputerOption() << " beats " << userOption << endl;
                    cout << "You lose Round " << numRounds << "!"<< endl; 
                }
                computerOption = fiveRounds.getComputerOption();//to determine that computers option will not be the same next round
            }
            cout << "You won " << winCount << " out of " << gameRounds << " rounds." << endl;
        
        }else if(gameRounds == 7){//if statement for seven rounds 
            cout << "Please have your input exactly like the game calls it too be." << endl;
            for(int numRounds = 1; numRounds <= 7; numRounds++){//for loop for how many rounds played
                cout << endl;
                cout << "Round " << numRounds << endl;
                cout << "rock, paper, scissors, lizard, spock!: ";
                cin >> userOption;//user input for the options
                cout << endl;
                cout << "You chose " << userOption << endl;//shows the user's option
                randomOption = rand() % 5;
                sevenRounds.setComputerOption(randomOption);//sets the computer option for the round
              while(computerOption == sevenRounds.getComputerOption()){//while loop for when the computer's option is the same as the previous round
                  randomOption = rand() % 5;
                  sevenRounds.setComputerOption(randomOption);
              }
                cout << "Computer chose " << sevenRounds.getComputerOption() <<endl;//shows computers option
                cout << endl;
                
                    while(userOption == sevenRounds.getComputerOption()){//while loop for when user's option and computer's option is the same
                        computerOption = sevenRounds.getComputerOption();
                        randomOption = rand() % 5;
                        cout << "Draw! Replay Round " << numRounds << ":";
                        cin >> userOption;
                        cout << "You chose " << userOption << endl;
                        sevenRounds.setComputerOption(randomOption);
                        while (computerOption == sevenRounds.getComputerOption()){
                           randomOption = rand() % 5;
                           sevenRounds.setComputerOption(randomOption);
                        }
                        cout << "Computer chose " << sevenRounds.getComputerOption() << endl;
                        cout << endl;
                    }
                /*Options to determine if user wins*/
                if(userOption == "scissors" && sevenRounds.getComputerOption() == "paper" ){
                    cout << userOption << " cuts " << sevenRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if (userOption == "paper" && sevenRounds.getComputerOption() == "rock"){
                    cout << userOption << " covers " << sevenRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if(userOption == "rock" && sevenRounds.getComputerOption() == "lizard"){
                    cout << userOption << " crushes " << sevenRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if (userOption == "lizard" && sevenRounds.getComputerOption() == "spock"){
                    cout << userOption << " poisons " << sevenRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if (userOption == "spock" && sevenRounds.getComputerOption() == "scissors"){
                    cout << userOption << " smashes " << sevenRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if (userOption == "scissors" && sevenRounds.getComputerOption() == "lizard"){
                    cout << userOption << " decapitates " << sevenRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if(userOption == "lizard" && sevenRounds.getComputerOption() == "paper" ){
                    cout << userOption << " eats " << sevenRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if(userOption == "paper" && sevenRounds.getComputerOption() == "spock"){
                    cout << userOption << " disproves " << sevenRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else if(userOption == "spock" && sevenRounds.getComputerOption() == "rock"){
                    cout << userOption << " vaporizes " << sevenRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins   
                }else if(userOption == "rock" && sevenRounds.getComputerOption() == "scissors"){
                    cout << userOption << " crushes " << sevenRounds.getComputerOption() << endl;
                    cout << "You won Round " << numRounds << "!"<< endl;
                    winCount++;//will increase by 1 everytime the user wins
                }else{//if computer's option beats the user's option
                    cout << sevenRounds.getComputerOption() << " beats " << userOption << endl;
                    cout << "You lose Round " << numRounds << "!"<< endl; 
                }
                cout << endl;
                computerOption = sevenRounds.getComputerOption();//to determine computer's option will not be the same next round
            }
            cout << "You won " << winCount << " out of " << gameRounds << " rounds." << endl;//outputing how many wins the user got in the rounds played
        }else{//when user inputs numbers that are not 3, 5 or 7 for rounds
            cout << "There can only be rounds of 3, 5 or 7." << endl;

    }
}