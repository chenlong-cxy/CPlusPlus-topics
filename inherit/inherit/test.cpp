//#include <iostream>
//#include <string>
//using namespace std;
////父类
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "张三"; //姓名
//	int _age = 18;     //年龄
//};
////子类
//class Student : public Person
//{
//protected:
//	int _stuid;   //学号
//};
////子类
//class Teacher : public Person
//{
//protected:
//	int _jobid;   //工号
//};
//int main()
//{
//	Student s;
//	Teacher t;
//	s.Print();
//	t.Print();
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
////基类
//class Person
//{
//private:
//	string _name = "张三"; //姓名
//};
////派生类
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl; //在派生类当中访问基类的private成员，error!
//	}
//protected:
//	int _stuid;   //学号
//};
//int main()
//{
//	Student s;
//	s.Print();
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
////基类
//class Person
//{
//public:
//	string _name = "张三"; //姓名
//};
////派生类
//class Student : Person
//{
//protected:
//	int _stuid;   //学号
//};
//int main()
//{
//	Student s;
//	cout << s._name << endl;
//	s.Print();
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
////基类
//class Person
//{
//protected:
//	string _name; //姓名
//	string _sex;  //性别
//	int _age;     //年龄
//};
////派生类
//class Student : public Person
//{
//protected:
//	int _stuid;   //学号
//};
//int main()
//{
//	Student s;
//	Person p = s;     //派生类对象赋值给基类对象
//	Person* ptr = &s; //派生类对象赋值给基类指针
//	Person& ref = s;  //派生类对象赋值给基类引用
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
////父类
//class Person
//{
//protected:
//	int _num = 111;
//};
////子类
//class Student : public Person
//{
//public:
//	void fun()
//	{
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999;
//};
//int main()
//{
//	Student s;
//	s.fun(); //999
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
////父类
//class Person
//{
//public:
//	void fun(int x)
//	{
//		cout << x << endl;
//	}
//};
////子类
//class Student : public Person
//{
//public:
//	void fun(double x)
//	{
//		cout << x << endl;
//	}
//};
//int main()
//{
//	Student s;
//	s.fun(3.14);       //直接调用子类当中的成员函数fun
//	s.Person::fun(20); //指定调用父类当中的成员函数fun
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;
//基类
class Person
{
public:
	//构造函数
	Person(const string& name = "peter")
		:_name(name)
	{
		cout << "Person()" << endl;
	}
	//拷贝构造函数
	Person(const Person& p)
		:_name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}
	//赋值运算符重载函数
	Person& operator=(const Person& p)
	{
		cout << "Person& operator=(const Person& p)" << endl;
		if (this != &p)
		{
			_name = p._name;
		}
		return *this;
	}
	//析构函数
	~Person()
	{
		cout << "~Person()" << endl;
	}
private:
	string _name; //姓名
};
//派生类
class Student : public Person
{
public:
	//构造函数
	Student(const string& name, int id)
		:Person(name) //调用基类的构造函数初始化基类的那一部分成员
		, _id(id) //初始化派生类的成员
	{
		cout << "Student()" << endl;
	}
	//拷贝构造函数
	Student(const Student& s)
		:Person(s) //调用基类的拷贝构造函数完成基类成员的拷贝构造
		, _id(s._id) //拷贝构造派生类的成员
	{
		cout << "Student(const Student& s)" << endl;
	}
	//赋值运算符重载函数
	Student& operator=(const Student& s)
	{
		cout << "Student& operator=(const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator=(s); //调用基类的operator=完成基类成员的赋值
			_id = s._id; //完成派生类成员的赋值
		}
		return *this;
	}
	//析构函数
	~Student()
	{
		cout << "~Student()" << endl;
		//派生类的析构函数会在被调用完成后自动调用基类的析构函数
	}
private:
	int _id; //学号
};
int main()
{
	Student s1("dragon", 20);
	Student s2(s1);
	Student s3("wjx", 19);
	s1 = s3;
	return 0;
}