#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Contact 
{
string name;
string address;
string mobileNumber;
};
int main() 
{
Contact contacts[10] = 
{
{"Saima", "123 Elm St", "123-456-7890"},
{"Sara", "456 Oak St", "234-567-8901"},
{"Saad", "789 Pine St", "345-678-9012"},
{"Sarmad", "101 Maple St", "456-789-0123"},
{"Ali", "202 Birch St", "567-890-1234"},
{"Ahmed", "303 Cedar St", "678-901-2345"},
{"Saba", "404 Willow St", "789-012-3456"},
{"Sami", "505 Redwood St", "890-123-4567"},
{"Samina", "606 Sequoia St", "901-234-5678"},
{"Nadia", "707 Cedar St", "012-345-6789"}
};
string searchPrefix;
cout<<"Enter the starting letters of the name to search: ";
cin>>searchPrefix;
transform(searchPrefix.begin(), searchPrefix.end(), searchPrefix.begin(), ::tolower);
cout << "Contacts matching the prefix "<<searchPrefix<<endl;
bool found=false;
for(int i=0;i<10;i++) 
{
string contactNameLower=contacts[i].name;
transform(contactNameLower.begin(),contactNameLower.end(),contactNameLower.begin(),::tolower);
if(contactNameLower.find(searchPrefix) == 0) 
{
cout<<"Name: "<<contacts[i].name<<endl;
cout<<"Address: "<<contacts[i].address<<endl;
cout<<"Mobile Number: "<<contacts[i].mobileNumber<<endl;
found=true;
}
}
if(!found) 
{
cout<<"No contacts found with the given prefix."<<endl;
}
return 0;
}

