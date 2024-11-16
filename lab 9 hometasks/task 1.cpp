#include<iostream>
using namespace std;
int main() 
{
int arr[3];
cout<<"Enter three integer values: ";
for(int i=0;i<3;++i) 
{
cin>>arr[i];
}
cout<<"\n Values in forward order: ";
for(int i=0;i<3;++i) 
{
cout<<arr[i]<<" ";
}
cout<<"\n Values in reversed order: ";
for(int i=2;i>=0;--i) 
{
cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}

