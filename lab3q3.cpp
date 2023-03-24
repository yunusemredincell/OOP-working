#include <iostream>
#include <string>

using namespace std;


struct NumberList // create a structure with two variables.
{
	int number[10];
	string direction;
	
};

void overwrite_p(NumberList* list) //The function that provide writing an array with new form according to rhe user's preferences.(with pointer)
{
	int i;
	
	 if(list->direction == "left-to-right")
	{
		for(i=0;i<9;i++)
		{	
			list->number[i+1] = list->number[i+1] +list->number[i];
		}
	}
	
	else if(list->direction == "right-to-left") 
	{
		for(i=9;i>0;i--)
		{
			list->number[i-1] = list->number[i-1] +list->number[i];
		}
	}
	
}

void overwrite_ref(NumberList& list2) //The function that provide writing an array with new form according to rhe user's preferences.(with reference)
{
	int i;
	 if(list2.direction == "left-to-right")
	{
		for(i=0;i<9;i++)
		{	
			list2.number[i+1] = list2.number[i+1] +list2.number[i];
		}
	}
	
	else if(list2.direction == "right-to-left")
	{
		for(i=9;i>0;i--)
		{
			list2.number[i-1] = list2.number[i-1] +list2.number[i];
		}
	}
	
	
}



int main()
{
	NumberList n1;
	char ans;
	int i;
	
	cout<<"Enter 10 integers and order of summation:";
	
	for(i=0;i<10;i++)
		cin>>n1.number[i];
	cin>>n1.direction;
	
	
	
		overwrite_p(&n1);
		
		cout<<"\nResult: ";
		for(i=0;i<10;i++)
			cout<<n1.number[i]<<" ";
	
	cout<<"\n\nEnter 10 integers and order of summation:";	
	for(i=0;i<10;i++)
		cin>>n1.number[i];
	cin>>n1.direction;
		
		overwrite_ref(n1);
		
		cout<<"\nResult: ";
		for(i=0;i<10;i++)
			cout<<n1.number[i]<<" ";
	

		
	
	return(0);
}