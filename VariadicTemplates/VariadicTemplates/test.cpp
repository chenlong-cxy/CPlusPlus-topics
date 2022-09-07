#include <iostream>
#include <string>
using namespace std;

//template<class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(args) << endl; //获取参数包中参数的个数
//	for (int i = 0; i < sizeof...(args); i++)
//	{
//		cout << args[i] << " "; //打印参数包中的每个参数
//	}
//	cout << endl;
//}
//template<class T, class ...Args> //增加一个模板参数
//void ShowList(T value, Args... args)
//{
//	cout << value << " "; //打印传入的若干参数中的第一个参数
//	if (sizeof...(args) == 0)
//	{
//		return;
//	}
//	ShowList(args...);    //将剩下参数继续向下传
//}

////递归终止函数
//void ShowList()
//{
//	cout << endl;
//}
////展开函数
//template<class T, class ...Args>
//void ShowList(T value, Args... args)
//{
//	cout << value << " "; //打印分离出的第一个参数
//	ShowList(args...);    //递归调用，将参数包继续向下传
//}
//int main()
//{
//	ShowList();
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', string("hello"));
//	return 0;
//}

////递归终止函数
//template<class T>
//void ShowListArg(const T& t)
//{
//	cout << t << endl;
//}
////展开函数
//template<class T, class ...Args>
//void ShowListArg(T value, Args... args)
//{
//	cout << value << " "; //打印传入的若干参数中的第一个参数
//	ShowList(args...);    //将剩下参数继续向下传
//}
////供外部调用的函数
//template<class ...Args>
//void ShowList(Args... args)
//{
//	ShowListArg(args...);
//}
//int main()
//{
//	//ShowList();
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', string("hello"));
//	return 0;
//}


////错误示例
//template<class T, class ...Args>
//void ShowList(T value, Args... args)
//{
//	cout << value << " "; //打印传入的若干参数中的第一个参数
//	if (sizeof...(args) == 0)
//	{
//		return;
//	}
//	ShowList(args...);    //将剩下参数继续向下传
//}
//int main()
//{
//	//ShowList();
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', string("hello"));
//	return 0;
//}


//#include <iostream>
//#include <string>
//class Person
//{
//public:
//	Person() = delete;
//	~Person()
//	{
//		std::cout << "Yes" << std::endl;
//	}
//	std::string name;
//	int age;
//};
//int main()
//{
//	Person p{ "zhangsan", 20 };
//	std::cout << "OK" << std::endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
////递归终止函数
//void ShowListArg()
//{
//	cout << endl;
//}
////展开函数
//template<class T, class ...Args>
//void ShowListArg(T value, Args... args)
//{
//	cout << value << " "; //打印传入的若干参数中的第一个参数
//	ShowListArg(args...); //将剩下参数继续向下传
//}
////供外部调用的函数
//template<class ...Args>
//void ShowList(Args... args)
//{
//	ShowListArg(args...);
//}
//int main()
//{
//	ShowList();
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', string("hello"));
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
////展开函数
//template<class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { args... }; //列表初始化
//	//打印参数包中的各个参数
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	ShowList(1);
//	ShowList(1, 2);
//	ShowList(1, 2, 3);
//	return 0;
//}


//#include <iostream>
//using namespace std;
////支持无参调用
//void ShowList()
//{
//	cout << endl;
//}
////处理函数
//template<class T>
//void PrintArg(const T& t)
//{
//	cout << t << " ";
//}
////展开函数
//template<class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { (PrintArg(args), 0)... }; //列表初始化+逗号表达式
//	cout << endl;
//}
//int main()
//{
//	ShowList();
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', string("hello"));
//	return 0;
//}

#include <iostream>
using namespace std;
//支持无参调用
void ShowList()
{
	cout << endl;
}
//处理函数
template<class T>
int PrintArg(const T& t)
{
	cout << t << " ";
	return 0;
}
//展开函数
template<class ...Args>
void ShowList(Args... args)
{
	int arr[] = { PrintArg(args)... }; //列表初始化
	cout << endl;
}
int main()
{
	ShowList();
	ShowList(1);
	ShowList(1, 'A');
	ShowList(1, 'A', string("hello"));
	return 0;
}


//#include <iostream>
//using namespace std;
//void ShowList() //0个参数的ShowList
//{
//	cout << endl;
//}
//template<class T>
//int PrintArg(const T& t)
//{
//	cout << t << " ";
//	return 0;
//}
//template<class ...Args>
//void ShowList(Args&&... args)
//{
//	int arr[] = { PrintArg(args)... }; //列表初始化
//	cout << endl;
//}
//int main()
//{
//	ShowList();
//	string s("ss");
//	ShowList(move(s));
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', string("hello"));
//	return 0;
//}


//#include <iostream>
//#include <list>
//using namespace std;
//int main()
//{
//	list<pair<int, char>> mylist;
//	mylist.emplace_back(10, 'a');
//	mylist.emplace_back(20, 'b');
//	mylist.emplace_back(make_pair(30, 'c'));
//
//	mylist.push_back(make_pair(40, 'd'));
//	mylist.push_back({ 50, 'e' });
//
//	for (auto e : mylist)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <initializer_list>
//#include <list>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	//Date(initializer_list<int> lt)
//	//{}
//	void Print()
//	{
//		cout << _year << ":" << _month << ":" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	list<Date> mylist;
//	Date d1;
//	mylist.push_back(d1);
//	mylist.push_back(Date(2022,9,7));
//	mylist.push_back({ 2022, 9, 8 });
//
//	mylist.emplace_back(d1);
//	mylist.emplace_back(Date(2022, 9, 7));
//	//mylist.emplace_back({ 2022, 9, 8 });
//	mylist.emplace_back(2022, 9, 14);
//	for (auto e : mylist)
//	{
//		e.Print();
//	}
//	return 0;
//}



#include <iostream>
#include <initializer_list>
#include <list>
using namespace std;
namespace cl
{
	class string
	{
	public:
		//构造函数
		string(const char* str = "")
		{
			cout << "string(const char* str) -- 构造函数" << endl;

			_size = strlen(str); //初始时，字符串大小设置为字符串长度
			_capacity = _size; //初始时，字符串容量设置为字符串长度
			_str = new char[_capacity + 1]; //为存储字符串开辟空间（多开一个用于存放'\0'）
			strcpy(_str, str); //将C字符串拷贝到已开好的空间
		}
		//交换两个对象的数据
		void swap(string& s)
		{
			//调用库里的swap
			::swap(_str, s._str); //交换两个对象的C字符串
			::swap(_size, s._size); //交换两个对象的大小
			::swap(_capacity, s._capacity); //交换两个对象的容量
		}
		//拷贝构造函数（现代写法）
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(const string& s) -- 拷贝构造" << endl;

			string tmp(s._str); //调用构造函数，构造出一个C字符串为s._str的对象
			swap(tmp); //交换这两个对象
		}
		//移动构造
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- 移动构造" << endl;
			swap(s);
		}
		//拷贝赋值函数（现代写法）
		string& operator=(const string& s)
		{
			cout << "string& operator=(const string& s) -- 深拷贝" << endl;

			string tmp(s); //用s拷贝构造出对象tmp
			swap(tmp); //交换这两个对象
			return *this; //返回左值（支持连续赋值）
		}
		//移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
			swap(s);
			return *this;
		}
		//析构函数
		~string()
		{
			//delete[] _str;  //释放_str指向的空间
			_str = nullptr; //及时置空，防止非法访问
			_size = 0;      //大小置0
			_capacity = 0;  //容量置0
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}

//int main()
//{
//	list<pair<int, cl::string>> mylist;
//	pair<int, cl::string> kv(1, "one");
//
//	mylist.emplace_back(kv);                  //左值
//	cout << endl;
//	mylist.emplace_back(pair<int, cl::string>(2, "two")); //右值
//	cout << endl;
//	mylist.emplace_back(3, "three");          //参数包
//
//	return 0;
//}

//int main()
//{
//	list<pair<int, cl::string>> mylist;
//	pair<int, cl::string> kv(1, "one");
//
//	mylist.push_back(kv);                  //左值
//	cout << endl;
//	mylist.push_back(pair<int, cl::string>(2, "two")); //右值
//	cout << endl;
//	mylist.push_back({ 3, "three" });
//
//	return 0;
//}