#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ifstream fin;
    ofstream fout;
    string stringTest;

    fin.open("test.html");
    fout.open("test.js");
    
    fin >> stringTest;
    fout << stringTest;
    fin.close();
    fout.close();
}