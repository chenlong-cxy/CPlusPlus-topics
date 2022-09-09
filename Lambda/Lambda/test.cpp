#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Goods
{
	string _name;  //����
	double _price; //�۸�
	int _num;      //����
};
struct ComparePriceLess
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._price < g2._price;
	}
};
struct ComparePriceGreater
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._price > g2._price;
	}
};
struct CompareNumLess
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._num < g2._num;
	}
};
struct CompareNumGreater
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._num > g2._num;
	}
};
int main()
{
	vector<Goods> v = { { "ƻ��", 2.1, 300 }, { "�㽶", 3.3, 100 }, { "����", 2.2, 1000 }, { "����", 1.5, 1 } };
	sort(v.begin(), v.end(), ComparePriceLess()); //���۸���������
	for (auto& e : v)
	{
		cout << e._name << " " << e._price << " " << e._num << endl;
	}
	cout << endl;
	sort(v.begin(), v.end(), ComparePriceGreater()); //���۸�������
	for (auto& e : v)
	{
		cout << e._name << " " << e._price << " " << e._num << endl;
	}
	cout << endl;
	sort(v.begin(), v.end(), CompareNumLess()); //��������������
	for (auto& e : v)
	{
		cout << e._name << " " << e._price << " " << e._num << endl;
	}
	cout << endl;
	sort(v.begin(), v.end(), CompareNumGreater()); //��������������
	for (auto& e : v)
	{
		cout << e._name << " " << e._price << " " << e._num << endl;
	}
	cout << endl;
	return 0;
}


//#include <iostream>
//using namespace std;
//int main()
//{
//	[]{}; //��򵥵�lambda���ʽ
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10, b = 20;
//	auto add = [](int x, int y)->int{return x + y; };
//	cout << add(a, b) << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10, b = 20;
//	auto add = [a, b]()->int{return a + b; };
//	//auto add = [a, b]{return a + b; };
//	cout << add() << endl;
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//struct Goods
//{
//	string _name;  //����
//	double _price; //�۸�
//	int _num;      //����
//};
//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 300 }, { "�㽶", 3.3, 100 }, { "����", 2.2, 1000 }, { "����", 1.5, 1 } };
//	auto f1 = [](const Goods& g1, const Goods& g2)->bool{return g1._price < g2._price; };
//	sort(v.begin(), v.end(), f1); //���۸���������
//	for (auto& e : v)
//	{
//		cout << e._name << " " << e._price << " " << e._num << endl;
//	}
//	cout << endl;
//	sort(v.begin(), v.end(), f1); //���۸�������
//	for (auto& e : v)
//	{
//		cout << e._name << " " << e._price << " " << e._num << endl;
//	}
//	cout << endl;
//	sort(v.begin(), v.end(), f1); //��������������
//	for (auto& e : v)
//	{
//		cout << e._name << " " << e._price << " " << e._num << endl;
//	}
//	cout << endl;
//	sort(v.begin(), v.end(), f1); //��������������
//	for (auto& e : v)
//	{
//		cout << e._name << " " << e._price << " " << e._num << endl;
//	}
//	cout << endl;
//	return 0;
//}
//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 300 }, { "�㽶", 3.3, 100 }, { "����", 2.2, 1000 }, { "����", 1.5, 1 } };
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//	{
//		return g1._price < g2._price; 
//	}); //���۸���������
//	for (auto& e : v)
//	{
//		cout << e._name << " " << e._price << " " << e._num << endl;
//	}
//	cout << endl;
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//	{
//		return g1._price > g2._price;
//	}); //���۸�������
//	for (auto& e : v)
//	{
//		cout << e._name << " " << e._price << " " << e._num << endl;
//	}
//	cout << endl;
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//	{
//		return g1._num < g2._num;
//	}); //��������������
//	for (auto& e : v)
//	{
//		cout << e._name << " " << e._price << " " << e._num << endl;
//	}
//	cout << endl;
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//	{
//		return g1._num > g2._num;
//	}); //��������������
//	for (auto& e : v)
//	{
//		cout << e._name << " " << e._price << " " << e._num << endl;
//	}
//	cout << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10, b = 20;
//	auto Swap = [](int& x, int& y)->void
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	Swap(a, b); //����a��b
//	cout << a << endl;
//	cout << b << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10, b = 20;
//	auto Swap = [&]
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//	Swap();
//	cout << a << endl;
//	cout << b << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10, b = 20;
//	auto Swap = [&a, &b]
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//	Swap();
//	cout << a << endl;
//	cout << b << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10, b = 20;
//	auto Swap = [a, b]()mutable
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//	Swap();
//	cout << a << endl;
//	cout << b << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10, b = 20;
//	auto Swap = [](int& x, int& y)->void
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	auto Add = [](int& x, int& y)->void
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	Swap(a, b);
//	cout << a << endl;
//	cout << b << endl;
//	cout << typeid(Swap).name() << endl;
//	cout << typeid(Add).name() << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Rate
//{
//public:
//	Rate(double rate)
//		:_rate(rate)
//	{}
//	double operator()(double money, int year)
//	{
//		return money * _rate * year;
//	}
//private:
//	double _rate;
//};
//int main()
//{
//	//��������
//	double rate = 0.49;
//	Rate r1(rate);
//	r1(10000, 2);
//	//lambda
//	auto r2 = [=](double money, int year)->double
//	{
//		return money * rate * year;
//	};
//	r2(10000, 2);
//	return 0;
//}