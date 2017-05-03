//Created By: Benny Serrato
//Created On: 5/2/2017
//This program will read student answers for a test and see if they are correct or not

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class GradeTest{//this class will calculate and grade a user's test once the answer key and user's responses are entered
    private: 
    string userAnswer_[99];//stores user's answers in the class 
    int testSize_;//determines test size
    double testScore_ = 0;//stores the test score
    string wrongAnswers_[99];//stores wrong answers
    double storePercentage_;//stores percentage recieved
    public:
    
   void setTestSize(int arraySize){//sets the test size
       testSize_ = arraySize;
   }
    void setUserAnswer(string userResponse[]){//mutator to set all user's answers
        for(int i = 0; i < testSize_; i++){
           userAnswer_[i] = userResponse[i]; 
        }
    }
    void setTestScore(string testAnswer[]){//mutator that calculates the test score 
        for(int i = 0; i < testSize_; i++){
            if(userAnswer_[i] == testAnswer[i] || userAnswer_[i] == "rand()" || userAnswer_[i] == "var"){//if correct recieve 1 point
                testScore_ = testScore_ + 1;
            }else if(userAnswer_[i] == "?"){//if ommitted recieve 0 points
                testScore_ = testScore_ + 0;
            }else{//if wrong subtract 1/4 of a point 
                wrongAnswers_[i] = userAnswer_[i];//stores the wrong answers 
                testScore_ = testScore_ - .25;
            }
        }
    }
    void setPercentage(){//mutator that calculates the percentage recieved
         storePercentage_ = (testScore_ /testSize_) * 100;
    }
    double getPercentage(){//accessor that gets percentage recieved
        return storePercentage_;//returns user's percentage recieved
    }
    string getGradeLetter(){//accessor that gets the letter grade using percentages
        string setGradeLetter;//stores grade letter
        if(storePercentage_ <= 100 && storePercentage_ >= 90 ){//if between 100 and 90 percent user recieves an A
            setGradeLetter = "A";
            
        }else if (storePercentage_ < 90 && storePercentage_ >= 80){//if between 89 and 80 percent user recieves a B
            setGradeLetter = "B";

        }else if (storePercentage_ < 80 && storePercentage_ >= 70){//if between 79 and 70 percent user recieves a C
            setGradeLetter = "C";
            
        }else if (storePercentage_ < 70 && storePercentage_ >= 60){//if between 69 and 60 percent user recieves a D
            setGradeLetter = "D";
            
        }else if (storePercentage_ < 60){//if below 59 percent user recieves a F
            setGradeLetter = "F";
            
        }
        return setGradeLetter;//returns the grade letter
    }
    string getwrongAnswers(int numWrong){//accessor that gets all wrong answers
        return wrongAnswers_[numWrong];//returns wrong answers 
    }
    double getTestScore(){//accesor that get the test score
        return testScore_;//returns the test score
    }
};

int main(){
    
    const int TEST_SIZE = 21;//Store size of test
    string firstName;//stores first name
    string lastName;//stores last name
    string answerArray[TEST_SIZE];//array that stores user's answers
    string correctAnswers[TEST_SIZE];//array that stores the answer key to test
    GradeTest testSet[99];// 
    
    ifstream fin;
    ofstream fout;
    fin.open("answerkey.txt");
    fout.open("testresult.txt");
    cout << "Please be sure to enter the answerkey to the test in the file 'answerkey.txt'" << endl;
    for(int i = 0; i < TEST_SIZE; i++){//for loop that enters the answerkey from a file
        fin >> correctAnswers[i];//enters the answerkey from a file
    }
    fin.close();
    cout << "Reading studentanswer.txt..." << endl;
    if(!fin){//to check if the file is opened in the program                         
        cout << "Error opening studentanswer.txt" << endl;
    }

    fin.open("studentanswer.txt");
    
    int j = 0;//stores index of the array of object
    while(!fin.eof()){//will continue to loop until the file ends
    fout << "Student Name: ";
    fin >> firstName;//file input for first name
    fout << firstName << " ";//file output for firstname
    fin >> lastName;//file input for last name
    fout << lastName << endl;//file output for last name
    for(int i = 0; i < TEST_SIZE; i++){
        fin >> answerArray[i];//file input for every answer
    }
    testSet[j].setTestSize(TEST_SIZE);//sets the test size for class 
    testSet[j].setUserAnswer(answerArray);//sets user's answers for class 
    testSet[j].setTestScore(correctAnswers);//sets answerkey to correct test
    testSet[j].setPercentage();//sets percantage gotten from test
    
    fout << endl;
    fout << "Answer's missed:" << endl;
    fout << endl;
    
    for(int i = 0; i < TEST_SIZE ; i++){//for loop to file output all wrong answers 
        if(testSet[j].getwrongAnswers(i) == ""){
            
        }else{
        fout << "Question " << i + 1<< ": ";
        fout << testSet[j].getwrongAnswers(i) << endl;//file output for every wrong answer 
        }
    }
    fout << endl;
    fout << "Test Score: " << testSet[j].getTestScore() << "/" << TEST_SIZE << endl;//file output for test score
    fout << "Percentage: " << testSet[j].getPercentage() << "%"<< endl;//file output for percentage
    fout << "Grade Letter: " << testSet[j].getGradeLetter() <<endl;//file output for letter grade
    fout << endl;
    j++;//moves to next index in the array of objects
}
    cout << "Finished!" << endl;
    cout << "Go to: testresult.txt , for the test results.";
    fin.close();
    fout.close();
    return 0;
}