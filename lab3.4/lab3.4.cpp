//Checked By: Benny Serrato
//Checked On: 4/4/2017
//This program should correctly calculate loans
 
/*********************************************************************
Write a loan calculator program. The user borrows A dollars at R%interest (compounded monthly) 
and makes a payment of P dollars at theend of each month. Your program should get all of this 
informationfrom the user as well as Y, a number of years to simulate, and shouldreturn the balance 
left after Y years. A typical run of the programmight look something like this: Enter the amount borrowed: 
10000Enter the monthly payment you'll make: 200Enter the annual interest rate: 7.5Enter the number of years you 
want to simulate: 3At the end of 3 years you owe 4468.19 dollars By running the program several times, you should 
be able to tell meapproximately how long it'll take to pay off your debt. For those that are unfamiliar with annual 
rates compounded monthly, ifR is the given annual rate and we do monthly compounding, then eachmonth's interest is 
computed at the rate R/12. Remember, if yourbalance owed at the beginning of the month is b then your balance owedat 
the end of the month will b(1 + (R/100)/12) minus the payment P youmake at the end of the month. ***********************************************************************/

#include <iostream>
using namespace std; 
int main(){
  double a, m, r, I; /* I which represents interest per month should be double because the when calculating monthly it 
  removes the decimals when declare as int causing the total owed after said years to not be exact*/
  
  int y;   // Input amount, payment, interest rate, and number of years
  cout << "Enter the amount borrowed: ";
  cin >> a;
  cout << "Enter the monthly payment you'll make: ";
  cin >> m;
  cout << "Enter the annual interest rate: ";
  cin >> r;
  cout << "Enter the number of years you want to simulate: ";
  cin >> y;
   // convert interest rate from percent to fraction
  r = r/100;
   // iterate through each month
  for(int i = 0; i < y*12; i++)
  {
    // calculate additional interest
    I = a*(r/12);
    // add interest and subtract payment from balance
    a = a + I - m;
  }
   // Print ending amount
  cout << "At the end of " << y << " years you owe " << a << " dollars" << endl;
   return 0;
   
}