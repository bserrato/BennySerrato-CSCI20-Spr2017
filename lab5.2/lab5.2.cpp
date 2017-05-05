//Created By: Benny Serrato
//Created On: 5/4/2017
//This program will read a cstring of the maximum size of 10 and then check if it's a paradigm
#include <iostream> 
#include <iostream>
#include <cstring> 
using namespace std;   

int main() {
    int nameLength = 10;//declares the size of the 
    char * name = new char[nameLength];//pointee

    cout << "Please enter a 10 letter word or less" << endl;
    cin >> name;

    char * head  = name;//stores the value of name into the pointer of head
    char * tail = name;//stores value of name into the pointer of tail
    nameLength = strlen(name);//gets the value of name 

    cout << "Your word is " << name << endl;//outputs the value of name

    if (nameLength<10)//to check if its 10 letters or less
    {
         while (*head != '\0')//outputs the value of head
         {
                cout << *head;
                head++;
         }
     }
     else
     {    while(nameLength > 10){//if its greater than 10 characters
          cout << "WARNING WORD TOO BIG TO DISPLAY!!" << endl;
     }
     }

     cout << endl;

     tail = &name[strlen(name) - 1];//determines the string length of tail address in pointee

     if (nameLength < 10)//checks if its 10 letter or less for tails
     {
          while (tail >= name)//outputs the value of tail backwards 
          {
                 cout << *tail;
                 tail--;
          }
     }
     cout << endl;

     head = name;//stores name in head 
     tail = &name[strlen(name) - 1];//stores the name backwards

     head++;
     tail--;

     if (*head == *tail)//checks if its a palindrome and outputs if it is or not
     {
         cout << "It is an palindrome!" << endl;
     }
     else
     {
         cout << "It is not an palindrome" << endl;
     }

     return 0; 
}