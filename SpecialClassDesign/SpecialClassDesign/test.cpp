//�����һ���ֻ࣬���ڶ��ϴ�������
//#include <iostream>
//using namespace std;
//class HeapOnly
//{
//public:
//	static HeapOnly* GetObj()
//	{
//		return new HeapOnly();
//	}
//private:
//	HeapOnly()
//	{}
//	HeapOnly(const HeapOnly& obj) = delete;
//};
//int main()
//{
//	HeapOnly* p = HeapOnly::GetObj();
//	//HeapOnly h(*p);
//	return 0;
//}

//�����һ���ֻ࣬����ջ�ϴ�������
//#include <iostream>
//using namespace std;
//class StackOnly
//{
//public:
//	static StackOnly GetObj()
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly()
//	{}
//	void* operator new(size_t size);
//	void operator delete(void* p);
//};
//int main()
//{
//	StackOnly obj = StackOnly::GetObj();
//	return 0;
//}

//�����һ���࣬���ܱ�����
//#include <iostream>
//using namespace std;
//class CopyBan
//{
//public:
//	CopyBan()
//	{}
//private:
//	CopyBan(const CopyBan&) = delete;
//	CopyBan& operator=(const CopyBan&) = delete;
//};
//int main()
//{
//	CopyBan obj1;
//	CopyBan obj2;
//	//obj1 = obj2;
//	return 0;
//}

//�����һ���࣬���ܱ��̳�
//#include <iostream>
//using namespace std;
//class NonInherit
//{
//public:
//private:
//	NonInherit()
//	{}
//};
//class A :public NonInherit
//{};
//int main()
//{
//	A a;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class NonInherit final
//{
//public:
//private:
//	NonInherit()
//	{}
//};
//class A :public NonInherit
//{};
//int main()
//{
//	return 0;
//}

//�����һ���ֻ࣬�ܴ���һ�����󣨵���ģʽ��
//#include <iostream>
//using namespace std;
////����ģʽ
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return &_Inst;
//	}
//	void Print()
//	{
//		cout << "OK" << endl;
//	}
//private:
//	Singleton()
//	{}
//	Singleton(const Singleton&) = delete;
//	static Singleton _Inst;
//};
//
////Singleton Singleton::_Inst = new Singleton();
//Singleton Singleton::_Inst;
//int main()
//{
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	Singleton::GetInstance()->Print();
//	//Singleton s(*Singleton::GetInstance());
//	//s.Print();
//	return 0;
//}

//#include <iostream>
//#include <mutex>
//using namespace std;
////����ģʽ
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		if (_Inst == nullptr)
//		{
//			_mtx.lock();
//			if (_Inst == nullptr)
//			{
//				_Inst = new Singleton();
//			}
//			_mtx.unlock();
//		}
//		return _Inst;
//	}
//	void Print()
//	{
//		cout << "OK" << endl;
//	}
//	class CGarbo
//	{
//	public:
//		~CGarbo()
//		{
//			if (_Inst != nullptr)
//			{
//				delete _Inst;
//				_Inst = nullptr;
//				cout << "Yes" << endl;
//			}
//		}
//	};
//private:
//	Singleton()
//	{}
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//	static Singleton* _Inst;
//	static mutex _mtx;
//	static CGarbo _Garbo;
//};
//
////Singleton Singleton::_Inst = new Singleton();
//Singleton* Singleton::_Inst = nullptr;
//mutex Singleton::_mtx;
//Singleton::CGarbo Singleton::_Garbo;
//int main()
//{
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	Singleton::GetInstance()->Print();
//	//Singleton s(*Singleton::GetInstance());
//	//s.Print();
//	return 0;
//}


