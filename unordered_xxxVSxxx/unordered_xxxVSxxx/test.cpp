#include <iostream>
#include <set>
#include <unordered_set>
#include <time.h>
using namespace std;
//#define CLOCKS_PER_SEC  1000
int main()
{
	int N = 100000;
	vector<int> v;
	v.reserve(N);
	srand((unsigned int)time(NULL));
	//�������N������
	for (int i = 0; i < N; i++)
	{
		v.push_back(rand());
	}

	/****************����Ч�ʲ���****************/
	//����N��������set����
	set<int> s;
	clock_t begin1 = clock();
	for (auto e : v)
	{
		s.insert(e);
	}
	clock_t end1 = clock();

	//����N��������unordered_set����
	unordered_set<int> us;
	clock_t begin2 = clock();
	for (auto e : v)
	{
		us.insert(e);
	}
	clock_t end2 = clock();

	//�ֱ��������set������unordered_set�������õ�ʱ��
	cout << "set insert: " << end1 - begin1 << endl;
	cout << "unordered_set insert: " << end2 - begin2 << endl;

	/****************����Ч�ʲ���****************/
	//��set�����в�����N����
	clock_t begin3 = clock();
	for (auto e : v)
	{
		s.find(e);
	}
	clock_t end3 = clock();

	//��unordered_set�����в�����N����
	clock_t begin4 = clock();
	for (auto e : v)
	{
		us.find(e);
	}
	clock_t end4 = clock();

	//�ֱ������set������unordered_set�����в�����N�������õ�ʱ��
	cout << "set find: " << end3 - begin3 << endl;
	cout << "unordered_set find: " << end4 - begin4 << endl;

	/****************ɾ��Ч�ʲ���****************/
	//����N������set������ɾ��
	clock_t begin5 = clock();
	for (auto e : v)
	{
		s.erase(e);
	}
	clock_t end5 = clock();

	//����N������unordered_set������ɾ��
	clock_t begin6 = clock();
	for (auto e : v)
	{
		us.erase(e);
	}
	clock_t end6 = clock();

	//�ֱ��������N������set������unordered_set������ɾ�����õ�ʱ��
	cout << "set erase: " << end5 - begin5 << endl;
	cout << "unordered_set erase: " << end6 - begin6 << endl;
	return 0;
}