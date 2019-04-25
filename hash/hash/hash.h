#ifndef HASH_H_
#define HASH_H_

#include <string>
#include <vector>
#include <list>

// Pair
// Holds string as key and generic Type as value
// Key is used for hash function and generic Type is stored in the table
template <typename Type>
struct pair 
{
	std::string first;
	Type second;
	pair(const std::string& x, const Type& y) : first(x), second(y) {}
	pair() : first(""), second(Type()) {}
	pair(const pair& other) { first = other.first; second = other.second; }
};


// Hash table
// Utilizes vector of lists as its container
// List stores pairs
// The function is the length of string mod the vector size
template <typename Type>
class hash
{
private:
	std::vector<std::list<pair<Type>>> buckets;
public:
	hash(int size); // constructor with initialized size
	hash(const hash<Type>& other); // copy constructor

	~hash(); // destructor

	hash<Type> operator=(const hash<Type>& other); // assignment operator

	typename std::list<pair<Type>>::iterator insert(const pair<Type>& item); // insert method, utilizes list's push_back

	bool remove(const pair<Type>& item); // remove method using a pair, utilizes list's erase
	bool remove(const std::string & key); // remove method using a string key, utilizes list's erase
	
	typename std::list<pair<Type>>::iterator locate(const pair<Type>& item); // locate method using a pair
	typename std::list<pair<Type>>::iterator locate(const std::string & key); // locate method using a string key
};

#endif


// constructor with initialized size
// utilizes vector's resize method
template<typename Type>
inline hash<Type>::hash(int size)
{
	buckets.resize(size);
}

// copy constructor
// utilizes vector's assignment operator
template<typename Type>
inline hash<Type>::hash(const hash<Type>& other)
{
	buckets = other.buckets;
}

// destructor
// utilizes vector's destructor
template<typename Type>
inline hash<Type>::~hash()
{
	buckets.~vector();
}

// assignment operator
// utilizes vector's assignmnet operator
template<typename Type>
inline hash<Type> hash<Type>::operator=(const hash<Type>& other)
{
	buckets = other.buckets;
	return this;
}

// insert method
// takes in item's string length and finds the mod with vector's size to find the index 
// uses list iterator to see if the item is already in the table
// if not in the table, uses list's push_back 
// if in the table, returns the item
// used the book for directions - page 553
template<typename Type>
inline typename std::list<pair<Type>>::iterator hash<Type>::insert(const pair<Type>& item)
{
	int index = item.first.size() % buckets.size(); // hash function

	// iterator traverses through the list in the index to see if the item already exists
	typename std::list<pair<Type>>::iterator pos = buckets[index].begin();
	while (pos != buckets[index].end() && pos->first != item.first)
	{
		++pos;
	}

	// if item is not in the list, adds it to the back of the list
	if (pos == buckets[index].end())
	{
		buckets[index].push_back(item);
		return pos;
	}
	// if item is in the list, returns the iterator pointing to the item
	else
	{
		return pos;
	}
}

// remove method that takes in pair item
// takes in item's string length and finds the mod with vector's size to find the index 
// uses list iterator to find the item
// after finding the item, uses list's erase method to delete the item
// returns true if deleted, returns false if could not find the item or could not delete it
template<typename Type>
inline bool hash<Type>::remove(const pair<Type>& item)
{
	int index = item.first.size() % buckets.size(); // hash function to find the index

	// locating the item
	typename std::list<pair<Type>>::iterator pos = buckets[index].begin();
	while (pos != buckets[index].end() && pos->first != item.first)
	{
		++pos;
	}

	// deleting the item
	if (pos->first == item.first)
	{
		buckets[index].erase(pos);
		return true;
	}
	else
	{
		return false;
	}
}

// remove method that takes in string key
// the code is the same as in the remove above, only item->first is replaced by key
template<typename Type>
inline bool hash<Type>::remove(const std::string & key)
{
	int index = key.size() % buckets.size();
	typename std::list<pair<Type>>::iterator pos = buckets[index].begin();

	while (pos != buckets[index].end() && pos->first != key)
	{
		++pos;
	}

	if (pos->first == key)
	{
		buckets[index].erase(pos);
		return true;
	}
	else
	{
		return false;
	}
}

// locate method that takes in pair item
// takes in item's string length and finds the mod with vector's size to find the index 
// uses list iterator to find the item
// after finding the item, returns the iterator pointing to the item
template<typename Type>
inline typename std::list<pair<Type>>::iterator hash<Type>::locate(const pair<Type>& item)
{
	int index = item.first.size() % buckets.size(); // hash function to locate the index

	// iterator that traverses through the list to locate the item
	typename std::list<pair<Type>>::iterator pos = buckets[index].begin();

	while (pos != buckets[index].end() && pos->first != item.first)
	{
		++pos;
	}
	return pos;
}

// locate method that takes in string key
// the code is the same as in the remove above, only item->first is replaced by key
template<typename Type>
inline typename std::list<pair<Type>>::iterator hash<Type>::locate(const std::string & key)
{
	int index = key.size() % buckets.size();
	typename std::list<pair<Type>>::iterator pos = buckets[index].begin();

	while (pos != buckets[index].end() && pos->first != key)
	{
		++pos;
	}
	return pos;
}

