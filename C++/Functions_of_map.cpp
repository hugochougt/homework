#include <iostream>
#include <map>
#include <utility> // make_pair
using namespace std;

int main()
{
    typedef map<char, int> MapType;
    MapType my_map;
 
    // insert elements using insert function
    my_map.insert(pair<char, int>('a', 1));
    my_map.insert(pair<char, int>('b', 2));
    my_map.insert(pair<char, int>('c', 3));
    my_map.insert(MapType::value_type('d', 4)); // all standard containers provide this typedef
    my_map.insert(make_pair('e', 5));      // can also use the utility function make_pair
	
	// Map keys are sorted automatically from lower to higher.
	// So, my_map.begin() points to the lowest key value not the key which was inserted first.
	MapType::iterator iter = my_map.begin();
	
	// erase the first element using the erase function
	my_map.erase(iter);
	
	// output the size of the map
	cout << "Size of the map : " << my_map.size() << endl;
	
	cout << "Enter a key to search for: ";
	char c;
	cin >> c;
	
	// find will return an iterator to the matching element if it is found
    // or to the end of the map if the key is not found
    iter = my_map.find(c);
    if(iter != my_map.end())
    	cout << "Value is " << iter->second << endl;
   	else	
   		cout << "Key is not in my_map" << endl;

	// clear the entries in the map
    my_map.clear();
  		
	return 0;
}
