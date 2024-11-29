#include <iostream>
using namespace std;
struct YearlyBudget 
{
string items[3];      
float budget[3][12]; 
};
void inputBudgetData(YearlyBudget&budget) 
{
budget.items[0]="Rent";
budget.items[1]="Electric";
budget.items[2]="Gas";
cout<<"Enter budget data for the following items (Rent, Electric, Gas) for each month (January - December)"<<endl;
for(int i=0;i<3;i++) 
{
cout<<"Enter budget for "<<budget.items[i]<<endl;
for(int j=0;j<12;j++) 
{
cout<<"Month "<<j + 1<<": ";
cin>>budget.budget[i][j];
}
}
}
void displayBudgetData(const YearlyBudget&budget) 
{
cout<<"\n Yearly Budget:";
cout<<"---------------------------------------------\n";
cout<<"Item        | January | February | March | April | May | June | July | August | September | October | November | December\n";
cout<<"---------------------------------------------\n";
for(int i=0;i<3;i++) 
{
cout<<budget.items[i]<<" | ";
for(int j=0;j<12;j++) 
{
cout<<budget.budget[i][j]<<"  | ";
}
cout<<endl;
}
}
int main() 
{
YearlyBudget myBudget;
inputBudgetData(myBudget);
displayBudgetData(myBudget);
return 0;
}

