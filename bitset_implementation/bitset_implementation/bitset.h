#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

namespace cl
{
	//模拟实现位图
	template<size_t N>
	class bitset
	{
	public:
		//构造函数
		bitset()
		{
			_bits.resize(N / 32 + 1, 0);
		}
		//设置位
		void set(size_t pos)
		{
			assert(pos < N);

			//算出pos映射的位在第i个整数的第j个位
			int i = pos / 32;
			int j = pos % 32;
			_bits[i] |= (1 << j); //将该位设置为1（不影响其他位）
		}
		//清空位
		void reset(size_t pos)
		{
			assert(pos < N);

			//算出pos映射的位在第i个整数的第j个位
			int i = pos / 32;
			int j = pos % 32;
			_bits[i] &= (~(1 << j)); //将该位设置为0（不影响其他位）
		}
		//反转位
		void flip(size_t pos)
		{
			assert(pos < N);

			//算出pos映射的位在第i个整数的第j个位
			int i = pos / 32;
			int j = pos % 32;
			_bits[i] ^= (1 << j); //将该进行反转（不影响其他位）
		}
		//获取比特位状态
		bool test(size_t pos)
		{
			assert(pos < N);

			//算出pos映射的位在第i个整数的第j个位
			int i = pos / 32;
			int j = pos % 32;
			if (_bits[i] & (1 << j)) //该比特位被设置
				return true;
			else //该比特位未被设置
				return false;
		}
		//获取可以容纳的位的个数
		size_t size()
		{
			return N;
		}
		//获取被设置位的个数
		size_t count()
		{
			size_t count = 0;
			//将每个整数中1的个数累加起来
			for (auto e : _bits)
			{
				int num = e;
				//计算整数num中1的个数
				while (num)
				{
					num = num&(num - 1);
					count++;
				}
			}
			return count; //位图中1的个数，即被设置位的个数
		}
		//判断位图中是否有位被设置
		bool any()
		{
			//遍历每个整数
			for (auto e : _bits)
			{
				if (e != 0) //该整数中有位被设置
					return true;
			}
			return false; //全部整数都是0，则没有位被设置过
		}
		//判断位图中是否全部位都没有被设置
		bool none()
		{
			return !any();
		}
		//判断位图中是否全部位都被设置
		bool all()
		{
			size_t n = _bits.size();
			//先检查前n-1个整数
			for (size_t i = 0; i < n - 1; i++)
			{
				if (~_bits[i] != 0) //取反后不为全0，说明取反前不为全1
					return false;
			}
			//再检查最后一个整数的前N%32位
			for (size_t j = 0; j < N % 32; j++)
			{
				if ((_bits[n - 1] & (1 << j)) == 0) //该位未被设置
					return false;
			}
			return true;
		}
		//打印函数
		void Print()
		{
			int count = 0;
			size_t n = _bits.size();
			for (size_t i = 0; i < n - 1; i++)
			{
				for (size_t j = 0; j < 32; j++)
				{
					if (_bits[i] & (1 << j))
						cout << "1";
					else
						cout << "0";
					count++;
				}
			}
			for (size_t j = 0; j < N % 32; j++)
			{
				if (_bits[n - 1] & (1 << j))
					cout << "1";
				else
					cout << "0";
				count++;
			}
			cout << " " << count << endl;
		}
	private:
		vector<int> _bits; //位图
	};
}

namespace cl
{
	//模拟实现位图
	template<size_t N>
	class bitset
	{
	public:
		//构造函数
		bitset();
		//设置位
		void set(size_t pos);
		//清空位
		void reset(size_t pos);
		//反转位
		void flip(size_t pos);
		//获取比特位状态
		bool test(size_t pos);
		//获取可以容纳的位的个数
		size_t size();
		//获取被设置位的个数
		size_t count();
		//判断位图中是否有位被设置
		bool any();
		//判断位图中是否全部位都没有被设置
		bool none();
		//判断位图中是否全部位都被设置
		bool all();
		//打印函数
		void Print();
	private:
		vector<int> _bits; //位图
	};
}