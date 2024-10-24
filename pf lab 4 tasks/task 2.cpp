#include <iostream>
using namespace std;
int main()
{
int age;
cout << "Enter your age: ";
cin >> age;

if (age < 0)
{
cout << "Invalid age" << endl;
} 
else if (age <= 12)
{
cout << "Child" << endl;
} 
else if (age >= 13 && age <= 19) 
{
if (age == 13) 
{
cout << "Just a Teen" << endl;
} 
else 
{
cout << "Teenager" << endl;
}
}
else if (age >= 20 && age <= 60) 
{
cout << "Adult" << endl;
}
else 
{ 
cout << "Senior Citizen" << endl;
}
return 0;
}
