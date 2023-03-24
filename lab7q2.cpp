#include <iostream>
#include <cstdlib> // to use rand function
#include <ctime>  // time function to srand

using namespace std;

class Villager { // villager class starting.
	
	protected: // protected variables (Inheritance)
	
		int health;
		int attackPower;
		
	public:
		
		// Constructor initilaze health and attack power to first value.
		
		Villager() : health{20} , attackPower{0}
		{
		}
		
		int attack (Villager & v1) //  check villager's attack situation witch v1 object.
		{
			cout<<"\nVillager cannot attack to anyone !! \n";
			return 0;
		}
		
		int getHealth()
		{
			return health;
		}
		
		void setHealth(int health)
		{
			this -> health = health;
		}
		
};

// Villager class ending...

// Archer class starting. 
class Archer: public Villager { // inherit public to access villager's class variable directly from base class.
	
		private:
			
		int nrOfArrows;	
		
		public:
		
		// Constructor initilaze health,attack power and nrOfArrows to first value.	
		Archer ()  
		{
			this->health = 60;
			this->attackPower = 40;
			this->nrOfArrows = 5;
		}
		
		int attack (Villager & v1) // use v1 object to check villager defence player health.
		{
			if(health <= 0)
				return -1;
		
			else 
			{
				srand(time(NULL));
				
				int damage = rand()% attackPower; // create a random damage number according to the attackPower.
				
				v1.setHealth(v1.getHealth() - damage);	
				
				nrOfArrows--; // decrease numbers of arrows.
				
				return damage;	
			}	 	
		}
		
		int attack (Archer & a1) // check Archer health and arrow situation and number of arrows. Then return the situation.
		{
			 if (health <= 0)
				return -1;
				
			else if(nrOfArrows <= 0)	
				return -2;
			
			else 
			{
				srand(time(NULL));
				
				int damage = rand()% attackPower + 1 ;
				
				a1.setHealth(a1.getHealth() - damage);	
				
				nrOfArrows--;
				
				return damage;	
			}	
				
		}	
		
		int getNrOfArrows() // getter method to access nrOfArrows.
		{
			return nrOfArrows;
		}
};

//Archer class ending...

int main()
{
	Villager v[15]; // create an villager array to reach player according to the user's number choosing.
	Archer a[15];  // create an archer array to reach player according to the user's number choosing.
	string attackPlayer,defencePlayer,temp;
	int count{1},n1,n2;
	
	srand (time(NULL));
	
	cout << "Enter command #" << count << ": ";
		cin>> attackPlayer >> n1 >> temp >> defencePlayer >> n2;
	
	while(!(attackPlayer == defencePlayer && n1 == n2))
	{
	
		if(attackPlayer == "Villager")
		{
			v[n1].attack(v[n2]);
		}
		
		else
		{ 
		int check= a[n1].attack(a[n2]); // we create a check variable to check situation according to the return parameters.
		
			if(check != -2) // if Archer have enough arrows, attackPlayer continue properly.
			{
				if(defencePlayer == "Archer") // check User's preferences to obtain player who defencePlayer.
				{
					if(check == -1) // not enough health attack player.
					{
						cout << "\n"<< attackPlayer << n1 << " is dead" << endl;
					}
					
					else
					{
						cout << "\n"<< attackPlayer << n1 << " made "<< check << " damage to "<< defencePlayer << n2 << "." << endl; // attackPlayer can damage to defence player. (random number)
						
						if(a[n2].getHealth() <= 0) // check health point after the damage.
						{
							cout <<"\n"<< defencePlayer << n2 << " is dead!" << endl;
						} 
					}
				}
				else // defence player is Villager.
				{
					int check = a[n1].attack(v[n2]);
					
					if(check == -1) // not enough health attack player.
					{
						cout << "\n"<< attackPlayer << n1 << " is dead" << endl;
					}
					
					else
					{
						cout <<"\n"<<  attackPlayer << n1 << " made "<< check << " damage to " << defencePlayer << n2 << "." << endl; // attackPlayer can damage to defence player. (random number
						
						if(v[n2].getHealth() <= 0) // check health point after the damage.
							cout << "\n"<<  defencePlayer << n2 << " is dead!" << endl;	
					}
				}
			}
			
			else
				cout  << "\n"<<  attackPlayer << n1 <<  " is out of arrows!" << endl; //  not enough arrows (return -2).
		}
		
		count++; // increase count to counting the command line.
		cout << "\nEnter command #" << count << ": ";
		cin>> attackPlayer >> n1 >> temp >> defencePlayer >> n2;
	}	
	cout <<"\nGame Finished! GoodBye...";

	return 0;
}