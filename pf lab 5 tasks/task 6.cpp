#include <iostream>
using namespace std;
int main()
{
double balance;
double withdrawalAmount;
cout<<"Enter your initial balance";
cin>>balance;
while (true) 
{
cout<<"Enter the amount to withdraw";
cin>>withdrawalAmount;
if (withdrawalAmount == 0) 
{
cout<<"Thank you"<<endl;
break;
}
if (withdrawalAmount>balance) 
{
cout<<"Insufficient funds"<<fixed<<balance<<endl;
} 
else
{
balance-=withdrawalAmount;
cout<<"Withdrawal successful"<<fixed<<balance<<endl;
}
}
return 0;
}
