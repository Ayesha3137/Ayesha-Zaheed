#include<iostream>
using namespace std;
int main()
{
int n,table,k;
cout<<"\n enter number";
cin>>n;
for(k=1;k<=10;k++)
{
table=n*k;
cout<<n<<"*"<<k<<"="<<table<<endl;	
}
return 0;	
}
