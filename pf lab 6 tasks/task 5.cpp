#include <iostream>
using namespace std;
int main()
{
int N;
int sum=0;
int i=1;
cout<<"Enter a natural number N";
cin>>N;
if (N>0) 
{ 
do
{
sum+=i*i; 
i++;         
} while 
(i <= N);
}
else 
{
cout<<"Please enter a natural number greater than 0"<<endl;
return 1;
}
cout<<"The sum of squares of the first "<<N<<"natural numbers is: "<<sum<<endl;
return 0;
}

