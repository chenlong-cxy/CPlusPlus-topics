//#include <iostream>
//using namespace std;
//int main()
//{
//	//���µ�p��b��c��*p������ֵ
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//
//	//���¼����Ƕ�������ֵ����ֵ����
//	int*& rp = p;
//	int& rb = b;
//	const int& rc = c;
//	int& pvalue = *p;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	double x = 1.1, y = 2.2;
//	
//	//���¼������ǳ�������ֵ
//	10;
//	x + y;
//	fmin(x, y);
//
//	//���¼������Ƕ���ֵ����ֵ����
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double rr3 = fmin(x, y);
//
//	//�������ᱨ��error C2106: ��=��: �����������Ϊ��ֵ����ֵ���ܳ����ڸ�ֵ���ŵ���ߣ�
//	//10 = 1;
//	//x + y = 1;
//	//fmin(x, y) = 1;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	double x = 1.1, y = 2.2;
//	int&& rr1 = 10;
//	cout << &rr1 << endl;
//	const double&& rr2 = x + y;
//
//	rr1 = 20;
//	cout << &rr1 << endl;
//	//rr2 = 5.5; //����
//	return 0;
//}


//#include <iostream>
//using namespace std;
//template<class T>
//void func(const T& x)
//{}
//int main()
//{
//	//��ֵ����ֻ��������ֵ������������ֵ
//	int a = 10;
//	int& ra1 = a; //ra1Ϊa�ı���
//	//int& ra2 = 10; //����ʧ�ܣ���Ϊ10����ֵ
//
//	//const��ֵ���üȿ���������ֵ��Ҳ��������ֵ
//	const int& ra3 = a;
//	const int& ra4 = 10;
//	return 0;
//}


#include <iostream>
using namespace std;
int main()
{
	//��ֵ����ֻ��������ֵ������������ֵ
	int&& r1 = 10;

	//error C2440: ����ʼ����: �޷��ӡ�int��ת��Ϊ��int &&��
	//message : �޷�����ֵ�󶨵���ֵ����
	int a = 10;
	int&& r2 = a;

	//��ֵ���ÿ�������move�Ժ����ֵ
	int&& r3 = std::move(a);
	return 0;
}