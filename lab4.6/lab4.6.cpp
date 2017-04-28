//Created By: Benny Serrato
//Created On: 4/27/2017
//This program will read grades and output a transcript using a html file

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class CalculateGPA{//this class will be used to calculate semester and overall GPAs of a student
  private:
    int setSize_;//sets the amount of classes a student has taken
    double storeOverall_;//strres overall GPA of a student
    double semesterGPA_;//stores the semester GPA of a student
    double totalUnits_ = 0;//stores the total amount of units a student has taken
    double totalScore_ = 0;//stores the grade score for a class a student has taken
  public:
    CalculateGPA(int arraySize){//overloaded constructor that gets array size
      setSize_ = arraySize;
    }
    void setSemesterGPA(int amountUnit[], string amountGrade[]){//mutator that calculates the semester GPA
      int gradeScore = 0;//stores indivual score of a student's grade
      for(int i = 0; i < setSize_; i++){
        if(amountGrade[i] == "A"){// gives gradescore for an A
          gradeScore = 4;//score for an A
          totalScore_ = totalScore_ + (gradeScore * amountUnit[i]);//adds all scores together
          
        }else if(amountGrade[i] == "B" ){//gives gradescore for a B
          gradeScore = 3;//score for a B
          totalScore_ = totalScore_ + (gradeScore * amountUnit[i]);//adds all scores together
          
        }else if(amountGrade[i] == "C"){//gives gradescore for a C
          gradeScore = 2;//score for a C
          totalScore_ = totalScore_ + (gradeScore * amountUnit[i]);//adds all scores together
          
        }else if(amountGrade[i] == "D"){//gives gradescore for a D
          gradeScore = 1;//score for a D
          totalScore_ = totalScore_ + (gradeScore * amountUnit[i]);//adds all scores together
          
        }else if(amountGrade[i] == "F"){//gives gradescore for a F
          gradeScore = 0;//score for a F
          totalScore_ = totalScore_ + (gradeScore * amountUnit[i]);//adds all scores together
          
        }else{//if student has no grade letter for a class
          
        }
      totalUnits_= totalUnits_ + amountUnit[i];//adds all units a student is taking
      }
      semesterGPA_ = totalScore_ / totalUnits_;//calculates the semester GPA
    }
    void setOverallGPA(double cumulativeGPA, int totalHours){//mutator that calculates overall GPA after semester
      double cumulativeScore =  cumulativeGPA * totalHours;//gets total overall grade score
      totalScore_ = totalScore_ + cumulativeScore;//adds semester grade score with overall grade score
      totalUnits_ = totalUnits_ + totalHours;//adds semester units with overall units taken
      storeOverall_ = totalScore_ / totalUnits_;//calculates overall GPA after semester
      
    }
    double getSemesterGPA(){
      return semesterGPA_;
    }
    double getoverallGPA(){
      return storeOverall_;
    }
    
};

int main(){
    int arraySize = 4;//declares size the array would be for a minimum full time student
    string firstName;//stores first name
    string lastName;//stores last name
    int semesterNum;//stores the number of semester taken
    int unitList[12];//stores units for semester
    string gradeList[12];//stores grade letters for semester
    int overallUnits;//stores total units taken
    double overallGPA;//stores overall GPA
    double semesterGPA;//stores semester GPA
    CalculateGPA firstStudent(arraySize);//class object to calculate the first student's GPA
    CalculateGPA secondStudent(arraySize);//class object to calculate the second student's GPA
    CalculateGPA thirdStudent(5);//class object to calculate the third student's GPA
    ifstream fin;//declares file input
    ofstream fout;//declares file output
    
    fin.open("studentgrades.txt");//opens input file
    fout.open("lab4.6.html");//opens output file
    cout << "Reading file: studentgrades.txt" << endl;
    fout << "<html>" << endl;
    fout << "<h1>Student Transcripts </h1>" << endl; 
    fout << "<h2>Name: ";
    fin >> firstName;//gets input for first name from the input file opened
    fout << firstName << " "; //outputs first name into a file
    fin >> lastName;//gets input for last name from the input file opened
    fout << lastName << "</h2>"<< endl;//outputs last name into a file
    fout << "<h2>Semester Number:";
    fin >> semesterNum;//gets semester number from the input file 
    fout << semesterNum << "</h2>"<< endl;//outputs semester number into a file
    for(int i = 0; i < arraySize ; i++){//for loop to contain all units and grade letters in an array
        fout << "<h2>";
        fout << "Class " << i + 1 <<":" <<endl;
        fin >> unitList[i];//gets all units from input file
        fout <<"Units: " << unitList[i] << endl;//outputs all units taken into a file
        fin >> gradeList[i];//gets all grade letters from input file
        fout << "Grade: " << gradeList[i] << endl;//outputs all grade letters into a file
        fout << "</h2>" << endl;
    }
    firstStudent.setSemesterGPA(unitList, gradeList);//sets semester GPA for first student

    fin >> overallUnits;//gets overall units from input file
    fin >> overallGPA;//gets overall GPA from input file
    firstStudent.setOverallGPA(overallGPA, overallUnits);//sets overall GPA after semester for first student
    fout << "<h2>Overall GPA(Before Semester):" << overallGPA << "</h2>" << endl;//outputs the overall GPA before semester into a file
    fout << "<h2>Total Units: " << overallUnits << "</h2>" << endl; // outputs overall units into a file
    semesterGPA = firstStudent.getSemesterGPA();//stores semester GPA
    fout << "<h2>Semester GPA:" << semesterGPA << "</h2>" << endl;//outputs semester GPA into a file
    overallGPA = firstStudent.getoverallGPA();//stores overall GPA after semester
    fout << "<h2>Current Overall GPA(After Semester):" << overallGPA << "</h2><br>" << endl;//outputs overall GPA after semester into a file
    
    /*second student*/
    fout << "<h2>Name: ";
    fin >> firstName;//gets input for first name from the input file opened
    fout << firstName << " "; //outputs first name into a file
    fin >> lastName;//gets input for last name from the input file opened
    fout << lastName << "</h2>"<< endl;//outputs last name into a file
    fout << "<h2>Semester Number:";
    fin >> semesterNum;//gets semester number from the input file 
    fout << semesterNum << "</h2>"<< endl;//outputs semester number into a file
    for(int i = 0; i < arraySize ; i++){//for loop to contain all units and grade letters in an array
        fout << "<h2>";
        fout << "Class " << i + 1 <<":" <<endl;
        fin >> unitList[i];//gets all units from input file
        fout <<"Units: " << unitList[i] << endl;//outputs all units taken into a file
        fin >> gradeList[i];//gets all grade letters from input file
        fout << "Grade: " << gradeList[i] << endl;//outputs all grade letters into a file
        fout << "</h2>" << endl;
    }
    secondStudent.setSemesterGPA(unitList, gradeList);//sets semester GPA for second student

    fin >> overallUnits;//gets overall units from input file
    fin >> overallGPA;//gets overall GPA from input file
    secondStudent.setOverallGPA(overallGPA, overallUnits);//sets overall GPA after semester for second student
    fout << "<h2>Overall GPA(Before Semester):" << overallGPA << "</h2>" << endl;//outputs the overall GPA before semester into a file
    fout << "<h2>Total Units: " << overallUnits << "</h2>" << endl; // outputs overall units into a file
    semesterGPA = secondStudent.getSemesterGPA();//stores semester GPA
    fout << "<h2>Semester GPA:" << semesterGPA << "</h2>" << endl;//outputs semester GPA into a file
    overallGPA = secondStudent.getoverallGPA();//stores overall GPA after semester
    fout << "<h2>Current Overall GPA(After Semester):" << overallGPA << "</h2><br>" << endl;//outputs overall GPA after semester into a file
    
     /*third student*/ 
    fout << "<h2>Name: ";
    fin >> firstName;//gets input for first name from the input file opened
    fout << firstName << " "; //outputs first name into a file
    fin >> lastName;//gets input for last name from the input file opened
    fout << lastName << "</h2>"<< endl;//outputs last name into a file
    fout << "<h2>Semester Number:";
    fin >> semesterNum;//gets semester number from the input file 
    fout << semesterNum << "</h2>"<< endl;//outputs semester number into a file
    for(int i = 0; i < 5 ; i++){//for loop to contain all units and grade letters in an array
        fout << "<h2>";
        fout << "Class " << i + 1 <<":" <<endl;
        fin >> unitList[i];//gets all units from input file
        fout <<"Units: " << unitList[i] << endl;//outputs all units taken into a file
        fin >> gradeList[i];//gets all grade letters from input file
        fout << "Grade: " << gradeList[i] << endl;//outputs all grade letters into a file
        fout << "</h2>" << endl;
    }
    thirdStudent.setSemesterGPA(unitList, gradeList);//sets semester GPA for third student

    fin >> overallUnits;//gets overall units from input file
    fin >> overallGPA;//gets overall GPA from input file
    thirdStudent.setOverallGPA(overallGPA, overallUnits);//sets overall GPA after semester for third student
    fout << "<h2>Overall GPA(Before Semester):" << overallGPA << "</h2>" << endl;//outputs the overall GPA before semester into a file
    fout << "<h2>Total Units: " << overallUnits << "</h2>" << endl; // outputs overall units into a file
    semesterGPA = thirdStudent.getSemesterGPA();//stores semester GPA
    fout << "<h2>Semester GPA:" << semesterGPA << "</h2>" << endl;//outputs semester GPA into a file
    overallGPA = thirdStudent.getoverallGPA();//stores overall GPA after semester
    fout << "<h2>Current Overall GPA(After Semester):" << overallGPA << "</h2><br>" << endl;//outputs overall GPA after semester into a file
    
    fout << "</html>" << endl;
    
    fin.close();
    fout.close();
    cout << "Finished!" << endl;
    cout << "Go to:  https://bennyserrato-workspace-spring2017-bserrato.c9users.io/lab4.6/lab4.6.html. , for your results";
}