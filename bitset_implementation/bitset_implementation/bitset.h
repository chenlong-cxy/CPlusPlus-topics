#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

namespace cl
{
	//ģ��ʵ��λͼ
	template<size_t N>
	class bitset
	{
	public:
		//���캯��
		bitset()
		{
			_bits.resize(N / 32 + 1, 0);
		}
		//����λ
		void set(size_t pos)
		{
			assert(pos < N);

			//���posӳ���λ�ڵ�i�������ĵ�j��λ
			int i = pos / 32;
			int j = pos % 32;
			_bits[i] |= (1 << j); //����λ����Ϊ1����Ӱ������λ��
		}
		//���λ
		void reset(size_t pos)
		{
			assert(pos < N);

			//���posӳ���λ�ڵ�i�������ĵ�j��λ
			int i = pos / 32;
			int j = pos % 32;
			_bits[i] &= (~(1 << j)); //����λ����Ϊ0����Ӱ������λ��
		}
		//��תλ
		void flip(size_t pos)
		{
			assert(pos < N);

			//���posӳ���λ�ڵ�i�������ĵ�j��λ
			int i = pos / 32;
			int j = pos % 32;
			_bits[i] ^= (1 << j); //���ý��з�ת����Ӱ������λ��
		}
		//��ȡλ��״̬
		bool test(size_t pos)
		{
			assert(pos < N);

			//���posӳ���λ�ڵ�i�������ĵ�j��λ
			int i = pos / 32;
			int j = pos % 32;
			if (_bits[i] & (1 << j)) //�ñ���λ������
				return true;
			else //�ñ���λδ������
				return false;
		}
		//��ȡ�������ɵ�λ�ĸ���
		size_t size()
		{
			return N;
		}
		//��ȡ������λ�ĸ���
		size_t count()
		{
			size_t count = 0;
			//��ÿ��������1�ĸ����ۼ�����
			for (auto e : _bits)
			{
				int num = e;
				//��������num��1�ĸ���
				while (num)
				{
					num = num&(num - 1);
					count++;
				}
			}
			return count; //λͼ��1�ĸ�������������λ�ĸ���
		}
		//�ж�λͼ���Ƿ���λ������
		bool any()
		{
			//����ÿ������
			for (auto e : _bits)
			{
				if (e != 0) //����������λ������
					return true;
			}
			return false; //ȫ����������0����û��λ�����ù�
		}
		//�ж�λͼ���Ƿ�ȫ��λ��û�б�����
		bool none()
		{
			return !any();
		}
		//�ж�λͼ���Ƿ�ȫ��λ��������
		bool all()
		{
			size_t n = _bits.size();
			//�ȼ��ǰn-1������
			for (size_t i = 0; i < n - 1; i++)
			{
				if (~_bits[i] != 0) //ȡ����Ϊȫ0��˵��ȡ��ǰ��Ϊȫ1
					return false;
			}
			//�ټ�����һ��������ǰN%32λ
			for (size_t j = 0; j < N % 32; j++)
			{
				if ((_bits[n - 1] & (1 << j)) == 0) //��λδ������
					return false;
			}
			return true;
		}
		//��ӡ����
		void Print()
		{
			int count = 0;
			size_t n = _bits.size();
			//�ȴ�ӡǰn-1������
			for (size_t i = 0; i < n - 1; i++)
			{
				for (size_t j = 0; j < 32; j++)
				{
					if (_bits[i] & (1 << j)) //��λ������
						cout << "1";
					else //��λδ������
						cout << "0";
					count++;
				}
			}
			//�ٴ�ӡ���һ��������ǰN%32λ
			for (size_t j = 0; j < N % 32; j++)
			{
				if (_bits[n - 1] & (1 << j)) //��λ������
					cout << "1";
				else //��λδ������
					cout << "0";
				count++;
			}
			cout << " " << count << endl; //��ӡ�ܹ���ӡ��λ�ĸ���
		}
	private:
		vector<int> _bits; //λͼ
	};
}

//namespace cl
//{
//	//ģ��ʵ��λͼ
//	template<size_t N>
//	class bitset
//	{
//	public:
//		//���캯��
//		bitset();
//		//����λ
//		void set(size_t pos);
//		//���λ
//		void reset(size_t pos);
//		//��תλ
//		void flip(size_t pos);
//		//��ȡλ��״̬
//		bool test(size_t pos);
//		//��ȡ�������ɵ�λ�ĸ���
//		size_t size();
//		//��ȡ������λ�ĸ���
//		size_t count();
//		//�ж�λͼ���Ƿ���λ������
//		bool any();
//		//�ж�λͼ���Ƿ�ȫ��λ��û�б�����
//		bool none();
//		//�ж�λͼ���Ƿ�ȫ��λ��������
//		bool all();
//		//��ӡ����
//		void Print();
//	private:
//		vector<int> _bits; //λͼ
//	};
//}

//#include <iostream>
//#include <string>
//#include <map>
//#include <queue>
//using namespace std;
//struct Func
//{
//	bool operator()(const pair<string, int>& p1, const pair<string, int>& p2)
//	{
//		if (p1.first > p2.first)
//			return true;
//		else if (p1.first == p2.first&&p1.second > p2.second)
//			return true;
//		else
//			return false;
//	}
//};
//int main()
//{
//	map<pair<string, int>, int, Func> m; //<<name, rows>, num>
//	queue<pair<string, int>> q; //<name, rows>
//	string path;
//	int n;
//	while (cin >> path >> n)
//	{
//		size_t pos = path.rfind('\\');
//		string name = path.substr(pos + 1);
//		if (name.size() > 16)
//			name = name.substr(name.size() - 16); //ֻ�������16λ
//		m[make_pair(name, n)]++;
//		if (m[make_pair(name, n)] == 1)
//		{
//			q.push(make_pair(name, n));
//			if (q.size() > 8)
//				q.pop();
//		}
//	}
//	while (!q.empty())
//	{
//		auto front = q.front();
//		q.pop();
//		cout << front.first << " " << front.second << " " << m[front] << endl;
//	}
//	return 0;
//}