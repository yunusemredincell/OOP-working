#include <iostream>
#include <iomanip>
using namespace std;

class Course {
	
	private: 
	
	int mtG, hwG, finG;
	double mtW, hwW, finW;
	string name;
	string letterGrade;
	
	
	public:
		// Constructors 
		
		Course() : Course{0.30,0.20,0.50} //for the first course's weight
		{
		}
		
		Course(double mtW, double hwW, double finW) :  	mtW{mtW},  hwW{hwW} , finW{finW} //for the second course's weight
		{
		}
		
	// Setter Methods to access private members 	
	
	void setName(string name)
	{
		this-> name = name;	
	}	
	void setMidterm(int mtG)
	{
		this->mtG = mtG;
	}	
	void setHomeWork(int hwG)
	{
		this->hwG = hwG;
	}	
	void setFinal(int finG)
	{
		this->finG = finG;
	}	
	
	void calculate() // Thanks to the calculate function, we obtain letter grades according to the university regulation.
	{
		double sum{0.0};
		
		sum= mtG * mtW + hwG * hwW + finG* finW ; 
		
			if(sum >= 90)
				letterGrade = "AA";
			else if (sum < 90 && sum>= 85)
				letterGrade = "BA";	
			else if (sum < 85 && sum>= 80)
				letterGrade = "BB";	
			else if (sum < 80 && sum>= 70)
				letterGrade = "CB";	
			else if (sum < 70 && sum>= 60)
				letterGrade = "CC";	
			else if (sum < 60 && sum>= 50)
				letterGrade = "DC";	
			else if (sum < 50 && sum>= 45)
				letterGrade = "DD";	
			else if (sum < 45 && sum>= 35)
				letterGrade = "FD";	
			else if (sum <35)
				letterGrade = "FF";			
	}
	
	// Getter functions that return the variable.
	string getName()
	{
		return name;
	}
	int getMidterm()
	{
		return mtG;
	}
	int getHomework()
	{
		return hwG;
	}
	int getFinal()
	{
		return finG;
	}
	string getLetterGrade()
	{
		return letterGrade;
	}

};



int main()
{
	
	Course course1; 
	
	
	double MtW, HwW, FinW;
	string tempname1,tempname2;
	int mgr1,hwgr1,fgr1;
	int mgr2,hwgr2,fgr2;
	
	cout<< "Enter weights for second course (midterm,homework,final): ";
		cin>> MtW >> HwW>> FinW;
	
	Course course2(MtW,HwW,FinW);
	cout << "\nEnter first course name: ";
		cin>> tempname1;
	cout << "\nEnter first course grades: ";
		cin >> mgr1 >> hwgr1 >> fgr1;
	
	course1.setName(tempname1);
	course1.setMidterm(mgr1);
	course1.setHomeWork(hwgr1);
	course1.setFinal(fgr1);		
	
	cout << "\nEnter second course name: ";
		cin>> tempname2;
	cout << "\nEnter second course grades: ";
		cin >> mgr2 >> hwgr2 >> fgr2;
	
	course2.setName(tempname2);
	course2.setMidterm(mgr2);
	course2.setHomeWork(hwgr2);
	course2.setFinal(fgr2);	
	
	course1.calculate();
	course2.calculate();
	cout<< setw(10) << left  << "Course" << setw(10) << left << "Midterm" << setw(10)<< left << "Homework" << setw(10) << left << "Final" << left << "Letter"<<endl;
	
	cout<< setw(10) << left  << course1.getName() << setw(10) << left << course1.getMidterm() << setw(10)<< left << course1.getHomework() << setw(10) << left << course1.getFinal() << left << course1.getLetterGrade()<<endl;
	cout<< setw(10) << left  << course2.getName() << setw(10) << left << course2.getMidterm() << setw(10)<< left << course2.getHomework() << setw(10) << left << course2.getFinal() << left << course2.getLetterGrade()<<endl;
	
	
	return(0);
}