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


#include <iostream>
#include <string>
using namespace std;
void f1()
{
	int i, j;
	cin >> i >> j;
	if (j == 0)
	{
		throw string("�������");
	}
	cout << i / j << endl;
}
int main()
{
	try
	{
		f1();
	}
	catch (int errid)
	{
		cout << "������: " << errid << endl;
	}
	catch (const string& s)
	{
		cout << "��������: " << s << endl;
	}
	return 0;
}