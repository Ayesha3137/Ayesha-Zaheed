#include<iostream>
using namespace std;
int main()
{
int i=1,j;
while(i<=10)
{
int j=0;
while(j<=5)
{
cout<<j<<"*"<<i<<"="<<i*j<<"\t";
j++;
}
cout<<endl;
i++;	
}
return 0;
}
