#include <iostream>

using namespace std;


int main()
{
	int N;
	int i{0},j{0};
	cout<<"How many numbers letters are you going to enter?";
		cin>> N;
	
	char *letter = new char[N]; // Dynamic Object
	int *repeat = new int[N];
	for(i=0;i<N;i++)
	{
		cout<<"\nEnter letter and how many times it will be repeated:";
			cin>> letter[i] >> repeat[i];
		cout<<endl;	
	}
	int k{0};
	for(i=0,k=0;i<N;i++,k++)
	{
		for(j=0;j<repeat[k];j++)
			cout<< letter[i];
			
	}
		
	delete [] letter;  // If you use dynamic memory, you should use delete after "new" operation.
	delete [] repeat;	// You should clear the memory to prevent unnecessary memory space occupation.
	
	
	
	
	return(0);
}