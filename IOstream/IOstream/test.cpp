//#include <iostream> //����iostream�ļ�
//using namespace std; //����std��׼�����ռ�
//int main()
//{
//	int a = 0;
//	cin >> a;
//	cout << a << endl;
//	return 0;
//}

//#include <iostream> //����iostream�ļ�
//int main()
//{
//	int a = 0;
//	std::cin >> a; //ʹ��ʱָ�����������ռ�
//	std::cout << a << std::endl; //ʹ��ʱָ�����������ռ�
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 0, b = 0;
//	cin >> a; //���룺10 20
//	cout << a << endl;
//	cin >> b; //ֱ�Ӵ����뻺������ȡ
//	cout << b << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;          //���룺"hello world"
//	cout << s << endl; //�����"hello"
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s;
//	getline(cin, s);   //���룺"hello world"
//	cout << s << endl; //�����"hello world"
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Date
//{
//	friend istream& operator>>(istream& in, Date& d);
//	friend ostream& operator<<(ostream& out, const Date& d);
//public:
//	Date(int year = 2021, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////��>>��������
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
////��<<��������
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "-" << d._month << "-" << d._day;
//	return out;
//}
//
//int main()
//{
//	Date d;
//	cin >> d;          //���룺2021 9 20
//	cout << d << endl; //�����2021-9-20
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	while (scanf("%d", &a) != EOF)
//	{
//		printf("%d\n", a);
//		//...
//	}
//	return 0;
//}

#include <iostream>
using namespace std;
int main()
{
	int a = 0;
	while (cin >> a)
	{
		cout << a << endl;
		//...
	}
	return 0;
}