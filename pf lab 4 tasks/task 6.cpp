#include<iostream>
using namespace std;
int main()
{
int score;
cout<<"enter exam score out of 100";
cin>>score;
if(score>=90)
{
cout<<"grade:A"<<endl;	
}
else if(score>=80&&score<=89)
{
if(score>=85)
{	
cout<<"grade:B+"<<endl;	
}
else
{
cout<<"grade:B"<<endl;	
}
}
else if(score>=70&&score<=79)
{
if(score>=75)
{
cout<<"grade:C+"<<endl;	
}
else
{
cout<<"grade:C"<<endl;	
}
}
else if(score>=60&&score<=69)
{
cout<<"grade D"<<endl;	
}
else
{
cout<<"grade F"<<endl;	
}
return 0;	
}
