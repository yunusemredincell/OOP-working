#include <iostream>
#include <string>

using namespace std;


int main()
{
	int pos{0};
	string str,substr;
	
	cout<<"Enter any string first :: ";
	getline(cin,str);
	
	cout<< "\nEnter substring you want to search :: ";
	cin>> substr;
	
	pos = str.find(substr);
	if(pos != string::npos)
		cout<< "\nThe substring ["<<substr<<"] is present in given string at position ["<<pos<<"]"<<endl;
	else
		cout<<"\nThere is no such a substring in your string!";
	
	
	
	
	
	
	
	return(0);	
}
