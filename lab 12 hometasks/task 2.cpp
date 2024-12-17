#include<iostream>
using namespace std;
int main(){
int a=5,x=10;
int* ptra = &a;
int* ptrx = &x;
cout<<"Before swapping"<<endl;
cout<<"a="<<a<<" x="<<x<<endl;
int temp=a; 
*ptra=*ptrx;   
*ptrx=temp;    
cout<<"After swapping"<<endl;
cout<<"a="<<a<<" x ="<<x<<endl;
return 0;
}
