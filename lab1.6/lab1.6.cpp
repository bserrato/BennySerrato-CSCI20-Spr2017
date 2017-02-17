//Created By: Benny Serrato
//Created On: 2/16/17
//This program will create descriptions of two seperate monsters for the User

#include <iostream>
#include <string>
using namespace std;
/* All strings required for the monsters*/
struct monsterCreation{
    string monsterName;// Name of the monster
    string monsterHead;// Head of the monster
    string monsterEyes;// Eyes of the monster
    string monsterEars;// Ears of the monster
    string monsterNose; // Nose of the monster
    string monsterMouth; // Mouth of the monster
};

int main();{

monsterCreation monsterOne;// Parts for the first monster
monsterCreation monsterTwo;// parts for the second monster

cout << "Enter a description of each part of your monster as stated further, you will make two monsters." << endl;

cout << "Input your first Monster's name: ";
cin >> monsterOne.monsterName;// Name of the first monster

cout << "Input your first Monster's head: ";
cin >> monsterOne.monsterHead;//Head of the first monster

cout << "Input your first Monster's eyes: ";
cin >> monsterOne.monsterEyes;//Eyes of the first monster

cout << "Input your first Monster's ears: ";
cin >> monsterOne.monsterEars;//Ears of the first monster

cout << "Input your first Monster's nose: ";
cin >> monsterOne.monsterNose;//Nose of the first monster

cout << "Input your first Monster's mouth: ";
cin >> monsterOne.monsterMouth;//Mouth of the first monster


cout << endl;

cout << "Input your second Monster's name: ";
cin >> monsterTwo.monsterName; //name of the second monster

cout << "Input your second Monster's head: ";
cin >> monsterTwo.monsterHead; //head of the second monster

cout << "Input your second Monster's eyes: ";
cin >> monsterTwo.monsterEyes; //Eyes of the second monster

cout << "Input your second Monster's ears: ";
cin >> monsterTwo.monsterEars; //Ears of the second monster

cout << "Input your second Monster's nose: ";
cin >> monsterTwo.monsterNose; //Nose of the second monster

cout << "Input your second Monster's mouth: ";
cin >> monsterTwo.monsterMouth; //Mouth of the second monster

cout << endl;

/*Outcome of the first monster */
cout << "First Monster:" << endl;
cout << monsterOne.monsterName << endl;
cout <<"Head: " << monsterOne.monsterName << endl;
cout << "Eyes: " << monsterOne.monsterEyes << endl;
cout << "Ears: " << monsterOne.monsterEars << endl;
cout << "Nose: " << monsterOne.monsterNose << endl;
cout << "Mouth: " << monsterOne.monsterMouth << endl;

cout << endl;
/*Outcome of the second monster*/
cout << "Second Monster:" << endl;
cout << monsterTwo.monsterName << endl;
cout <<"Head: " << monsterTwo.monsterName << endl;
cout << "Eyes: " << monsterTwo.monsterEyes << endl;
cout << "Ears: " << monsterTwo.monsterEars << endl;
cout << "Nose: " << monsterTwo.monsterNose << endl;
cout << "Mouth: " << monsterTwo.monsterMouth << endl;
return 0;
}