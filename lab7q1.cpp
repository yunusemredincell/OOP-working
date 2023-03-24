#include <iostream>

using namespace std;



class CoffeeMachine { 

	protected: //  use protected to subclass access the variable.
	
	int coffeeAmount;	
	
	public:
	//Constructor	
	CoffeeMachine() : coffeeAmount{0}
	{
	}
	//Method
	void addCoffee (int coffee)
	{
		coffeeAmount += coffee;
	}
	
};

class LatteMachine: public CoffeeMachine {
	
	private:
	
	int milkAmount;
		
	public: 
	//Constructor
	LatteMachine() : milkAmount{0}
	{
	}
	//Methods
	
	void addMilk(int milk)
	{
	milkAmount += milk;	
	}
	
	int makeLatte (int cup)
	{
		
		if(cup > coffeeAmount)
		{
			cout<<"\n Not Enough Coffee! ";
			return -1;
				
		}
		else if(cup > milkAmount)
		{
			cout<<"\n Not Enough Milk! ";
			return -2;
			
		}
		else 
		{
			cout<<"\nEnjoy! \n ";
			coffeeAmount -= cup; // update coffee amount
			milkAmount -= cup;   // update milk amount
			return 0;
		}
				
	}
	
};

class FilterCoffeeMachine: public CoffeeMachine{ // we inherit public to aceess variable directly from base class.
	
	public:

	//Method

	int makeFilterCoffee(int cup)
	{
		if(cup > coffeeAmount)
		{
			cout<<"\nNot Enough Coffee! ";		
			return -1;	
		}
		
		else 
		{
			cout<<"\nEnjoy! \n";
		
			coffeeAmount -= cup;
		
			return 0;
		}			
	}
	
};

int main()
{
	string answer;
	int cup;
	int add;
	
	// create object
	LatteMachine l; 
	FilterCoffeeMachine f;
	CoffeeMachine c;
	
	while(answer != "none")
	{
		cout<<"\nfilter or latte? ";
			cin>> answer;
	
		if(answer == "filter")
		{
			cout<<"\n How many cups of coffee do you want? ";
				cin>> cup;	
			
			int check = f.makeFilterCoffee(cup);
			
			while(check)
			{
				cout<<"Add: ";
					cin>> add;
					
				f.addCoffee(add);
				check = f.makeFilterCoffee(cup);	
			}
			
		}
	
		else if (answer == "latte")
		{
			cout<<"\n How many cups of coffee do you want? ";
				cin>> cup;
			
			int check = l.makeLatte(cup);
			
			while(check)
			{
				cout<<"Add: ";
					cin>> add;
				
				if(check == -1)	
					l.addCoffee(add);
				
				else if (check == -2)
					l.addMilk(add);
						
				check = l.makeLatte(cup);	
			}
		
		}
		
	} 
	
	cout<<"\nGoodBye...";
	
	return(0);
}