//#include <iostream>
//using namespace std;
//int main()
//{
//	//���µ�p��b��c��*p������ֵ
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//
//	//���¼����Ƕ�������ֵ����ֵ����
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
//	//���¼������ǳ�������ֵ
//	10;
//	x + y;
//	fmin(x, y);
//
//	//���¼������Ƕ���ֵ����ֵ����
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double rr3 = fmin(x, y);
//
//	//�������ᱨ��error C2106: ��=��: �����������Ϊ��ֵ����ֵ���ܳ����ڸ�ֵ���ŵ���ߣ�
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
//	//rr2 = 5.5; //����
//	return 0;
//}


//#include <iostream>
//using namespace std;
//template<class T>
//void func(const T& x)
//{}
//int main()
//{
//	//��ֵ����ֻ��������ֵ������������ֵ
//	int a = 10;
//	int& ra1 = a; //ra1Ϊa�ı���
//	//int& ra2 = 10; //����ʧ�ܣ���Ϊ10����ֵ
//
//	//const��ֵ���üȿ���������ֵ��Ҳ��������ֵ
//	const int& ra3 = a;
//	const int& ra4 = 10;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	//��ֵ����ֻ��������ֵ������������ֵ
//	int&& r1 = 10;
//
//	//error C2440: ����ʼ����: �޷��ӡ�int��ת��Ϊ��int &&��
//	//message : �޷�����ֵ�󶨵���ֵ����
//	int a = 10;
//	int&& r2 = a;
//
//	//��ֵ���ÿ�������move�Ժ����ֵ
//	int&& r3 = std::move(a);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	//���µ�p��b��c��*p������ֵ
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
//	//���¼������ǳ�������ֵ
//	10;
//	x + y;
//	fmin(x, y);
//
//	//����ʾ������ֵ���ܳ����ڸ�ֵ���ŵ���ߣ�
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
//	cout << &rr1 << endl; //ȡ��ֵ�ĵ�ַ
//	rr1 = 20; //�޸���ֵ
//
//	double x = 1.1, y = 2.2;
//	const double&& rr2 = x + y; //const��ֵ����
//	//rr2 = 5.5; //����
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
//	func(s);       //sΪ��ֵ
//
//	func("world"); //"world"Ϊ��ֵ
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a = 10;
//
//	//int&& r1 = a;     //��ֵ���ò���������ֵ
//	int&& r2 = move(a); //��ֵ���ÿ�������move�Ժ����ֵ
//	return 0;
//}


//#include <iostream>
//using namespace std;
//namespace cl
//{
//	//ģ��ʵ��string��
//	class string
//	{
//	public:
//		//[]��������أ��ɶ���д��
//		char& operator[](size_t i)
//		{
//			assert(i < _size); //����±�ĺϷ���
//			return _str[i]; //���ض�Ӧ�ַ�
//		}
//		//...
//	private:
//		char* _str;       //�洢�ַ���
//		size_t _size;     //��¼�ַ�����ǰ����Ч����
//		//...
//	};
//}
//int main()
//{
//	cl::string s("hello");
//	s[3] = 'x';    //���÷��أ�֧���ⲿ�޸�
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
			return _str; //�����ַ����е�һ���ַ��ĵ�ַ
		}
		iterator end()
		{
			return _str + _size; //�����ַ��������һ���ַ��ĺ�һ���ַ��ĵ�ַ
		}
		//���캯��
		string(const char* str = "")
		{
			_size = strlen(str); //��ʼʱ���ַ�����С����Ϊ�ַ�������
			_capacity = _size; //��ʼʱ���ַ�����������Ϊ�ַ�������
			_str = new char[_capacity + 1]; //Ϊ�洢�ַ������ٿռ䣨�࿪һ�����ڴ��'\0'��
			strcpy(_str, str); //��C�ַ����������ѿ��õĿռ�
		}
		//�����������������
		void swap(string& s)
		{
			//���ÿ����swap
			::swap(_str, s._str); //�������������C�ַ���
			::swap(_size, s._size); //������������Ĵ�С
			::swap(_capacity, s._capacity); //�����������������
		}
		//�������캯�����ִ�д����
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(const string& s) -- ���" << endl;

			string tmp(s._str); //���ù��캯���������һ��C�ַ���Ϊs._str�Ķ���
			swap(tmp); //��������������
		}
		//��ֵ��������أ��ִ�д����
		string& operator=(const string& s)
		{
			cout << "string& operator=(const string& s) -- ���" << endl;

			string tmp(s); //��s�������������tmp
			swap(tmp); //��������������
			return *this; //������ֵ��֧��������ֵ��
		}
		//�ƶ�����
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- �ƶ�����" << endl;
			swap(s);
		}
		//�ƶ���ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- �ƶ���ֵ" << endl;
			swap(s);
			return *this;
		}
		//��������
		~string()
		{
			delete[] _str;  //�ͷ�_strָ��Ŀռ�
			_str = nullptr; //��ʱ�ÿգ���ֹ�Ƿ�����
			_size = 0;      //��С��0
			_capacity = 0;  //������0
		}
		//[]���������
		char& operator[](size_t i)
		{
			assert(i < _size); //����±�ĺϷ���
			return _str[i]; //���ض�Ӧ�ַ�
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
			if (_size == _capacity) //�ж��Ƿ���Ҫ����
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2); //����������Ϊԭ��������
			}
			_str[_size] = ch; //���ַ�β�嵽�ַ���
			_str[_size + 1] = '\0'; //�ַ����������'\0'
			_size++; //�ַ����Ĵ�С��һ
		}
		//+=���������
		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch); //β���ַ���
			return *this; //������ֵ��֧������+=��
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
//	func1(s);  //ֵ����
//	func2(s);  //��ֵ���ô���
//
//	s += 'X';  //��ֵ���÷���
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

	lt.push_back(s); //����string�Ŀ�������

	lt.push_back("2222");             //����string���ƶ�����
	lt.push_back(cl::string("3333")); //����string���ƶ�����
	lt.push_back(std::move(s));       //����string���ƶ�����
	return 0;
}