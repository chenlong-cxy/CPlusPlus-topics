#include <iostream>
#include <string>
using namespace std;

//template<class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(args) << endl; //获取参数包中参数的个数
//	for (int i = 0; i < sizeof...(args); i++)
//	{
//		cout << args[i] << " "; //打印参数包中的每个参数
//	}
//	cout << endl;
//}
//template<class T, class ...Args> //增加一个模板参数
//void ShowList(T value, Args... args)
//{
//	cout << value << " "; //打印传入的若干参数中的第一个参数
//	if (sizeof...(args) == 0)
//	{
//		return;
//	}
//	ShowList(args...);    //将剩下参数继续向下传
//}

//void ShowList() //0个参数的ShowList
//{
//	cout << endl;
//}
//template<class T, class ...Args> //增加一个模板参数
//void ShowList(T value, Args... args)
//{
//	cout << value << " "; //打印传入的若干参数中的第一个参数
//	ShowList(args...);    //将剩下参数继续向下传
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
//void ShowList(const T& t) //0个参数的ShowList
//{
//	cout << t << endl;
//}
//template<class T, class ...Args> //增加一个模板参数
//void ShowList(T value, Args... args)
//{
//	cout << value << " "; //打印传入的若干参数中的第一个参数
//	ShowList(args...);    //将剩下参数继续向下传
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