//#include "HashTable.h"
//#include "unordered_map.h"
//#include "unordered_set.h"
#include "HashTableS.h"

int main()
{
	//cl::testset();
	//cl::testmap();
	HashTable<int, int> ht;
	ht.Insert(make_pair(1, 2));
	ht.Erase(1);
	ht.Find(1);
	return 0;
}