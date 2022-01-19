#include "bitset.h"

int main()
{
	cl::bitset<37> bs;
	bs.Print();
	bs.set(2);
	bs.Print();
	bs.set(4);
	bs.set(6);
	bs.set(7);
	bs.set(34);
	bs.set(5);
	bs.set(8);
	bs.set(24);
	bs.Print();
	bs.reset(6);
	bs.reset(0);
	bs.Print();
	cout << bs.test(8) << endl;
	cout << bs.test(6) << endl;
	bs.flip(34);
	bs.Print();
	cout << bs.count() << endl;
	cout << bs.size() << endl;
	cout << bs.any() << endl;
	cout << bs.none() << endl;
	cout << bs.all() << endl;
	return 0;
}

//int main()
//{
//	//cl::bitset<4294967295> bs;
//	cl::bitset<-1> bs;
//	return 0;
//}