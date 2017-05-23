//Created By: Benny Serrato and Riley Slater
//Created On: 5/17/2017
/*This program will create a hangman game by implementing file input to get a database of words for the player to guess, use the class to check the player's guess and determine
the outcome of the rounds, have array of object for each individual player's round outcome, and then get results and output it in a html file 
*/
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cctype>
using namespace std;

class WordGuess {//This class will process the guesses the player input and will output depending if they guesses right or wrong and see if they won or lost the round
    private:
        string correctAnswer_;//will store the word that player will be guessing
        string storeGuess_;//stores the letter or word guess the player inputed
        string previousGuesses_[99];
        int timeArray_[99];//an array to store time for each round 
        int winCount_ = 0;//determines if the player got a point or not for the round
        int loseCount_ = 0;//determines how many chances the player will have left
        int breakNum_ = 0;//number that is used as a condition for the loop
        string userWord_;//template of the hidden word
        int indexOfSpace_;//checks for spacing in the word
        int indexOfLetter_;//checks if the the letter guess matched any letter in the word
    public:
        void SetPreviousGuess(string word, int index) {     //Sets the previous letter and word guesses
            previousGuesses_[index] = word;
        }
        string GetPreviousGuess(int index) {     //Returns the guess at a specific index
            return previousGuesses_[index];
        }
        void SetWord(string correctWord){//stores the word that will be guessed by the player
            correctAnswer_ = correctWord;
        }
        void SetGuess(string userGuess){//stores the player's guess 
            storeGuess_ = userGuess;
        }
        void SetLetters(){//sets the character that will be used to hide the words that the player will be guessing
            if (correctAnswer_.find(' ') != string::npos) {//finds any spaces that the word selected may have
                indexOfSpace_ = correctAnswer_.find(' ');
            }
            else {
                indexOfSpace_ = -1;//will set index to -1 of there are no spacings in the word
            }
            for (int x = 0; x < correctAnswer_.length(); x++) {       //This for loop converts a word to _ based on how long the word is
                userWord_.push_back('#');
            }
            if (indexOfSpace_ != -1) {//sets a space to show the player that the word has spacing
                userWord_.replace(indexOfSpace_, 1, " ");
            }
            if (correctAnswer_.find(' ', indexOfSpace_ + 1)) { //checks to make sure if the word has two spacings in it
                indexOfSpace_ = correctAnswer_.find(' ', indexOfSpace_ + 1);
            }
            if (indexOfSpace_ != -1) {//sets a space to show the player that the word has 2 spacings in it
                userWord_.replace(indexOfSpace_, 1, " ");
            }
        }
        void HideWord(){//outputs the word that the player has to guess 
            cout << endl << userWord_ << endl << endl;
        }
        void DetermineWord(){
            if(userWord_.find('#') != string::npos && breakNum_ != 1) {//will stop check when there are not more '#' and when player wins or loses
                for(int i = 0; i < storeGuess_.length(); i++){//changes all uppercase letter to lowercase for the game incase the player inputed uppercase
                storeGuess_.at(i) = tolower(storeGuess_.at(i));
                }
                if (storeGuess_ == correctAnswer_) {//checks if player guessed correctly the word 
                    cout << endl << "*******************";
                    cout << endl << "You Won This Round!" << endl;
                    cout << "*******************" << endl << endl;
                    cout << "Your word was: " << correctAnswer_ << endl;
                    winCount_++;
                    breakNum_ = 1;
                }
                else if (storeGuess_.length() > 1) {//if the word guess was wrong they lose a chance
                    cout << "You guessed the word wrong" << endl;
                    loseCount_++;   
                }
                indexOfLetter_ = correctAnswer_.find(storeGuess_);//searches the letter guess in the word the player is trying to find
                if (indexOfLetter_ != -1 && storeGuess_.length() == 1) {//if state if the player is guessing a letter and check if the letter was found
                    userWord_.replace(indexOfLetter_, 1, storeGuess_);//replaces '#' with the letter the player guessed
                    while (correctAnswer_.find(storeGuess_, indexOfLetter_ + 1) != string::npos) {//while loop to check if there are any other letters found from the player guess
                        indexOfLetter_ = correctAnswer_.find(storeGuess_, indexOfLetter_ + 1);//searches the letter guess in the word the player is trying to find
                        userWord_.replace(indexOfLetter_, 1, storeGuess_);//replaces '#' with the letter the player guessed
                    }
                    cout << "You found a letter" << endl;
                }
                else if (storeGuess_.length() == 1) {//if the letter did not match the player loses a chance
                    cout << "You didn't find the letter" << endl;
                    loseCount_++;
                }
                cout << endl;
                if (userWord_.find('#') == string::npos) {//if there are no more '#' in the word the player wins and gets a point
                    cout << endl;
                    cout << "*******************";
                    cout << endl << "You Won This Round!" << endl;
                    cout << "*******************" << endl << endl;
                    cout << "Your word was: " << correctAnswer_ << endl;
                    winCount_++;
                    breakNum_ = 1;
                }
            }
        }
        int GetScores(){//gets the score of the round 
            return winCount_;
        }
        void SetTime(int timer, int index) {//stores the time clocked for each round
            timeArray_[index] = timer;
        }
        int GetTime(int index) {//gets the time in each round
            return timeArray_[index];
        }
        int getbreakNum(){//gets the value of break num for the loop
            return breakNum_;
        }
        void PrintResult(){//prints out the hangman depending on how many chances the player has left 
            char backSlash = '\\';//stores the character of \ as \ means something else when in quotes
            if(breakNum_ != 1){//stops outputing the hangman when 
                    if (loseCount_ == 0) {
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|      /     |" << endl;
                        cout << "|            |" << endl;
                        cout << "|            |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    if (loseCount_ == 1) {
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|            |" << endl;
                        cout << "|            |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    else if (loseCount_ == 2) {
                        cout << " ____________ " << endl;
                        cout << "|      |     |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|     |      |" << endl;
                        cout << "|            |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    else if (loseCount_ == 3) {
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|    /|      |" << endl;
                        cout << "|            |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    else if (loseCount_ == 4) {
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|    /|" << backSlash << "     |" << endl;
                        cout << "|            |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    else if (loseCount_ == 5) {
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|    /|" << backSlash << "     |" << endl;
                        cout << "|    /       |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    else if (loseCount_ == 6) {
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|     o/     |" << endl;
                        cout << "|    /|" << backSlash << "     |" << endl;
                        cout << "|    / " << backSlash << "     |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                        cout << "You were hung!" << endl;
                        cout << "Your word was: " << correctAnswer_ << endl;
                        breakNum_ = 1;
                    }
            }
        }

};

int main() {
    string array[415] = {" "};
    string tempWord;
    srand(time(0));
    int randomNum[99];
    string userLetter[99];
    int players = 0;
    string p1Name;
    string p2Name;
    string difficulty;
    int numRounds;
    string checkLetter[99];                 //DECLARATIONS FOR ALL VARIABLES
    int stopNum = 0;
    string previousGuesses = "";
    int num = 0;
    int userTime[20];
    time_t start;
    time_t end;
    int timeArray[99];
    int totalscores = 0;
    int totalscores2 = 0;
    int roundOrganizer = 0;     //organizes round for 2 player
    
    WordGuess player1[99];
    WordGuess player2[99];
    
    ifstream fin;       //Declares fin
    ofstream fout;      //Declares fout
    
    fin.open("listoffoods.txt");    //Opens a file with a list of all the food words
    fout.open("html.html");         //Opens a file for an HTML page with scores output
    
    for (int i = 0; !fin.eof(); i++) {      //For loop that runs until the end of the listoffoods.txt file
        getline(fin, tempWord);             //Gets a line in the listoffoods.txt file
        array[i] = tempWord;                //Sets the line equal at index i in the array
    }
    
    cout << " ____________________________ " << endl;
    cout << "|~~~~~Welcome to Hangman~~~~~|" << endl;
    cout << "|~~~~The Category is Food~~~~|" << endl;
    cout << " ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ " << endl;
    cout << "Would you like 1 or 2 players? ";      //cin and cout for player amount
    cin >> players;
    while(players != 1 && players != 2){        //For loop that checks to make sure that user inputted 1 or 2
        cout << "I'm sorry this game can only be played with 1 or 2 players." << endl; 
        cout << "Are there 2 players or 1? ";
        cin >> players;
    } 
    cout << "Type in your difficulty between easy, normal, or hard: ";      //cin cout for difficulty
    cin >> difficulty;
    /*while loop to create a way for the player to only be able to input easy, normal, or hard */ 
    while(difficulty != "easy" && difficulty != "Easy" && difficulty != "EASY" && difficulty != "normal" && difficulty != "Normal" && difficulty != "NORMAL" && difficulty != "hard" && difficulty != "Hard" && difficulty != "HARD"){
        cout << "I'm sorry there is no " << difficulty << " mode." << endl;
        cout << "Type in your difficulty between easy, normal, or hard: ";
        cin >> difficulty;
    }
    if(players == 1){
        cout << "How many rounds do you want to play? ";        //cin cout for how many rounds the user wants to play
        cin >> numRounds;
    }
    else if (players == 2){
        cout << "How many rounds per player? ";     //cin cout for how many rounds each the users want to play
        cin >> numRounds;
    }
    if (players == 1) {     //Program if the only 1 player
        cout << "Player 1 First Name: ";        //cin cout for how player's name
        cin >> p1Name; 
        for (int i = 0; i < numRounds; i++) {       //For loop that iterates for the number of rounds
            for(int x = 0; x < 99; x++){            //For loop that makes sure the index is empty
                userLetter[x] = "";
            }
            for(int l = 0; l < 99; l++){            //For loop that makes sure the index is empty
                checkLetter[l] = "";
            }
            stopNum = 0;        //Declares stopNum as 0 for later use
            if (i == 0) {
                time(&start);       //Starts the time if it is the first round
            }
            cout << endl;
            cout << "Round " << i + 1 << endl;      //Outputs the round
            randomNum[i] = rand() % 414;        //Gets a random number between 1 and 414 (used for index of array)
            array[i] = array[randomNum[i]];     //Sets the index of the array equal to the array with index of the random number
            if(difficulty == "easy" || difficulty == "Easy" || difficulty == "EASY"){   // create for people who want easy mode in the game
                while(array[i].length() > 5 || previousGuesses.find(array[i]) != string::npos){ //While the word is greater then 5 and it can't find the word in the previously used words
                    randomNum[i] = rand() % 414;        //Gets a new random number
                    array[i] = array[randomNum[i]];     //Sets the index of the array to the array with index of the random number
                }
            }
            else if(difficulty == "normal" || difficulty == "Normal" || difficulty == "NORMAL"){    //creates a normal mode
                while(array[i].length() > 11 || array[i].length() < 6 || previousGuesses.find(array[i]) != string::npos){ //While the word is greater then 11 and it can't find the word in the previously used words
                    randomNum[i] = rand() % 414;
                    array[i] = array[randomNum[i]];
                }
            }
            else if(difficulty == "hard" || difficulty == "Hard" || difficulty == "HARD"){ //creates hard mode
                while(array[i].length() < 12 || previousGuesses.find(array[i]) != string::npos){    //While the word is greater then 11 and it can't find the word in the previously used words
                    randomNum[i] = rand() % 414;    //Gets a new random number
                    array[i] = array[randomNum[i]]; //Sets the index of the array to the array with index of the random number
                }
            }
            previousGuesses.append(array[i]);       //Adds the word to a string of previous words
            player1[i].SetWord(array[i]);       //Runs the Class function SetWord and with paremeter of the array[i]
            player1[i].SetLetters();            //Runs the Class function SetLetters
            for(int j = 0; stopNum != 1; j++){      //Checks to make sure stopNum isn't equal to 1 (sets it in the class)
            if (j == 0) {                                   //Outputs only if the it is the first guess 
                    cout << " ____________ " << endl;
                    cout << "|       |    |" << endl;
                    cout << "|      /     |" << endl;
                    cout << "|            |" << endl;
                    cout << "|            |" << endl;
                    cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
            }
            player1[i].HideWord();      //Runs the class function HideWord to output the word for user to use as a reference (########)
            cout << "Guess the entire word or pick a letter: ";
            if(i == 0 && j == 0){       //Fixed a C9 bug we had with input for round 1
                getline(cin, userLetter[j]);
            }
            getline(cin, userLetter[j]);            //Input for userLetter (user word or letter guess)
            
            for (int m = 0; m < 99; m++) {  //Loop that checks if the userGuess hasn't been used before
                while (player1[i].GetPreviousGuess(m) == userLetter[j]) {   //While the previous guess index of m isn't equal to the recent user guess
                    if (player1[i].GetPreviousGuess(m).length() == 1) {     //If it is a letter
                        cout << "You have already guessed that letter: ";
                        getline(cin, userLetter[j]);
                    }
                    else {      //If it is a word
                        cout << "You have already guessed that word: ";
                        getline(cin, userLetter[j]);
                    }
                    m = -1;         //Resets m so it starts the loop over instead of start where it left off
                }
            }
            player1[i].SetPreviousGuess(userLetter[j], j);      //Adds the guess to an array in the class
            player1[i].SetGuess(userLetter[j]);     //Sets their guess in the class by running the class function SetGuess
            player1[i].DetermineWord();            //Runs the main class function that determines if the letter or word matches
            player1[i].PrintResult();               //Output function in the class for the results
            stopNum = player1[i].getbreakNum();     //Sets stop num equal to what it is in the class
            if (stopNum != 1) {         //Checks to see if stopNum is not equal to 1 (if the word hasn't been guessed)
                cout << "Letters used:";
                for(int k = 0; k < 99; k++){            //For loop to ouput the letters the user has already used
                    if (userLetter[k].length() == 1) {      //Checks to make sure the user didn't guess a word
                        if(checkLetter[k] == userLetter[j] ){       //If the checkLetter and userLetter are the same
                        userLetter[j] = "";     //Sets the userLetter to empty
                        }
                        cout << " " << userLetter[k];  //outputs the letter
                    }
                }
                cout << endl;       //Extra spacing
                cout << "Words guessed:";   
                for(int k = 0; k < 99; k++){        //For loop that outputs the words the user has guessed
                    if (userLetter[k].length() > 1) {       //If the user guessed a word
                        if(checkLetter[k] == userLetter[j]){        //If the two strings compare
                        userLetter[j] = "";     //Sets it empty
                        }
                         cout << " " << userLetter[k]; //Outputs the word
                    }
                }
                cout << endl;       //Extra spacing
        }
        checkLetter[j] = userLetter[j];     //Sets checkLetter equal to userLetter
            }
            player1[i].GetScores();     //Gets the scores
            time(&end);     //Ends the timer
            player1[i].SetTime(difftime(end, start), i);        //Gets the difference of the start time and end time the sets it as SetTime
            time(&start);       //Restarts the timer
        }
        totalscores = 0;        //Sets totalscores equal to 0
        for(int k; k < 99; k++){        //For loop that adds up the total score the user got
            totalscores = totalscores + player1[k].GetScores();
        }
    }
    
    
    else if (players == 2) {            //If players is equal to 2
        cout << "Player 1 First Name: "; 
        cin >> p1Name;
        cout << "Player 2 First Name: ";
        cin >> p2Name;
            for (int i = 0; i < numRounds * 2; i++) {       //Multipies the rounds by 2 (since 2 players) and runs that many times
                if (i % 2 == 0) {           //Modulo to calculate which round/player it is
                cout << endl << p1Name << "'s Turn" << endl;
                }
                else {
                    cout << endl << p2Name << "'s Turn" << endl;
                }
        if(i % 2 == 0) {    //If it is player 1's turn
            if (i == 0) {
                time(&start);       //Starts the timer if it is the first round
            }
            cout << endl;
            for(int x = 0; x < 99; x++){        //Sets the user letter to empty
                userLetter[x] = "";
            }
            for(int l = 0; l < 99; l++){        //Sets the check letter to empty
                checkLetter[l] = "";
            }
            stopNum = 0;
            randomNum[i] = rand() % 414;        //Gets a random number between 1 and 414
            array[i] = array[randomNum[i]];     //Sets the array equal to the index of that number
            if(difficulty == "easy" || difficulty == "Easy" || difficulty == "EASY"){// create for people who want easy mode in the game
                while(array[i].length() > 5 || previousGuesses.find(array[i]) != string::npos){
                    randomNum[i] = rand() % 414;
                    array[i] = array[randomNum[i]];
                }
            }
            else if(difficulty == "normal" || difficulty == "Normal" || difficulty == "NORMAL"){//creates a normal mode
                while(array[i].length() > 11 || array[i].length() < 6 || previousGuesses.find(array[i]) != string::npos){
                    randomNum[i] = rand() % 414;
                    array[i] = array[randomNum[i]];
                }
            }
            else if(difficulty == "hard" || difficulty == "Hard" || difficulty == "HARD"){  //creates hard mode
                while(array[i].length() < 12 || previousGuesses.find(array[i]) != string::npos){
                    randomNum[i] = rand() % 414;
                    array[i] = array[randomNum[i]];
                    }
                }
            previousGuesses.append(array[i]);       //Adds to the previousGuesses string the word that was chosen
            player1[i].SetWord(array[i]);           //Sets the word to a private variable in the class
            player1[i].SetLetters();                //Sets the letters of the word for reference to the actual word
            for(int j = 0; stopNum != 1; j++){      //Runs until stopNum is equal to 1
                if (j == 0) {           //if it is the user's first guess
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|      /     |" << endl;
                        cout << "|            |" << endl;
                        cout << "|            |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                }
                player1[i].HideWord();      //Outputs the hidden word for reference to the actual word
                cout << "Guess the entire word or pick a letter: ";
                if(i == 0 && j == 0){           //Fixes a problem with the input we had
                    getline(cin, userLetter[j]);
                }
                getline(cin, userLetter[j]);//Input
                
                for (int m = 0; m < 99; m++) {      //Loop that checks if the user guess is the same as the previous user guesses
                    while (player1[i].GetPreviousGuess(m) == userLetter[j]) {       //Compares the previous guesses to the recent guess
                        if (player1[i].GetPreviousGuess(m).length() == 1) {     //If it is a letter
                            cout << "You have already guessed that letter: ";
                            getline(cin, userLetter[j]);
                        }
                        else {          //If it is a word
                            cout << "You have already guessed that word: ";
                            getline(cin, userLetter[j]);
                        }
                        m = -1;     //Resets m so that the loop doesn't start where it left off
                    }
                }
                player1[i].SetPreviousGuess(userLetter[j], j);
                player1[i].SetGuess(userLetter[j]);     //Sets the guess the user chose to a private variable in the class
                player1[i].DetermineWord();             //Runs the main function of the class to check if the letter is in the word
                player1[i].PrintResult();               //Prints out the results
                stopNum = player1[i].getbreakNum();     //Gets the break number from the class
                if (stopNum != 1) {         //If stop num is not equal to 1
                    cout << "Letters used:";
                    for(int k = 0; k < 99; k++){        //Outputs the words that the user has used
                        if (userLetter[k].length() == 1) {      //Checks to make sure that the length is only 1 (a letter)
                            if(checkLetter[k] == userLetter[j] ){           //Checks to see if checkLetter and userLetter compare
                            userLetter[j] = "";         //Sets it empty if it is
                            }
                            cout << " " << userLetter[k];   //Outputs the letter
                        }
                    }
                cout << endl;
                cout << "Words guessed:";
                for(int k = 0; k < 99; k++){        //Outputs the words guessed
                    if (userLetter[k].length() > 1) {           //If the guess is a word not a letter
                        if(checkLetter[k] == userLetter[j]){        //If the word is compared to previous words
                        userLetter[j] = "";                         //Sets it to an empty string
                        }
                        cout << " " << userLetter[k]; 
                    }
                    }
                cout << endl;
                }
            checkLetter[j] = userLetter[j];         //Sets checkLetter equal to userLetter
            }
            player1[i].GetScores();         //Gets the scores from the class
            time(&end);         //Ends the timer
            player1[i].SetTime(difftime(end, start), i);            //Gets the difference of the 2 times sets it in the class
            time(&start);
        }                               //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            else {                      // THIS IS THE SAME AS THE FIRST IF STATEMENT, JUST IS FOR PLAYER 2
                if (i == 1) {           //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    time(&start);
                }
                cout << endl;
                for(int x = 0; x < 99; x++){
                    userLetter[x] = "";
                }
                for(int l = 0; l < 99; l++){
                    checkLetter[l] = "";
                }
                stopNum = 0;
                randomNum[i] = rand() % 414;
                array[i] = array[randomNum[i]];
                if(difficulty == "easy" || difficulty == "Easy" || difficulty == "EASY"){// create for people who want easy mode in the game
                    while(array[i].length() > 5 || previousGuesses.find(array[i]) != string::npos){
                        randomNum[i] = rand() % 414;
                        array[i] = array[randomNum[i]];
                    }
                }
                else if(difficulty == "normal" || difficulty == "Normal" || difficulty == "NORMAL"){//creates a normal mode
                    while(array[i].length() > 11 || array[i].length() < 6 || previousGuesses.find(array[i]) != string::npos){
                        randomNum[i] = rand() % 414;
                        array[i] = array[randomNum[i]];
                    }
                }
                else if(difficulty == "hard" || difficulty == "Hard" || difficulty == "HARD"){
                    while(array[i].length() < 12 || previousGuesses.find(array[i]) != string::npos){//creates hard mode
                        randomNum[i] = rand() % 414;
                        array[i] = array[randomNum[i]];
                    }
                }
                previousGuesses.append(array[i]);
                player2[i].SetWord(array[i]);
                player2[i].SetLetters();
                for(int j = 0; stopNum != 1; j++){
                    if (j == 0) {
                        cout << " ____________ " << endl;
                        cout << "|       |    |" << endl;
                        cout << "|      /     |" << endl;
                        cout << "|            |" << endl;
                        cout << "|            |" << endl;
                        cout << " ¯¯¯¯¯¯¯¯¯¯¯¯ " << endl;
                    }
                    player2[i].HideWord();
                    cout << "Guess the entire word or pick a letter: ";
                    if(i == 0 && j == 0){
                        getline(cin, userLetter[j]);
                    }
                    getline(cin, userLetter[j]);
                    for (int m = 0; m < 99; m++) {
                        while (player2[i].GetPreviousGuess(m) == userLetter[j]) {
                            if (player2[i].GetPreviousGuess(m).length() == 1) {
                                cout << "You have already guessed that letter: ";
                                getline(cin, userLetter[j]);
                            }
                            else {
                            cout << "You have already guessed that word: ";
                            getline(cin, userLetter[j]);
                            }
                            m = -1;
                        }
                }
                    player2[i].SetPreviousGuess(userLetter[j], j);
                    player2[i].SetGuess(userLetter[j]);
                    player2[i].DetermineWord();
                    player2[i].PrintResult();
                    stopNum = player2[i].getbreakNum();
                    if (stopNum != 1) {
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
                        cout << endl;
                    }
                    checkLetter[j] = userLetter[j];
                }
                player2[i].GetScores();
                time(&end);
                player2[i].SetTime(difftime(end, start), i);
                time(&start);
            }
        }
        totalscores = 0;
        for(int k = 0; k < 99; k++){
            totalscores = totalscores + player1[k].GetScores();
        }
        totalscores2 = 0;
        for(int k = 0; k < 99; k++){
            totalscores2 = totalscores2 + player2[k].GetScores();
        }
    }
        
    int totalTime1 = 0;//declares a variable that will store the total time the 1st player used to play the game
    int totalTime2 = 0;//declares a variable that will store the total time the 2nd player used to play the game
    
    /*This is the output the html file will recieve to show the the final results of the game */
    fout << "<style>html {background-image: url('background.png') }.floatR {float:right;}.floatL {float:left;}.center {text-align:center;}.floatL {padding-left:133px;padding-right:133px;border:5px solid black;}.floatR {padding-right:133px;padding-left:133px;border:5px solid black;}</style>" << endl << endl;
    fout << "<html>" << endl;
    fout << "<title>Final Scores</title><br>" << endl;
    fout << "<h1 class = 'center' style = 'font-size:30px;'><u>Final Scores</u></h1><br>" << endl;
    if (players == 1) {
        //Player 1
        fout << "<div id = 'p1Div' class = 'center'>" << endl;
        fout << "<h1 id = 'p1Header' class = 'center'>" << p1Name << "'s Scores</h1><br>" << endl;
        fout << "<h1 class = 'center'>Final Score: " << totalscores << "</h1><br>" << endl;
        for (int i = 0; i < numRounds; i++) {//outputs time for player
            fout << "<h1 class = 'center'>Time Round " << i + 1 << ": " << player1[i].GetTime(i) << "</h1><br>" << endl;
            totalTime1 = totalTime1 + player1[i].GetTime(i);//sets total time for player 
        }
        fout << "<h1 class = 'center'>Final Time: " << totalTime1 << " seconds</h1><br>" << endl;
    }
    else if (players == 2) {
        if (totalscores > totalscores2) {
        fout << "<h1 class = 'center' style = 'font-size:40px;'>" << p1Name << " Won!</h1>" << endl;
        }
        else if (totalscores < totalscores2) {
        fout << "<h1 class = 'center' style = 'font-size:40px;'>" << p2Name << " Won!</h1>" << endl;
        }
        else if (totalscores == totalscores2){
         fout << "<h1 class = 'center' style = 'font-size:40px;'>Draw!</h1>" << endl;
        }
        //Player 1
        roundOrganizer = 0;//sets round organizer to 0 to organize the rounds
        fout << "<div id = 'p1Div' class = 'floatL'>" << endl;
        fout << "<h1 id = 'p1Header' class = 'center'>" << p1Name << "'s Scores</h1><br>" << endl;
        fout << "<h1 class = 'center'>Final Score: " << totalscores << "</h1><br>" << endl;
        for (int i = 0; i < numRounds * 2; i = i + 2) {//outputs times for each round for player 1
            if(i == 0){
            fout << "<h1 class = 'center'>Time Round " << i + 1 << ": " << player1[i].GetTime(i) << "</h1><br>" << endl;
            }
            else{
            roundOrganizer++;
            fout << "<h1 class = 'center'>Time Round " << (i + 1) - roundOrganizer << ": " << player1[i].GetTime(i) << "</h1><br>" << endl;
            }
            totalTime1 = totalTime1 + player1[i].GetTime(i);//sets the total time for player 1
        }
        fout << "<h1 class = 'center'>Final Time: " << totalTime1 << " seconds</h1><br>" << endl;
        fout << "</div>" << endl;
        //Player 2
        roundOrganizer = 0;//sets round organizer to 0 to organize the rounds
        fout << "<div id = 'p2Div' class = 'floatR'>" << endl;
        fout << "<h1 id = 'p2Header' class = 'center'>" << p2Name << "'s Scores</h1><br>" << endl;
        fout << "<h1 class = 'center'>Final Score: " << totalscores2 << "</h1><br>" << endl;
        for (int i = 1; i < numRounds * 2; i = i + 2) {//outouts times for each round
            if(i == 1){
            fout << "<h1 class = 'center'>Time Round " << i << ": " << player2[i].GetTime(i) << "</h1><br>" << endl;
            }
            else{
                roundOrganizer++;
                fout << "<h1 class = 'center'>Time Round " << i - roundOrganizer << ": " << player2[i].GetTime(i) << "</h1><br>" << endl;
            }
            totalTime2 = totalTime2 + player2[i].GetTime(i);//sets total time for player 2
        }
        fout << "<h1 class = 'center'>Final Time: " << totalTime2 << " seconds</h1><br>" << endl;
        fout << "</div>" << endl;
        }
        fin.close(); //closes the fin file
        fout.close(); //closes the fout file
        cout << "Results, go to: https://bennyserrato-workspace-spring2017-bserrato.c9users.io/Finalproject/html.html";     //Link to the HTML file that shows the output
    
    return 0;
}
