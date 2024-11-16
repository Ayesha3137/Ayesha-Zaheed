#include <iostream>
using namespace std;
int main() 
{
float ticketprice=100.0;
float popcornprice=50.0;
float totalcost;
const int maxusers=10;
int numusers;
cout<<"How many users attend the event (Maximum 10): ";
cin>>numusers;
if(numusers>maxusers) 
{
cout<<"Error:Not more users allowed."<<endl;
}
int usernames[10];
for(int i=0;i<numusers;++i) 
{
cout<<"Enter name for user "<<i + 1<<": ";
cin>>usernames[i];
}
cout<<"\n User names for the event:"<<endl;
for (int i=0;i<numusers;++i) 
{
cout<<"User"<<i + 1<<": "<<usernames[i]<<endl;
}
float totalCost=0;
cout<<"\n Cost details for each user:"<<endl;
for(int i=0;i<numusers;++i) 
{
float usertotalcost=ticketprice+popcornprice;
totalcost+=usertotalcost;
cout<<usernames[i]<<"Ticket Price: "<<ticketprice<<"+Popcorn Price: "<<popcornprice<<"=Total: "<<usertotalcost<<endl;
}
cout<<"\n Total cost for all users: "<<totalcost<<endl;
return 0;
}

