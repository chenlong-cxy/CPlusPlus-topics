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

#include <iostream>
//�����ռ����ͨ����
namespace N1 //N1Ϊ�����ռ������
{
	//�������ռ��У��ȿ��Զ��������Ҳ���Զ��庯��
	int a;
	int Add(int x, int y)
	{
		return x + y;
	}
}


//�����ռ��Ƕ�׶���
namespace N1 //����һ����ΪN1�������ռ�
{
	int a;
	int b;
	namespace N2 //Ƕ�׶�����һ����ΪN2�������ռ�
	{
		int c;
		int d;
	}
}
//int main()
//{
//	N1::a = 20;
//	N1::N2::a = 10;
//	std::cout << N1::a << std::endl << N1::N2::a << std::endl;
//	return 0;
//}