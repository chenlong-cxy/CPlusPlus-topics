//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = -19;
//	cout << a % 2 << endl;
//	return 0;
//}

//两个线程打印1-100（不控制顺序）
//#include <iostream>
//#include <thread>
//using namespace std;
//int main()
//{
//	size_t n = 100;
//	thread t1([n]{
//		for (size_t i = 0; i < n; i += 2)
//		{
//			cout << i << endl;
//		}
//	});
//	thread t2([n]{
//		for (size_t i = 1; i < n; i += 2)
//		{
//			cout << i << endl;
//		}
//	});
//	t1.join();
//	t2.join();
//	return 0;
//}


//在有执行体之前没有id
//#include <iostream>
//#include <thread>
//#include <vector>
//using namespace std;
//void func(int num)
//{
//	for (int i = 0; i <= num; i++)
//	{
//		//cout << i << endl;
//	}
//}
//int main()
//{
//	thread t1;
//	cout << t1.get_id() << endl;
//	t1 = thread(func, 100);
//	cout << t1.get_id() << endl;
//	t1.join();
//	return 0;
//}


////线程池（未加锁）
//#include <iostream>
//#include <thread>
//#include <vector>
//using namespace std;
//void func(int num)
//{
//	for (int i = 0; i <= num; i++)
//	{
//		cout << this_thread::get_id() << ":" << i << endl;
//	}
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<thread> vthreads;
//	vthreads.resize(n);
//	for (auto& td : vthreads)
//	{
//		td = thread(func, 100);
//		//cout << td.get_id() << endl;
//	}
//	for (auto& td : vthreads)
//	{
//		td.join();
//	}
//	return 0;
//}


////线程池（加锁）
//#include <iostream>
//#include <thread>
//#include <vector>
//#include <mutex>
//using namespace std;
//
//mutex mtx;
//
//void func(int num)
//{
//	mtx.lock();
//	for (int i = 0; i <= num; i++)
//	{
//		cout << this_thread::get_id() << ":" << i << endl;
//	}
//	mtx.unlock();
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<thread> vthreads;
//	vthreads.resize(n);
//	for (auto& td : vthreads)
//	{
//		td = thread(func, 100);
//	}
//	for (auto& td : vthreads)
//	{
//		td.join();
//	}
//	return 0;
//}


////线程池（lambda表达式）
//#include <iostream>
//#include <thread>
//#include <vector>
//#include <mutex>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<thread> vthreads;
//	vthreads.resize(n);
//	mutex mtx;
//	int x = 0;
//	int num = 100; //100000;
//	for (auto& td : vthreads)
//	{
//		td = thread([&mtx, &num, &x]
//		{
//			mtx.lock();
//			for (int i = 0; i < num; i++)
//			{
//				x++;
//			}
//			mtx.unlock();
//		});
//	}
//	for (auto& td : vthreads)
//	{
//		td.join();
//	}
//	printf("%d个线程并行对x++了%d次, x:%d\n", n, num, x);
//	return 0;
//}


////++汇编
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int x = 0;
//	x++;
//	return 0;
//}


////休眠
//#include <iostream>
//#include <thread>
//#include <vector>
//#include <mutex>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<thread> vthreads;
//	vthreads.resize(n);
//	mutex mtx;
//	int x = 0;
//	int num = 100; //100000;
//	for (auto& td : vthreads)
//	{
//		td = thread([&mtx, &num, &x]
//		{
//			for (int i = 0; i < num; i++)
//			{
//				mtx.lock();
//				x++;
//				cout << this_thread::get_id() << ":" << x << endl;
//				this_thread::sleep_for(chrono::milliseconds(500));
//				mtx.unlock();
//			}
//		});
//	}
//	for (auto& td : vthreads)
//	{
//		td.join();
//	}
//	printf("%d个线程并行对x++了%d次, x:%d\n", n, num, x);
//	return 0;
//}


////原子操作
//#include <iostream>
//#include <thread>
//#include <vector>
//#include <mutex>
//#include <atomic>
//#include <cintypes>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<thread> vthreads;
//	vthreads.resize(n);
//	mutex mtx;
//	//int x = 0;
//	//atomic<int> x{ 0 };
//	//atomic<int> x(0);
//	atomic_int x = { 0 };
//	int num = 1000000;
//	for (auto& td : vthreads)
//	{
//		td = thread([&mtx, &num, &x]
//		{
//			for (int i = 0; i < num; i++)
//			{
//				x++;
//			}
//		});
//	}
//	for (auto& td : vthreads)
//	{
//		td.join();
//	}
//	printf("%d个线程并行对x++了%d次, x:%d\n", n, num, x);
//	return 0;
//}


//#include <iostream>
//#include <mutex>
//using namespace std;
//namespace cl
//{
//	template<class Mutex>
//	class lock_guard
//	{
//	public:
//		lock_guard(Mutex& mtx)
//			:_mtx(mtx)
//		{
//			mtx.lock();
//			cout << "加锁" << endl;
//		}
//		~lock_guard()
//		{
//			mtx.unlock();
//			cout << "解锁" << endl;
//		}
//		lock_guard(const lock_guard&) = delete;
//	private:
//		Mutex& _mtx;
//	};
//	template<class Mutex>
//	class unique_lock
//	{
//	public:
//		unique_lock(Mutex& mtx)
//			:_mtx(mtx)
//		{
//			mtx.lock();
//			cout << "加锁" << endl;
//		}
//		void lock()
//		{
//			mtx.lock();
//		}
//		void unlock()
//		{
//			mtx.unlock();
//		}
//		~unique_lock()
//		{
//			mtx.unlock();
//			cout << "解锁" << endl;
//		}
//		unique_lock(const unique_lock&) = delete;
//	private:
//		Mutex& _mtx;
//	};
//}
//mutex mtx;
//void func()
//{
//	//cl::lock_guard<mutex> lg(mtx);
//	//mtx.lock();
//	//...
//	{
//		cl::lock_guard<mutex> lg(mtx);
//		FILE* fout = fopen("data.txt", "r");
//		if (fout == nullptr)
//		{
//			//
//			return;
//		}
//	}
//
//	int n = 0;
//	cin >> n;
//	char* p = new char[n]; //抛异常
//	//...
//	//mtx.unlock();
//}
//int main()
//{
//	try{
//		func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//bool trans_to_camel(char* str)
//{
//	string s(str);
//	size_t start = 0;
//	size_t end = s.find('_', start);
//	string ret;
//	while (end != string::npos)
//	{
//		string sub = s.substr(start, end - start);
//		sub[0] -= 32;
//		ret += sub;
//		while (s[end] == '_')
//			end++;
//		start = end;
//		end = s.find('_', start);
//	}
//	string sub = s.substr(start, end - start);
//	sub[0] -= 32;
//	ret += sub;
//	ret[0] += 32;
//	for (char e : ret)
//	{
//		*str++ = e;
//	}
//	*str = '\0';
//	return true;
//}
//int main()
//{
//	char str[] = "trans__to_camel___xxxx";
//	trans_to_camel(str);
//	cout << str << endl;
//	return 0;
//}


#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
int main()
{
	mutex mtx;
	condition_variable cv;
	int n = 0;
	bool flag = true;
	thread t1([&mtx, &cv, &flag, &n]
	{
		unique_lock<mutex> ul(mtx);
		while (n < 100)
		{
			cv.wait(ul, [&flag]{return flag; });
			cout << this_thread::get_id() << ":" << n << endl;
			n++;
			flag = false;
			cv.notify_one();
		}
	});
	thread t2([&mtx, &cv, &flag, &n]
	{
		unique_lock<mutex> ul(mtx);
		while (n < 100)
		{
			cv.wait(ul, [&flag]{return !flag; });
			cout << this_thread::get_id() << ":" << n << endl;
			n++;
			flag = true;
			cv.notify_one();
		}
	});
	t1.join();
	t2.join();
	return 0;
}