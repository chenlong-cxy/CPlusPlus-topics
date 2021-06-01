#include "Date.h"
void Test1()
{
	Date d1(2020, 2, 29);
	d1.Print();
	d1 += 10;
	d1.Print();
	Date d2;
	d2 = d1 + 10;
	d1.Print();
	d2.Print();
	d1 -= 10;
	d1.Print();
}
void Test2()
{
	Date d1(2021, 5, 29);
	Date d2;
	++d1;
	d1.Print();
	d2 = d1++;
	d1.Print();
	d2.Print();
}
void Test3()
{
	Date d1(2021, 7, 29);
	Date d2(2021, 6, 29);
	cout << (d1 > d2) << endl;

	Date d3(2001, 10, 19);
	Date d4(2021, 5, 29);
	cout << (d3 == d4) << endl;

	cout << (d2 - d1) << endl;
	cout << (d4 - d3) << endl;
}
void Test4()
{
	Date d1(2021, 6, 1);
	Date d2;
	d2 = d1++;
	d2.Print();
	d1--;
	d2 = ++d1;
	d2.Print();
}
int main()
{
	Test4();
	return 0;
}