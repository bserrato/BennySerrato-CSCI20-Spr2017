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
    double planPrice;//Price of the plan for phone 
    int dataPlan;//plan of amount of data
    int familyPlan;//amount of family members in plan
    string memberPlan;//check if a coporate member
    
    cout << "Dumb Phones: ";
    cin >> dumbPhone;//Customer input for amount of dumb phones
    
    cout << "Smart Phones: ";
    cin >> smartPhone;//Customer input for amount of smart phones
    
    cout << "Tablets: ";
    cin >> tabletPhone;//Customer input for amount of tablets
    
    cout << "Amount of Gigabytes: ";
    cin >> dataPlan;//Customer input for amount of gigabytes in plan
    
    cout << "Family Members in Plan: ";
    cin >> familyPlan;//Customer input for amount of family members on plan
    
    cout << "Coporate Member?: ";
    cin >> memberPlan;//Customer input for if the customer is a coperate member
    
    if(memberPlan == "yes" || memberPlan == "Yes" || memberPlan == "Y" || memberPlan == "YES" || memberPlan == "y"){//if the customer is a coportate member for the discount
        cout << "Corporate Member ";
        if (dataPlan > 32){//cheaper to have unlimited data after 32 Gigabytes
            cout << "Unlimited Data ";
            planPrice = 75 + ((dataPlan - 10) * 1.50 );
        
            if(tabletPhone >= 0 && smartPhone >= 0 && dumbPhone >= 0){//amount of phones the customer wants on the plan
            planPrice = planPrice + (tabletPhone * 10) + (smartPhone * 5) + (dumbPhone * 0);
                if (familyPlan > 2){//if customer has more than 2 people in plan
                cout << "Family Plan Discount "
                    planPrice = planPrice + ((familyPlan - 2) * 3);
                }
                else{//if customers has 2 or less people in plan
                cout << "Family Plan Discount" << endl;
                    planPrice = planPrice;
                }
            }
            else{//if customer does not want phones in plan
            planPrice = planPrice;
                if (familyPlan > 2){//if customer has more than 2 people in plan
                    planPrice = planPrice + ((familyPlan - 2) * 3);
                }
                else{//if customers has 2 or less people in plan
                    planPrice = planPrice;
                }
            }
        }
        else if(dataPlan <= 32 && dataPlan > 15){//Charge for data before 32 gigabytes
            planPrice = 5 + ((dataPlan - 1) * .75 ) + ((dataPlan - 5) * 1.5) + ((dataPlan - 15) * 3);
            if(tabletPhone >= 0 && smartPhone >= 0 && dumbPhone >= 0){//amount of phones the customer wants on the plan
            planPrice = planPrice + (tabletPhone * 10) + (smartPhone * 5) + (dumbPhone * 0);
                if (familyPlan > 2){//if customer has more than 2 people in plan
                    planPrice = planPrice + ((familyPlan - 2) * 3);
                }
                else{//if customers has 2 or less people in plan
                    planPrice = planPrice;
                }
            }
            else{//if customer does not want phones in plan
            planPrice = planPrice;
                if (familyPlan > 2){//if customer has more than 2 people in plan
                    planPrice = planPrice + ((familyPlan - 2) * 3);
                }
                else{//if customers has 2 or less people in plan
                    planPrice = planPrice;
                }
            }
        }
        else if (dataPlan <= 15 && dataPlan > 5){//if customer wants more than 5 gigabytes and atleast 15 gigabytes
        planPrice = 5 + ((dataPlan - 1) * .75 ) + ((dataPlan - 5) * 1.5);
            if(tabletPhone >= 0 && smartPhone >= 0 && dumbPhone >= 0){//amount of phones the customer wants on the plan
            planPrice = planPrice + (tabletPhone * 10) + (smartPhone * 5) + (dumbPhone * 0);
                if (familyPlan > 2){//if customer has more than 2 people in plan
                    planPrice = planPrice + ((familyPlan - 2) * 3);
                }
                else{//if customers has 2 or less people in plan
                    planPrice = planPrice;
                }
            }
            else{//if customer does not want phones in plan
            planPrice = planPrice;
                if (familyPlan > 2){//if customer has more than 2 people in plan
                    planPrice = planPrice + ((familyPlan - 2) * 3);
                }
                else{//if customers has 2 or less people in plan
                    planPrice = planPrice;
                }
            }
        }
        else{//if customer wants atleast 5 gigabytes
            planPrice = 5 + ((dataPlan - 1) *.75);
            if(tabletPhone >= 0 && smartPhone >= 0 && dumbPhone >= 0){//amount of phones the customer wants on the plan
            planPrice = planPrice + (tabletPhone * 10) + (smartPhone * 5) + (dumbPhone * 0);
                if (familyPlan > 2){//if customer has more than 2 people in plan
                    planPrice = planPrice + ((familyPlan - 2) * 3);
                }
                else{//if customers has 2 or less people in plan
                    planPrice = planPrice;
                }
            }
            else{//if customer does not want phones in plan
            planPrice = planPrice;
                if (familyPlan > 2){//if customer has more than 2 people in plan
                    planPrice = planPrice + ((familyPlan - 2) * 3);
                }
                else{//if customers has 2 or less people in plan
                    planPrice = planPrice;
                }
            }
        }
        planPrice = planPrice - (planPrice * .10);
    }    
    else{//if the customer isn't a coportate member for the discount
       if (dataPlan > 32){//cheaper to have unlimited data after 32 Gigabytes
            planPrice = 75 + ((dataPlan - 10) * 1.50 );
        
            if(tabletPhone >= 0 && smartPhone >= 0 && dumbPhone >= 0){//amount of phones the customer wants on the plan
            planPrice = planPrice + (tabletPhone * 10) + (smartPhone * 5) + (dumbPhone * 0);
                if (familyPlan > 2){//if customer has more than 2 people in plan
                    planPrice = planPrice + ((familyPlan - 2) * 3);
                }
                else{//if customers has 2 or less people in plan
                    planPrice = planPrice;
                }
            }
            else{//if customer does not want phones in plan
            planPrice = planPrice;
                if (familyPlan > 2){//if customer has more than 2 people in plan
                    planPrice = planPrice + ((familyPlan - 2) * 3);
                }
                else{//if customers has 2 or less people in plan
                    planPrice = planPrice;
                }
            }
        }
        else if(dataPlan <= 32 && dataPlan > 15){//Charge for data before 32 gigabytes
            planPrice = 5 + ((dataPlan - 1) * .75 ) + ((dataPlan - 5) * 1.5) + ((dataPlan - 15) * 3);
            if(tabletPhone >= 0 && smartPhone >= 0 && dumbPhone >= 0){//amount of phones the customer wants on the plan
            planPrice = planPrice + (tabletPhone * 10) + (smartPhone * 5) + (dumbPhone * 0);
                if (familyPlan > 2){//if customer has more than 2 people in plan
                    planPrice = planPrice + ((familyPlan - 2) * 3);
                }
                else{//if customers has 2 or less people in plan
                    planPrice = planPrice;
                }
            }
            else{//if customer does not want phones in plan
            planPrice = planPrice;
                if (familyPlan > 2){//if customer has more than 2 people in plan
                    planPrice = planPrice + ((familyPlan - 2) * 3);
                }
                else{//if customers has 2 or less people in plan
                    planPrice = planPrice;
                }
            }
        }
        else if (dataPlan <= 15 && dataPlan > 5){//if customer wants more than 5 gigabytes and atleast 15 gigabytes
        planPrice = 5 + ((dataPlan - 1) * .75 ) + ((dataPlan - 5) * 1.5);
            if(tabletPhone >= 0 && smartPhone >= 0 && dumbPhone >= 0){//amount of phones the customer wants on the plan
            planPrice = planPrice + (tabletPhone * 10) + (smartPhone * 5) + (dumbPhone * 0);
                if (familyPlan > 2){//if customer has more than 2 people in plan
                    planPrice = planPrice + ((familyPlan - 2) * 3);
                }
                else{//if customers has 2 or less people in plan
                    planPrice = planPrice;
                }
            }
            else{//if customer does not want phones in plan
            planPrice = planPrice;
                if (familyPlan > 2){//if customer has more than 2 people in plan
                    planPrice = planPrice + ((familyPlan - 2) * 3);
                }
                else{//if customers has 2 or less people in plan
                    planPrice = planPrice;
                }
            }
        }
        else{//if customer wants atleast 5 gigabytes
            planPrice = 5 + ((dataPlan - 1) *.75);
            if(tabletPhone >= 0 && smartPhone >= 0 && dumbPhone >= 0){//amount of phones the customer wants on the plan
            planPrice = planPrice + (tabletPhone * 10) + (smartPhone * 5) + (dumbPhone * 0);
                if (familyPlan > 2){//if customer has more than 2 people in plan
                    planPrice = planPrice + ((familyPlan - 2) * 3);
                }
                else{//if customers has 2 or less people in plan
                    planPrice = planPrice;
                }
            }
            else{//if customer does not want phones in plan
            planPrice = planPrice;
                if (familyPlan > 2){//if customer has more than 2 people in plan
                    planPrice = planPrice + ((familyPlan - 2) * 3);
                }
                else{//if customers has 2 or less people in plan
                    planPrice = planPrice;
                }
            }
        }
    }    
    cout << "Total Charge: $" << planPrice << endl;
    return 0;
}