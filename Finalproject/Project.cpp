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
    
    ifstream fin;
    ofstream fout;
    
    fin.open("listoffoods.txt");
    
    for (int i = 0; !fin.eof(); i++) {
        getline(fin, tempWord);
        array[i] = tempWord;
    }
    //WE NEED THIS IN OUR FOR LOOP TO EXECUTE EACH TIME THE FOR LOOP RUNS
    //int randomNum = rand() % 414;
    //array[randomNum]
}