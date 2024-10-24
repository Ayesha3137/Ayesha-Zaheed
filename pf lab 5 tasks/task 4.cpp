#include <iostream>
using namespace std;
int main()
{
int n,sum=0,digit=1;
cout<<"enter numbers";
cin>>n;
if(n<=0)
{
cout<<"\n enter numbers";
return 1;
} 
while(n>1)
{
sum+=digit;
n+=2;
}
cout<<"\n sum of odd numbers"<<n<<sum;
return 0;
}
