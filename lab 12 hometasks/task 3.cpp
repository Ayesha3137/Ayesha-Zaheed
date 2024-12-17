#include <iostream>
using namespace std;
int square(int z)
{
return z*z;
}
int main()
{
int(*squarePtr)(int);
squarePtr=&square;
int z;
cout<<"Enter a number: ";
cin>>z;
int result=squarePtr(z);
cout<<"The square"<<" is "<<result<<endl;
return 0;
}

