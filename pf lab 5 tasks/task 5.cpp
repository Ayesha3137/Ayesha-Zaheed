#include<iostream>
using namespace std;
int main()
{
const int days=7; 
double temperatures[days]; 
double sum=0.0; 
double average; 
for (int i=0;i<days;i++) 
{
cout<<"Enter the temperature for day"<<(i + 1)<<": ";
cin>>temperatures[i];
sum+=temperatures[i]; 
} 
average = sum / days;
cout<<"The average temperature for the week is"<<average<<"degrees"<<endl;
return 0;
}
