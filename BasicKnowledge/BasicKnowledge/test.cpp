//#include <iostream>
//using namespace std;
//int main()
//{
//	cout << "hello world" << endl;
//	return 0;
//}

//#include <iostream>
//int main()
//{
//	std::cout << "hello world" << std::endl;
//	return 0;
//}

//#include <iostream>
//int main()
//{
//	std::cout << "hello world" << std::endl;
//	return 0;
//}

//#include <stdio.h>
//namespace N1
//{
//	int printf;
//	namespace N2
//	{
//		int a;
//	}
//}
//int main()
//{
//	N1::printf = 10;
//	printf("%d\n", N1::printf);
//	N1::N2::a = 10;
//	return 0;
//}

//#include <iostream>
////�����ռ����ͨ����
//namespace N1 //N1Ϊ�����ռ������
//{
//	//�������ռ��У��ȿ��Զ��������Ҳ���Զ��庯��
//	int a;
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//}


////�����ռ��Ƕ�׶���
//namespace N1 //����һ����ΪN1�������ռ�
//{
//	int a;
//	int b;
//	namespace N2 //Ƕ�׶�����һ����ΪN2�������ռ�
//	{
//		int c;
//		int d;
//	}
//}
//int main()
//{
//	N1::a = 20;
//	N1::N2::a = 10;
//	std::cout << N1::a << std::endl << N1::N2::a << std::endl;
//	return 0;
//}

//�����ռ��ʹ��
//�������ռ����Ƽ��������޶���
//#include <stdio.h>
//namespace N
//{
//	int a;
//	double b;
//}
//int main()
//{
//	N::a = 10;//�������ռ��еĳ�Աa��ֵΪ10
//	printf("%d\n", N::a);//��ӡ�����ռ��еĳ�Աa
//	return 0;
//}

//ʹ��using�������ռ��еĳ�Ա����
//#include <stdio.h>
//namespace N
//{
//	int a;
//	double b;
//}
//using N::a;//�������ռ��еĳ�Աa����
//int main()
//{
//	a = 10;//�������ռ��еĳ�Աa��ֵΪ10
//	printf("%d\n", a);//��ӡ�����ռ��еĳ�Աa
//	return 0;
//}

////ʹ��using namespace �����ռ���������
//#include <stdio.h>
//namespace N
//{
//	int a;
//	double b;
//}
//using namespace N;//�������ռ�N�����г�Ա����
//int main()
//{
//	a = 10;//�������ռ��еĳ�Աa��ֵΪ10
//	printf("%d\n", a);//��ӡ�����ռ��еĳ�Աa
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	cout << "hello world!" << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int i = 10;
//	double d = 3.14;
//	char arr[] = "�ǲ��Ǻܷ��㣿";
//	cout << i << endl;//��ӡ����i
//	cout << d << endl;//��ӡ������d
//	cout << arr << endl;//��ӡ�ַ���arr
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int i;
//	double d;
//	char arr[20];
//	cin >> i;//��ȡһ������
//	cin >> d;//��ȡһ��������
//	cin >> arr;//��ȡһ���ַ���
//	cout << i << endl;//��ӡ����i
//	cout << d << endl;//��ӡ������d
//	cout << arr << endl;//��ӡ�ַ���arr
//	return 0;
//}

//#include <iostream>
//using namespace std;
//void Print(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Print();//û��ָ��ʵ�Σ�ʹ�ò�����Ĭ��ֵ����ӡ0��
//	Print(10);//ָ����ʵ�Σ�ʹ��ָ����ʵ�Σ���ӡ10��
//	return 0;
//}

//#include <iostream>
//using namespace std;
//void Print(int a = 10, int b = 20, int c = 30)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//int main()
//{
//	Print();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int x = 20;
//void Print(int a, int b, int c = x)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//int main()
//{
//	x = 20;
//	Print(10, 20);
//	x = 10;
//	Print(10, 20);
//	return 0;
//}

////test.h
//#include "test.h"
//#include <iostream>
//using namespace std;
////test.c
//void Print(int a, int b, int c = 30)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//int main()
//{
//	Print(10, 20);
//	return 0;
//}

//int x = 30;//ȫ�ֱ���
//void Print(int a, int b, int c = x)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}


//#include <iostream>
//using namespace std;
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//double Add(double x, double y)
//{
//	return x + y;
//}
//
//int main()
//{
//	cout << Add(1, 2) << endl;//��ӡ1+2�Ľ��
//	cout << Add(1.1, 2.2) << endl;//��ӡ1.1+2.2�Ľ��
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int& b = a;//������aȥ��һ����������b
//	cout << "a = " << a << endl;//a��ӡ���Ϊ10
//	cout << "b = " << b << endl;//b��ӡ���Ҳ��10
//	b = 20;//�ı�bҲ���Ǹı���a
//	cout << "a = " << a << endl;//a��ӡ���Ϊ20
//	cout << "b = " << b << endl;//b��ӡ���Ҳ��Ϊ20
//	return 0;
//}

//int a = 10;
//int& b = a;//�����ڶ���ʱ�����ʼ��
//
//int& b;
//b = a;

//int a = 10;
//int& b = a;
//int& c = a;
//int& d = a;

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int& b = a;
//	int c = 20;
//	b = c;
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	const int a = 10;
//	//int& ra = a;    //��������ʱ�����aΪ����
//	const int& ra = a;
//	//int& b = 10;    //��������ʱ�����10Ϊ����
//	const int& b = 10;
//	return 0;
//}

////��������
//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int b = 20;
//	cout << "a = " << a << " " << "b = " << b << endl;
//	Swap(a, b);
//	cout << "a = " << a << " " << "b = " << b << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int& Add(int a, int b)
//{
//	static int c = a + b;
//	return c;
//}
//int main()
//{
//	int& a = Add(1, 2);
//	cout << a << endl;
//	Add(10, 20);
//	cout << a << endl;
//	return 0;
//}


//#include <time.h>
//#include <iostream>
//using namespace std;
//struct A{ int a[10000]; };
//void TestFunc1(A a){}
//void TestFunc2(A& a){}
//void TestRefAndValue()
//{
//	A a;
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//int main()
//{
//	TestRefAndValue();
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	//���﷨�ϣ������a���ռ�ȡ��һ��������û���¿��ռ�
//	int& ra = a;
//	ra = 20;
//
//	//���﷨�ϣ����ﶨ����һ��paָ�룬������4���ֽڣ�32λ�������Ŀռ䣬���ڴ洢a�ĵ�ַ
//	int* pa = &a;
//	*pa = 20;
//	return 0;
//}


//int Add(int a, int b)
//{
//	return a + b;
//}
//int main()
//{
//	int ret = Add(1, 2);
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//double Fun()
//{
//	return 3.14;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'A';
//	auto d = Fun();
//	//��ӡ����b,c,d������
//	cout << typeid(b).name() << endl;//��ӡint
//	cout << typeid(c).name() << endl;//��ӡchar
//	cout << typeid(d).name() << endl;//��ӡdouble
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	auto b = &a;   //�Զ��Ƶ���b������Ϊint*
//	auto* c = &a;  //�Զ��Ƶ���c������Ϊint*
//	auto d = a;    //�Զ��Ƶ���d������Ϊint
//	auto& e = a;   //�Զ��Ƶ���e������Ϊint
//	//��ӡ����b,c,d������
//	cout << typeid(b).name() << endl;//��ӡ���Ϊint*
//	cout << typeid(c).name() << endl;//��ӡ���Ϊint*
//	cout << typeid(d).name() << endl;//��ӡ���Ϊint
//	cout << typeid(e).name() << endl;//��ӡ���Ϊint
//	return 0;
//}


//int main()
//{
//	auto a = 1, b = 2; //��ȷ
//	auto c = 3, d = 4.0; //������������auto������ʼ���Ƶ�Ϊͬһ����
//	return 0;
//}


//void TestAuto(auto x)
//{}


//int main()
//{
//	int a[] = { 1, 2, 3 };
//	auto b[] = { 4, 5, 6 };//error
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//������Ԫ��ֵȫ������2
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		arr[i] *= 2;
//	}
//	//��ӡ�����е�����Ԫ��
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	//������Ԫ��ֵȫ������2
//	for (auto& e : arr)
//	{
//		e *= 2;
//	}
//	//��ӡ�����е�����Ԫ��
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//#include <stdio.h>
//NULL
//#define NULL    ((void *)0)

//#include <iostream>
//NULL
//#define NULL    0
//nullptr
//#include <stddef.h>
//int* p1 = NULL;
//int* p2 = 0;

//#include <iostream>
//using namespace std;
//void Fun(int p)
//{
//	cout << "Fun(int)" << endl;
//}
//void Fun(int* p)
//{
//	cout << "Fun(int*)" << endl;
//}
//int main()
//{
//	Fun(0);           //��ӡ���Ϊ Fun(int)
//	Fun(NULL);        //��ӡ���Ϊ Fun(int)
//	Fun((int*)NULL);  //��ӡ���Ϊ Fun(int*)
//	Fun(nullptr);
//	return 0;
//}

#include <iostream>
using namespace std;
void Fun(int a, double b)
{
	cout << "a" << endl;
}
void Fun(double a, int b)
{
	cout << "b" << endl;
}
int main()
{
	Fun(1, 1.1);
	Fun(1.1, 1);
	return 0;
}