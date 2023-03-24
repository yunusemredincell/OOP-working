#include <iostream>
#include <string>

using namespace std;

class UpDownNumbers {
	
	private:
		int start;
		int length;
		int *numbers;
	
	public:
		// Constructors
	
		UpDownNumbers(int start,int length) : start{start}, length{length} // User defined Constructor
		{	
			numbers = new int[length];
		}
		UpDownNumbers(const UpDownNumbers &b)  // Copy Constructor
		{
			start = b.start;
			length = b.length;
			numbers = new int[length];
		
			for(int i{0};i<length;i++)
			{
				numbers[i] = b.numbers[i];
			}	
		}
		// Destructor
		~UpDownNumbers()
		{
			delete numbers;
		}
	
	// Setter
	
	void setStart(int start)
	{
		this -> start = start;
	}

	
	// Methods
		
	void generate()	
	{
	numbers[0] = start;
	
		for (int i{1}; i<length ;i++)
		{
			if(numbers[i-1]%2)
				numbers[i] = 3*numbers[i-1] - 1 ;
			else
				numbers[i] = (numbers[i-1] / 2) + 5 ;	
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



int main ()
{
	int tempstart ,templength,tempstart2;
	
	cout<< "Enter length and start for Object A: ";
		cin>>templength>>tempstart;
	
	UpDownNumbers objA{tempstart,templength};
		
	UpDownNumbers objB{objA};

	
	objA.generate();	
	
	cout<< "\n\nObject A (start:"<< tempstart <<", length "<< templength <<"): ";
	objA.print();

	
	objB.generate();
	
	cout<< "\n\nObject B (b=a): ";
	objB.print();

	cout<< "\n\nEnter new start for Object B: ";
		cin>> tempstart2;
		
	cout<<"\n\nb.start is "<<tempstart2 <<" now. ";
	
	objB.setStart(tempstart2);

	objB.generate();
	
	cout<< "\n\nObject A (start:"<< tempstart <<", length "<< templength <<"): ";
	objA.print();
	
	cout<< "\n\nObject B (start:"<<tempstart2<<", length "<<templength<<"): ";
	objB.print();	

	return(0);
}