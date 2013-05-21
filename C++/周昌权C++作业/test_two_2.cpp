#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main(void)
{
	char line[81];
	int word,space,digit,other;

	while(cin.getline(line, 81))
	{
		char *p = line;

		word = space = digit = other = 0;

	    while(*p!='\0') 
	    {
			if(isalpha(p[i]))
				word++;
			else if(isspace(p[i]))
				space++;
			else if(isdigit(p[i]))
				digit++;
			else
				other++;
				
			p++;
        }				
		cout << "Words: " << word << endl;
		cout << "Spaces: " << space << endl;
		cout << "Digits: " << digit << endl;
		cout << "Other charateristics: " << other << endl;
	}
	return 0;
}
