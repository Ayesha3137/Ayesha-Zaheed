#include<iostream>
using namespace std;
int main()
{
char amount;
cout<<"D. deposit"<<endl;
cout<<"W. withdraw"<<endl;
cout<<"T. transfer"<<endl;
cin>>amount;
switch(amount)
{
case '1':
cout<<"0.5% charges of deposited amount"<<endl;
break;
case '2':
cout<<"1.5% charges of withdraw amount"<<endl;
break;
case '3':
cout<<"2.5% charges of transfer amount"<<endl;	
break;
default:
cout<<"unknown amount";
break;	
}
return 0;	
}
