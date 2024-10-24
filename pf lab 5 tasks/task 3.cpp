#include<iostream>
using namespace std;
int main()
{
int number; 
int sum = 0; 
cout <<"Enter numbers to sum (negative number to stop)"<< endl;
while (true) 
{
cin >> number; 
if (number < 0) 
{
break; 
}
sum += number; 
}
cout <<"Total sum of non-negative numbers"<<sum<<endl;
return 0;
}
