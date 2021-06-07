//#include <iostream>
//using namespace std;
//// ������������
//void Swapi(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//// ��������˫���ȸ�����
//void Swapd(double* p1, double* p2)
//{
//	double tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}

//// ������������
//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//// ��������˫���ȸ�����
//void Swap(double& x, double& y)
//{
//	double tmp = x;
//	x = y;
//	y = tmp;
//}


//template <class T1, class T2, ..., class Tn>
//template <typename T1,typename T2,...,typename Tn>


//#include <iostream>
//using namespace std;
//template <class T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	cout << "a:" << a << endl;
//	cout << "b:" << b << endl;
//	double x = 1.1;
//	double y = 2.2;
//	Swap(x, y);
//	cout << "x:" << x << endl;
//	cout << "y:" << y << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//template <typename T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	//int a = 10, b = 20;
//	//int c = Add(a, b);//����������ʵ��a��b���ݳ�ģ�����Ϊint����
//
//	int a = 10;
//	double b = 1.1;
//	int c = Add(a, b);
//	return 0;
//}


//#include <iostream>
//using namespace std;
//template <typename T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 10;
//	double b = 1.1;
//	int c = Add<int>(a, b);//ָ��ģ�������ʵ������Ϊint
//	return 0;
//}


//#include <iostream>
//using namespace std;
////ר������int���ͼӷ��ķ�ģ�庯��
//int Add(const int& x, const int& y)
//{
//	return x + y;
//}
////ͨ�����ͼӷ��ĺ���ģ��
//template <typename T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 10, b = 20;
//	int c = Add(a, b); //���÷�ģ�庯��������������Ҫʵ����
//	int d = Add<int>(a, b); //���ñ�����ʵ������Add����
//	return 0;
//}


//#include <iostream>
//using namespace std;
////ר������int���ͼӷ��ķ�ģ�庯��
//int Add(const int& x, const int& y)
//{
//	return x + y;
//}
////ͨ�����ͼӷ��ĺ���ģ��
//template <typename T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = Add(10, 20); //���ģ�庯����ȫƥ�䣬����Ҫ����ģ��ʵ����
//	int b = Add<int>(2, 2.2); //����ģ��������ɸ���ƥ��İ汾�������������ʵ�����ɸ���ƥ���Add����
//	return 0;
//}

//#include <iostream>
//using namespace std;
//template<typename T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = Add(2, 2.2); //ģ�庯���������Զ�����ת��������ͨ������
//	return 0;
//}


//template<class T1,class T2,...,class Tn>
//class ��ģ����
//{
//	//���ڳ�Ա����
//};

//#include <iostream>
//using namespace std;
//template<class T>
//class Score
//{
//public:
//	void Print()
//	{
//		cout << "��ѧ:" << _Math << endl;
//		cout << "����:" << _Chinese << endl;
//		cout << "Ӣ��:" << _English << endl;
//	}
//private:
//	T _Math;
//	T _Chinese;
//	T _English;
//};
//int main()
//{
//	Score<double> s1;
//	s1.Print();
//	return 0;
//}


#include <iostream>
using namespace std;
template<class T>
class Score
{
public:
	void Print();
private:
	T _Math;
	T _Chinese;
	T _English;
};
//��ģ���еĳ�Ա���������ⶨ�壬��Ҫ��ģ������б�
template<class T>
void Score<T>::Print()
{
	cout << "��ѧ:" << _Math << endl;
	cout << "����:" << _Chinese << endl;
	cout << "Ӣ��:" << _English << endl;
}
int main()
{
	//Score�����������࣬Score<int>��Score<double>������������
	Score<int> s1;
	Score<double> s2;
	s1.Print();
	return 0;
}