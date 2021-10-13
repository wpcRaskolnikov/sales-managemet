#ifndef PROCESS_H
#define PROCESS_H
#include<fstream>
#include<list>
#include<string>
using std::string;
using std::list;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;

template <typename T>
list<T> searchFromList(list<T> oldList, string nameToFind)
{
	list<T> newList;
	for (auto& temp : oldList)
	{
		if (temp.isName(nameToFind))
		{
			newList.push_back(temp);
		}
	}
	return newList;
}

template <typename T>
bool listToFile(list<T>& oldList, const string fileName)
{
	ofstream fp(fileName, ios::out);
	for (auto& temp : oldList)
	{
		fp << temp << endl;
	}
	return true;
}

template <typename T>
bool deleteFromList(list<T>& oldList, string nameToDelete, int num)
{
	int count = 1;
	for (auto curr = oldList.begin(); curr != oldList.end(); curr++)
	{
		if (curr->isName(nameToDelete))
		{
			if (count == num)
			{
				oldList.erase(curr);
				return true;
			}
			count++;
		}
	}
	return false;
}

template <typename T>
bool readListFromFile(list<T>& oldList, const string fileName)
{
	ifstream fp(fileName, ios::in);
	while (fp)
	{
		T newT;
		fp >> newT;
		oldList.push_back(newT);
		fp.get();
	}
	return true;
}

template <typename T>
bool traverseList(list<T>& oldList)
{
	for (auto& temp : oldList)
	{
		cout << temp << endl;
	}
	return true;
}

#endif
