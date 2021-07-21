#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <assert.h>
#include <iostream>
using namespace std;

//namespace cl
//{
//	class string
//	{
//	public:
//		string(const char* str = "") 
//			:_str(new char[strlen(str) + 1])
//		{
//			strcpy(_str, str);
//		}
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//		//传统写法
//		//string(const string& s)
//		//	:_str(new char[strlen(s._str) + 1])
//		//{
//		//	strcpy(_str, s._str);
//		//}
//		//string& operator=(const string& s)
//		//{
//		//	if (this != &s)
//		//	{
//		//		delete[] _str;
//		//		_str = new char[strlen(s._str) + 1];
//		//		strcpy(_str, s._str);
//		//	}
//		//	return *this;
//		//}
//		//现代写法
//		string(const string& s)
//			:_str(nullptr)
//		{
//			string tmp(s._str);
//			swap(_str, tmp._str);
//		}
//		string& operator=(string s)
//		{
//			swap(_str, s._str);
//			return *this;
//		}
//		string& operator=(const string& s) //防止自己给自己赋值
//		{
//			if (this != &s)
//			{
//				string tmp(s);
//				swap(_str, tmp._str);
//			}
//			return *this;
//		}
//		const char* c_str()
//		{
//			return _str;
//		}
//	private:
//		char* _str;
//	};
//	void test_string1()
//	{
//		string s1("hello world");
//		string s2(s1);
//		cout << s1.c_str() << endl;
//		cout << s2.c_str() << endl;
//		string s3("hello bit");
//		s1 = s3;
//		cout << s1.c_str() << endl;
//		cout << s3.c_str() << endl;
//	}
//}


namespace cl
{
	class string
	{
	public:
		typedef char* iterator;
		//构造函数
		string(const char* str = "")
		{
			_size = strlen(str); //初始时，字符串大小设置为字符串长度
			_capacity = _size; //初始时，字符串容量设置为字符串长度
			_str = new char[_capacity + 1]; //为存储字符串开辟空间（多开一个用于存放'\0'）
			strcpy(_str, str); //将C字符串拷贝到已开好的空间
		}
		//析构函数
		~string()
		{
			delete[] _str;  //释放_str指向的空间
			_str = nullptr; //及时置空，防止非法访问
			_size = 0;      //大小置0
			_capacity = 0;  //容量置0
		}
		//交换两个对象的数据
		void swap(string& s)
		{
			//调用库里的swap
			::swap(_str, s._str); //交换两个对象的C字符串
			::swap(_size, s._size); //交换两个对象的大小
			::swap(_capacity, s._capacity); //交换两个对象的容量
		}
		//拷贝构造函数
		//传统写法
		//string(const string& s)
		//	:_str(new char[strlen(s._str) + 1]) //_str申请一块刚好可以容纳s._str的空间
		//	, _size(0)
		//	, _capacity(0)
		//{
		//	strcpy(_str, s._str);    //将s._str拷贝一份到_str
		//	_size = s._size;         //_size赋值
		//	_capacity = s._capacity; //_capacity赋值
		//}
		//现代写法
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str); //调用构造函数，构造出一个C字符串为s._str的对象
			//swap(_str, s._str);
			//swap(_size, s._size);
			//swap(_capacity, s._capacity);
			swap(tmp); //交换这两个对象
		}

		//赋值运算符重载
		////传统写法
		//string& operator=(const string& s)
		//{
		//	if (this != &s) //自己给自己赋值无需操作
		//	{
		//		delete[] _str; //将原来_str指向的空间释放
		//		_str = new char[strlen(s._str) + 1]; //重新申请一块刚好可以容纳s._str的空间
		//		strcpy(_str, s._str);    //将s._str拷贝一份到_str
		//		_size = s._size;         //_size赋值
		//		_capacity = s._capacity; //_capacity赋值
		//	}
		//	return *this; //返回左值（支持连续赋值）
		//}
		//现代写法1
		string& operator=(string s)
		{
			//swap(_str, s._str);
			//swap(_size, s._size);
			//swap(_capacity, s._capacity);

			//this->swap(s);

			swap(s); //交换这两个对象
			return *this; //返回左值（支持连续赋值）
		}
		////现代写法2
		//string& operator=(const string& s)
		//{
		//	if (this != &s) //防止自己给自己赋值
		//	{
		//		string tmp(s); //用s拷贝构造出对象tmp
		//		swap(tmp); //交换这两个对象
		//	}
		//	return *this; //返回左值（支持连续赋值）
		//}
		//可读可写
		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}
		//只读
		const char& operator[](size_t i)const
		{
			assert(i < _size);
			return _str[i];
		}

		iterator begin()
		{
			return _str; //返回字符串中第一个字符的地址
		}
		iterator end()
		{
			return _str + _size; //返回字符串中最后一个字符的后一个字符的地址
		}
		//大小
		size_t size()const
		{
			return _size; //返回字符串当前的有效长度
		}
		//容量
		size_t capacity()const
		{
			return _capacity; //返回字符串当前的容量
		}
		//判空
		bool empty()
		{
			return !strcmp(_str, "");
		}
		//清空字符串
		void clear()
		{
			_str = ""; //将字符串置空
		}
		//待定
		void resize(size_t n, char ch = '\0')
		{
			reserve(n); //若n大于对象当前容量，则需调用reserve函数进行增容
			//
			for (size_t i = _size; i < n; i++)
			{
				_str[i] = ch;
			}
			_size = n;
			_str[n] = '\0';
		}
		//改变容量，大小不变
		void reserve(size_t n)
		{
			if (n > _capacity) //当n大于对象当前容量时才需执行操作
			{
				char* tmp = new char[n + 1]; //多开一个空间用于存放'\0'
				strcpy(tmp, _str); //将对象原本的C字符串拷贝过来
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
				reserve(2 * _capacity); //将容量扩大为原来的两倍
			}
			_str[_size] = ch; //将字符尾插到字符串
			_str[_size + 1] = '\0'; //字符串后面放上'\0'
			_size++; //字符串的大小加一
		}
		//尾插字符串
		void append(const char* str)
		{
			size_t len = _size + strlen(str); //尾插str后字符串的大小（不包括'\0'）
			if (len > _capacity) //判断是否需要增容
			{
				reserve(len); //增容
			}
			strcpy(_str + _size, str); //将str尾插到字符串后面
			_size = len; //字符串大小改变
		}
		//+=运算符重载
		string& operator+=(char ch)
		{
			push_back(ch); //尾插字符串
			return *this; //返回左值（支持连续+=）
		}
		//+=运算符重载
		string& operator+=(const char* str)
		{
			append(str); //尾插字符串
			return *this; //返回左值（支持连续+=）
		}

		bool operator>(const string& s)const
		{
			//size_t i = 0;
			//size_t len1 = size(), len2 = s.size();
			//while (i <= len1||i <= len2)
			//{
			//	if (_str[i] > s._str[i])
			//		return true;
			//	else if (_str[i] < s._str[i])
			//		return false;
			//	i++;
			//}
			if (strcmp(_str, s._str) > 0)
				return true;
			else
				return false;
		}
		bool operator>=(const string& s)const
		{
			return (*this > s) || (*this == s);
		}
		bool operator<(const string& s)const
		{
			return !(*this >= s);
		}
		bool operator<=(const string& s)const
		{
			return !(*this > s);
		}
		bool operator==(const string& s)const
		{
			return !strcmp(_str, s._str);
		}
		bool operator!=(const string& s)const
		{
			return !(*this == s);
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
	void test_string1()
	{
		string s1("hello world");
		string s2(s1);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		string s3("hello bit");
		s1 = s3;
		cout << s1.c_str() << endl;
		cout << s3.c_str() << endl;
	}
	void test_string2()
	{
		string s1("hello");
		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;
	}
	void test_string3()
	{
		string s("hello world!!!");
		string::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
		//编译器将其替换为迭代器
		for (auto e : s)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void test_string4()
	{
		string s("hello");
		cout << "_size:" << s.size() << endl;
		cout << "_capacity:" << s.capacity() << endl;
		s.push_back('!');
		cout << "_size:" << s.size() << endl;
		cout << "_capacity:" << s.capacity() << endl;
		s.push_back('!');
		cout << "_size:" << s.size() << endl;
		cout << "_capacity:" << s.capacity() << endl;
		s.push_back('!');
		cout << "_size:" << s.size() << endl;
		cout << "_capacity:" << s.capacity() << endl;
		s.push_back('!');
		cout << "_size:" << s.size() << endl;
		cout << "_capacity:" << s.capacity() << endl;
		s.push_back('!');
		cout << "_size:" << s.size() << endl;
		cout << "_capacity:" << s.capacity() << endl;
		s.push_back('!');
		cout << "_size:" << s.size() << endl;
		cout << "_capacity:" << s.capacity() << endl;
		s.append("csdn");
		cout << "_size:" << s.size() << endl;
		cout << "_capacity:" << s.capacity() << endl;
		cout << s.c_str() << endl;
		s.append("this is a test.");
		cout << "_size:" << s.size() << endl;
		cout << "_capacity:" << s.capacity() << endl;
		cout << s.c_str() << endl;
		s += 'x';
		cout << "_size:" << s.size() << endl;
		cout << "_capacity:" << s.capacity() << endl;
		cout << s.c_str() << endl;
		s += "xxxxx";
		cout << "_size:" << s.size() << endl;
		cout << "_capacity:" << s.capacity() << endl;
		cout << s.c_str() << endl;
	}
	void test_string5()
	{
		string s("hello");
		cout << s.size() << endl;
		cout << s.capacity() << endl;
		s.resize(20);
		cout << s.size() << endl;
		cout << s.capacity() << endl;
		s.resize(1);
		cout << s.size() << endl;
		cout << s.capacity() << endl;
	}
	void test_string6()
	{
		string s1("abcd");
		string s2("abcd");
		cout << (s1 > s2) << endl;
		cout << (s1 >= s2) << endl;
		cout << (s1 < s2) << endl;
		cout << (s1 <= s2) << endl;
		cout << (s1 == s2) << endl;
		cout << (s1 != s2) << endl;
	}
	void test_string7()
	{
		string s("");
		cout << s.empty() << endl;
		string s1;
		cout << s.empty() << endl;
	}
	void test_string8()
	{
		string s("CSDN");
		s.resize(10, '#');
		cout << s.c_str() << endl;
		cout << s.size() << endl;
		cout << s.capacity() << endl;
		s.resize(1, '#');
		cout << s.c_str() << endl;
		cout << s.size() << endl;
		cout << s.capacity() << endl;
	}
}

//namespace cl
//{
//	//模拟实现string类
//	class string
//	{
//		//<<和>>运算符重载函数
//		friend istream& operator>>(istream& cin, string& s);
//		friend ostream& operator<<(ostream& cout, const string& s);
//	public:
//		typedef char* iterator;
//		//默认成员函数
//		string(const char* str = "");          //构造函数
//		string(const string& s);               //拷贝构造函数
//		string& operator=(const string& s);    //赋值运算符重载函数
//		~string();                             //析构函数
//
//		//迭代器相关函数
//		iterator begin();
//		iterator end();
//
//		//容量和大小相关函数
//		size_t size();
//		size_t capacity();
//		void reserve(size_t n);
//		void resize(size_t n, char ch = '\0');
//		bool empty()const;
//
//		//修改字符串相关函数
//		void push_back(char ch);
//		string& operator+=(char ch);
//		void append(const char* str);
//		string& operator+=(const char* str);
//		string& insert(size_t pos, char ch);
//		string& insert(size_t pos, const char* str);
//		string& erase(size_t pos, size_t len);
//		void clear();
//		void swap(string& s);
//		const char* c_str()const;
//
//		//访问字符串相关函数
//		char& operator[](size_t i);
//		const char& operator[](size_t i)const;
//		size_t find(char ch, size_t pos = 0)const;
//		size_t find(const char* str, size_t pos = 0)const;
//
//		//关系运算符重载函数
//		bool operator>(const string& s)const;
//		bool operator>=(const string& s)const;
//		bool operator<(const string& s)const;
//		bool operator<=(const string& s)const;
//		bool operator==(const string& s)const;
//		bool operator!=(const string& s)const;
//
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//	};
//}