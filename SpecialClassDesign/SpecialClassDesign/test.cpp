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


//�����һ���ֻ࣬���ڶ��ϴ�������
//#include <iostream>
//using namespace std;
//class HeapOnly
//{
//public:
//	//2���ṩһ����ȡ����Ľӿڣ����Ҹýӿڱ�������Ϊ��̬��Ա����
//	static HeapOnly* CreateObj()
//	{
//		return new HeapOnly;
//	}
//private:
//	//1�������캯������Ϊ˽��
//	HeapOnly()
//	{}
//	//3�����������캯������Ϊ˽�У�����ֻ������ʵ��
//	//C++98
//	HeapOnly(const HeapOnly&);
//	//C++11
//	//HeapOnly(const HeapOnly&) = delete;
//};
//int main()
//{
//	HeapOnly* p = HeapOnly::CreateObj();
//	//HeapOnly copy(*p);
//	return 0;
//}

//�����һ���ֻ࣬����ջ�ϴ�������
//#include <iostream>
//using namespace std;
//class StackOnly
//{
//public:
//	//2���ṩһ����ȡ����Ľӿڣ����Ҹýӿڱ�������Ϊ��̬��Ա����
//	static StackOnly CreateObj()
//	{
//		return StackOnly();
//	}
//private:
//	//1�������캯������Ϊ˽��
//	StackOnly()
//	{}
//};
//int main()
//{
//	StackOnly obj1 = StackOnly::CreateObj();
//	static StackOnly obj2(obj1); //�ھ�̬�������������
//	StackOnly* ptr = new StackOnly(obj1); //�ڶ��Ͽ����������
//	return 0;
//}
//#include <iostream>
//using namespace std;
//class StackOnly
//{
//public:
//	StackOnly()
//	{}
//private:
//	//C++98
//	void* operator new(size_t size);
//	void operator delete(void* p);
//	//C++11
//	//void* operator new(size_t size) = delete;
//	//void operator delete(void* p) = delete;
//};
//int main()
//{
//	StackOnly s;
//	static StackOnly obj; //�ھ�̬����������
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
//	//C++98
//	CopyBan(const CopyBan&);
//	CopyBan& operator=(const CopyBan&);
//	//C++11
//	//CopyBan(const CopyBan&) = delete;
//	//CopyBan& operator=(const CopyBan&) = delete;
//};
//int main()
//{
//	CopyBan c;
//	return 0;
//}

//�����һ���࣬���ܱ��̳�
//C++98
//#include <iostream>
//using namespace std;
//class NonInherit
//{
//public:
//	static NonInherit CreateObj()
//	{
//		return NonInherit();
//	}
//private:
//	//�����캯������Ϊ˽��
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

//C++11
//#include <iostream>
//using namespace std;
//class NonInherit final
//{
//	//...
//};
//class A :public NonInherit
//{};
//int main()
//{
//	return 0;
//}


//�����һ���ֻ࣬�ܴ���һ�����󣨵���ģʽ��
//����ģʽ
//#include <iostream>
//using namespace std;
//class Singleton
//{
//public:
//	//3���ṩһ��ȫ�ַ��ʵ��ȡ��������
//	static Singleton* GetInstance()
//	{
//		return _inst;
//	}
//private:
//	//1�������캯������Ϊ˽�У���������
//	Singleton()
//	{}
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//	//2���ṩһ��ָ���������staticָ��
//	static Singleton* _inst;
//};
//
////�ڳ������֮ǰ��ɵ�������ĳ�ʼ��
//Singleton* Singleton::_inst = new Singleton;
//
//int main()
//{
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	return 0;
//}

//����ģʽ
//#include <iostream>
//#include <mutex>
//using namespace std;
//class Singleton
//{
//public:
//	//3���ṩһ��ȫ�ַ��ʵ��ȡ��������
//	static Singleton* GetInstance()
//	{
//		//˫���
//		if (_inst == nullptr)
//		{
//			_mtx.lock();
//			if (_inst == nullptr)
//			{
//				_inst = new Singleton;
//			}
//			_mtx.unlock();
//		}
//		return _inst;
//	}
//private:
//	//1�������캯������Ϊ˽�У���������
//	Singleton()
//	{}
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//	//2���ṩһ��ָ���������staticָ��
//	static Singleton* _inst;
//	static mutex _mtx; //������
//};
//
////�ڳ������֮ǰ�Ƚ�staticָ���ʼ��Ϊ��
//Singleton* Singleton::_inst = nullptr;
//mutex Singleton::_mtx; //��ʼ��������
//
//int main()
//{
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	char* p = new char[1024 * 1024 * 1024];
//	return 0;
//}

////�ͷ�
//#include <iostream>
//#include <mutex>
//using namespace std;
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		//˫������
//		if (_inst == nullptr)
//		{
//			_mtx.lock();
//			if (_inst == nullptr)
//			{
//				_inst = new Singleton;
//			}
//			_mtx.unlock();
//		}
//		return _inst;
//	}
//	static void DelInstance()
//	{
//		_mtx.lock();
//		if (_inst != nullptr)
//		{
//			delete _inst;
//			_inst = nullptr;
//		}
//		_mtx.unlock();
//	}
//private:
//	Singleton()
//	{}
//
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//
//	static Singleton* _inst;
//	static mutex _mtx;
//};
//
//Singleton* Singleton::_inst = nullptr;
//mutex Singleton::_mtx;
//
//int main()
//{
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	char* p = new char[1024 * 1024 * 1024];
//	return 0;
//}

////�ͷ�
//#include <iostream>
//#include <mutex>
//using namespace std;
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		//˫������
//		if (_inst == nullptr)
//		{
//			_mtx.lock();
//			if (_inst == nullptr)
//			{
//				_inst = new Singleton;
//			}
//			_mtx.unlock();
//		}
//		return _inst;
//	}
//	class CGarbo
//	{
//	public:
//		~CGarbo()
//		{
//			if (_inst != nullptr)
//			{
//				delete _inst;
//				_inst = nullptr;
//			}
//		}
//	};
//private:
//	Singleton()
//	{}
//
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//
//	static Singleton* _inst;
//	static mutex _mtx;
//	static CGarbo _gc;
//};
//
//Singleton* Singleton::_inst = nullptr;
//mutex Singleton::_mtx;
//Singleton::CGarbo Singleton::_gc;
//
//int main()
//{
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	return 0;
//}

//�����汾����
#include <iostream>
#include <mutex>
using namespace std;
class Singleton
{
public:
	//2���ṩһ��ȫ�ַ��ʵ��ȡ��������
	static Singleton* GetInstance()
	{
		static Singleton inst;
		return &inst;
	}
private:
	//1�������캯������Ϊ˽�У���������
	Singleton()
	{}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
};

int main()
{
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
	return 0;
}