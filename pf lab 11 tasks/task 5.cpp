#include <iostream>
#include <string>
using namespace std;
struct Currency 
{
string currencyType;
float amount;      
};
float convertToRupees(float dollars)
{
const float conversionRate=280.0;
return dollars*conversionRate;
}
int main() 
{
Currency userCurrency;
cout<<"Enter the amount in US Dollars (USD): ";
cin>>userCurrency.amount;
userCurrency.currencyType="Rs";
float convertedAmount=convertToRupees(userCurrency.amount);
cout<<userCurrency.amount<<" USD is equal to "<<convertedAmount<<" "<<userCurrency.currencyType<<"."<<endl;
return 0;
}

