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

//#include <iostream>
//#include <string>
//using namespace std;
////基类
//class Person
//{
//public:
//	//构造函数
//	Person(const string& name = "peter")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	//拷贝构造函数
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	//赋值运算符重载函数
//	Person& operator=(const Person& p)
//	{
//		cout << "Person& operator=(const Person& p)" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//	//析构函数
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//private:
//	string _name; //姓名
//};
////派生类
//class Student : public Person
//{
//public:
//	//构造函数
//	Student(const string& name, int id)
//		:Person(name) //调用基类的构造函数初始化基类的那一部分成员
//		, _id(id) //初始化派生类的成员
//	{
//		cout << "Student()" << endl;
//	}
//	//拷贝构造函数
//	Student(const Student& s)
//		:Person(s) //调用基类的拷贝构造函数完成基类成员的拷贝构造
//		, _id(s._id) //拷贝构造派生类的成员
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	//赋值运算符重载函数
//	Student& operator=(const Student& s)
//	{
//		cout << "Student& operator=(const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s); //调用基类的operator=完成基类成员的赋值
//			_id = s._id; //完成派生类成员的赋值
//		}
//		return *this;
//	}
//	//析构函数
//	~Student()
//	{
//		cout << "~Student()" << endl;
//		//派生类的析构函数会在被调用完成后自动调用基类的析构函数
//	}
//private:
//	int _id; //学号
//};
//int main()
//{
//	Student s1("dragon", 20);
//	Student s2(s1);
//	Student s3("wjx", 19);
//	s1 = s3;
//	return 0;
//}

////不能被继承的类
//#include <iostream>
//using namespace std;
//class A
//{
//private:
//	A()
//	{}
//};
////class B : public A
////{
////public:
////	B()
////	{
////
////	}
////};
//int main()
//{
//	A a;
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//class Student;
//class Person
//{
//public:
//	//声明Display是Person的友元
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; //姓名
//};
//class Student : public Person
//{
//public:
//	//声明Display是Student的友元
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _id; //学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl; //可以访问
//	cout << s._id << endl; //无法访问
//}
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
////基类
//class Person
//{
//public:
//	Person() 
//	{ 
//		_count++; 
//	}
//	Person(const Person& p) 
//	{
//		_count++;
//	}
//protected:
//	string _name; //姓名
//public:
//	static int _count; //统计人的个数。
//};
//int Person::_count = 0; //静态成员变量在类外进行初始化
////派生类
//class Student : public Person
//{
//protected:
//	int _stuNum; //学号
//};
////派生类
//class Graduate : public Person
//{
//protected:
//	string _seminarCourse; //研究科目
//};
//int main()
//{
//	Student s1;
//	Student s2(s1);
//	Student s3;
//	Graduate s4;
//	cout << &Person::_count << endl; //4
//	cout << &Student::_count << endl; //4
//	return 0;
//}

//class Person
//class Student : public Person
//class PostGraduate : public Student

//class Student
//class Teacher
//class Assistant : public Student, public Teacher

//class Person
//class Student : public Person
//class Teacher : public Person
//class Assistant : public Student, public Teacher

//




#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	string _name; //姓名
//};
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : public Person
//{
//protected:
//	int _id; //职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; //主修课程
//};
//int main()
//{
//	Assistant a;
//	a._name = "peter"; //二义性：无法明确知道要访问哪一个_name
//	//显示指定访问哪个父类的成员
//	a.Student::_name = "张同学";
//	a.Teacher::_name = "张老师";
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	string _name; //姓名
//};
//class Student : virtual public Person //虚拟继承
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person //虚拟继承
//{
//protected:
//	int _id; //职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; //主修课程
//};
//int main()
//{
//	Assistant a;
//	a._name = "peter";
//	cout << a.Student::_name << endl; //peter
//	cout << a.Teacher::_name << endl; //peter
//	cout << &a.Student::_name << endl; //0136F74C
//	cout << &a.Teacher::_name << endl; //0136F74C
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	int _a;
//};
//class B : public A
//{
//public:
//	int _b;
//};
//class C : public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	int _a;
//};
//class B : virtual public A
//{
//public:
//	int _b;
//};
//class C : virtual public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	B b = d;
//	return 0;
//}


//class Car
//{
//protected:
//	string _colour; //颜色
//	string _num; //车牌号
//};
//class BMW : public Car
//{
//public:
//	void Drive()
//	{
//		cout << "this is BMW" << endl;
//	}
//};


class Tire
{
protected:
	string _brand; //品牌
	size_t _size; //尺寸
};
class Car
{
protected:
	string _colour; //颜色
	string _num; //车牌号
	Tire _t; //轮胎
};