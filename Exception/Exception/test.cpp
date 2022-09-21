//try
//{
//	//保护的标识代码
//}
//catch (ExceptionName e1)
//{
//	//catch块
//}
//catch (ExceptionName e2)
//{
//	//catch块
//}
//catch (ExceptionName eN)
//{
//	//catch块
//}

////这里表示这个函数会抛出A/B/C/D中的某种类型的异常
//void func() throw(A, B, C, D);
////这里表示这个函数只会抛出bad_alloc的异常
//void* operator new(std::size_t size) throw(std::bad_alloc);
////这里表示这个函数不会抛出异常
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
//		cout << "错误码: " << errid << endl;
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
//		throw string("除零错误");
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
//		cout << "错误码: " << errid << endl;
//	}
//	catch (const string& s)
//	{
//		cout << "错误描述: " << s << endl;
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
//		throw string("除零错误");
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
//		throw string("malloc失败");
//	}
//}
//void f3()
//{
//	p3 = fopen("test.txt", "r");
//	if (p3 == nullptr)
//	{
//		throw string("fopen失败");
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
//		cout << "错误码: " << errid << endl;
//	}
//	catch (const string& s)
//	{
//		cout << "错误描述: " << s << endl;
//		if (s == "fopen失败")
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
//		cout << "错误码: " << e.GetErrid() << endl;
//		cout << "错误描述: " << e.what() << endl;
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
//		cout << "错误码: " << e.GetErrid() << endl;
//		cout << "错误描述: " << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
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
//		throw CacheException(1, "数据不存在");
//	}
//}
//void f2()
//{
//	throw SqlException(2, "数据库链接失败");
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
//		cout << "错误码: " << e.GetErrid() << endl;
//		cout << "错误描述: " << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
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
//		msg += "sql语句: ";
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
//		throw CacheException(1, "数据不存在");
//	}
//}
//void f2()
//{
//	throw SqlException(2, "数据库查询失败", "select * from t_student");
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
//		cout << "错误码: " << e.GetErrid() << endl;
//		cout << "错误描述: " << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
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
//		throw; //将捕获到的异常再次重新抛出
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
//	throw string("这是一个异常");
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
//		cout << "错误描述：" << s << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//void func1()
//{
//	throw string("这是一个异常");
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
//		throw; //将捕获到的异常再次重新抛出
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
//		cout << "未知异常" << endl;
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
	int _errid;     //错误编号
	string _errmsg; //错误描述
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
		msg += "sql语句: ";
		msg += _sql;
		return msg;
	}
protected:
	//...
	string _sql; //导致异常的SQL语句
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
		throw CacheException(1, "数据不存在");
	}
}
void f2()
{
	throw SqlException(2, "数据库查询失败", "select * from t_student");
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
		cout << "错误码: " << e.GetErrid() << endl;
		cout << "错误描述: " << e.what() << endl;
	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}
	return 0;
}
