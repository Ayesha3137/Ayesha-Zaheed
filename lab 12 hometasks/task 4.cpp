#include <iostream>
using namespace std;
int main() 
{
int var=5;
int* pointVar=&var;
cout<<"Original value of var: "<<var<<endl;
cout<<"Address of var(&var): "<<&var<<endl;
cout<<"pointVar: "<<pointVar<<endl;
cout<<"Content of the address pointed to by pointVar (*pointVar): "<<*pointVar<<endl;
cout<<"Enter a new value for var: ";
cin>>*pointVar;
cout<<"Updated value of var: "<<var<<endl;
return 0;
}

