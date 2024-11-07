#include <iostream>
using namespace std;
int main() 
{
int n,fac=1;
cout<<"Enter a number: ";
cin>>n;
if(n<0) 
{
cout<<"Not possible for the negative numbers!"<<endl;
} 
else 
{
for(int i=1;i<=n;i++) 
{
for(int j=1;j<=1;j++) 
{ 
fac*=i;
}
}
cout<<"Factorial of "<<n <<"="<<fac<<endl;
}
return 0;
}

