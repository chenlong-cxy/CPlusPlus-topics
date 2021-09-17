//#include <iostream> //包含iostream文件
//using namespace std; //引入std标准命名空间
//int main()
//{
//	int a = 0;
//	cin >> a;
//	cout << a << endl;
//	return 0;
//}

//#include <iostream> //包含iostream文件
//int main()
//{
//	int a = 0;
//	std::cin >> a; //使用时指定所属命名空间
//	std::cout << a << std::endl; //使用时指定所属命名空间
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 0, b = 0;
//	cin >> a; //输入：10 20
//	cout << a << endl;
//	cin >> b; //直接从输入缓冲区提取
//	cout << b << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;          //输入："hello world"
//	cout << s << endl; //输出："hello"
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s;
//	getline(cin, s);   //输入："hello world"
//	cout << s << endl; //输出："hello world"
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
////对>>进行重载
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
////对<<进行重载
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "-" << d._month << "-" << d._day;
//	return out;
//}
//
//int main()
//{
//	Date d;
//	cin >> d;          //输入：2021 9 20
//	cout << d << endl; //输出：2021-9-20
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