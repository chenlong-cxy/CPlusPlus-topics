//#include <stdlib.h>
//
//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof (int)* 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
//	free(ptr1);
//	free(ptr3);
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	//ջ�����ٿռ䣬�ȿ��ٵĿռ��ַ��
//	int a = 10;
//	int b = 20;
//	cout << &a << endl;
//	cout << &b << endl;
//
//	//�������ٿռ䣬�ȿ��ٵĿռ��ַ��
//	int* c = (int*)malloc(sizeof(int)* 10);
//	int* d = (int*)malloc(sizeof(int)* 10);
//	cout << c << endl;
//	cout << d << endl;
//	return 0;
//}


//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//int main()
//{
//	//��̬����10��int���͵Ŀռ�
//	int* p1 = (int*)malloc(sizeof(int)* 10);
//	int* p2 = new int[10];
//	cout << p2 << endl;
//	free(p1);
//	delete[] p2;
//	cout << p2 << endl;
//	//��̬���뵥��int���͵Ŀռ�
//	int* p3 = (int*)malloc(sizeof(int));
//	int* p4 = new int;
//
//	free(p3);
//	delete p4;
//	
//	//��̬���뵥��int���͵Ŀռ䲢��ʼ��Ϊ10
//	int* p5 = (int*)malloc(sizeof(int));
//	*p5 = 10;
//	int* p6 = new int(10);
//
//	free(p5);
//	delete p6;
//
//	//��̬����10��int���͵Ŀռ䲢��ʼ��Ϊ0��9
//	int* p7 = (int*)malloc(sizeof(int)* 10);
//	for (int i = 0; i < 10; i++)
//	{
//		p7[i] = i;
//	}
//	int* p8 = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//
//	free(p7);
//	delete[] p8;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Test
//{
//public:
//	Test() //���캯��
//		:_a(0)
//	{
//		cout << "���캯��" << endl;
//	}
//	~Test() //��������
//	{
//		cout << "��������" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	Test* p1 = new Test;
//	delete p1;
//
//	Test* p2 = (Test*)malloc(sizeof(Test));
//	free(p2);
//
//	Test* p3 = new Test[10];
//	delete[] p3;
//
//	Test* p4 = (Test*)malloc(sizeof(Test)* 10);
//	free(p4);
//	return 0;
//}


#include <iostream>

//using namespace std;
//int main()
//{
//	void* p1 = malloc(0xffffffff);
//	if (p1 == NULL)
//	{
//		cout << "error" << endl;
//	}
//	free(p1);
//
//	//int* p2 = (int*)operator new(0xffffffff);
//	//operator delete(p2);
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	int* p = new int;
//	cout << p << endl;
//	delete p;
//	cout << p << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	int* p1 = (int*)operator new(sizeof(int)* 10);
//	operator delete(p1);
//
//	int* p2 = (int*)operator new(sizeof(int)* 10);
//	free(p2);
//	return 0;
//}



//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//void Test()
//{
//	int* p1 = (int*)malloc(INT_MAX);
//	if (p1 == NULL)
//	{
//		cout << "malloc fail" << endl;
//	}
//	free(p1);
//
//	int* p2 = (int*)operator new(INT_MAX);
//	delete p2;
//}
//int main()
//{
//	try
//	{
//		Test();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a = 0) //���캯�� 
//		:_a(a)
//	{}
//
//	~A() //��������
//	{}
//private:
//	int _a;
//};
//int main()
//{
//	//new(place_address)type ��ʽ
//	A* p1 = (A*)malloc(sizeof(A));
//	new(p1)A;
//
//	//new(place_address)type(initializer-list) ��ʽ
//	A* p2 = (A*)malloc(sizeof(A));
//	new(p2)A(2021);
//
//	//��������Ҳ������ʾ����
//	p1->~A();
//	p2->~A();
//	return 0;
//}


//void MemoryLeaks()
//{
//	// 1.�ڴ������������ͷ�
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//
//	// 2.�쳣��ȫ����
//	int* p3 = new int[10];
//	Func(); // ����Func�������쳣���� delete[] p3δִ�У�p3û���ͷ�.
//	delete[] p3;
//}


#include <iostream>
using namespace std;
int main()
{
	//0xffffffffulת��Ϊʮ���ƾ���4G
	void* p = malloc(0xffffffffful);
	cout << p << endl;

	return 0;
}