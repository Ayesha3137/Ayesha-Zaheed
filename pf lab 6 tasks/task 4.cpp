#include<iostream>
using namespace std;
int main()
{
int choice;
do
{
cout<<"Menu is:"<<endl;
cout<<"1. Print Hello"<<endl; 
cout<<"2. Print World"<<endl; 
cout<<"3. Exit"<<endl;
cin>>choice;	

switch(choice)
{
case 1:
cout<<"Print Hello"<<endl;
break;
case 2:
cout<<"Print World"<<endl;
break;
case 3:
cout<<"Exit"<<endl;
break;
default:
cout<<"Ooops!not available!"<<endl;
break;	
}
}	
while(choice!=3);
return 0;
}
