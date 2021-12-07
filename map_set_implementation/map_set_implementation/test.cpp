#include "RBTree.h"

void test1()
{
	RBTree<int, int> t;
	t.Insert(make_pair(1, 1));
	t.Insert(make_pair(2, 2));
	t.Insert(make_pair(3, 3));
	RBTree<int, int> t1(t);
	RBTree<int, int> t2;
	t2 = t;
	t1.Inorder();
	t2.Inorder();
}

int main()
{
	test1();
	return 0;
}