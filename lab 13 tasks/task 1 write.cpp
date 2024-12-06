#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream file("filename.txt");
	file<<"Hello, World!"<<endl;
	file<<"File handling in C++"<<endl;
	file.close();
	
}
