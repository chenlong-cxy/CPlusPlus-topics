//try
//{
//	//�����ı�ʶ����
//}
//catch (ExceptionName e1)
//{
//	//catch��
//}
//catch (ExceptionName e2)
//{
//	//catch��
//}
//catch (ExceptionName eN)
//{
//	//catch��
//}

////�����ʾ����������׳�A/B/C/D�е�ĳ�����͵��쳣
//void func() throw(A, B, C, D);
////�����ʾ�������ֻ���׳�bad_alloc���쳣
//void* operator new(std::size_t size) throw(std::bad_alloc);
////�����ʾ������������׳��쳣
//void* operator new(std::size_t size, void* ptr) throw();


//#include <iostream>
//using namespace std;
//int main()
//{
//	try{
//		char* ptr = new char[0x7fffffff];
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl; //bad allocation
//	}
//	return 0;
//}


//#include <iostream>
//using namespace std;
//void f1()
//{
//	int i, j;
//	cin >> i >> j;
//	if (j == 0)
//	{
//		throw 1;
//	}
//	cout << i / j << endl;
//}
//int main()
//{
//	try
//	{
//		f1();
//	}
//	catch (int errid)
//	{
//		cout << "������: " << errid << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//void f1()
//{
//	int i, j;
//	cin >> i >> j;
//	if (j == 0)
//	{
//		throw string("�������");
//	}
//	cout << i / j << endl;
//}
//int main()
//{
//	try
//	{
//		f1();
//	}
//	catch (int errid)
//	{
//		cout << "������: " << errid << endl;
//	}
//	catch (const string& s)
//	{
//		cout << "��������: " << s << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//void f1()
//{
//	int i, j;
//	cin >> i >> j;
//	if (j == 0)
//	{
//		throw string("�������");
//	}
//	cout << i / j << endl;
//}
//int* p2 = nullptr;
//FILE* p3 = nullptr;
//void f2()
//{
//	p2 = (int*)malloc(40);
//	if (p2 == nullptr)
//	{
//		throw string("mallocʧ��");
//	}
//}
//void f3()
//{
//	p3 = fopen("test.txt", "r");
//	if (p3 == nullptr)
//	{
//		throw string("fopenʧ��");
//	}
//}
//int main()
//{
//	try
//	{
//		f1();
//		f2();
//		f3();
//		free(p2);
//		fclose(p3);
//	}
//	catch (int errid)
//	{
//		cout << "������: " << errid << endl;
//	}
//	catch (const string& s)
//	{
//		cout << "��������: " << s << endl;
//		if (s == "fopenʧ��")
//		{
//			free(p2);
//		}
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//class MyException
//{
//public:
//	MyException(int errid, const char* errmsg)
//		:_errid(errid)
//		, _errmsg(errmsg)
//	{}
//	int GetErrid() const
//	{
//		return _errid;
//	}
//	const string& what() const
//	{
//		return _errmsg;
//	}
//private:
//	int _errid;
//	string _errmsg;
//};
//void f2()
//{
//	throw MyException(1, "test");
//}
//void f1()
//{
//	try{
//		f2();
//	}
//	catch (const MyException& e)
//	{
//		cout << "f1:" << endl;
//		cout << "������: " << e.GetErrid() << endl;
//		cout << "��������: " << e.what() << endl;
//	}
//}
//int func()
//{
//	return 2;
//}
//int main()
//{
//	try
//	{
//		f1();
//		char* ptr = new char[0x7fffffff];
//	}
//	catch (const MyException& e)
//	{
//		cout << "������: " << e.GetErrid() << endl;
//		cout << "��������: " << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "δ֪�쳣" << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//class MyException
//{
//public:
//	MyException(int errid, const char* errmsg)
//		:_errid(errid)
//		, _errmsg(errmsg)
//	{}
//	int GetErrid() const
//	{
//		return _errid;
//	}
//	const string& what() const
//	{
//		return _errmsg;
//	}
////private:
//protected:
//	int _errid;
//	string _errmsg;
//	//...
//};
//class CacheException : public MyException
//{
//public:
//	CacheException(int errid, const char* errmsg)
//		:MyException(errid, errmsg)
//	{}
//protected:
//	//...
//};
//class SqlException : public MyException
//{
//public:
//	SqlException(int errid, const char* errmsg)
//		:MyException(errid, errmsg)
//	{}
//protected:
//	//...
//};
//class NetworkException : public MyException
//{
//public:
//	NetworkException(int errid, const char* errmsg)
//		:MyException(errid, errmsg)
//	{}
//protected:
//	//...
//};
//void f1()
//{
//	int i = 0;
//	cin >> i;
//	if (i == 0)
//	{
//		throw CacheException(1, "���ݲ�����");
//	}
//}
//void f2()
//{
//	throw SqlException(2, "���ݿ�����ʧ��");
//}
//int main()
//{
//	try
//	{
//		f1();
//		f2();
//	}
//	catch (const MyException& e)
//	{
//		cout << "������: " << e.GetErrid() << endl;
//		cout << "��������: " << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "δ֪�쳣" << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//class MyException
//{
//public:
//	MyException(int errid, const char* errmsg)
//		:_errid(errid)
//		, _errmsg(errmsg)
//	{}
//	int GetErrid() const
//	{
//		return _errid;
//	}
//	virtual string what() const
//	{
//		return _errmsg;
//	}
//	//private:
//protected:
//	int _errid;
//	string _errmsg;
//	//...
//};
//class CacheException : public MyException
//{
//public:
//	CacheException(int errid, const char* errmsg)
//		:MyException(errid, errmsg)
//	{}
//	virtual string what() const
//	{
//		string msg = "CacheException: ";
//		msg += _errmsg;
//		return msg;
//	}
//protected:
//	//...
//};
//class SqlException : public MyException
//{
//public:
//	SqlException(int errid, const char* errmsg, const char* sql)
//		:MyException(errid, errmsg)
//		, _sql(sql)
//	{}
//	virtual string what() const
//	{
//		string msg = "CacheException: ";
//		msg += _errmsg;
//		msg += "sql���: ";
//		msg += _sql;
//		return msg;
//	}
//protected:
//	//...
//	string _sql;
//};
//class NetworkException : public MyException
//{
//public:
//	NetworkException(int errid, const char* errmsg)
//		:MyException(errid, errmsg)
//	{}
//protected:
//	//...
//};
//void f1()
//{
//	int i = 0;
//	cin >> i;
//	if (i == 0)
//	{
//		throw CacheException(1, "���ݲ�����");
//	}
//}
//void f2()
//{
//	throw SqlException(2, "���ݿ��ѯʧ��", "select * from t_student");
//}
//int main()
//{
//	try
//	{
//		f1();
//		f2();
//	}
//	catch (const MyException& e)
//	{
//		cout << "������: " << e.GetErrid() << endl;
//		cout << "��������: " << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "δ֪�쳣" << endl;
//	}
//	return 0;
//}


//#include <iostream>
//using namespace std;
//double Division(int a, int b)
//{
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//void Func()
//{
//	int* array = new int[10];
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (...)
//	{
//		cout << "delete []" << array << endl;
//		delete[] array;
//		throw; //�����񵽵��쳣�ٴ������׳�
//	}
//	//...
//	cout << "delete []" << array << endl;
//	delete[] array;
//}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//void func1()
//{
//	throw string("����һ���쳣");
//}
//void func2()
//{
//	func1();
//}
//void func3()
//{
//	func2();
//}
//int main()
//{
//	try
//	{
//		func3();
//	}
//	catch (const string& s)
//	{
//		cout << "����������" << s << endl;
//	}
//	catch (...)
//	{
//		cout << "δ֪�쳣" << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//void func1()
//{
//	throw string("����һ���쳣");
//}
//void func2()
//{
//	int* array = new int[10];
//	try
//	{
//		func1();
//		//do something...
//	}
//	catch (...)
//	{
//		delete[] array;
//		throw; //�����񵽵��쳣�ٴ������׳�
//	}
//	delete[] array;
//}
////void func2()
////{
////	int* array = new int[10];
////	func1();
////
////	//do something...
////
////	delete[] array;
////}
//int main()
//{
//	try
//	{
//		func2();
//	}
//	catch (const string& s)
//	{
//		cout << s << endl;
//	}
//	catch (...)
//	{
//		cout << "δ֪�쳣" << endl;
//	}
//	return 0;
//}


#include <iostream>
#include <string>
using namespace std;
class Exception
{
public:
	Exception(int errid, const char* errmsg)
		:_errid(errid)
		, _errmsg(errmsg)
	{}
	int GetErrid() const
	{
		return _errid;
	}
	virtual string what() const
	{
		return _errmsg;
	}
	//private:
protected:
	int _errid;     //������
	string _errmsg; //��������
	//...
};
class CacheException : public Exception
{
public:
	CacheException(int errid, const char* errmsg)
		:Exception(errid, errmsg)
	{}
	virtual string what() const
	{
		string msg = "CacheException: ";
		msg += _errmsg;
		return msg;
	}
protected:
	//...
};
class SqlException : public Exception
{
public:
	SqlException(int errid, const char* errmsg, const char* sql)
		:Exception(errid, errmsg)
		, _sql(sql)
	{}
	virtual string what() const
	{
		string msg = "CacheException: ";
		msg += _errmsg;
		msg += "sql���: ";
		msg += _sql;
		return msg;
	}
protected:
	//...
	string _sql; //�����쳣��SQL���
};
class NetworkException : public Exception
{
public:
	NetworkException(int errid, const char* errmsg)
		:Exception(errid, errmsg)
	{}
protected:
	//...
};
void f1()
{
	int i = 0;
	cin >> i;
	if (i == 0)
	{
		throw CacheException(1, "���ݲ�����");
	}
}
void f2()
{
	throw SqlException(2, "���ݿ��ѯʧ��", "select * from t_student");
}
int main()
{
	try
	{
		f1();
		f2();
	}
	catch (const Exception& e)
	{
		cout << "������: " << e.GetErrid() << endl;
		cout << "��������: " << e.what() << endl;
	}
	catch (...)
	{
		cout << "δ֪�쳣" << endl;
	}
	return 0;
}
