#include<iostream>
#include<fstream>
#include <string>
using namespace std;

void logActivity(const string& activity) {
    
    ofstream textfile("UserLog.txt", ios::app); 
    if (textfile.is_open()) {
        textfile << activity << endl; 
        textfile.close(); 
    } else {
        cerr << "Error: Unable to open UserLog.txt for writing!" << endl; 
    }
}

int main() {
    
    logActivity("'John' User logged in");
    logActivity("'Jane' Accessed the dashboard");
    logActivity("'Bob' Performed an operation");

    return 0;
}

