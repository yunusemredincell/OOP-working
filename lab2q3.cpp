#include <iostream>
#include <string>

using namespace std;

int main()
{
	int vowel {0}, consonant{0}, digit{0},space{0};
	string str;
	
	cout<<"Enter a line of string: ";
	getline(cin,str);
	
	for(int i{0};i<str.length();i++)
	{
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
			vowel++;
		else if (str[i]>='a'&& str[i]<='z'||str[i]>='A'&& str[i]<='Z')
			consonant++;
		else if(str[i]>='0'&& str[i]<='9')
				digit++;
		else if(str[i]==' ')
			space++;		
	}
	cout<<"Vowels: "<< vowel <<endl<<"Consonants: "<< consonant <<endl<< "Digits: "<< digit <<endl<<"White Spaces: "<<space; 
	
	
	
	
	return(0);
}
