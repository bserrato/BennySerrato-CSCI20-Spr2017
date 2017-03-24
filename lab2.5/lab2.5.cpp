//Created By:Benny Serrato
//Created On:3/7/2017
//This program will use User input to get an output of five books with information that was inputed

#include <iostream>
#include <cstring>
using namespace std;
/*This class is used to get user input for books then outputs the book when finished*/
class BookInfo {
    private: 
    string bookTitle_;//store data for the book title to be accessed by functions in the class
    string bookAuthor_;//store data for the book author to be accessed by functions in the class
    int bookYear_;//store data for the book copyright year to be accessed by functions in the class
    
    public:
    /*declarations of all the functions in the class*/
    void SetBookTitle(string userTitle); 
    void SetBookAuthor(string userAuthor);
    void SetBookYear(int userYear);
    string GetBookTitle();
    string GetBookAuthor();
    int GetBookYear();
    void PrintBook();
    };
    void BookInfo::SetBookTitle(string userTitle){
        bookTitle_ = userTitle;
        return;
    }
    void BookInfo::SetBookAuthor(string userAuthor){
        bookAuthor_ = userAuthor;
        return;
    }
    void BookInfo::SetBookYear(int userYear){
        bookYear_ = userYear;
        return;
    }
    string BookInfo::GetBookTitle(){
        return bookTitle_;
    }
    string BookInfo::GetBookAuthor(){
        return bookAuthor_;
    }
    int BookInfo::GetBookYear(){
        return bookYear_;
    }
    /*Function that displays the outcome of the book information*/
    void BookInfo::PrintBook(){
        
        cout << "Book title: " << GetBookTitle() << endl;
        cout << "Book Author: " << GetBookAuthor() << endl;
        cout << "Book Copyright Year: " << GetBookYear() << endl;
        return;
        
    }
    int main(){
        
        string inputTitle;//initial variable for the book title to get user input 
        string inputAuthor;//initial variable for the book author to get user input
        int inputYear;//initial variable for the book copyright year to get user input
        
        BookInfo firstbook;//first Object to get input and output from the class for the first book
        BookInfo secondbook;//second Object to get input and output from the class for the second book
        BookInfo thirdbook;//third Object to get input and output from the class for the third book
        BookInfo fourthbook;//fourth Object to get input and output from the class for the fourth book
        BookInfo fifthbook;//fifth Object to get the input and output from the class for the fifth book
        
        cout << "Enter information for the books you will have to input five books of your choice." << endl;
        cout << endl;
        
        /*Inputing the second book information*/
        cout << "Enter the Title of the first book: ";
        getline(cin, inputTitle);
        cout << "Enter the name of the author for the first book: ";
        getline(cin, inputAuthor);
        cout << "Enter the copyright year of the first book: ";
        cin >> inputYear;
        /*Storing all user input data into the class variable to be accessed for the first book*/
        firstbook.SetBookTitle(inputTitle);
        firstbook.SetBookAuthor(inputAuthor);
        firstbook.SetBookYear(inputYear);
        
        cout << endl;
        
        cin.clear();
        cin.ignore();
        
        /*Inputing the second book information*/
        cout << "Enter the Title of the second book: ";
        getline(cin, inputTitle);
        cout << "Enter the name of the author for the second book: ";
        getline(cin, inputAuthor);
        cout << "Enter the copyright year of the second book: ";
        cin >> inputYear;
        /*Storing all user input data into the class variable to be accessed for the second book*/
        secondbook.SetBookTitle(inputTitle);
        secondbook.SetBookAuthor(inputAuthor);
        secondbook.SetBookYear(inputYear);
        
        cout << endl;
         
        cin.clear();
        cin.ignore();
        
        /*Inputing the third book information*/
        cout << "Enter the Title of the third book: ";
        getline(cin, inputTitle);
        cout << "Enter the name of the author for the third book: ";
        getline(cin, inputAuthor);
        cout << "Enter the copyright year of the third book: ";
        cin >> inputYear;
        /*Storing all user input data into the class variable to be accessed for the third book*/
        thirdbook.SetBookTitle(inputTitle);
        thirdbook.SetBookAuthor(inputAuthor);
        thirdbook.SetBookYear(inputYear);
        
        cout << endl;
         
        cin.clear();
        cin.ignore();
        /*Inputing the fourth book information*/
        cout << "Enter the Title of the fourth book: ";
        getline(cin, inputTitle);
        cout << "Enter the name of the author for the fourth book: ";
        getline(cin, inputAuthor);
        cout << "Enter the copyright year of the fourth book: ";
        cin >> inputYear;
        /*Storing all user input data into the class variable to be accessed for the fourth book*/
        fourthbook.SetBookTitle(inputTitle);
        fourthbook.SetBookAuthor(inputAuthor);
        fourthbook.SetBookYear(inputYear);
        
        cout << endl;
         
        cin.clear();
        cin.ignore();
        /*Inputing the fifth book information*/
        cout << "Enter the Title of the fifth book: ";
        getline(cin, inputTitle);
        cout << "Enter the name of the author for the fifth book: ";
        getline(cin, inputAuthor);
        cout << "Enter the copyright year of the fifth book: ";
        cin >> inputYear;
        /*Storing all user input data into the class variable to be accessed for the fifth book*/
        fifthbook.SetBookTitle(inputTitle);
        fifthbook.SetBookAuthor(inputAuthor);
        fifthbook.SetBookYear(inputYear);
        
        cout << endl;
         
        cin.clear();
        cin.ignore();
        /*Outcome of the program for the five books*/
        cout << "First Book: " << endl;
        firstbook.PrintBook();
        cout << endl;
        
        cout << "Second Book: " << endl;
        secondbook.PrintBook();
        cout << endl;
        
        cout << "Third Book: " << endl;
        thirdbook.PrintBook();
        cout << endl;
        
        cout << "Fourth Book: " << endl;
        fourthbook.PrintBook();
        cout << endl;
        
        cout << "Fifth Book: " << endl;
        fifthbook.PrintBook();
        cout << endl;

        return 0;
    }