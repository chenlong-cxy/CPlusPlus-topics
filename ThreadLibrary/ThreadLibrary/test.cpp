//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = -19;
//	cout << a % 2 << endl;
//	return 0;
//}

//两个线程打印1-100（不控制顺序）
#include <iostream>
#include <thread>
using namespace std;
int main()
{
	size_t n = 100;
	thread t1([n]{
		for (size_t i = 0; i < n; i += 2)
		{
			cout << i << endl;
		}
	});
	thread t2([n]{
		for (size_t i = 1; i < n; i += 2)
		{
			cout << i << endl;
		}
	});
	t1.join();
	t2.join();
	return 0;
}