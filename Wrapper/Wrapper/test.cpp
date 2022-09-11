//#include <iostream>
//using namespace std;
//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count: " << ++count << endl;
//	cout << "count: " << &count << endl;
//
//	return f(x);
//}
//double func(double i)
//{
//	return i / 2;
//}
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//int main()
//{
//	//函数名
//	cout << useF(func, 11.11) << endl;
//
//	//函数对象
//	cout << useF(Functor(), 11.11) << endl;
//
//	//lambda表达式
//	cout << useF([](double d)->double{return d / 4; }, 11.11) << endl;
//	return 0;
//}


//template <class T> function;     // undefined
//template <class Ret, class... Args>
//class function<Ret(Args...)>;


//#include <iostream>
//#include <functional>
//using namespace std;
//int f(int a, int b)
//{
//	return a + b;
//}
//struct Functor
//{
//public:
//	int operator()(int a, int b)
//	{
//		return a + b;
//	}
//};
//class Plus
//{
//public:
//	static int plusi(int a, int b)
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)
//	{
//		return a + b;
//	}
//};
//int main()
//{
//	//函数名（函数指针）
//	function<int(int, int)> func1 = f;
//	cout << func1(1, 2) << endl;
//
//	//函数对象（仿函数）
//	function<int(int, int)> func2 = Functor();
//	cout << func2(1, 2) << endl;
//
//	//lambda表达式
//	function<int(int, int)> func3 = [](int a, int b){return a + b; };
//	cout << func3(1, 2) << endl;
//
//	//类的静态成员函数
//	//function<int(int, int)> func4 = Plus::plusi;
//	function<int(int, int)> func4 = &Plus::plusi;
//	cout << func4(1, 2) << endl;
//
//	//类的非静态成员函数
//	function<double(Plus, double, double)> func5 = &Plus::plusd;
//	cout << func5(Plus(), 1.1, 2.2) << endl;
//	return 0;
//}


//#include <iostream>
//#include <functional>
//using namespace std;
//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count: " << ++count << endl;
//	cout << "count: " << &count << endl;
//
//	return f(x);
//}
//double func(double i)
//{
//	return i / 2;
//}
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//int main()
//{
//	//函数名
//	function<double(double)> func1 = func;
//	cout << useF(func1, 11.11) << endl;
//
//	//函数对象
//	function<double(double)> func2 = Functor();
//	cout << useF(func2, 11.11) << endl;
//
//	//lambda表达式
//	function<double(double)> func3 = [](double d)->double{return d / 4; };
//	cout << useF(func3, 11.11) << endl;
//	return 0;
//}


//class Solution {
//public:
//	int evalRPN(vector<string>& tokens) {
//		stack<int> st;
//		for (const auto& str : tokens)
//		{
//			int left, right;
//			if (str == "+" || str == "-" || str == "*" || str == "/")
//			{
//				right = st.top();
//				st.pop();
//				left = st.top();
//				st.pop();
//				switch (str[0])
//				{
//				case '+':
//					st.push(left + right);
//					break;
//				case '-':
//					st.push(left - right);
//					break;
//				case '*':
//					st.push(left * right);
//					break;
//				case '/':
//					st.push(left / right);
//					break;
//				default:
//					break;
//				}
//			}
//			else
//			{
//				st.push(stoi(str));
//			}
//		}
//		return st.top();
//	}
//};


//class Solution {
//public:
//	int evalRPN(vector<string>& tokens) {
//		stack<int> st;
//		unordered_map<string, function<int(int, int)>> opMap = {
//			{ "+", [](int a, int b){return a + b; } },
//			{ "-", [](int a, int b){return a - b; } },
//			{ "*", [](int a, int b){return a * b; } },
//			{ "/", [](int a, int b){return a / b; } }
//		};
//		for (const auto& str : tokens)
//		{
//			int left, right;
//			if (str == "+" || str == "-" || str == "*" || str == "/")
//			{
//				right = st.top();
//				st.pop();
//				left = st.top();
//				st.pop();
//				st.push(opMap[str](left, right));
//			}
//			else
//			{
//				st.push(stoi(str));
//			}
//		}
//		return st.top();
//	}
//};


//template <class Fn, class... Args>
///* unspecified */ bind(Fn&& fn, Args&&... args);
//template <class Ret, class Fn, class... Args>
///* unspecified */ bind(Fn&& fn, Args&&... args);


#include <iostream>
#include <functional>
using namespace std;
int Plus(int a, int b)
{
	return a + b;
}
class Sub
{
public:
	int sub(int a, int b)
	{
		return a - b;
	}
};
int main()
{
	function<int(int, int)> func1 = bind(Plus, placeholders::_1, placeholders::_2);
	cout << func1(1, 2) << endl;

	//想把plus绑定成一个值+10
	function<int(int)> func2 = bind(Plus, placeholders::_1, 10);
	cout << func2(2) << endl;

	//绑定固定的可调用对象
	function<int(int, int)> func3 = bind(&Sub::sub, Sub(), placeholders::_1, placeholders::_2);
	cout << func3(1, 2) << endl;

	function<int(int, int)> func4 = bind(&Sub::sub, Sub(), placeholders::_2, placeholders::_1);
	cout << func4(1, 2) << endl;
	return 0;
}