//#include <iostream>
//#include <string>
//using namespace std;
////����
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "����"; //����
//	int _age = 18;     //����
//};
////����
//class Student : public Person
//{
//protected:
//	int _stuid;   //ѧ��
//};
////����
//class Teacher : public Person
//{
//protected:
//	int _jobid;   //����
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
////����
//class Person
//{
//private:
//	string _name = "����"; //����
//};
////������
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl; //�������൱�з��ʻ����private��Ա��error!
//	}
//protected:
//	int _stuid;   //ѧ��
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
////����
//class Person
//{
//public:
//	string _name = "����"; //����
//};
////������
//class Student : Person
//{
//protected:
//	int _stuid;   //ѧ��
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
////����
//class Person
//{
//protected:
//	string _name; //����
//	string _sex;  //�Ա�
//	int _age;     //����
//};
////������
//class Student : public Person
//{
//protected:
//	int _stuid;   //ѧ��
//};
//int main()
//{
//	Student s;
//	Person p = s;     //���������ֵ���������
//	Person* ptr = &s; //���������ֵ������ָ��
//	Person& ref = s;  //���������ֵ����������
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
////����
//class Person
//{
//protected:
//	int _num = 111;
//};
////����
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
////����
//class Person
//{
//public:
//	void fun(int x)
//	{
//		cout << x << endl;
//	}
//};
////����
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
//	s.fun(3.14);       //ֱ�ӵ������൱�еĳ�Ա����fun
//	s.Person::fun(20); //ָ�����ø��൱�еĳ�Ա����fun
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
////����
//class Person
//{
//public:
//	//���캯��
//	Person(const string& name = "peter")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	//�������캯��
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	//��ֵ��������غ���
//	Person& operator=(const Person& p)
//	{
//		cout << "Person& operator=(const Person& p)" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//	//��������
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//private:
//	string _name; //����
//};
////������
//class Student : public Person
//{
//public:
//	//���캯��
//	Student(const string& name, int id)
//		:Person(name) //���û���Ĺ��캯����ʼ���������һ���ֳ�Ա
//		, _id(id) //��ʼ��������ĳ�Ա
//	{
//		cout << "Student()" << endl;
//	}
//	//�������캯��
//	Student(const Student& s)
//		:Person(s) //���û���Ŀ������캯����ɻ����Ա�Ŀ�������
//		, _id(s._id) //��������������ĳ�Ա
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	//��ֵ��������غ���
//	Student& operator=(const Student& s)
//	{
//		cout << "Student& operator=(const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s); //���û����operator=��ɻ����Ա�ĸ�ֵ
//			_id = s._id; //����������Ա�ĸ�ֵ
//		}
//		return *this;
//	}
//	//��������
//	~Student()
//	{
//		cout << "~Student()" << endl;
//		//������������������ڱ�������ɺ��Զ����û������������
//	}
//private:
//	int _id; //ѧ��
//};
//int main()
//{
//	Student s1("dragon", 20);
//	Student s2(s1);
//	Student s3("wjx", 19);
//	s1 = s3;
//	return 0;
//}

////���ܱ��̳е���
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
//	//����Display��Person����Ԫ
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; //����
//};
//class Student : public Person
//{
//public:
//	//����Display��Student����Ԫ
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _id; //ѧ��
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl; //���Է���
//	cout << s._id << endl; //�޷�����
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
////����
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
//	string _name; //����
//public:
//	static int _count; //ͳ���˵ĸ�����
//};
//int Person::_count = 0; //��̬��Ա������������г�ʼ��
////������
//class Student : public Person
//{
//protected:
//	int _stuNum; //ѧ��
//};
////������
//class Graduate : public Person
//{
//protected:
//	string _seminarCourse; //�о���Ŀ
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
//	string _name; //����
//};
//class Student : public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : public Person
//{
//protected:
//	int _id; //ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; //���޿γ�
//};
//int main()
//{
//	Assistant a;
//	a._name = "peter"; //�����ԣ��޷���ȷ֪��Ҫ������һ��_name
//	//��ʾָ�������ĸ�����ĳ�Ա
//	a.Student::_name = "��ͬѧ";
//	a.Teacher::_name = "����ʦ";
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	string _name; //����
//};
//class Student : virtual public Person //����̳�
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : virtual public Person //����̳�
//{
//protected:
//	int _id; //ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; //���޿γ�
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
//	string _colour; //��ɫ
//	string _num; //���ƺ�
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
	string _brand; //Ʒ��
	size_t _size; //�ߴ�
};
class Car
{
protected:
	string _colour; //��ɫ
	string _num; //���ƺ�
	Tire _t; //��̥
};