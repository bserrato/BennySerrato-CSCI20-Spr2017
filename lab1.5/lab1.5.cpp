//Created by: Benny Serrato
//Created on: 2/8/17
//This program uses strings to get and use user input for the Mad Lib
#include <iostream>
#include <string>
using namespace std;
int main (){

string firstNoun; //string created for the first noun in the Mad Lib
string firstVerb; //string created for the first verb in the Mad Lib
string firstAdjective; //string created for the first adjective in the Mad Lib
string secondNoun; //string created for the first noun in the Mad Lib
string secondVerb; //string created for the second verb in the Mad Lib
string thirdNoun; //string created for the second verb in the Mad Lib
string secondAdjective; //string created for the second adjective in the Mad Lib 
string fourthNoun; //string created for the fourth Noun in the Mad Lib

cout << "Hello welcome Mad libs we will give you input boxes to input while also telling what to input in the box such as when asking a noun input a noun and etc." << endl;
/*Minor instruction so the user understands the program */
cout << "All inputs must be one word answers. That means no spaces allowed." << endl;//rule so the User does not input whitespace in the Mad Lib

cout << "Enter your first Noun:";//User has to input their first noun
cin >> firstNoun;//User inputs a noun

cout << "Enter your first Verb:";//User has to input their first verb
cin >> firstVerb;//User inputs a verb

cout << "Enter your first Adjective:";//User has to input their first adjective
cin >> firstAdjective;//User inputs an adjective

cout << "Enter your second Noun:";//User input a second noun
cin >> secondNoun;//User inputs a noun

cout << "Enter your second Verb:";//User inputs a second verb
cin >> secondVerb;//User inputs a verb

cout << "Enter your third Noun:";//User inputs a thrid noun
cin >> thirdNoun;//User inputs a noun

cout << "Enter your second Adjective:";//User inputs a second adjective
cin >> secondAdjective;//User inputs an adjective

cout << "Enter your third Noun:";//User inputs a third noun
cin >> thirdNoun; //User inputs a noun

cout << "Enter your fourth Noun:"; //User inputs a fourth noun
cin >> fourthNoun; //User inputs a noun

cout << "There once was a guy named Doug, who was looking for " << firstNoun << " around town." << endl;//First sentence of the Mad Lib
cout << "Once Doug found "<< firstNoun <<", he " << firstVerb << "ed it or them." << endl;//Second sentence of the Mad Lib
cout << "Afterwards, Doug found a " << firstAdjective << " " << secondNoun << " at a park bench.";//Thrid sentence of the Mad Lib
cout << "Doug decided to " << secondVerb << " the " << firstAdjective << " " << secondNoun << " from the park bench to his " << thirdNoun << "." << endl;//Fourth sentence of the Mad Lib
cout << "While Doug was taking " << firstAdjective << " " << secondNoun << ", Doug took a whif of " << thirdNoun << " and passed out on the " << fourthNoun << endl;//Fith sentence of the Mad Lib
cout << "Thus concludes the adventures of " << secondAdjective << " Doug.";// Sixth and final sentence of the Mad Lib
}