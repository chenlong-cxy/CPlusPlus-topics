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
//		//��ͳд��
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
//		//�ִ�д��
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
//		string& operator=(const string& s) //��ֹ�Լ����Լ���ֵ
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
		//���캯��
		string(const char* str = "")
		{
			_size = strlen(str); //��ʼʱ���ַ�����С����Ϊ�ַ�������
			_capacity = _size; //��ʼʱ���ַ�����������Ϊ�ַ�������
			_str = new char[_capacity + 1]; //Ϊ�洢�ַ������ٿռ䣨�࿪һ�����ڴ��'\0'��
			strcpy(_str, str); //��C�ַ����������ѿ��õĿռ�
		}
		//��������
		~string()
		{
			delete[] _str; //�ͷŴ洢�ַ����Ŀռ�
			_str = nullptr; //��ʱ�ÿգ���ֹ�Ƿ�����
			_size = 0; //��С��0
			_capacity = 0; //������0
		}
		//�����������������
		void swap(string& s)
		{
			//���ÿ����swap
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		//�������캯��
		//��ͳд��
		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		string& operator=(const string& s)
		{
		//�ִ�д��
		//string(const string& s)
		//	:_str(nullptr)
		//	, _size(0)
		//	, _capacity(0)
		//{
		//	string tmp(s._str); //���ù��캯�����������tmp��tmp�д洢��C�ַ���Ϊs._str
		//	//swap(_str, tmp._str);
		//	//swap(_size, tmp._size);
		//	//swap(_capacity, tmp._capacity);

		//	//this->swap(tmp);
		//	
		//	swap(tmp);
		//}
		//��ֵ���������
		string& operator=(string s)
		{
			//swap(_str, s._str);
			//swap(_size, s._size);
			//swap(_capacity, s._capacity);

			//this->swap(s);

			swap(s);
			return *this;
		}
		//�ɶ���д
		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}
		//ֻ��
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
		//��С
		size_t size()const
		{
			return _size;
		}
		//����
		size_t capacity()const
		{
			return _capacity;
		}
		//����
		void resize(size_t n, char ch = '\0')
		{
			reserve(n);
			for (size_t i = _size; i <= _capacity; i++)
			{
				_str[i] = ch;
			}
			_size = n;
		}
		//�ı�_capacity��_size����
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

		//����C���͵��ַ���
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
		//�����������滻Ϊ������
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
//	//ģ��ʵ��string��
//	class string
//	{
//		//<<��>>��������غ���
//		friend istream& operator>>(istream& cin, string& s);
//		friend ostream& operator<<(ostream& cout, const string& s);
//	public:
//		typedef char* iterator;
//		//Ĭ�ϳ�Ա����
//		string(const char* str = "");          //���캯��
//		string(const string& s);               //�������캯��
//		string& operator=(const string& s);    //��ֵ��������غ���
//		~string();                             //��������
//
//		//��������غ���
//		iterator begin();
//		iterator end();
//
//		//�����ʹ�С��غ���
//		size_t size();
//		size_t capacity();
//		void reserve(size_t n);
//		void resize(size_t n, char ch = '\0');
//		bool empty()const;
//
//		//�޸��ַ�����غ���
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
//		//�����ַ�����غ���
//		char& operator[](size_t i);
//		const char& operator[](size_t i)const;
//		size_t find(char ch, size_t pos = 0)const;
//		size_t find(const char* str, size_t pos = 0)const;
//
//		//��ϵ��������غ���
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