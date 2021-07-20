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
			delete[] _str; //释放存储字符串的空间
			_str = nullptr; //及时置空，防止非法访问
			_size = 0; //大小置0
			_capacity = 0; //容量置0
		}
		//交换两个对象的数据
		void swap(string& s)
		{
			//调用库里的swap
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		//拷贝构造函数
		//传统写法
		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		string& operator=(const string& s)
		{
		//现代写法
		//string(const string& s)
		//	:_str(nullptr)
		//	, _size(0)
		//	, _capacity(0)
		//{
		//	string tmp(s._str); //调用构造函数，构造对象tmp，tmp中存储的C字符串为s._str
		//	//swap(_str, tmp._str);
		//	//swap(_size, tmp._size);
		//	//swap(_capacity, tmp._capacity);

		//	//this->swap(tmp);
		//	
		//	swap(tmp);
		//}
		//赋值运算符重载
		string& operator=(string s)
		{
			//swap(_str, s._str);
			//swap(_size, s._size);
			//swap(_capacity, s._capacity);

			//this->swap(s);

			swap(s);
			return *this;
		}
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
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		//大小
		size_t size()const
		{
			return _size;
		}
		//容量
		size_t capacity()const
		{
			return _capacity;
		}
		//待定
		void resize(size_t n, char ch = '\0')
		{
			reserve(n);
			for (size_t i = _size; i <= _capacity; i++)
			{
				_str[i] = ch;
			}
			_size = n;
		}
		//改变_capacity，_size不变
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(2 * _capacity);
			}
			_str[_size] = ch;
			_str[_size + 1] = '\0';
			_size++;
		}
		void append(const char* str)
		{
			size_t len = _size + strlen(str);
			if (len > _capacity)
			{
				reserve(len);
			}
			strcpy(_str + _size, str);
			_size = len;
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
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