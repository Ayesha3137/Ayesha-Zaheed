#include<iostream>
using namespace std;
int main()
{
int n,sum=0;
cout<<"enter a no: ";
cin>>n;
while(n>0)
{
sum=sum+n%10;
n=n/10;	
}
cout<<"\n sum of digits="<<sum<<endl;
return 0;	
}
