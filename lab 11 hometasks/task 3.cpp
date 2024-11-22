#include<iostream>
using namespace std;
int cube(int n) 
{
return n*n*n;
}
int main() 
{
int number;
cout<<"Enter an integer to find its cube(enter 0 to stop): "<<endl;
while(true) 
{
cin>>number; 
if(number==0) 
{
break; 
}
cout<<"Cube of "<<number<<" is: "<<cube(number)<<endl;
cout<<"Enter another integer(or 0 to stop): "<<endl;
}
return 0;
}

