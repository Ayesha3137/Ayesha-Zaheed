#include <iostream>
using namespace std;
int main() 
{
float entryFee= 200.0;
float snackCost=150.0;
const int MAXSTUDENTS=15;
int numStudents;
cout<<"How many students will attend the game night?(Maximum 15): ";
cin>>numStudents;
if(numStudents>MAXSTUDENTS) 
{
cout<<"Error: Not more students allowed."<<endl;
}
string studentNames;
for(int i=0;i<numStudents;++i) 
{
cout<<"Enter name for student "<<i+1<<": ";
cin>>studentNames[i];
}
cout<<"\n User names for the event:"<<endl;
for(int i=0;i<numStudents;++i) 
{
cout<<"User "<<i+1<<": "<<studentNames[i]<<endl;
}
float totalCost=0;
cout<<"\n Cost details for each student:"<<endl;
for(int i=0;i<numStudents;++i) 
{
float studentTotalCost=entryFee+snackCost;
totalCost+=studentTotalCost;
cout<<studentNames[i]<<"Entry Fee: "<< entryFee <<"+Snack Cost: "<< snackCost<<"=Total: "<< studentTotalCost<<endl;
}
cout<<"\n Total cost for all students: "<<totalCost<<endl;
return 0;
}
