#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	char ans;
	string filename;
	string str;
	cout<<"Enter a file name: ";
	cin>>filename;
	
	fstream file;
	
	file.open(filename, ios::out);
	
	if(!file)
		cout<<"Error!!!";
	else
		cout<< "File creating successfully\n\n";
	
	
	cout<<"Enter information to store: "<<endl;
	    getline(cin,str);
	while(file)
	{
		getline(cin,str);
		file << str << endl;
		cout<<"\nDo you want to enter more information? (y/n)..";
		cin>>ans;
		cin.ignore();
		if(ans=='n')
			break;		
					
	}
	cout<<"The information successfully stored in the file!\n\n";
	cout<< "Do you want to see? (y/n)..";
	file.close();
	cin>>ans;
	cin.ignore();
	
	if(ans=='y')
	{
	file.open(filename,ios::in);
	file.seekg(0,ios::beg);
	cout<<"Information are: \n";
	while(file)
		{
	    	getline(file,str);
	   		cout<< str <<endl;
		}
	}
	else
		cout<<"GoodBye!";
	
    file.close();
    
	return(0);
}

