#include<iostream>
#include<fstream>
#include <string>
using namespace std;

void logActivity(const string& activity) 
{   
    ofstream textfile("UserLog.txt", ios::app); 
    if (textfile.is_open()) 
	{
        textfile << activity << endl;  
        textfile.close();  
    } 
	else 
	{
        cerr << "Error: Unable to open UserLog.txt for writing!" << endl; 
    }
}
void readLogFile()
{
    ifstream textfile("UserLog.txt"); 
    if (textfile.is_open()) 
	{
        string line;
        cout << "\nLogged Activities:\n";
      
        while (getline(textfile, line)) 
		{
            cout << line << endl;
        }
        textfile.close();  
    } 
	else 
	{
        cerr << "Error: Unable to open UserLog.txt for reading!" << endl;  
    }
}

int main() {
    
    logActivity("'John' User logged in");
    logActivity("'Jane' Accessed the dashboard");
    logActivity("'Bob' Performed an operation");

    readLogFile();

    return 0;
}

