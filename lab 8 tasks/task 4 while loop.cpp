#include <iostream>
using namespace std;
int main()
{
int n,fac=1;
cout<<"Enter a number:";
cin>>n;
if(n<0) 
{
cout<<"Not possible for negative numbers!"<<endl;
} 
else 
{
int i=1;
while(i<=n) 
{
int j=1;
while(j<=1) 
{ 
fac*=i;
j++;  
i++; 
}
cout<<"Factorial of "<<n<<"="<<fac<<endl;
}
}
return 0;
}
