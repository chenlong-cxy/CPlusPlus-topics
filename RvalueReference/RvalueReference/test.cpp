//#include <iostream>
//using namespace std;
//int main()
//{
//	//以下的p、b、c、*p都是左值
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//
//	//以下几个是对上面左值的左值引用
//	int*& rp = p;
//	int& rb = b;
//	const int& rc = c;
//	int& pvalue = *p;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	double x = 1.1, y = 2.2;
//	
//	//以下几个都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//
//	//以下几个都是对右值的右值引用
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double rr3 = fmin(x, y);
//
//	//这里编译会报错：error C2106: “=”: 左操作数必须为左值（右值不能出现在赋值符号的左边）
//	//10 = 1;
//	//x + y = 1;
//	//fmin(x, y) = 1;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	double x = 1.1, y = 2.2;
//	int&& rr1 = 10;
//	cout << &rr1 << endl;
//	const double&& rr2 = x + y;
//
//	rr1 = 20;
//	cout << &rr1 << endl;
//	//rr2 = 5.5; //报错
//	return 0;
//}


//#include <iostream>
//using namespace std;
//template<class T>
//void func(const T& x)
//{}
//int main()
//{
//	//左值引用只能引用左值，不能引用右值
//	int a = 10;
//	int& ra1 = a; //ra1为a的别名
//	//int& ra2 = 10; //编译失败，因为10是右值
//
//	//const左值引用既可以引用左值，也可引用右值
//	const int& ra3 = a;
//	const int& ra4 = 10;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	//右值引用只能引用右值，不能引用左值
//	int&& r1 = 10;
//
//	//error C2440: “初始化”: 无法从“int”转换为“int &&”
//	//message : 无法将左值绑定到右值引用
//	int a = 10;
//	int&& r2 = a;
//
//	//右值引用可以引用move以后的左值
//	int&& r3 = std::move(a);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	//以下的p、b、c、*p都是左值
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//	return 0;
//}
//
//int main()
//{
//	double x = 1.1, y = 2.2;
//
//	//以下几个都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//
//	//错误示例（右值不能出现在赋值符号的左边）
//	//10 = 1;
//	//x + y = 1;
//	//fmin(x, y) = 1;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	int&& rr1 = 10;
//	cout << &rr1 << endl; //取右值的地址
//	rr1 = 20; //修改右值
//
//	double x = 1.1, y = 2.2;
//	const double&& rr2 = x + y; //const右值引用
//	//rr2 = 5.5; //报错
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//template<class T>
//void func(const T& val)
//{
//	cout << val << endl;
//}
//int main()
//{
//	string s("hello");
//	func(s);       //s为左值
//
//	func("world"); //"world"为右值
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a = 10;
//
//	//int&& r1 = a;     //右值引用不能引用左值
//	int&& r2 = move(a); //右值引用可以引用move以后的左值
//	return 0;
//}


//#include <iostream>
//using namespace std;
//namespace cl
//{
//	//模拟实现string类
//	class string
//	{
//	public:
//		//[]运算符重载（可读可写）
//		char& operator[](size_t i)
//		{
//			assert(i < _size); //检测下标的合法性
//			return _str[i]; //返回对应字符
//		}
//		//...
//	private:
//		char* _str;       //存储字符串
//		size_t _size;     //记录字符串当前的有效长度
//		//...
//	};
//}
//int main()
//{
//	cl::string s("hello");
//	s[3] = 'x';    //引用返回，支持外部修改
//	return 0;
//}


#include <iostream>
#include <string.h>
#include <list>
#include <string>
#include <assert.h>
using namespace std;
namespace cl
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str; //返回字符串中第一个字符的地址
		}
		iterator end()
		{
			return _str + _size; //返回字符串中最后一个字符的后一个字符的地址
		}
		//构造函数
		string(const char* str = "")
		{
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
			cout << "string(const string& s) -- 深拷贝" << endl;

			string tmp(s._str); //调用构造函数，构造出一个C字符串为s._str的对象
			swap(tmp); //交换这两个对象
		}
		//赋值运算符重载（现代写法）
		string& operator=(const string& s)
		{
			cout << "string& operator=(const string& s) -- 深拷贝" << endl;

			string tmp(s); //用s拷贝构造出对象tmp
			swap(tmp); //交换这两个对象
			return *this; //返回左值（支持连续赋值）
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
			delete[] _str;  //释放_str指向的空间
			_str = nullptr; //及时置空，防止非法访问
			_size = 0;      //大小置0
			_capacity = 0;  //容量置0
		}
		//[]运算符重载
		char& operator[](size_t i)
		{
			assert(i < _size); //检测下标的合法性
			return _str[i]; //返回对应字符
		}

		//改变容量，大小不变
		void reserve(size_t n)
		{
			if (n > _capacity) //当n大于对象当前容量时才需执行操作
			{
				char* tmp = new char[n + 1]; //多开一个空间用于存放'\0'
				strncpy(tmp, _str, _size + 1); //将对象原本的C字符串拷贝过来（包括'\0'）
				delete[] _str; //释放对象原本的空间
				_str = tmp; //将新开辟的空间交给_str
				_capacity = n; //容量跟着改变
			}
		}
		//尾插字符
		void push_back(char ch)
		{
			if (_size == _capacity) //判断是否需要增容
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2); //将容量扩大为原来的两倍
			}
			_str[_size] = ch; //将字符尾插到字符串
			_str[_size + 1] = '\0'; //字符串后面放上'\0'
			_size++; //字符串的大小加一
		}
		//+=运算符重载
		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch); //尾插字符串
			return *this; //返回左值（支持连续+=）
		}
		//返回C类型的字符串
		const char* c_str()const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}
namespace cl
{
	cl::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}
		cl::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;
			str += (x + '0');
		}
		if (flag == false)
		{
			str += '-';
		}
		std::reverse(str.begin(), str.end());
		return str;
	}
}
void func1(cl::string s)
{}
void func2(const cl::string& s)
{}
//int main()
//{
//	cl::string s("hello world");
//	func1(s);  //值传参
//	func2(s);  //左值引用传参
//
//	s += 'X';  //左值引用返回
//	return 0;
//}

//int main()
//{
//	cl::string s = cl::to_string(1234);
//	return 0;
//}

//int main()
//{
//	//cl::string s = cl::to_string(1234);
//	//cl::to_string(1234);
//
//	cl::string s;
//	//...
//	s = cl::to_string(1234);
//	return 0;
//}

//namespace cl
//{
//	cl::string to_string(int value)
//	{
//		cl::string str;
//		//...
//		return str;
//	}
//}

//int main()
//{
//	cl::string s = cl::to_string(1234);
//
//	return 0;
//}

//namespace cl
//{
//	cl::string to_string(int value)
//	{
//		cl::string str;
//		//...
//		return str;
//	}
//}
//int main()
//{
//	cl::string s;
//	//...
//	s = cl::to_string(1234);
//
//	return 0;
//}

//int main()
//{
//	int* p = nullptr;
//	delete p;
//	list<cl::string> lt;
//	lt.push_back("1234");
//	cl::string s("hello");
//	lt.push_back(s);
//	lt.push_back(move(s));
//	return 0;
//}

//template<class _Ty>
//inline typename remove_reference<_Ty>::type&& move(_Ty&& _Arg) _NOEXCEPT
//{
//	//forward _Arg as movable
//	return ((typename remove_reference<_Ty>::type&&)_Arg);
//}
//int main()
//{
//	string s("123");
//	string s1(move(s));
//	return 0;
//}

//cl::string& func(cl::string& s)
//{
//	return s;
//}
//int main()
//{
//	cl::string s("hello");
//	func(s);
//	return 0;
//}

int main()
{
	list<cl::string> lt;
	cl::string s("1111");

	lt.push_back(s); //调用string的拷贝构造

	lt.push_back("2222");             //调用string的移动构造
	lt.push_back(cl::string("3333")); //调用string的移动构造
	lt.push_back(std::move(s));       //调用string的移动构造
	return 0;
}