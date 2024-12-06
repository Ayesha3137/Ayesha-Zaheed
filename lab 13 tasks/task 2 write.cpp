#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream textfile("output.txt");
	textfile<<"Writing to a file in C++."<<endl;
	textfile<<"File handling is essential for data manipulation"<<endl;
	textfile.close();
}
