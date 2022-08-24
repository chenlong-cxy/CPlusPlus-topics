#include "BloomFilter.h"

void BloomFilterTest1()
{
	BloomFilter<100> bf;
	bf.Set("张三");
	bf.Set("李四");
	cout << bf.Test("张三") << endl; //1
	cout << bf.Test("李四") << endl; //1
	cout << bf.Test("王五") << endl; //0
}
void BloomFilterTest2()
{
	//BloomFilter<800> bf;
	BloomFilter<400> bf;
	vector<string> v1;
	for (int i = 0; i < 100; i++)
	{
		string url = "https://blog.csdn.net/chenlong_cxy?spm=1010.2135.3001.5343";
		url += to_string(1234 + i);
		v1.push_back(url);
	}
	for (auto& url : v1)
	{
		bf.Set(url);
	}
	int count = 0;
	for (auto& url : v1)
	{
		if (bf.Test(url))
			count++;
	}
	cout << count << endl; //100

	vector<string> v2;
	for (int i = 0; i < 100; i++)
	{
		string url = "https://blog.csdn.net/chenlong_cxy?spm=1010.2135.3001.5343";
		url += to_string(10000 + i);
		v2.push_back(url);
	}
	int err2 = 0;
	for (auto& url : v2)
	{
		if (bf.Test(url))
			err2++;
	}
	cout << "相似字符串：" << err2 << endl; //39

	vector<string> v3;
	for (int i = 0; i < 100; i++)
	{
		string url = "https://www.baidu.com/";
		url += to_string(10000 + i);
		v3.push_back(url);
	}
	int err3 = 0;
	for (auto& url : v3)
	{
		if (bf.Test(url))
			err3++;
	}
	cout << "不相似字符串：" << err3 << endl; //20
}

int main()
{
	//BloomFilterTest1();
	BloomFilterTest2();
	return 0;
}
