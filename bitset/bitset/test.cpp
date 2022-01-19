//#include <iostream>
//#include <string>
//#include <bitset>
//using namespace std;
//
//int main()
//{
//	//����һ��16λ��λͼ������λ����ʼ��Ϊ0
//	bitset<16> bs1; //0000000000000000
//	//����һ��16λ��λͼ����������ֵ��ʼ��λͼ��ǰnλ
//	bitset<16> bs2(0xfa5); //0000111110100101
//	//����һ��16λ��λͼ�������ַ����е�0/1���г�ʼ��λͼ��ǰnλ
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
//	bs.set(2); //���õ�2λ
//	bs.set(4); //���õ�4λ
//	cout << bs << endl; //00010100
//	
//	bs.flip(); //��ת����λ
//	cout << bs << endl; //11101011
//	cout << bs.count() << endl; //6
//
//	cout << bs.test(3) << endl; //1
//
//	bs.reset(0); //��յ�0λ
//	cout << bs << endl; //11101010
//
//	bs.flip(7); //��ת��7λ
//	cout << bs << endl; //01101010
//
//	cout << bs.size() << endl; //8
//
//	cout << bs.any() << endl; //1
//
//	bs.reset(); //�������λ
//	cout << bs.none() << endl; //1
//
//	bs.set(); //��������λ
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