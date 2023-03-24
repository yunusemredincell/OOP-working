#include <iostream>
#include <string>
#include <iomanip> // to use setw functiton during the printing information.

using namespace std;

class Employee{ // Create a Employee class to calculate bonus for each employee according to the their year and salary.
	
	private:  // Create private section to protect variable from others.
		string name;
		int year;
		double salary;
		double bonus;
		
		
	public: 
	// Create set functions to access  private variable.
	void setName(string empname)
	{
		name = empname;
	}
	
	void setYear(int empyear)
	{
		year = empyear;
	}
	
	void setSalary(double empsalary)
	{
		salary = empsalary;
		
	}
	// Create a calculate bonus function to calculate employee's bonus to use employee's year.
	void calculateBonus()
	{
		
		if(year<=5)
			bonus *= 0;
		else if(year>5 && year<=10)
			bonus= salary * 0.05;
		else if(year>10 && year<=15)
			bonus= salary * 0.10;
		else if(year>15 && year<=20)
			bonus=salary * 0.15;
		else if(year>20)
			bonus=salary * 0.20;				
			
	}
	
	// Finally, to print all information we create a print function.
	void print()
	{
		cout << setw(20)<<left <<name << setw(20)<<left << year <<setw(20)<<left << salary <<setw(20)<<left << bonus <<endl;
	}
};



int main()
{
	// We create temporary variable to read information.
	string tempname;
	double tempsalary;
	int n;
	int tempyear;
	
	cout<<"Please enter the number of workers whose bonus you want to know: ";
		cin>>n;
		
	Employee arr[n]; // We create an employee array to access public functions in class. 
	
	for(int i{0} ; i<n ; i++)
	{
		cout<<"\nEnter employee name, employed years and salary:";
			cin >>tempname>>tempyear>>tempsalary;
				
		arr[i].setName(tempname);
		arr[i].setYear(tempyear);
		arr[i].setSalary(tempsalary);	
	}	
	
	
	for(int i{0} ; i<n ; i++)
	{
		arr[i].calculateBonus();
	}
		
	cout<<"\n\n";
	
	cout<< setw(20) << left  << "Name" << setw(20) << left << "Year" << setw(20)<< left << "Salary" << setw(20) << left << "Bonus"<<endl;

	for(int i{0} ; i<n ; i++)
	{
		arr[i].print();
	}	
	
	
	
	
	
	return(0);
}