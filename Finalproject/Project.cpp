//I created a seperate file "testing.cpp" to work on this project so i don't create bugs in the main program, letting you know just so you want to see what things i've been working on with your coding 
//and finding bugs, btw this some amazing stuff you got here holy crap lol

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

class WordGuess {
    private:
        
    public:
        
};

int main() {
    string array[415] = {" "};
    string tempWord;
    srand(time(0));
    int randomNum[10];
    string guesses[20];
    string userLetter;
    string userWord;
    int indexOfSpace;
    int indexOfLetter;
    int timesLost = 0;
    int timesLost1 = 0;
    char backSlash = '\\';
    int players = 0;
    string p1Name;
    string p2Name;
    
    ifstream fin;
    ofstream fout;
    
    fin.open("listoffoods.txt");
    
    for (int i = 0; !fin.eof(); i++) {
        getline(fin, tempWord);
        array[i] = tempWord;
    }
    
    cout << "Would you like 1 or 2 players? ";
    cin >> players;
    if (players == 1) {
        for (int i = 0; i < 3; i++) {
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
            for (int x = 0; x < array[i].length(); x++) {       //This for loop converts a word to _ based on how long the word is
                userWord.push_back('#');
            }
            if (indexOfSpace != -1) {
                userWord.replace(indexOfSpace, 1, " ");
            }
            for (int j = 0; userWord.find('#') != string::npos; j++) {
                timesLost = 0;
                cout << endl << userWord << endl << endl;
                cout << "Guess the entire word or pick a letter: ";
                getline(cin, userLetter);
                if (userLetter == array[i]) {
                    cout << endl << "*******************";
                    cout << endl << "You Won This Round!" << endl;
                    cout << "*******************" << endl << endl;
                    break;
                }
                indexOfLetter = array[i].find(userLetter);
                if (indexOfLetter != -1 && userLetter.length() == 1) {
                    userWord.replace(indexOfLetter, 1, userLetter);
                    while (array[i].find(userLetter, indexOfLetter + 1) != string::npos) {
                        indexOfLetter = array[i].find(userLetter, indexOfLetter + 1);
                        userWord.replace(indexOfLetter, 1, userLetter);
                    }
                    cout << "You found a letter" << endl;
                }
                else if (userLetter.length() == 1) {
                    cout << "You didn't find the letter" << endl;
                    timesLost++;
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
                    cout << "You were hung!" << endl;
                    break;
                }
                cout << endl;
                if (userWord.find('#') == string::npos) {
                    cout << "*******************";
                    cout << endl << "You Won This Round!" << endl;
                    cout << "*******************" << endl << endl;
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
        for (int i = 0; i < 6; i++) {
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
                getline(cin, userLetter);
                if (userLetter == array[i]) {
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
                    indexOfLetter = array[i].find(userLetter);
                    if (indexOfLetter != -1 && userLetter.length() == 1) {
                        userWord.replace(indexOfLetter, 1, userLetter);
                        while (array[i].find(userLetter, indexOfLetter + 1) != string::npos) {
                            indexOfLetter = array[i].find(userLetter, indexOfLetter + 1);
                            userWord.replace(indexOfLetter, 1, userLetter);
                        }
                        cout << "You found a letter" << endl;
                    }
                    else if (userLetter.length() == 1) {
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
}