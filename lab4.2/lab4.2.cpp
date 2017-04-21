//Created On: Benny Serrato
//Create By: 4/13/2017
//This program will run like a online shopping cart

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    const int SHOP_SIZE = 10;//size of the shop array
    string inventoryName[SHOP_SIZE] = {"Teddy Bear","Baseball Bat", "Gaming Chair", "Computer Monitor", "Keyboard", "Computer Mouse", "Notebook", "Headphones", "Hat", "Knit Gloves"};//contains the names of the items
    int inventorySize[SHOP_SIZE] = {5, 4, 8, 7, 5, 9, 3, 6, 7, 2};//contains the amount of items in stock
    double shopPrice[SHOP_SIZE] = {9.99, 24.99, 109.99, 89.99, 20.99, 79.99, 16.02, 49.99, 24.00, 6.00};//contains the prices of items 
    string customerCart[99];//contain the customer's items being purchased
    double totalPrice = 0;//calculating the total amount after selecting items
    string userAnswer;
    
    cout << "List of items for purchase" << endl;
    cout << endl;
    
    for(int i = 0;i < SHOP_SIZE; i++){//for loop to create a list for what for sale amount in store and prices of in inventory
    cout << inventoryName[i] << ", Amount Left: " << inventorySize[i] << ", Cost: $" << shopPrice[i] << endl;
    }
    
    cout << endl;
    cout << "Please type what items you want to putting in your shopping cart." << endl;
    
        for(int i = 0; i < 99; i++ ){//determine what the customer wishes to purchase
                if(userAnswer == "No" || userAnswer == "no"){
                    
                }else{
                getline(cin, customerCart[i]);
                /*Determines what the customer wants and to check if that item is still in stock */
                if(customerCart[i] == inventoryName[0] && inventorySize[0] > 0){
                    totalPrice = totalPrice + shopPrice[0];//Calculates the amount the customer will owe
                    inventorySize[0]= inventorySize[0] - 1;//removes one from inventory when purchased
                    cout << inventoryName[0] << " Amount Left: " << inventorySize[0] << endl;
            
                }else if(customerCart[i] == inventoryName[1] && inventorySize[1] > 0){
                    totalPrice = totalPrice + shopPrice[1];//Calculates the amount the customer will owe
                    inventorySize[1] = inventorySize[1] - 1;//removes one from inventory when purchased
                    cout << inventoryName[1] << " Amount Left: " << inventorySize[1] << endl;
            
                }else if(customerCart[i] == inventoryName[2] && inventorySize[2] > 0){
                    totalPrice = totalPrice + shopPrice[2];//Calculates the amount the customer will owe
                    inventorySize[2] = inventorySize[2] - 1;//removes one from inventory when purchased
                    cout << inventoryName[2] << " Amount Left: " << inventorySize[2] << endl;
            
                }else if(customerCart[i] == inventoryName[3] && inventorySize[3] > 0){
                    totalPrice = totalPrice + shopPrice[3];//Calculates the amount the customer will owe
                    inventorySize[3] = inventorySize[3] - 1;//removes one from inventory when purchased
                    cout << inventoryName[3] << " Amount Left: " << inventorySize[3] << endl;
            
                }else if(customerCart[i] == inventoryName[4] && inventorySize[4] > 0){
                    totalPrice = totalPrice + shopPrice[4];//Calculates the amount the customer will owe
                    inventorySize[4] = inventorySize[4] - 1;//removes one from inventory when purchased
                    cout << inventoryName[4] << " Amount Left: " << inventorySize[4] << endl;
            
                }else if(customerCart[i] == inventoryName[5] && inventorySize[5] > 0){
                    totalPrice = totalPrice + shopPrice[5];//Calculates the amount the customer will owe
                    inventorySize[5] = inventorySize[5] - 1;//removes one from inventory when purchased
                    cout << inventoryName[5] << " Amount Left: " << inventorySize[5] << endl;
            
                }else if(customerCart[i] == inventoryName[6] && inventorySize[6] > 0){
                    totalPrice = totalPrice + shopPrice[6];//Calculates the amount the customer will owe
                    inventorySize[6] = inventorySize[6] - 1;//removes one from inventory when purchased
                    cout << inventoryName[6] << " Amount Left: " << inventorySize[6] << endl;
            
                }else if(customerCart[i] == inventoryName[7] && inventorySize[7] > 0){
                    totalPrice = totalPrice + shopPrice[7];//Calculates the amount the customer will owe
                    inventorySize[7] = inventorySize[7] - 1;//removes one from inventory when purchased
                    cout << inventoryName[7] << " Amount Left: " << inventorySize[7] << endl;
            
                }else if(customerCart[i] == inventoryName[8] && inventorySize[8] > 0){
                    totalPrice = totalPrice + shopPrice[8];//Calculates the amount the customer will owe
                    inventorySize[8] = inventorySize[8] - 1;//removes one from inventory when purchased
                    cout << inventoryName[8] << " Amount Left: " << inventorySize[8] << endl;
            
                }else if(customerCart[i] == inventoryName[9] && inventorySize[9] > 0){
                    totalPrice = totalPrice + shopPrice[9];//Calculates the amount the customer will owe
                    inventorySize[9] = inventorySize[9] - 1;//removes one from inventory when purchased
                    cout << inventoryName[9] << " Amount Left: " << inventorySize[9] << endl;
            
                }else{//When an item runs out of stock or when customer inputs the item incorrectly
                    if(inventorySize[0] <= 0 || inventorySize[1] <= 0 || inventorySize[2] <= 0 || inventorySize[3] <= 0 || inventorySize[4] <= 0 || inventorySize[5] <= 0 || inventorySize[6] <= 0 || inventorySize[7] <= 0 || inventorySize[8] <= 0 || inventorySize[9] <= 0){
                
                        cout << "Sorry! " << customerCart[i] << " is out of stock!" << endl;
                        cout << "We do have other items available for purchase! " << endl;
                    }else{
                        cout << "I'm sorry could you repeat that again I didn't understand." << endl;
                    }
                    i--;
                }
                }
        }
        cout << "You've purchased: " << endl;
        
        for(int i = 0; i < SHOP_SIZE; i++){//Prints out all of the customer's purchases
            cout << customerCart[i] << " ";
        }
        cout << endl;
        cout << "Your total is: $" << totalPrice;//Total amount the customer owes
}