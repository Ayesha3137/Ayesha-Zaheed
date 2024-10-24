#include<iostream>
using namespace std;
int main()
{
char op;
cout<<"1. +"<<endl;
cout<<"2. -"<<endl;
cout<<"3. /"<<endl;
cout<<"4. *"<<endl;
cin>>op;
switch(op)
{
case '+':
cout<<"addition"<<endl;
break;
case '-':
cout<<"subtraction"<<endl;
break;
case '/':
cout<<"division"<<endl;
break;
case '*':
cout<<"multiplication"<<endl;
break;
default:
cout<<"invalid operation"<<endl;
break;	
}
return 0;		
}
