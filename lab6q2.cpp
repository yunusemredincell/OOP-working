#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class NumbersClass {
	
	private:
		int length;
		int *numbers;
		
	bool isPrime(int num )
	{
		if(num==0 || num==1)
			return false;
			
		for(int i{2};i<=num/2;i++)
		{
			if(num%i==0)
			{
				return false;
			}
				
		}
		return true;	
	}	
	
	public:
		// Constructors
		
		NumbersClass() : length{0}
		{
		}
		NumbersClass(int length) :  length{length} // User defined Constructor
		{	
			numbers = new int[length];
		}
	NumbersClass(const 	NumbersClass &b)  // Copy Constructor
		{
			length = b.length;
			numbers = new int[length];
			for(int i{0};i<length;i++)
			{
				numbers[i] = b.numbers[i];
			}	
		}
		// Destructor
		~NumbersClass()
		{
			delete numbers;
		}
		
	//Methods
	void generate()
	{
		srand(time(NULL));
		
			for(int i{0}; i<length;i++)
			{
				numbers[i] = rand()%10000;
			}
	}
	
	void filter(string option)
	{
		int count{0};
	
		if(option == "prime")
		{
			for(int i{0};i<length;i++)
			{
				if(isPrime(numbers[i]))	
				{
					numbers[count] = numbers[i];
					count++;
				}
			}
			length = count;		
		}
		else if(option=="nonprime")
		{ 
		int count2{0};
		
			for(int i{0};i<length;i++)
			{
				if(isPrime(numbers[i])==0)
				{
					numbers[count2] = numbers[i];
					count2++;
				}
			}
		length = count2;	
		}
		
	}
	
	void print()
	{
		for(int i{0}; i<length ;i++)
		{
			cout<< numbers[i]<<" ";	
		}	
	}
};
	
int main()
{
	int templength;
	
	cout<< "Enter length: ";
		cin>>templength;
	
	 NumbersClass num1{templength}; // Call the user-defined constructor

	num1.generate();

	NumbersClass num2{num1}; // Call the copy constructor
	NumbersClass num3{num1};
	
	cout<<"\n\nA: ";
	num1.print();
	
	num2.filter("prime");
	
	cout<<"\n\nB: ";
	num2.print();
	
	num3.filter("nonprime");
	
	cout<<"\n\nC: ";
	num3.print();
	
	
	return(0);
}