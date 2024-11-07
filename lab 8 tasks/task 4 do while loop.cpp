#include <iostream>
using namespace std;
int main() 
{
int n,fac=1;
cout<<"Enter a number: ";
cin>>n;
if(n<0) 
{
cout<<"Not possible for negative numbers!"<<endl;
} 
else 
{
int i=1;
do 
{
int j=1;
do 
{
fac*=i;
j++;
} 
while(j<=1);
i++;  
} 
while(i<=n);
cout<<"Factorial of "<<n <<"="<<fac<<endl;
}
return 0;
}

