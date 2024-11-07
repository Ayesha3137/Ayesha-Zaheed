#include<iostream>
using namespace std;
int main()
{
int i=1,j;
do
{
j=0;
do
{
cout<<j<<"*"<<i<<"="<<i*j<<"\t";
j++;	
}
while(j<=5);
cout<<endl;
i++;
}
while(i<=10);
return 0;
}
