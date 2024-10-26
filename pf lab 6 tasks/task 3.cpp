#include<iostream>
using namespace std;
int main()
{
const int secretnum=31;
int usernum;
do
{
cout<<"enter secret number here(the number should be between 20 and 40):"<<endl;
cin>>usernum;
if(usernum<secretnum)
{
cout<<"too low!try again"<<endl;	
}
else if(usernum>secretnum)
{
cout<<"too high!try again"<<endl;	
}
else
{
cout<<"congragulations!your attempt is correct"<<endl;	
}
}
while(usernum!=secretnum);
return 0;	
}
