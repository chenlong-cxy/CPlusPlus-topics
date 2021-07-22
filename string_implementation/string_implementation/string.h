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
		//����<<��>>��������غ���Ϊstring�����Ԫ����
		//friend istream& operator>>(istream& cin, string& s);
		//friend ostream& operator<<(ostream& cout, const string& s);
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
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
			delete[] _str;  //�ͷ�_strָ��Ŀռ�
			_str = nullptr; //��ʱ�ÿգ���ֹ�Ƿ�����
			_size = 0;      //��С��0
			_capacity = 0;  //������0
		}
		//�����������������
		void swap(string& s)
		{
			//���ÿ����swap
			::swap(_str, s._str); //�������������C�ַ���
			::swap(_size, s._size); //������������Ĵ�С
			::swap(_capacity, s._capacity); //�����������������
		}
		//�������캯��
		//��ͳд��
		//string(const string& s)
		//	:_str(new char[strlen(s._str) + 1]) //_str����һ��պÿ�������s._str�Ŀռ�
		//	, _size(0)
		//	, _capacity(0)
		//{
		//	strcpy(_str, s._str);    //��s._str����һ�ݵ�_str
		//	_size = s._size;         //_size��ֵ
		//	_capacity = s._capacity; //_capacity��ֵ
		//}
		//�ִ�д��
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str); //���ù��캯���������һ��C�ַ���Ϊs._str�Ķ���
			//swap(_str, s._str);
			//swap(_size, s._size);
			//swap(_capacity, s._capacity);
			swap(tmp); //��������������
		}

		//��ֵ���������
		////��ͳд��
		//string& operator=(const string& s)
		//{
		//	if (this != &s) //�Լ����Լ���ֵ�������
		//	{
		//		delete[] _str; //��ԭ��_strָ��Ŀռ��ͷ�
		//		_str = new char[strlen(s._str) + 1]; //��������һ��պÿ�������s._str�Ŀռ�
		//		strcpy(_str, s._str);    //��s._str����һ�ݵ�_str
		//		_size = s._size;         //_size��ֵ
		//		_capacity = s._capacity; //_capacity��ֵ
		//	}
		//	return *this; //������ֵ��֧��������ֵ��
		//}
		//�ִ�д��1
		string& operator=(string s)
		{
			//swap(_str, s._str);
			//swap(_size, s._size);
			//swap(_capacity, s._capacity);

			//this->swap(s);

			swap(s); //��������������
			return *this; //������ֵ��֧��������ֵ��
		}
		////�ִ�д��2
		//string& operator=(const string& s)
		//{
		//	if (this != &s) //��ֹ�Լ����Լ���ֵ
		//	{
		//		string tmp(s); //��s�������������tmp
		//		swap(tmp); //��������������
		//	}
		//	return *this; //������ֵ��֧��������ֵ��
		//}
		//[]��������أ��ɶ���д��
		char& operator[](size_t i)
		{
			assert(i < _size); //����±�ĺϷ���
			return _str[i]; //���ض�Ӧ�ַ�
		}
		//[]��������أ�ֻ����
		const char& operator[](size_t i)const
		{
			assert(i < _size); //����±�ĺϷ���
			return _str[i]; //���ض�Ӧ�ַ�
		}

		iterator begin()
		{
			return _str; //�����ַ����е�һ���ַ��ĵ�ַ
		}
		iterator end()
		{
			return _str + _size; //�����ַ��������һ���ַ��ĺ�һ���ַ��ĵ�ַ
		}
		const_iterator begin()const
		{
			return _str; //�����ַ����е�һ���ַ���const��ַ
		}
		const_iterator end()const
		{
			return _str + _size; //�����ַ��������һ���ַ��ĺ�һ���ַ���const��ַ
		}
		//��С
		size_t size()const
		{
			return _size; //�����ַ�����ǰ����Ч����
		}
		//����
		size_t capacity()const
		{
			return _capacity; //�����ַ�����ǰ������
		}
		//�п�
		bool empty()
		{
			return strcmp(_str, "") == 0;
		}
		//����ַ���
		void clear()
		{
			_size = 0; //size�ÿ�
			_str[_size] = '\0'; //�ַ����������'\0'
		}
		//�ı��С
		void resize(size_t n, char ch = '\0')
		{
			if (n <= _size) //nС�ڵ�ǰsize
			{
				_size = n; //��size����Ϊn
				_str[_size] = '\0'; //��size���ַ������'\0'
			}
			else //n���ڵ�ǰ��size
			{
				if (n > _capacity) //�ж��Ƿ���Ҫ����
				{
					reserve(n); //����
				}
				for (size_t i = _size; i < n; i++) //��size����n��������ַ�Ϊch
				{
					_str[i] = ch;
				}
				_size = n; //size����
				_str[_size] = '\0'; //�ַ����������'\0'
			}
		}
		//�ı���������С����
		void reserve(size_t n)
		{
			if (n > _capacity) //��n���ڶ���ǰ����ʱ����ִ�в���
			{
				char* tmp = new char[n + 1]; //�࿪һ���ռ����ڴ��'\0'
				strncpy(tmp, _str, _size + 1); //������ԭ����C�ַ�����������������'\0'��
				delete[] _str; //�ͷŶ���ԭ���Ŀռ�
				_str = tmp; //���¿��ٵĿռ佻��_str
				_capacity = n; //�������Ÿı�
			}
		}
		//β���ַ�
		void push_back(char ch)
		{
			//if (_size == _capacity) //�ж��Ƿ���Ҫ����
			//{
			//	reserve(_capacity == 0 ? 4 : _capacity * 2); //����������Ϊԭ��������
			//}
			//_str[_size] = ch; //���ַ�β�嵽�ַ���
			//_str[_size + 1] = '\0'; //�ַ����������'\0'
			//_size++; //�ַ����Ĵ�С��һ

			insert(_size, ch); //���ַ���ĩβ�����ַ�ch
		}
		//β���ַ���
		void append(const char* str)
		{
			//size_t len = _size + strlen(str); //β��str���ַ����Ĵ�С��������'\0'��
			//if (len > _capacity) //�ж��Ƿ���Ҫ����
			//{
			//	reserve(len); //����
			//}
			//strcpy(_str + _size, str); //��strβ�嵽�ַ�������
			//_size = len; //�ַ�����С�ı�

			insert(_size, str); //���ַ���ĩβ�����ַ���str
		}
		//+=���������
		string& operator+=(char ch)
		{
			push_back(ch); //β���ַ���
			return *this; //������ֵ��֧������+=��
		}
		//+=���������
		string& operator+=(const char* str)
		{
			append(str); //β���ַ���
			return *this; //������ֵ��֧������+=��
		}
		//��posλ�ò����ַ�
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size); //����±�ĺϷ���
			if (_size == _capacity) //�ж��Ƿ���Ҫ����
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2); //����������Ϊԭ��������
			}
			char* end = _str + _size;
			//��posλ�ü���֮����ַ����Ų��һλ
			while (end >= _str + pos)
			{
				*(end + 1) = *(end);
				end--;
			}
			_str[pos] = ch; //posλ�÷���ָ���ַ�
			_size++; //size����
			return *this;
		}
		//��posλ�ò����ַ���
		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size); //����±�ĺϷ���
			size_t len = strlen(str); //������Ҫ������ַ����ĳ��ȣ�����'\0'��
			if (len + _size > _capacity) //�ж��Ƿ���Ҫ����
			{
				reserve(len + _size); //����
			}
			char* end = _str + _size;
			//��posλ�ü���֮����ַ����Ų��lenλ
			while (end >= _str + pos)
			{
				*(end + len) = *(end);
				end--;
			}
			strncpy(_str + pos, str, len); //posλ�ÿ�ʼ����ָ���ַ���
			_size += len; //size����
			return *this;
		}
		//ɾ��posλ�ÿ�ʼ��len���ַ�
		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size); //����±�ĺϷ���
			size_t n = _size - pos; //posλ�ü���������Ч�ַ�����
			if (len >= n) //˵��posλ�ü��������ַ�����ɾ��
			{
				_size = pos; //size����
				_str[_size] = '\0'; //�ַ����������'\0'
			}
			else //˵��posλ�ü���󷽵���Ч�ַ���Ҫ����һ����
			{
				strcpy(_str + pos, _str + pos + len); //����Ҫ��������Ч�ַ�������Ҫɾ������Ч�ַ�
				_size -= len; //size����
			}
			return *this;
		}
		//������ҵ�һ��ƥ����ַ�
		size_t find(char ch, size_t pos = 0)
		{
			assert(pos < _size); //����±�ĺϷ���
			for (size_t i = pos; i < _size; i++) //��posλ�ÿ�ʼ���Ѱ��Ŀ���ַ�
			{
				if (_str[i] == ch)
				{
					return i; //�ҵ�Ŀ���ַ����������±�
				}
			}
			return npos; //û���ҵ�Ŀ���ַ�������npos
		}
		//������ҵ�һ��ƥ����ַ���
		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size); //����±�ĺϷ���
			const char* ret = strstr(_str + pos, str); //����strstr���в���
			if (ret) //ret��Ϊ��ָ�룬˵���ҵ���
			{
				return ret - _str; //�����ַ�����һ���ַ����±�
			}
			else //û���ҵ�
			{
				return npos; //����npos
			}
		}
		//������ҵ�һ��ƥ����ַ�
		size_t rfind(char ch, size_t pos = npos)
		{
			string tmp(*this); //�����������tmp
			reverse(tmp.begin(), tmp.end()); //����reverse���ö���tmp��C�ַ���
			if (pos >= _size) //����pos�����ַ�����Ч����
			{
				pos = _size - 1; //��������posΪ�ַ������һ���ַ����±�
			}
			pos = _size - 1 - pos; //��pos��Ϊ����Գƺ��λ��
			size_t ret = tmp.find(ch, pos); //����find����
			if (ret != npos)
				return _size - 1 - ret; //�ҵ��ˣ�����ret����Գƺ��λ��
			else
				return npos; //û�ҵ�������npos
		}
		//������ҵ�һ��ƥ����ַ���
		size_t rfind(const char* str, size_t pos = npos)
		{
			string tmp(*this); //�����������tmp
			reverse(tmp.begin(), tmp.end()); //����reverse���ö���tmp��C�ַ���
			size_t len = strlen(str); //�����ҵ��ַ����ĳ���
			char* arr = new char[len + 1]; //����arr�ַ��������ڿ���str�ַ�����
			strcpy(arr, str); //����str��arr
			size_t left = 0, right = len - 1; //��������ָ��
			//�����ַ���arr
			while (left < right)
			{
				::swap(arr[left], arr[right]);
				left++;
				right--;
			}
			if (pos >= _size) //����pos�����ַ�����Ч����
			{
				pos = _size - 1; //��������posΪ�ַ������һ���ַ����±�
			}
			pos = _size - 1 - pos; //��pos��Ϊ����Գƺ��λ��
			size_t ret = tmp.find(arr, pos); //����find����
			delete[] arr; //����arrָ��Ŀռ䣬�����ڴ�й©
			if (ret != npos)
				return _size - ret - len; //�ҵ��ˣ�����ret����Գƺ��ٵ�����λ��
			else
				return npos; //û�ҵ�������npos
		}
		//>���������
		bool operator>(const string& s)const
		{
			return strcmp(_str, s._str) > 0;
		}
		//>=���������
		bool operator>=(const string& s)const
		{
			return (*this > s) || (*this == s);
		}
		//<���������
		bool operator<(const string& s)const
		{
			return !(*this >= s);
		}
		//<=���������
		bool operator<=(const string& s)const
		{
			return !(*this > s);
		}
		//==���������
		bool operator==(const string& s)const
		{
			return strcmp(_str, s._str) == 0;
		}
		//!=���������
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
		static const size_t npos;
	};
	const size_t string::npos = -1;
	//>>�����������
	istream& operator>>(istream& in, string& s)
	{
		s.clear(); //����ַ���
		char ch = in.get(); //��ȡһ���ַ�
		while (ch != ' '&&ch != '\n') //����ȡ�����ַ����ǿո��'\n'��ʱ�������ȡ
		{
			s += ch; //����ȡ�����ַ�β�嵽�ַ�������
			ch = in.get(); //������ȡ�ַ�
		}
		return in; //֧����������
	}
	//<<�����������
	ostream& operator<<(ostream& out, const string& s)
	{
		//ʹ�÷�Χfor�����ַ��������
		for (auto e : s)
		{
			cout << e;
		}
		return out; //֧���������
	}
	//��ȡһ�к��пո���ַ���
	istream& getline(istream& in, string& s)
	{
		s.clear(); //����ַ���
		char ch = in.get(); //��ȡһ���ַ�
		while (ch != '\n') //����ȡ�����ַ�����'\n'��ʱ�������ȡ
		{
			s += ch; //����ȡ�����ַ�β�嵽�ַ�������
			ch = in.get(); //������ȡ�ַ�
		}
		return in;
	}

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
	void test_string9()
	{
		string s("hello world");
		s.insert(3, "what");
		cout << s.c_str() << endl;
		s.insert(0, "what");
		cout << s.c_str() << endl;
		s.insert(3, 'p');
		cout << s.c_str() << endl;
		s.insert(0, 'x');
		cout << s.c_str() << endl;
		s.erase(4, 3);
		cout << s.c_str() << endl;
		s.erase(2);
		cout << s.c_str() << endl;
	}
	void test_string10()
	{
		string s("hello world");
		//cout << s.find('w', 0) << endl;
		//cout << s.c_str() << endl;

		//cout << s.find('r', 2) << endl;
		//cout << s.c_str() << endl;

		//cout << s.find(" w", 0) << endl;
		//cout << s.c_str() << endl;

		//cout << s.find("w ") << endl;
		//cout << s.c_str() << endl;

		//cout << s.rfind('w', 20) << endl;
		//cout << s.c_str() << endl;

		//cout << s.rfind('e', 60) << endl;
		//cout << s.c_str() << endl;

		cout << s.rfind("elo", 0) << endl;
		cout << s.c_str() << endl;

		cout << s.rfind("rl", 9) << endl;
		cout << s.c_str() << endl;
	}
	void test_string11()
	{
		string s("hello world");
		cout << s << endl;
		cin >> s;
		cout << s << endl;
		getline(cin, s);
		cout << s << endl;
	}
}

//namespace cl
//{
//	//ģ��ʵ��string��
//	class string
//	{
//		//����<<��>>��������غ���Ϊstring�����Ԫ����
//		friend istream& operator>>(istream& cin, string& s);
//		friend ostream& operator<<(ostream& cout, const string& s);
//	public:
//		typedef char* iterator;
//		typedef const char* const_iterator;
//
//		//Ĭ�ϳ�Ա����
//		string(const char* str = "");         //���캯��
//		string(const string& s);              //�������캯��
//		string& operator=(const string& s);   //��ֵ��������غ���
//		~string();                            //��������
//
//		//��������غ���
//		iterator begin();
//		iterator end();
//		const_iterator begin()const;
//		const_iterator end()const;
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
//		void append(const char* str);
//		string& operator+=(char ch);
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
//		size_t rfind(char ch, size_t pos = npos)const;
//		size_t rfind(const char* str, size_t pos = 0)const;
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
//		char* _str;       //�洢�ַ���
//		size_t _size;     //��¼�ַ�����ǰ����Ч����
//		size_t _capacity; //��¼�ַ�����ǰ������
//		static const size_t npos; //��̬��Ա�������������ֵ��
//	};
//	const size_t string::npos = -1;
//
//	//<<��>>��������غ���
//	istream& operator>>(istream& in, string& s);
//	ostream& operator<<(ostream& out, const string& s);
//	istream& getline(istream& in, string& s);
//}