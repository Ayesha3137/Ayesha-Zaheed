#include <iostream>
using namespace std;
int main() 
{
int i=1;
do 
{
int j=1;
do 
{
cout<<"*";
j++; 
} 
while(j<=9);
cout<<endl;
i++;
} 
while(i<=9);
return 0;
}
