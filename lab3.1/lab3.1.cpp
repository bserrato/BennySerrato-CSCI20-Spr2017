//Created By: Benny Serrato
//Created On: 3/23/2017
//This program will get appropriate cell phone plans for buyers

#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int dumbPhone;//amount of dumb phones 
    int smartPhone;//amount of smart phones
    int tabletPhone;//amount of tablets
    int planPrice;//Price of the plan for phone 
    int dataPlan;//plan of amount of data
    int familyPlan;//amount of family members in plan
    string memberPlan;//check if a coporate member
    
    cout << "Dumb Phones: ";
    cin >> dumbPhone;
    
    cout << "Smart Phones: ";
    cin >> smartPhone;
    
    cout << "Tablets: ";
    cin >> tabletPhone;
    
    cout << "Family Members in Plan";
    cin >> familyPlan;
    
    cout << "Coporate Member?";
    cin >> memberPlan;
    if(tabletPhone > 0 && smartPhone > 0 && dumbPhone > 0 && dataPlan <= 5 && familyPlan >2 && memberPlan == "yes" || memberPlan == "Yes" || memberPlan == "Y"){
        planPrice = (tabletPhone * 10)+(smartPhone * 5)+(dumbPhone * 0) + 30 + (familyPlan * 3) + 5;
        planPrice = planPrice - (planPrice * .10);
    }
    else if(tabletPhone > 0 && smartPhone > 0 && dumbPhone > 0 && dataPlan <= 5 && familyPlan > 2 && memberPlan == "no" || memberPlan == "No" || memberPlan == "N"){
        planPrice = dumbPhone * 0;
        
    }
    else if(tabletPhone > 0 && smartPhone > 0 && dumbPhone > 0 && dataPlan <= 5 && familyPlan >2 && memberPlan == "yes" || memberPlan == "Yes" || memberPlan == "Y"){
        
    }
    
    cout << "Charge: "<< planPrice << endl;
    return 0;
}