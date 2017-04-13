//Created By: Benny Serrato
//Created On: 4/11/17
//This program will use a class that will store an array and work with the values stored in the array

#include <iostream>
#include <cstring>
using namespace std;
class ArrayTools{//This class will store and work with 
    private:
    int arraySize_ = 0; //stores the array size 
    int storeArray_[99];//store values into the array
    public: 
    ArrayTools(int overloadArray[],int overloadSize){//overloaded constructor to store array values and array size
        arraySize_ = overloadSize;
        for (int i = 0; i < arraySize_ ;i++){
        storeArray_[i] = overloadArray[i];
        }
    }
    void Print(){//Prints the values of the array
        for(int i = 0; i < arraySize_; i++ ){
        cout << storeArray_[i]  << " ";
        }
        cout << endl;
    }
    int Find_min(int minParameter, int maxParameter){//finds the minimum value of the array
        int minNumber = storeArray_[minParameter];
        for (int i = minParameter; i < maxParameter; i++){
            if (minNumber > storeArray_[i]){
                minNumber = storeArray_[i];
            }
        }
        return minNumber;
    }
    int Find_max(int minParameter, int maxParameter){//finds the maximum of the array
        int maxNumber = storeArray_[0];
        for(int i = 0; i < arraySize_; i++){
            if (maxNumber < storeArray_[i]){
                maxNumber = storeArray_[i];
            }
        }
        return maxNumber;
    }
    int Find_sum(){
        int sumNumber = 0;
        for(int i = 0; i < arraySize_; i++){
            sumNumber = sumNumber + storeArray_[i];
        }
       return sumNumber; 
    }
    int Num_even(){//finding how many even numbers are in the array
        int evenCount = 0; 
        for(int i = 0; i < arraySize_; i++){
         if(storeArray_[i] % 2 == 0){
             evenCount++;
         }   
        }
        return evenCount;
    }
    int Num_odd(){//finding how many odd numbers are in the array
        int oddCount = 0;
        for(int i = 0; i < arraySize_; i++){
         if(storeArray_[i] % 2 == 1){
             oddCount++;
         }   
        }
        return oddCount;
    }
    int Search(int searchNumber){//searching for a specified number in the array
       for(int i = 0; i < arraySize_; i++ ){
           if (storeArray_[i] == searchNumber){
               return i;
           }
           return -1;
       }
    }
    string Is_sorted(){//determining if the array is sorted ascendingly
        string isSorted;
        for(int i = 0; i < arraySize_; i++){
        if(storeArray_[i] > storeArray_[i - 1]){
           isSorted = "yes";
        }else{
            isSorted = "no";
        }
    }
    return isSorted;
    }
};

int main()
{
    const int SIZE = 10;
    int myArray[SIZE];
    
    for(int i = 0; i < SIZE; i++){
        cin >>  myArray[i];
    }
    ArrayTools a(myArray,SIZE);
    
    a.Print();
    cout << "Min: " << a.Find_min(0, 4) << endl;
    cout << "Max: " << a.Find_max(5, 10) << endl;
    cout << "Sum = " << a.Find_sum() << endl;
    cout << "Even Numbers: " << a.Num_even() << endl;
    cout << "Odd Numbers: " << a.Num_odd() << endl;
    cout << "Search 10 " << a.Search(10) << endl;
    cout << "Sorted? " << a.Is_sorted() << endl;
    
    return 0;
}