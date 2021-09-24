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

#include <iostream>
#include <string>
using namespace std;
//基类
class Person
{
protected:
	string _name; //姓名
	string _sex;  //性别
	int _age;     //年龄
};
//派生类
class Student : public Person
{
protected:
	int _stuid;   //学号
};
int main()
{
	Student s;
	Person p = s;     //派生类对象赋值给基类对象
	Person* ptr = &s; //派生类对象赋值给基类指针
	Person& ref = s;  //派生类对象赋值给基类引用
	return 0;
}