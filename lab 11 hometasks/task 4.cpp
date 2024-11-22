#include<iostream>
using namespace std;
void printTempOpinion(int temp) 
{
if(temp<10) 
{
cout<<"Cold"<<endl;
} 
else if(temp>=20&&temp<=30) 
{
cout<<"OK"<<endl;
} 
else 
{
cout<<"Hot"<<endl;
} 
}
int main() 
{
int temperature;
cout<<"Enter the temperature: ";
cin>>temperature;
printTempOpinion(temperature);
return 0;
}

