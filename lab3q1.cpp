#include <iostream>
#include <vector> 

using namespace std;


struct Course //create a structure with two variables.
{
	float grade;
	string coursecode;
	
};

int main()
{	
	
	char ans;
	int i;
	int count{0};
	
	vector <Course> c;  //we use vector because we don't know how many lessons the user will enter
	Course k;
	
	while(ans != 'n')
	{
		cout<<"Enter course code and grade: ";
			
			cin >>c.coursecode>> k.grade ;
			cin.ignore();
			c.push_back(k);
		
		
		cout<<"\n Add new course ? (y/n)..";
			cin>>ans;
		
		count++;
		cout<<endl;
			
	}
	
		
	
	
	cout<<"List of entered " << count <<" courses: "<<endl;
	for(i=0;i<count;i++)
	{
		cout<<"-"<< c.at(i).coursecode<<","<<"Grade: "<<c.at(i).grade<<endl;
	}
	double cgpa,sum{0.0};
	
	for(i=0;i<count;i++)
		sum += c.at(i).grade;
	
	cgpa= sum/double(count);
	
	cout<<"CGPA: "<<cgpa;
	
	
	
	return(0);
}