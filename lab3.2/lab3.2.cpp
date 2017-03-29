//Created By: Benny Serrato
//Created On: 3/28/2017
//This program will calculate income tax and the amount owed or refunded to the user

#include <iostream>
#include <cstring>
using namespace std;
int main(){
    string firstName;
    string lastName;
    int marriageStatus;
    int grossAmount;
    int withHeld;
    int adjustedIncome;
    double incomeTax;
    double refundAmount;
    
    cout << "First name: ";
    cin >> firstName;//user input of their first name
    
    cout << "Last name: ";
    cin >> lastName;//user input of their last name
    
    cout << "Married or Single, for married press 1 for single press 2: ";
    cin >> marriageStatus;//user input of their marital status
    
    cout << "Total Gross Wage: ";
    cin >> grossAmount;//user input of their gross wage
    
    cout << "Amount Withheld: ";
    cin >> withHeld;//user input of their withheld
    
    switch(marriageStatus){//To determine the marital status of the user
        case 1:
        adjustedIncome = grossAmount - (3900 * 2);//if the user is married the gross wage will be subtracted by the personal exemption twice
            
            if(adjustedIncome > 0 && adjustedIncome <= 17850){//if the adjust gross income is between 0 and 17850
                
                incomeTax = adjustedIncome * .10;
                
            }else if(adjustedIncome > 17850 && adjustedIncome <= 72500){//if the adjusted gross income is between 17851 and 72500
               
                incomeTax = 1785 + (.15 * (adjustedIncome - 17850));
                
            }else if(adjustedIncome > 72500){//if the adjusted gross income is greater than 72500
                
                incomeTax = 9982.50 + (.28 * (adjustedIncome - 72500));
                
            }else{//if they have no income 
                incomeTax = 0;
            }
        break;
        case 2: 
        adjustedIncome = grossAmount - 3900;//if single the gross wage will be subtraqcted by the personal exemption once
            if(adjustedIncome >= 0 && adjustedIncome <= 8925){//if the adjusted gross income is between 0 and 8925
                
                incomeTax = adjustedIncome * .10;
                
            }else if(adjustedIncome > 8925 && adjustedIncome <= 36250){//if the adjusted gross income is between 8926 and 36250
                
                incomeTax = 892.50 + (.15 * (adjustedIncome - 8925));
                
            }else if (adjustedIncome > 36250 && adjustedIncome <= 87850){//if the adjusted gross income is between 36251 and 87850
               
                incomeTax = 4991.25 + (.25 * (adjustedIncome - 36250));
                
            }else if (adjustedIncome > 87850){//if the adjusted gross income is greater than 87850
                
                incomeTax = 17891.25 + (.28 * (adjustedIncome - 87850));
                
            }else{//if user has no income 
                
                incomeTax = 0;
            }
            break;
            default://the user must press 1 or 2 to recieve the appropriate amount of income tax
                cout << "Please press 1 or 2 to select marital status.";
    }
    
    refundAmount = (-1 * incomeTax) + withHeld;
    /* Outcome of program*/
    cout << endl; 
    
    cout << "Name: " << firstName << " " << lastName<< endl;
    
    cout << "Total Gross Adjusted Income: $" << adjustedIncome << endl;
    
    cout << "Total Tax Owed: $" << incomeTax << endl;
    
    if(refundAmount >= 0){//refund if the user's withheld is more than income tax
    cout << firstName << " " << lastName << " is entitled to a refund of $" << refundAmount << endl; 
    }else{//owe if user's withheld is less than income tax
        refundAmount = -1 * refundAmount;
        cout << firstName << " " << lastName << " owes the amount of $" << refundAmount << endl; 
    }
}