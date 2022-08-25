#pragma once

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

struct BKDRHash
{
	size_t operator()(const string& s)
	{
		size_t value = 0;
		for (auto ch : s)
		{
			value = value * 131 + ch;
		}
		return value;
	}
};
struct APHash
{
	size_t operator()(const string& s)
	{
		size_t value = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			if ((i & 1) == 0)
			{
				value ^= ((value << 7) ^ s[i] ^ (value >> 3));
			}
			else
			{
				value ^= (~((value << 11) ^ s[i] ^ (value >> 5)));
			}
		}
		return value;
	}
};
struct DJBHash
{
	size_t operator()(const string& s)
	{
		if (s.empty())
			return 0;
		size_t value = 5381;
		for (auto ch : s)
		{
			value += (value << 5) + ch;
		}
		return value;
	}
};
//布隆过滤器
template<size_t N, class K = string, class Hash1 = BKDRHash, class Hash2 = APHash, class Hash3 = DJBHash>
class BloomFilter
{
public:
	void Set(const K& key)
	{
		//计算出key对应的三个位
		//Hash1 hf1;
		//int i1 = hf1(key) % N;
		size_t i1 = Hash1()(key) % N;
		size_t i2 = Hash2()(key) % N;
		size_t i3 = Hash3()(key) % N;
		//cout << i1 << " " << i2 << " " << i3 << endl;

		//设置位图中的这三个位
		_bs.set(i1);
		_bs.set(i2);
		_bs.set(i3);
	}
	bool Test(const K& key)
	{
		//依次判断key对应的三个位是否被设置
		size_t i1 = Hash1()(key) % N;
		if (_bs.test(i1) == false)
		{
			return false; //key一定不存在
		}

		size_t i2 = Hash2()(key) % N;
		if (_bs.test(i2) == false)
		{
			return false; //key一定不存在
		}

		size_t i3 = Hash3()(key) % N;
		if (_bs.test(i3) == false)
		{
			return false; //key一定不存在
		}

		return true; //key对应的三个位都被设置，key存在（可能误判）
	}
private:
	bitset<N> _bs;
};
