#include <iostream>
#include <string>
using namespace std;

//template<class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(args) << endl; //��ȡ�������в����ĸ���
//	for (int i = 0; i < sizeof...(args); i++)
//	{
//		cout << args[i] << " "; //��ӡ�������е�ÿ������
//	}
//	cout << endl;
//}
//template<class T, class ...Args> //����һ��ģ�����
//void ShowList(T value, Args... args)
//{
//	cout << value << " "; //��ӡ��������ɲ����еĵ�һ������
//	if (sizeof...(args) == 0)
//	{
//		return;
//	}
//	ShowList(args...);    //��ʣ�²����������´�
//}

////�ݹ���ֹ����
//void ShowList()
//{
//	cout << endl;
//}
////չ������
//template<class T, class ...Args>
//void ShowList(T value, Args... args)
//{
//	cout << value << " "; //��ӡ������ĵ�һ������
//	ShowList(args...);    //�ݹ���ã����������������´�
//}
//int main()
//{
//	ShowList();
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', string("hello"));
//	return 0;
//}

////�ݹ���ֹ����
//template<class T>
//void ShowListArg(const T& t)
//{
//	cout << t << endl;
//}
////չ������
//template<class T, class ...Args>
//void ShowListArg(T value, Args... args)
//{
//	cout << value << " "; //��ӡ��������ɲ����еĵ�һ������
//	ShowList(args...);    //��ʣ�²����������´�
//}
////���ⲿ���õĺ���
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


////����ʾ��
//template<class T, class ...Args>
//void ShowList(T value, Args... args)
//{
//	cout << value << " "; //��ӡ��������ɲ����еĵ�һ������
//	if (sizeof...(args) == 0)
//	{
//		return;
//	}
//	ShowList(args...);    //��ʣ�²����������´�
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
////�ݹ���ֹ����
//void ShowListArg()
//{
//	cout << endl;
//}
////չ������
//template<class T, class ...Args>
//void ShowListArg(T value, Args... args)
//{
//	cout << value << " "; //��ӡ��������ɲ����еĵ�һ������
//	ShowListArg(args...); //��ʣ�²����������´�
//}
////���ⲿ���õĺ���
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
////չ������
//template<class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { args... }; //�б��ʼ��
//	//��ӡ�������еĸ�������
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
////֧���޲ε���
//void ShowList()
//{
//	cout << endl;
//}
////������
//template<class T>
//void PrintArg(const T& t)
//{
//	cout << t << " ";
//}
////չ������
//template<class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { (PrintArg(args), 0)... }; //�б��ʼ��+���ű��ʽ
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
//֧���޲ε���
void ShowList()
{
	cout << endl;
}
//������
template<class T>
int PrintArg(const T& t)
{
	cout << t << " ";
	return 0;
}
//չ������
template<class ...Args>
void ShowList(Args... args)
{
	int arr[] = { PrintArg(args)... }; //�б��ʼ��
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
//void ShowList() //0��������ShowList
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
//	int arr[] = { PrintArg(args)... }; //�б��ʼ��
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
		//���캯��
		string(const char* str = "")
		{
			cout << "string(const char* str) -- ���캯��" << endl;

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
			cout << "string(const string& s) -- ��������" << endl;

			string tmp(s._str); //���ù��캯���������һ��C�ַ���Ϊs._str�Ķ���
			swap(tmp); //��������������
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
		//������ֵ�������ִ�д����
		string& operator=(const string& s)
		{
			cout << "string& operator=(const string& s) -- ���" << endl;

			string tmp(s); //��s�������������tmp
			swap(tmp); //��������������
			return *this; //������ֵ��֧��������ֵ��
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
			//delete[] _str;  //�ͷ�_strָ��Ŀռ�
			_str = nullptr; //��ʱ�ÿգ���ֹ�Ƿ�����
			_size = 0;      //��С��0
			_capacity = 0;  //������0
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
//	mylist.emplace_back(kv);                  //��ֵ
//	cout << endl;
//	mylist.emplace_back(pair<int, cl::string>(2, "two")); //��ֵ
//	cout << endl;
//	mylist.emplace_back(3, "three");          //������
//
//	return 0;
//}

//int main()
//{
//	list<pair<int, cl::string>> mylist;
//	pair<int, cl::string> kv(1, "one");
//
//	mylist.push_back(kv);                  //��ֵ
//	cout << endl;
//	mylist.push_back(pair<int, cl::string>(2, "two")); //��ֵ
//	cout << endl;
//	mylist.push_back({ 3, "three" });
//
//	return 0;
//}