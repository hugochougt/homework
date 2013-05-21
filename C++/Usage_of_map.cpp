/*

	The following code demonstrates 
	how to use the map<string, int> 
	to count occurrences of words. 
	It uses the word as the key and 
	the count as the value.
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
	map<string, int> wordcounts;
	string s;
	
	while(cin >> s && s != "end")
		++wordcounts[s];
		
	while(cin >> s && s != "end")
		cout << s << ' ' << wordcounts[s] << endl;
		
	return 0;
}
