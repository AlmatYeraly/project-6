// Almat Yeraly and Daniel Tucker
// CS-273 Data Structures
// Project 6 - Hash Tables
// All the code was written by us, unless specified

#include "hash.h"
#include <iostream>


int main()
{
	// creating new hash table
	hash<int> hs1(5);
	// creating pairs
	pair<int> item1 = pair<int>("bottle", 1);
	pair<int> item2 = pair<int>("blue", 2);
	pair<int> item3 = pair<int>("key", 3);
	pair<int> item4 = pair<int>("folder", 4);

	// testing insert
	hs1.insert(item1);
	hs1.insert(item2);
	hs1.insert(item3);
	hs1.insert(item4);

	// testing locate with pair and key
	std::list<pair<int>>::iterator it = hs1.locate(item1);
	std::cout << it->first << " " << it->second << " "; 
	it = hs1.locate(item2);
	std::cout << it->first << " " << it->second << " ";
	it = hs1.locate(item3);
	std::cout << it->first << " " << it->second << " ";
	it = hs1.locate("folder");
	std::cout << it->first << " " << it->second << "\n";

	// testing locate with pair and key
	std::cout << hs1.remove(item1) << "\n";
	std::cout << hs1.remove("blue") << "\n";

	system("pause");
	return 0;
}