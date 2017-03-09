//Created By:Benny Serrato
//Created On:3/9/2017
//This program will convert temperatures into Kelvins,Celsius,and Fahrenheit
#include <iostream>
using namespace std;

class TemperatureConverter{//This class will convert temperatures Kelvin, Celsius, Fahrenheit
  public:
  TemperatureConverter();
  TemperatureConverter(double resKelvin);
  void SetTempFromKelvin (double userKelvin);
  double GetTempFromKelvin();
  void SetTempFromCelsius(double userCelsius);
  double GetTempAsCelsius();
  void SetTempFromFahrenheit(double userFahrenheit);
  double GetTempAsFahrenheit();
  void PrintTemperatures();
  private:
  double kelvin_;
};
TemperatureConverter::TemperatureConverter(){
    kelvin_ = 0;
}
TemperatureConverter::TemperatureConverter(double resKelvin){
    kelvin_ = resKelvin;
}
void TemperatureConverter::SetTempFromKelvin(double userKelvin){
    kelvin_ = userKelvin;
    return;
}
double TemperatureConverter::GetTempFromKelvin(){
    return kelvin_;
}
void TemperatureConverter::SetTempFromCelsius(double userCelsius){
    kelvin_ = userCelsius + 273.15;
    return;
}
double TemperatureConverter::GetTempAsCelsius(){
    return kelvin_ - 273.15;
}
void TemperatureConverter::SetTempFromFahrenheit(double userFahrenheit){
    kelvin_ = (5*(userFahrenheit - 32)/9) + 273.15;
    return;
}
double TemperatureConverter::GetTempAsFahrenheit(){
    return ((kelvin_ - 273.15) * 9)/5 + 32;
}
void TemperatureConverter::PrintTemperatures(){
    cout << "Kelvin: " << GetTempFromKelvin() << endl;
    cout << "Celsius: " << GetTempAsCelsius() << endl;
    cout << "Fahrenheit: " << GetTempAsFahrenheit() << endl;
    cout << endl;
    return;
}
int main(){
    TemperatureConverter temp1; //testing default constructor
    TemperatureConverter temp2(274); //testing overloaded constructor
    
    temp1.PrintTemperatures();
    temp2.PrintTemperatures();
    
    temp1.SetTempFromKelvin(400.15); //testing mutator function
    cout<<temp1.GetTempFromKelvin()<<endl;//testing accessor function
    temp1.PrintTemperatures();
    
    temp2.SetTempFromCelsius(32); //testing other functions
    cout<<temp2.GetTempAsCelsius()<<endl;
    temp2.PrintTemperatures();
    
    temp2.SetTempFromFahrenheit(32); 
    cout<<temp2.GetTempAsFahrenheit()<<endl;
    temp2.PrintTemperatures();
    
    return 0;
}