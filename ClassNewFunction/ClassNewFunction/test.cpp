#include <iostream>
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
		//移动构造
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- 移动构造" << endl;
			swap(s);
		}
		//赋值运算符重载（现代写法）
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
class Person
{
public:
	Person(const char* name = "", int age = 0)
		:_name(name)
		, _age(age)
	{}
	//Person(const Person& p)
	//	:_name(p._name)
	//	, _age(p._age)
	//{}
	//Person& operator=(Person&& p) = default;
	//Person& operator=(const Person& p)
	//{
	//	if (this != &p)
	//	{
	//		_name = p._name;
	//		_age = p._age;
	//	}
	//	return *this;
	//}
	//~Person()
	//{}
private:
	cl::string _name;
	int _age;
};
//int main()
//{
//	Person s1;
//	//Person s2 = s1;
//	//Person s3 = std::move(s1);
//	Person s4;
//	s4 = std::move(s1);
//
//	return 0;
//}
int main()
{
	cl::string s1;
	cl::string s2;
	s1 = s2;
	return 0;
}