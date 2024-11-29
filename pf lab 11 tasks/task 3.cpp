#include <iostream>
#include <limits>
using namespace std;
void findGreatest() 
{
int number,greatest=numeric_limits<int>::min();
cout<<"\n Enter 20 numbers: ";
for(int i=0;i<20;i++) 
{
cin>>number;
if(number>greatest) 
{
greatest=number;
}
}
cout<<"The greatest number is: "<<greatest<<endl;
}
int main() 
{
findGreatest();
return 0;
}

