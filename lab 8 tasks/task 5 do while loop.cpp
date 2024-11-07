#include<iostream>
using namespace std;
int main() 
{
int n,sum = 0;
cout<<"Enter a number: ";
cin>>n;
do 
{
sum+=n%10;
n=n/10; 
} 
while(n>0);
cout<<"\nSum of digits= "<<sum<<endl;
return 0;
}

