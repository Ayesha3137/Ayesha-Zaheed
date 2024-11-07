#include<iostream>
using namespace std;
int main()
{
int rows=7,i=1,j;
do
{
j=1;
do
{
cout<<"*";
j++;	
}
while(j<=i);
cout<<endl;
i++;
}
while(i<=rows);
return 0;
}
