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
		//�ƶ�����
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- �ƶ�����" << endl;
			swap(s);
		}
		//��ֵ��������أ��ִ�д����
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