#include <iostream>
#include <string>
using namespace std;

//template<class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(args) << endl; //��ȡ�������в����ĸ���
//	for (int i = 0; i < sizeof...(args); i++)
//	{
//		cout << args[i] << " "; //��ӡ�������е�ÿ������
//	}
//	cout << endl;
//}
//template<class T, class ...Args> //����һ��ģ�����
//void ShowList(T value, Args... args)
//{
//	cout << value << " "; //��ӡ��������ɲ����еĵ�һ������
//	if (sizeof...(args) == 0)
//	{
//		return;
//	}
//	ShowList(args...);    //��ʣ�²����������´�
//}

//void ShowList() //0��������ShowList
//{
//	cout << endl;
//}
//template<class T, class ...Args> //����һ��ģ�����
//void ShowList(T value, Args... args)
//{
//	cout << value << " "; //��ӡ��������ɲ����еĵ�һ������
//	ShowList(args...);    //��ʣ�²����������´�
//}
//int main()
//{
//	ShowList();
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', string("hello"));
//	return 0;
//}

//template<class T>
//void ShowList(const T& t) //0��������ShowList
//{
//	cout << t << endl;
//}
//template<class T, class ...Args> //����һ��ģ�����
//void ShowList(T value, Args... args)
//{
//	cout << value << " "; //��ӡ��������ɲ����еĵ�һ������
//	ShowList(args...);    //��ʣ�²����������´�
//}
//int main()
//{
//	//ShowList();
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', string("hello"));
//	return 0;
//}






#include <iostream>
#include <string>
class Person
{
public:
	Person() = delete;
	~Person()
	{
		std::cout << "Yes" << std::endl;
	}
	std::string name;
	int age;
};
int main()
{
	Person p{ "zhangsan", 20 };
	std::cout << "OK" << std::endl;
	return 0;
}