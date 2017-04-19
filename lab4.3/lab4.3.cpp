//Created By: Benny Serrato
//Created On: 4/18/2017
//This program will run like a online store using classes to store what is for sell, their pricing, and how much is in stock.

#include<iostream>
#include<string>
using namespace std;

class StoreInventory{//this class will be used to store the items for sale, their price, and amount for sale and 
    private:
        string storeName_[99];
        double inventoryPrice_[99];
        double totalCost_ = 0;
        int inventoryStock_[99];
        int shopSize_;
        string storePurchases_[99];
    public:
    StoreInventory(const int stockSize){//overloaded constructor to determine the array size
            shopSize_ = stockSize;
        }
    void setStoreInventory(string storeInventory[]){//sets the name of the items for sale
        for(int i= 0; i < shopSize_; i++){
            storeName_[i] = storeInventory[i];
        }
    }
    string getStoreInventory(int accessInventory){//will return the names of the items for sale
        return storeName_[accessInventory];
    }
    void setStorePrices(double storePrices[]){//sets the item prices
        for(int i = 0; i < shopSize_; i++){
            inventoryPrice_[i] = storePrices[i];
        }
    }
    double getStorePrices(int accessPrices){//returns the item prices
        return inventoryPrice_[accessPrices];
    }
    void setInventoryStock(int storeStock[]){//sets the amount for sale 
        for(int i = 0; i < shopSize_; i++){
            inventoryStock_[i] = storeStock[i];
        }   
    }
    int getInventoryStock(int accessStock){//will return the amount for sale
        return inventoryStock_[accessStock];
    } 
    void setCustomerPurchases(string storeInputs[]){//sets all customer purchases
        for(int i = 0; i < 99;i++){
        storePurchases_[i] = storeInputs[i];
        }
    }
    string getCustomerPurchases(int amountPurchased){//returns all customer purchases
        return storePurchases_[amountPurchased];
    }
};

int main(){
    const int STORE_SIZE = 10;//size of the store's array
    string inventoryName[STORE_SIZE] = {"Soccer Cleats","Baseball Bat","Football","Football Helmet","Socks","Hat","Sunglasses","Sunscreen","Hiking Boots","Canoe"};//array that stores inventory name
    double shopPrices[STORE_SIZE] = {59.18,24.99,25.00,51.99,9.99,24.00,15.95,26.50,54.83,269.99};//array that stores inventory pricing 
    int stockSize[STORE_SIZE]={10, 20, 15, 11, 5, 23, 18, 17, 9, 4};//array that stores all amount of inventory
    string customerPurchase[99];//arrray that is the customer's shopping cart
    string userAnswer;//Determines if the customer wishes to continue shopping
    int totalPrice = 0;//will Calculate the amount the customer owes
    int purchaseCounter = 0;//counts all purchases the customer made
    StoreInventory sportStore(STORE_SIZE);

    sportStore.setStoreInventory(inventoryName);
    sportStore.setStorePrices(shopPrices);
    sportStore.setInventoryStock(stockSize);
    
    cout << "Welcome to the online sport store!" << endl;
    cout << "Here is a list what is for sale." << endl;
    cout << endl;
    
    for(int i = 0; i < STORE_SIZE;i++){
        cout << sportStore.getStoreInventory(i) << ", Price: $" << sportStore.getStorePrices(i) << ", Amount Left: " << sportStore.getInventoryStock(i) << endl;
    }
    
    cout << endl;
    cout << "Please type what items you want to purchase." << endl;
        for(int i = 0; i < 99; i++ ){//will check if the item the customer call is for sale or not
                if(userAnswer == "no" || userAnswer == "No"){//whenever the customer decides to quit selecting items
                }else{
                    getline(cin, customerPurchase[i]);
                    purchaseCounter++;
                /*Determines what the customer wants and to check if that item is still in stock */
                if(customerPurchase[i] == inventoryName[0] && stockSize[0] > 0){
                    totalPrice = totalPrice + shopPrices[0];//Calculates the amount cost of the customer's purchases
                    stockSize[0]= stockSize[0] - 1;//removes one from amount for sale
                    cout << inventoryName[0] << " Amount Left: " << stockSize[0] << endl;
                    cout << "Do you wish to continue purchasing?" << endl; 
                    getline(cin, userAnswer);//Customer's reponse if they wish to continue purchasing items
                }else if(customerPurchase[i] == inventoryName[1] && stockSize[1] > 0){
                    totalPrice = totalPrice + shopPrices[1];//Calculates the amount cost of the customer's purchases
                    stockSize[1] = stockSize[1] - 1;//removes one from amount for sale
                    cout << inventoryName[1] << " Amount Left: " << stockSize[1] << endl;
                    cout << "Do you wish to continue purchasing?" << endl;
                    getline(cin, userAnswer);//Customer's reponse if they wish to continue purchasing items
                }else if(customerPurchase[i] == inventoryName[2] && stockSize[2] > 0){
                    totalPrice = totalPrice + shopPrices[2];//Calculates the amount cost of the customer's purchases
                    stockSize[2] = stockSize[2] - 1;//removes one from amount for sale
                    cout << inventoryName[2] << " Amount Left: " << stockSize[2] << endl;
                    cout << "Do you wish to continue purchasing?" << endl;
                    getline(cin, userAnswer);//Customer's reponse if they wish to continue purchasing items
                }else if(customerPurchase[i] == inventoryName[3] && stockSize[3] > 0){
                    totalPrice = totalPrice + shopPrices[3];//Calculates the amount cost of the customer's purchases
                    stockSize[3] = stockSize[3] - 1;//removes one from amount for sale
                    cout << inventoryName[3] << " Amount Left: " << stockSize[3] << endl;
                    cout << "Do you wish to continue purchasing?" << endl;
                    getline(cin, userAnswer);//Customer's reponse if they wish to continue purchasing items
                }else if(customerPurchase[i] == inventoryName[4] && stockSize[4] > 0){
                    totalPrice = totalPrice + shopPrices[4];//Calculates the amount cost of the customer's purchases
                    stockSize[4] = stockSize[4] - 1;//removes one from amount for sale
                    cout << inventoryName[4] << " Amount Left: " << stockSize[4] << endl;
                    cout << "Do you wish to continue purchasing?" << endl;
                    getline(cin, userAnswer);//Customer's reponse if they wish to continue purchasing items
                }else if(customerPurchase[i] == inventoryName[5] && stockSize[5] > 0){
                    totalPrice = totalPrice + shopPrices[5];//Calculates the amount cost of the customer's purchases
                    stockSize[5] = stockSize[5] - 1;//removes one from amount for sale
                    cout << inventoryName[5] << " Amount Left: " << stockSize[5] << endl;
                    cout << "Do you wish to continue purchasing?" << endl;
                    getline(cin, userAnswer);//Customer's reponse if they wish to continue purchasing items
                }else if(customerPurchase[i] == inventoryName[6] && stockSize[6] > 0){
                    totalPrice = totalPrice + shopPrices[6];//Calculates the amount cost of the customer's purchases
                    stockSize[6] = stockSize[6] - 1;//removes one from amount for sale
                    cout << inventoryName[6] << " Amount Left: " << stockSize[6] << endl;
                    cout << "Do you wish to continue purchasing?" << endl;
                    getline(cin, userAnswer);//Customer's reponse if they wish to continue purchasing items
                }else if(customerPurchase[i] == inventoryName[7] && stockSize[7] > 0){
                    totalPrice = totalPrice + shopPrices[7];//Calculates the amount cost of the customer's purchases
                    stockSize[7] = stockSize[7] - 1;//removes one from amount for sale
                    cout << inventoryName[7] << " Amount Left: " << stockSize[7] << endl;
                    cout << "Do you wish to continue purchasing?" << endl;
                    getline(cin, userAnswer);//Customer's reponse if they wish to continue purchasing items
                }else if(customerPurchase[i] == inventoryName[8] && stockSize[8] > 0){
                    totalPrice = totalPrice + shopPrices[8];//Calculates the amount cost of the customer's purchases
                    stockSize[8] = stockSize[8] - 1;//removes one from amount for sale
                    cout << inventoryName[8] << " Amount Left: " << stockSize[8] << endl;
                    cout << "Do you wish to continue purchasing?" << endl;
                    getline(cin, userAnswer);//Customer's reponse if they wish to continue purchasing items
                }else if(customerPurchase[i] == inventoryName[9] && stockSize[9] > 0){
                    totalPrice = totalPrice + shopPrices[9];//Calculates the amount cost of the customer's purchases
                    stockSize[9] = stockSize[9] - 1;//removes one from amount for sale
                    cout << inventoryName[9] << " Amount Left: " << stockSize[9] << endl;
                    cout << "Do you wish to continue purchasing?" << endl;
                    getline(cin, userAnswer);//Customer's reponse if they wish to continue purchasing items
                }else{//When an item runs out of stock or when customer inputs the item incorrectly
                    if(stockSize[0] <= 0 || stockSize[1] <= 0 || stockSize[2] <= 0 || stockSize[3] <= 0 || stockSize[4] <= 0 || stockSize[5] <= 0 || stockSize[6] <= 0 || stockSize[7] <= 0 || stockSize[8] <= 0 || stockSize[9] <= 0){
                
                        cout << "Sorry! " << customerPurchase[i] << " is out of stock!" << endl;
                        cout << "We do have other items available for purchase! " << endl;
                        cout << "Do you wish to continue purchasing?" << endl;
                        getline(cin, userAnswer);//Customer's reponse if they wish to continue purchasing items
                    }else{
                        cout << "I'm sorry could you repeat that again I didn't understand." << endl;
                    }
                    i--;
                }
                }
        }
        sportStore.setCustomerPurchases(customerPurchase);//stores all purchases inside of object sportStore
        cout << "You've purchased: " << endl;
        
        for(int i = 0; i < purchaseCounter; i++){//Prints out all of the customer's purchases
           cout << sportStore.getCustomerPurchases(i) << " ";
        }
        cout << endl;
        cout << "Your total is: $" << totalPrice;//Total amount the customer owes
    
    
    return 0;
}