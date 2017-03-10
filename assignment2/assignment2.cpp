//Created by: Benny Serrato
//Created On: 2/28/2017
//This program will convert the distance of a  unit of measurement to another unit of measurements by using a class

#include <iostream>
using namespace std;

class MeasurementConverter {//This is class will display a distance using the measurements of miles, yards, feet, or inches
  public:
  MeasurementConverter(){//default constructor
      miles_ = 0;
  }
  MeasurementConverter(double resMiles){//overloaded constructor
      miles_ = resMiles;
  }
  void SetDistMiles(double userMiles){//store miles in the private variable
      miles_ = userMiles;
      return;
  }
  double GetDistInMiles(){//returns stored miles
   return miles_;
  }
  void SetDistFromYards(double userYards){//converts yards to miles and stores in the private variable
  miles_ = userYards / 1760;
  return;
  }
  double GetDistAsYards(){//converts miles to yards and returns it
      return miles_ * 1760;
  }
  void SetDistFromFeet(double userFeet){//converts feet to miles and stores it in the private variable
      miles_ = userFeet / 5280;
      return;
  }
  double GetDistAsFeet(){//converts miles to feet and returns it
      return miles_ * 5280;
  }
  void SetDistFromInches(double userInches){//converts inches to miles and stores in the private variable
      miles_ = userInches / 63360;
      return;
  }
  double GetDistAsInches(){//converts miles to inches and returns it
      return miles_ * 63360;
  }
  void PrintMeasurements(){//prints out all returned measurements in main()
      cout << "Miles: " << GetDistInMiles() << endl;
      cout << "Yards: " << GetDistAsYards() << endl;
      cout << "Feet: "  << GetDistAsFeet()  << endl;
      cout << "Inches: " << GetDistAsInches() << endl;
      cout << endl;
      return;
  }
  private:
  double miles_;//stores the value of miles
};

int main(){
    MeasurementConverter dist1;//testing the default constructor
    MeasurementConverter dist2(15);//testing the overloaded constructor
    
    dist1.PrintMeasurements();
    dist2.PrintMeasurements();
    
    /*Testing miles conversion functions*/
    dist1.SetDistMiles(1);//mutator function for miles
    cout << "Starting Miles: " << dist1.GetDistInMiles() << endl;//accessor function for miles
    dist1.PrintMeasurements();
    
    /*Testing yards conversion */
    dist2.SetDistFromYards(20); //mutator for yards
    cout << "Starting Yards: " <<  dist2.GetDistAsYards() << endl; //accessor for yards
    dist2.PrintMeasurements();
    
    /* Testing feet conversion */
    dist2.SetDistFromFeet(16);  //mutator for feet
    cout << "Starting Feet: " << dist2.GetDistAsFeet() << endl; //accessor for feet
    dist2.PrintMeasurements();
    
    /* Testing inches conversion */
    dist2.SetDistFromInches(100);
    cout << "Starting Inches: " << dist2.GetDistAsInches() << endl;
    dist2.PrintMeasurements();
    
    return 0; 
}