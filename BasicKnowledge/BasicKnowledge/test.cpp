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

#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	int& b = a;//������aȥ��һ����������b
	cout << "a = " << a << endl;//a��ӡ���Ϊ10
	cout << "b = " << b << endl;//b��ӡ���Ҳ��10
	b = 20;//�ı�bҲ���Ǹı���a
	cout << "a = " << a << endl;//a��ӡ���Ϊ20
	cout << "b = " << b << endl;//b��ӡ���Ҳ��Ϊ20
	return 0;
}