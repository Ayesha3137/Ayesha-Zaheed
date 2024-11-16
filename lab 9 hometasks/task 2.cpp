#include<iostream>
using namespace std;
int main() 
{
int N;
cout<<"Enter the size of the square matrix (N x N): ";
cin>>N;
int matrix[N][N],transposed[N][N];
cout<<"Enter the elements of the matrix("<<N<<"x"<<N<<"): ";
for(int i=0;i<N;++i) 
{
for(int j=0;j<N;++j) 
{
cin>>matrix[i][j];
}
}
for(int i=0;i<N;++i) 
{
for(int j=0;j<N;++j) 
{
transposed[j][i]=matrix[i][j];
}
}
cout<<"\nOriginal Matrix: ";
for(int i=0;i<N;++i) 
{
for(int j=0;j<N;++j) 
{
cout<<matrix[i][j]<<" ";
}
cout<<endl;
}
cout<<"\nTransposed Matrix: ";
for(int i=0;i<N;++i) 
{
for(int j=0;j<N;++j) 
{
cout<<transposed[i][j]<< " ";
}
cout<<endl;
}
return 0;
}
