#include <iostream>
#include <iomanip>


using namespace std;

int main()
{
	int i,totalkm[5],lastkm[5];
	string carname[10];
	
	 
	for(i=0;i<5;i++)
	{
		cout<<"Enter car model: ";
		cin>> carname[i];
		
		cout<<"\n Enter total distance: ";
		cin>> totalkm[i];
		
		cout<<"\nEnter last km: ";
		cin>> lastkm[i];
		cout<<endl;
	}
	cout<<"\n";
    cout<< setw(20)<< left  << "Car";
	cout<< setw(20)<< left << "Total Km";
	cout<< setw(31)<< left << "Last Km";
	cout<< setw(38)<< left <<"Needs Maintainance"<<endl;
	
	
	for(i=0;i<5;i++)
	{
		 cout<<setw(20)<<left<<carname[i];
		 cout<< setw(20)<< left <<totalkm[i];
		 cout<< setw(31)<< left <<lastkm[i];
		 
		 	if(totalkm[i] - lastkm[i] > 10000)
		 		cout<< setw(38)<< left <<"YES";
	
			else
				cout<< setw(38) <<left <<"NO";	 		
	 cout<<"\n";
		 
	}
	return(0);
}
