#include<iostream>
using namespace std;
int main()
{
string rightpassword="ayesha@@",userpassword;
const int totaltries=3;
int tries=0;
do
{
cout<<"enter your password here:"<<endl;
cin>>userpassword;
tries++;
if(userpassword==rightpassword)
{
cout<<"congrats you entered correct password!"<<endl;	
}
else
{
cout<<"password you entered is incorrect,try again!"<<endl;
}
}
while(tries<totaltries);
if(tries==totaltries)
{
cout<<"attempts over,exiting program!"<<endl;	
}
return 0;
}
