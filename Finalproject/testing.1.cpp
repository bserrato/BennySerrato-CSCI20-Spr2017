//This is just for testing out code without messing up the main project  //created a sort of difficulty choice //found bug that erases hangman when guessing a right letter /*edit*/ fix bug timeLost would reset 
//the hangman when guessing correctly a letter as it set it to 0 everytime it looped, placed it in the loop for rounds as that would reset the hangman every round

//R: Sorry, I don't have much time this weekend, since we have no lab on Tuesday we can work on this. I had a little time on Friday so I tried to code up as much as I could.
//R: I have a bug that it skips the first guess and goes straight to the second guess, I'm guessing this is a C9 issue because the logic is fine. Let me know if you can figure it out.
//R: I like the addition of easy, medium, and hard mode. Really great idea.

//B: Yea I see the bug which is weird cause I thought you started with the picture we can try to fix it on tuesday
//B: I'm also trying to create a way that the player could see what letters they've used on the hangman, still trying to debug that and the difficulty modes.
//B: I'm also thinking of implementing your checking code into the class so we could create a class for this program.
//B:Trying to see what we could use for our output, could create results for single player and see who won for the 2 player hangman.
//B: I said that some for loops could be while loops, but I implemented j as a way to output letters guessed.

//R: We can work on that bug in class, I am thinking maybe if we start the for loop at -1 and don't execute of the ouput, but i'm sure April knows about the issue with it and she might be able to fix it with a cin.ignore() or someting like that.
//R: I really like how you implemented the letters previously used, nice work. 
//R: The more we can do with the class the better, because right now the class's only task is keeping score and i don't think that would be enough.
//R: We could use file output for maybe an HTML page, we could implement how fast they completed the word as well.
//R: I knew we would need that j, lol.
//R: Found a bug, letters used doesn't reset after the round is over and a new word begins.

//B: maybe we make an for loop at the beginning to make the array set to null so that would be a sort of reset
//B: I also still need to figure out the letters previously read as i would need to find a way to not have letter repeat themselves
//B: also wouldnt the hangman be done by the 6th chance as it looks like the person is completely there
//B: Its weird it works when i put another getline with the other one but after the first one there will be two cins
//B: Managed to fix the skipping of the first guess but i made a for loop so there would be 2 cins in the first guess which fixes it
//B: We should still try to find a better solution to the guess as i made a temporary fix to the guessing code, 
//B: also i believe the skipping only happens in round 1 as when im in round two i get double inputs, that could shorten our search to find the bug
//B: Found that some of our input file words are capitalized ill try to fix that as much as i can might miss some
//B: would also need to find a way to not have the same words for 2 rounds in a row, i think we did this in one of the labs or assignments

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

class WordGuess {
    private:
        string correctAnswer_;
        string Checkletter_[99];
        int winCount_;
        int loseCount_;
    public:
        void SetWord(string correctWord){
            correctAnswer_ = correctWord;
        }
        void DetermineLetter(string userGuess[], int &letterIndex, int &spaceIndex, string &wordTemplate){
            if (correctAnswer_.find(' ') != string::npos) {
                    spaceIndex = correctAnswer_.find(' ');
                }
                else {
                    spaceIndex = -1;
                }
                for (int x = 0; x < correctAnswer_.length(); x++) {       //This for loop converts a word to _ based on how long the word is
                wordTemplate.push_back('#');
                }
                if (spaceIndex != -1) {
                wordTemplate.replace(spaceIndex, 1, " ");
                }
            for(int i = 0; wordTemplate.find('#') != string::npos; i++){
               
                if (userGuess[i] == correctAnswer_) {
                    cout << endl << "*******************";
                    cout << endl << "You Won This Round!" << endl;
                    cout << "*******************" << endl << endl;
                }
                letterIndex = correctAnswer_.find(userGuess[i]);
                if (letterIndex != -1 && userGuess[i].length() == 1) {
                    wordTemplate.replace(letterIndex, 1, userGuess[i]);
                    while (correctAnswer_.find(userGuess[i], letterIndex + 1) != string::npos) {
                        letterIndex = correctAnswer_.find(userGuess[i], letterIndex + 1);
                        wordTemplate.replace(letterIndex, 1, userGuess[i]);
                    }
                    cout << "You found a letter" << endl;
                }
                else if (userGuess[i].length() == 1) {
                    cout << "You didn't find the letter" << endl;
                    loseCount_++;
                }
            }
        }
        int GetChances(){
            return loseCount_;
        }
};

int main() {
    string array[415] = {" "};
    string tempWord;
    srand(time(0));
    int randomNum[10];
    string guesses[20];
    string userLetter[99];
    string userWord;
    int indexOfSpace;
    int indexOfLetter;
    int timesLost = 0;
    int timesLost1 = 0;
    char backSlash = '\\';
    int players = 0;
    string p1Name;
    string p2Name;
    string difficulty;
    int numRounds;
    string checkLetter[99];
    int breakNum = 0;
    WordGuess gameRounds[99];
    
    ifstream fin;
    ofstream fout;
    
    fin.open("listoffoods.txt");
    fout.open("testing.html");
    
    for (int i = 0; !fin.eof(); i++) {
        getline(fin, tempWord);
        array[i] = tempWord;
    }
    
    cout << "Would you like 1 or 2 players? ";
    cin >> players;
    while(players != 1 && players != 2){
        cout << "I'm sorry this game can only be played with 1 or 2 players." << endl;
        cout << "Are there 2 players or 1? ";
        cin >> players;
    } 
    cout << "Type in your difficulty between easy, normal, or hard: ";
    cin >> difficulty;
    /*while loop to create a way for the player to only be able to input easy, normal, or hard */ 
    while(difficulty != "easy" && difficulty != "Easy" && difficulty != "EASY" && difficulty != "normal" && difficulty != "Normal" && difficulty != "NORMAL" && difficulty != "hard" && difficulty != "Hard" && difficulty != "HARD"){
        cout << "I'm sorry there is no " << difficulty << " mode." << endl;
        cout << "Type in your difficulty between easy, normal, or hard: ";
        cin >> difficulty;
    }
    if(players == 1){
        cout << "How many rounds do you want to play? ";
        cin >> numRounds;
    }
    else if (players == 2){
        cout << "How many rounds per player? ";
        cin >> numRounds;
    }
    if (players == 1) {
        cout << "Player 1 First Name: "; 
        cin >> p1Name;
        for (int i = 0; i < numRounds; i++) {
            cout << endl;
            cout << "Round " << i + 1 << endl;
            breakNum = 0;

            timesLost = 0;//timesLost should be up here to reset the hangman for a new round
            //R: That makes sense.
            userWord = "";
            randomNum[i] = rand() % 414;
            array[i] = array[randomNum[i]];
            if(difficulty == "easy" || difficulty == "Easy" || difficulty == "EASY"){// create for people who want easy mode in the game
                while(array[i].length() > 5){
                    randomNum[i] = rand() % 414;
                    array[i] = array[randomNum[i]];
                }
            }
            else if(difficulty == "normal" || difficulty == "Normal" || difficulty == "NORMAL"){//creates a normal mode
                while(array[i].length() < 6){
                    while(array[i].length() > 11){
                        randomNum[i] = rand() % 414;
                        array[i] = array[randomNum[i]];
                    }
                }
            }
            else if(difficulty == "hard" || difficulty == "Hard" || difficulty == "HARD"){
                while(array[i].length() < 12){//creates hard mode
                    randomNum[i] = rand() % 414;
                    array[i] = array[randomNum[i]];
                }
            }
            cout << array[i] << endl;
            if (array[i].find(' ') != string::npos) {
                indexOfSpace = array[i].find(' ');
            }
            else {
                indexOfSpace = -1;
            }
            for (int x = 0; x < array[i].length(); x++) {       //This for loop converts a word to _ based on how long the word is
                userWord.push_back('#');
            }
            if (indexOfSpace != -1) {
                userWord.replace(indexOfSpace, 1, " ");
            }
            for (int j = 0; userWord.find('#') != string::npos && breakNum != 1; j++) {
                
                if (timesLost == 0 && j == 0) {
                    cout << " ____________ " << endl;
                    cout << "|       |    |" << endl;
                    cout << "|      /     |" << endl;
                    cout << "|            |" << endl;
                    cout << "|            |" << endl;
                    cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                }
                cout << endl << userWord << endl << endl;
                cout << "Guess the entire word or pick a letter: ";
                if(j == 0 && i == 0 ){
                    getline(cin,userLetter[j]);
                }
                getline(cin, userLetter[j]);
                
               //class function here 
               gameRounds[i].SetWord(array[i]);
               gameRounds[i].DetermineLetter(userLetter,indexOfLetter, indexOfSpace, userWord);
               timesLost = gameRounds[i].GetChances();
               cout << endl;
                if (breakNum != 1) {
                    if (timesLost == 0) {
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|      /     |" << endl;
                        cout << "|            |" << endl;
                        cout << "|            |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    if (timesLost == 1) {
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|            |" << endl;
                        cout << "|            |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    else if (timesLost == 2) {
                        cout << " ____________ " << endl;
                        cout << "|      |     |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|     |      |" << endl;
                        cout << "|            |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    else if (timesLost == 3) {
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|    /|      |" << endl;
                        cout << "|            |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    else if (timesLost == 4) {
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|    /|" << backSlash << "     |" << endl;
                        cout << "|            |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    else if (timesLost == 5) {
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|    /|" << backSlash << "     |" << endl;
                        cout << "|    /       |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    else if (timesLost == 6) {//wouldn't the guy be hung by this point making the player lose here?
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|    /|" << backSlash << "     |" << endl;
                        cout << "|    / " << backSlash << "     |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                        cout << "You were hung!" << endl;
                        cout << "Your word was: " << array[i] << endl;
                        breakNum = 1;
                    }
                }
                if (breakNum != 1) {
                cout << "Letters used:";//creating a way the player could see what letters they've used up
                for(int k = 0; k < 99; k++){
                    if (userLetter[k].length() == 1) {
                        if(checkLetter[k] == userLetter[j] ){
                        userLetter[j] = "";
                        }
                        cout << " " << userLetter[k]; 
                    }
                }
                cout << endl;
                cout << "Words guessed:";
                for(int k = 0; k < 99; k++){
                    if (userLetter[k].length() > 1) {
                        if(checkLetter[k] == userLetter[j]){
                        userLetter[j] = "";
                        }
                         cout << " " << userLetter[k]; 
                    }
                }
                checkLetter[j] = userLetter [j];
                cout << endl;
                if (userWord.find('#') == string::npos) {
                    cout << endl;
                    cout << "*******************";
                    cout << endl << "You Won This Round!" << endl;
                    cout << "*******************" << endl << endl;
                }
            }
            }
        }
    }
    
    else if (players == 2) {
        timesLost = 0;
        timesLost1 = 0;
        cout << "Player 1 First Name: "; 
        cin >> p1Name;
        cout << "Player 2 First Name: ";
        cin >> p2Name;
        for (int i = 0; i < numRounds * 2; i++) {
            if (i == 0 || i == 2 || i == 4 || i == 6) {
                cout << endl << p1Name << "'s Turn" << endl;
            }
            else {
                cout << endl << p2Name << "'s Turn" << endl;
            }
            userWord = "";
            randomNum[i] = rand() % 414;
            array[i] = array[randomNum[i]];
            cout << array[i] << endl;
            if (array[i].find(' ') != string::npos) {
                indexOfSpace = array[i].find(' ');
            }
            else {
                indexOfSpace = -1;
            }
            for (int x = 0; x < array[i].length(); x++) {       //This for loop converts a word to # based on how long the word is
                userWord.push_back('#');
            }
            if (indexOfSpace != -1) {
                userWord.replace(indexOfSpace, 1, " ");
            }
            for (int j = 0; userWord.find('#') != string::npos; j++) {
                cout << endl << userWord << endl << endl;
                cout << "Guess the entire word or pick a letter: ";
                getline(cin, userLetter[j]);
                if (userLetter[j] == array[i]) {
                    cout << "**********************" << endl;
                    if (i == 0 || i == 2 || i == 4 || i == 6) {
                        cout << p1Name << " Won this Round!" << endl;
                    }
                    else {
                        cout << p2Name << " Won this Round!" << endl;
                    }
                    cout << "**********************" << endl << endl;
                }
                else {
                    indexOfLetter = array[i].find(userLetter[j]);
                    if (indexOfLetter != -1 && userLetter[j].length() == 1) {
                        userWord.replace(indexOfLetter, 1, userLetter[j]);
                        while (array[i].find(userLetter[j], indexOfLetter + 1) != string::npos) {
                            indexOfLetter = array[i].find(userLetter[j], indexOfLetter + 1);
                            userWord.replace(indexOfLetter, 1, userLetter[j]);
                        }
                        cout << "You found a letter" << endl;
                    }
                    else if (userLetter[j].length() == 1) {
                        cout << "You didn't find the letter" << endl;
                        if (i == 0 || i == 2 || i == 4 || i == 6) {
                            timesLost++;
                        }
                        else {
                            timesLost1++;
                        }
                    }
                    cout << endl;
                    if (timesLost == 0) {
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|      /     |" << endl;
                        cout << "|            |" << endl;
                        cout << "|            |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    if (timesLost == 1) {
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|            |" << endl;
                        cout << "|            |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    else if (timesLost == 2) {
                        cout << " ____________ " << endl;
                        cout << "|      |     |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|     |      |" << endl;
                        cout << "|            |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    else if (timesLost == 3) {
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|    /|      |" << endl;
                        cout << "|            |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    else if (timesLost == 4) {
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|    /|" << backSlash << "     |" << endl;
                        cout << "|            |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    else if (timesLost == 5) {
                        cout << " ____________ " << endl; 
                        cout << "|       |    |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|    /|" << backSlash << "     |" << endl;
                        cout << "|    /       |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    else if (timesLost == 6) {
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|    /|" << backSlash << "     |" << endl;
                        cout << "|    / " << backSlash << "     |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    else if (timesLost == 7) {
                        if (i == 0 || i == 2 || i == 4 || i == 6) {
                            cout << p1Name << " was hung!" << endl;
                        }
                        else {
                            cout << p2Name << " was hung!" << endl;
                        }
                        break;
                    }
                    cout << "letters used: ";
                    for(int k = 0; k < 99; k++){
                    //need to find a way to not output same letters or words guessed, or output input that would not be read by the program
                    cout << userLetter[k];
                    }
                    cout << endl;
                    if (userWord.find('#') == string::npos) {
                        cout << "**********************" << endl;
                        if (i == 0 || i == 2 || i == 4 || i == 6) {
                            cout << p1Name << " Won this Round!" << endl;
                        }
                        else {
                            cout << p2Name << " Won this Round!" << endl;
                        }
                        cout << "**********************" << endl << endl;
                    }
                }
            }
        }
    }
    return 0;
}