#include<iostream>
using namespace std;
int main()
{
int i,j;
for(i=1;i<=10;i++)
{
for(j=0;j<=5;j++)
{
cout<<j<<"*"<<i<<"="<<i*j<<"\t";	
}
cout<<endl;	
}
return 0;
}
