#include <iostream>
using namespace std;
int main() 
{
int n,sum=0;
cout<<"Enter a number: ";
cin>>n;	
for(;n>0;n=n/10) 
{
sum=sum+n%10;
cout<<"Sum of the digits is=" <<sum<<endl;
}
return 0;
}
