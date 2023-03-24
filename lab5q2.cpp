#include <iostream>
#include <iomanip>

using namespace std;

// Contact class
class Contact{

	private:
		string name;
		string number;
				
	public:
	
	// Constructor 
	Contact() :  name{"Unknown"}, number{"0"}  // No arguments constructor. 
	{
	}
	Contact(string name, string number): name{name},number{number} //User defined constructor. Constructor with parameters.
	{
	}
	
	// Methods
	
	void print (string writemode) // print function provide printing variable according to the user's choices(light or headers)
	{
		
		if (writemode == "light")
		{
			
			cout<< setw(15) << left << name << setw(15) << left <<number <<endl<<endl;
		}
		else if(writemode == "headers")
		{
			cout << "\nName: "<<name<<endl<< "\nNumber: "<<number <<endl;
			
		}
	
	}
	
	// Setter Methods to access private members
	void setName(string name)
	{
		this-> name = name;	
	}	
	
	void setNumber(string number)
	{
		this-> number = number;	
	}	
	// Getter methods
	string getName()
	{
		return name;
	}
	
	string getNumber()
	{
		return number;
	}
	
};

class AdressBook{
	
	private:
 
	int nrofcontacts;
	Contact contacts[15]; // create an array belonging Contact class
	
	
	int search(string name1) // private methods to find a name's place and return the place's index (otherwise -1)
	{
		for(int i{0};i<nrofcontacts;i++)
		{
			if(name1 == contacts[i].getName())
				return i;            
		}
		return -1;
	}
	
	public:
	
	// Constructor	
	AdressBook() : nrofcontacts{0} 
	{	
	}
	
	// Methods 
	bool add(Contact con1) 	// Adding new data (name and number) according to the user's preferences. return true or false (it depends on the situation).
	{ 
		if(search(con1.getName())== -1)
		{
			
			contacts[nrofcontacts].setName(con1.getName());
			contacts[nrofcontacts].setNumber(con1.getNumber());
			
			nrofcontacts++;
			return true;
			
		}
		return false;	
	}
	bool remove (string name ) // Deleting the data (name and number) according to the user's preferences. return true or false (it depends on the situation).
	{
		
		int i = search(name);
		if(search(name)!= -1)
		{
			for(i;i<nrofcontacts-1;i++)
			{
			contacts[i].setName(contacts[i+1].getName());
			contacts[i].setNumber(contacts[i+1].getNumber()) ;	
			}
			nrofcontacts--;
			return true;
		}
		return false;
	}
	
	void print() // print function provide printing variable according to the user's choices(light or headers). Calling the Contact class' print function,and printing on screen.
	{
		string write_choose;
		cout<< "\nEnter your write mode choose (light or headers): ";
				cin>> write_choose;
		
		if(nrofcontacts > 0)
		{
			if(write_choose == "light")	
			{
			cout<< setw(15) << left << "\nName" << setw(15) << left << "Number"<<endl<<endl;
		
			for(int i{0}; i < nrofcontacts; i++)
				contacts[i].print("light");
				
			}
			else if((write_choose == "headers"))
			{
				for(int i{0}; i < nrofcontacts; i++)
					contacts[i].print("headers");
			}
			else if(write_choose != "headers" || "light")
				cout<< "\nYou entered invalid writemode !! ";
				
		}
		else
			cout << "\nThere is no contacts in book." << endl;
		
	}
		
};


void menu(int choose); // Function decleration

int main()
{
	int choose;
	menu(choose); // CCalling the menu function to see options.
	
	
	return(0);
}



void menu(int choose) // This function offers the user options about the action he/she wants to do and receives the selection.
{
	Contact con1;
	
	AdressBook adress1;
	
	string tempname,tempnum;
	
do
	{
		cout<<"\n1. Display Address Book"<<endl<<"2. Add New Contact"<<endl<<"3. Remove Contact"<<endl<<" 4. Exit";
	
		cout<<"\n\nEnter your choice: ";
			cin>> choose;
		
		if(choose<1 || choose>=5)
		{
			cout<<"\nPlease again enter a number between 1-4: ";
				cin>> choose;
		}
				
		else if(choose==1)
		{
			adress1.print();	
		}
		else if(choose == 2)
		{
			cout<<"\nEnter name: ";
				cin>> tempname;
			cout<< "\nEnter number: ";
				cin>> tempnum;
	
		con1.setName(tempname);
		con1.setNumber(tempnum);
		
		if(adress1.add(con1))
				cout<<"\nContact added."<<endl;
		else
			cout<<"\n Already exist";		
			
		}
		
		else if(choose == 3)
		{
			
		string name;
		cout << "\nEnter a name: ";
			cin >> name;
			
			if(adress1.remove(name))
				cout << "\nContact removed" << endl;
			
			else
				cout << "\nContact is not available." << endl;
			
		}
	
	} while(choose!=4);
	
	 if(choose==4)
		cout<<(" Good Bye! ");
}
