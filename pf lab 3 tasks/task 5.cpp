#include<iostream>
using namespace std;
int main()
{
int marks1,marks2,marks3,ave;
cout<<"enter marks of 3 subjects";
cin>>marks1>>marks2>>marks3;
ave=marks1+marks2+marks3/3;
if(ave>=90)
{
cout<<"Grade A";	
}
else if(ave>=80)
{
cout<<"Grade B";	
}
else if(ave>=70)
{
cout<<"Grade C";	
}
else if(ave>=60)
{
cout<<"Grade D";	
}
else
{
cout<<"Grade F";	
}
return 0;	
}
