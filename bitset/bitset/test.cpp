//#include <iostream>
//#include <string>
//#include <bitset>
//using namespace std;
//
//int main()
//{
//	//构造一个16位的位图，所有位都初始化为0
//	bitset<16> bs1; //0000000000000000
//	//构造一个16位的位图，根据所给值初始化位图的前n位
//	bitset<16> bs2(0xfa5); //0000111110100101
//	//构造一个16位的位图，根据字符串中的0/1序列初始化位图的前n位
//	bitset<16> bs3(string("10111001")); //0000000010111001
//
//	cout << bs1 << endl;
//	cout << bs2 << endl;
//	cout << bs3 << endl;
//	return 0;
//}

//#include <iostream>
//#include <bitset>
//using namespace std;
//
//int main()
//{
//	bitset<8> bs;
//	bs.set(2); //设置第2位
//	bs.set(4); //设置第4位
//	cout << bs << endl; //00010100
//	
//	bs.flip(); //反转所有位
//	cout << bs << endl; //11101011
//	cout << bs.count() << endl; //6
//
//	cout << bs.test(3) << endl; //1
//
//	bs.reset(0); //清空第0位
//	cout << bs << endl; //11101010
//
//	bs.flip(7); //反转第7位
//	cout << bs << endl; //01101010
//
//	cout << bs.size() << endl; //8
//
//	cout << bs.any() << endl; //1
//
//	bs.reset(); //清空所有位
//	cout << bs.none() << endl; //1
//
//	bs.set(); //设置所有位
//	cout << bs.all() << endl; //1
//	return 0;
//}

//#include <iostream>
//#include <bitset>
//using namespace std;
//
//int main()
//{
//	bitset<8> bs;
//	cin >> bs; //10110
//	cout << bs << endl; //00010110
//	bitset<8> tmp;
//	tmp = bs;
//	cout << tmp << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <bitset>
//using namespace std;
//
//int main()
//{
//	bitset<8> bs1(string("10101010"));
//	bitset<8> bs2(string("10101010"));
//	bs1 >>= 1;
//	cout << bs1 << endl; //01010101
//
//	bs2 |= bs1;
//	cout << bs2 << endl; //11111111
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <bitset>
//using namespace std;
//
//int main()
//{
//	bitset<8> bs1(string("10101010"));
//	bitset<8> bs2(string("01010101"));
//	cout << (bs1&bs2) << endl; //00000000
//	cout << (bs1|bs2) << endl; //11111111
//	cout << (bs1^bs2) << endl; //11111111
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <bitset>
//using namespace std;
//
//int main()
//{
//	bitset<8> bs(string("10101010"));
//	bs[0] = 1;
//	cout << bs << endl;
//	//bitset<-1> bs1;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <bitset>
//using namespace std;
//
//int main()
//{
//	//bitset<4294967296> bs;
//	//bitset<4294967295> bs;
//	bitset<-1> bs;
//	return 0;
//}

#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main()
{
	bitset<8> bs(string("00110101"));
	cout << bs[0] << endl; //1
	bs[0] = 0;
	cout << bs << endl; //00110100
	return 0;
}