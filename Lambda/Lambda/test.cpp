#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Goods
{
	string _name;  //名字
	double _price; //价格
	int _num;      //数量
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
	vector<Goods> v = { { "苹果", 2.1, 300 }, { "香蕉", 3.3, 100 }, { "橙子", 2.2, 1000 }, { "菠萝", 1.5, 1 } };
	sort(v.begin(), v.end(), ComparePriceLess()); //按价格升序排序
	for (auto& e : v)
	{
		cout << e._name << " " << e._price << " " << e._num << endl;
	}
	cout << endl;
	sort(v.begin(), v.end(), ComparePriceGreater()); //按价格降序排序
	for (auto& e : v)
	{
		cout << e._name << " " << e._price << " " << e._num << endl;
	}
	cout << endl;
	sort(v.begin(), v.end(), CompareNumLess()); //按数量升序排序
	for (auto& e : v)
	{
		cout << e._name << " " << e._price << " " << e._num << endl;
	}
	cout << endl;
	sort(v.begin(), v.end(), CompareNumGreater()); //按数量降序排序
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
//	[]{}; //最简单的lambda表达式
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
//	string _name;  //名字
//	double _price; //价格
//	int _num;      //数量
//};
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 300 }, { "香蕉", 3.3, 100 }, { "橙子", 2.2, 1000 }, { "菠萝", 1.5, 1 } };
//	auto f1 = [](const Goods& g1, const Goods& g2)->bool{return g1._price < g2._price; };
//	sort(v.begin(), v.end(), f1); //按价格升序排序
//	for (auto& e : v)
//	{
//		cout << e._name << " " << e._price << " " << e._num << endl;
//	}
//	cout << endl;
//	sort(v.begin(), v.end(), f1); //按价格降序排序
//	for (auto& e : v)
//	{
//		cout << e._name << " " << e._price << " " << e._num << endl;
//	}
//	cout << endl;
//	sort(v.begin(), v.end(), f1); //按数量升序排序
//	for (auto& e : v)
//	{
//		cout << e._name << " " << e._price << " " << e._num << endl;
//	}
//	cout << endl;
//	sort(v.begin(), v.end(), f1); //按数量降序排序
//	for (auto& e : v)
//	{
//		cout << e._name << " " << e._price << " " << e._num << endl;
//	}
//	cout << endl;
//	return 0;
//}
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 300 }, { "香蕉", 3.3, 100 }, { "橙子", 2.2, 1000 }, { "菠萝", 1.5, 1 } };
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//	{
//		return g1._price < g2._price; 
//	}); //按价格升序排序
//	for (auto& e : v)
//	{
//		cout << e._name << " " << e._price << " " << e._num << endl;
//	}
//	cout << endl;
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//	{
//		return g1._price > g2._price;
//	}); //按价格降序排序
//	for (auto& e : v)
//	{
//		cout << e._name << " " << e._price << " " << e._num << endl;
//	}
//	cout << endl;
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//	{
//		return g1._num < g2._num;
//	}); //按数量升序排序
//	for (auto& e : v)
//	{
//		cout << e._name << " " << e._price << " " << e._num << endl;
//	}
//	cout << endl;
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//	{
//		return g1._num > g2._num;
//	}); //按数量降序排序
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
//	Swap(a, b); //交换a和b
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
//	//函数对象
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