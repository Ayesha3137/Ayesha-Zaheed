#include <iostream>
#include <string>
using namespace std;
struct Product 
{
int code;
string description;
char packaging; 
float price;
float discount;
};
int main() 
{
Product products[10] = 
{
{1, "Product 1", 'S', 150.0, 10.0},
{2, "Product 2", 'M', 500.0, 5.0},
{3, "Product 3", 'L', 700.0, 15.0},
{4, "Product 4", 'L', 300.0, 5.0},
{5, "Product 5", 'L', 1000.0, 10.0},
{6, "Product 6", 'M', 250.0, 8.0},
{7, "Product 7", 'S', 50.0, 5.0},
{8, "Product 8", 'L', 850.0, 20.0},
{9, "Product 9", 'M', 450.0, 7.0},
{10, "Product 10", 'L', 1200.0, 25.0}
};
cout<<"Products with Large packaging and net price between 200 and 1000:\n";
for(int i=0;i<10;i++) 
{
if(products[i].packaging == 'L') 
{
float netPrice=products[i].price-(products[i].price*products[i].discount/100);
if(netPrice>=200&&netPrice<=1000) 
{
cout<<"Code: "<<products[i].code<<endl;
cout<<"Description: "<<products[i].description<<endl;
cout<<"Packaging: "<<products[i].packaging<<endl;
cout<<"Price: "<<products[i].price<<endl;
cout<<"%Discount: "<<products[i].discount<<endl;
cout<<"Net Price: "<<netPrice<<endl;
}
}
}
return 0;
}

