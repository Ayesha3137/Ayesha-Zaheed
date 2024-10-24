#include<iostream>
using namespace std;
int main()
{
char days;
cout<<"1. monday"<<endl;
cout<<"2. tuesday"<<endl;
cout<<"3. wednesday"<<endl;
cout<<"4. thursday"<<endl;
cout<<"5. friday"<<endl;
cout<<"6. saturday"<<endl;
cout<<"7. sunday"<<endl;
cin>>days;
switch(days)
{
case 'A':
cout<<"start of the workweek."<<endl;
break;
case 'B':
cout<<"it's tuesday,stay productive."<<endl;
break;
case 'C':
cout<<"midweek motivation!"<<endl;
break;
case 'D':
cout<<"almost the weekend."<<endl;
break;
case 'E':
cout<<"TGIF!"<<endl;
break;
case 'F':
cout<<"relax it's saturday!"<<endl;
break;
case 'G':
cout<<"enjoy your sunday."<<endl;
break;
default:
cout<<"invalid day"<<endl;
break;		
}
return 0;
}
