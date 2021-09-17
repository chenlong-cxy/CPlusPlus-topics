//#include <iostream> //包含iostream文件
//using namespace std; //引入std标准命名空间
//int main()
//{
//	int a = 0;
//	cin >> a;
//	cout << a << endl;
//	return 0;
//}

//#include <iostream> //包含iostream文件
//int main()
//{
//	int a = 0;
//	std::cin >> a; //使用时指定所属命名空间
//	std::cout << a << std::endl; //使用时指定所属命名空间
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 0, b = 0;
//	cin >> a; //输入：10 20
//	cout << a << endl;
//	cin >> b; //直接从输入缓冲区提取
//	cout << b << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;          //输入："hello world"
//	cout << s << endl; //输出："hello"
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s;
//	getline(cin, s);   //输入："hello world"
//	cout << s << endl; //输出："hello world"
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Date
//{
//	friend istream& operator>>(istream& in, Date& d);
//	friend ostream& operator<<(ostream& out, const Date& d);
//public:
//	Date(int year = 2021, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////对>>进行重载
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
////对<<进行重载
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "-" << d._month << "-" << d._day;
//	return out;
//}
//
//int main()
//{
//	Date d;
//	cin >> d;          //输入：2021 9 20
//	cout << d << endl; //输出：2021-9-20
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	while (scanf("%d", &a) != EOF)
//	{
//		printf("%d\n", a);
//		//...
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 0;
//	while (cin >> a)
//	{
//		cout << a << endl;
//		//...
//	}
//	return 0;
//}

//#include <iostream>
//#include <fstream>
//using namespace std;
////以二进制的形式对文件进行写入
//void WriteBinary()
//{
//	ofstream ofile; //定义文件流对象
//	ofile.open("test.bin", ofstream::out | ofstream::binary); //以二进制写入的方式打开test.bin文件
//	char data[] = "2021dragon";
//	ofile.write(data, strlen(data)); //将data字符串写入文件
//	ofile.put('!'); //将字符'!'写入文件
//	ofile.close(); //关闭文件
//}
////以二进制的形式对文件进行读取
//void ReadBinary()
//{
//	ifstream ifile; //定义文件流对象
//	ifile.open("test.bin", ofstream::in | ofstream::binary); //以二进制读取的方式打开test.bin文件
//	ifile.seekg(0, ifile.end); //跳转到文件末尾
//	int length = ifile.tellg(); //获取当前字符在文件当中的位置，即文件的字符总数
//	ifile.seekg(0, ifile.beg); //重新回到文件开头
//	char data[100];
//	ifile.read(data, length); //将文件当中的数据全部读取到字符串data当中
//	cout << length << endl; 
//	cout << data << endl;
//	ifile.close(); //关闭文件
//}
////以文本的形式对文件进行写入
//void WriteTxt()
//{
//	ofstream ofile; //定义文件流对象
//	ofile.open("test.txt"); //以写入的方式打开test.txt文件
//	char data[] = "2021dragon";
//	ofile.write(data, strlen(data)); //将data字符串写入文件
//	ofile.put('!'); //将字符'!'写入文件
//	ofile.close(); //关闭文件
//}
////以文本的形式对文件进行读取
//void ReadTxt()
//{
//	ifstream ifile; //定义文件流对象
//	ifile.open("test.txt"); //以读取的方式打开test.txt文件
//	ifile.seekg(0, ifile.end); //跳转到文件末尾
//	int length = ifile.tellg(); //获取当前字符在文件当中的位置，即文件的字符总数
//	ifile.seekg(0, ifile.beg); //重新回到文件开头
//	char data[100];
//	ifile.read(data, length); //将文件当中的数据全部读取到字符串data当中
//	cout << length << endl;
//	cout << data << endl;
//	ifile.close(); //关闭文件
//}
////对文件进行写入操作
//void WriteFile()
//{
//	ofstream ofs("data.txt"); //定义文件流对象，并打开文件
//	ofs << "2021dragon!"; //字符串“流入”文件
//	ofs.close(); //关闭文件
//}
////对文件进行读取操作
//void ReadFile()
//{
//	ifstream ifs("data.txt"); //定义文件流对象，并打开文件
//	char data[100];
//	ifs >> data; //文件数据“流入”字符串data
//	cout << data << endl;
//	ifs.close(); //关闭文件
//}
//int main()
//{
//	//WriteBinary();
//	//ReadBinary();
//	//WriteTxt();
//	//ReadTxt();
//	WriteFile();
//	ReadFile();
//	return 0;
//}

//#include <iostream>
//#include <fstream>
//#include <string.h>
//using namespace std;
//void WriteBin()
//{
//	// 这里注意使用二进制方式打开写
//	ofstream ofs("data.txt", ifstream::out | ifstream::binary);
//	char data[] = "2021dragon加油";
//	ofs.write(data, strlen(data));
//	ofs.close();
//}
//int main()
//{
//	WriteBin();
//	return 0;
//}

//#include<iostream>
//#include<fstream>
//using namespace std;
//
//struct Person{
//	char m_Name[64];
//	int m_Age;
//};
//void test01(){
//	ofstream ofs;
//	ofs.open("binary.txt", ios::out | ios::binary);
//	Person p = { "曹操", 23 };
//	//写入数据到文件里 
//	ofs.write((const char*)&p, sizeof(Person));
//	ofs.close();
//}
//
//int main(){
//	test01();
//
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//int main()
//{
//	int a = 10;
//	char arr[10];
//	itoa(a, arr, 10); //将整型的a转化为十进制字符数字存储在字符串arr当中
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int a = 10;
//	char arr[10];
//	sprintf(arr, "%d", a); //将整型的a转化为字符串格式存储在字符串arr当中
//	return 0;
//}

//#include <iostream>
//#include <sstream>
//#include <string>
//using namespace std;
//int main()
//{
//	int a = 10;
//	string sa;
//	stringstream s;
//	s << a; //将int类型的a放入输入流
//	s >> sa; //从s中抽取前面插入的int类型的值，赋值给string类型（方式一）
//	cout << sa << endl;
//	s.str(""); //将stringstream底层管理的string对象设置为空字符串
//	s.clear(); //将上次转换状态清空掉
//	//进行下一次转换
//	double b = 3.14;
//	s << b;
//	sa = s.str(); //获取stringstream中管理的string类型（方式二）
//	cout << sa << endl;
//	return 0;
//}


#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	string rets;
	stringstream s;
	s << "2021" << "dragon"; //将多个字符串放入stringstream中
	s >> rets; //方式一获取
	cout << rets << endl;
	s.str(""); //将stringstream底层管理的string对象设置为空字符串
	s.clear(); //将上次转换状态清空掉
	s << "Thanks" << " " << "for" << " " << "reading"; //将多个字符串放入stringstream中
	rets = s.str(); //方式二获取
	cout << rets << endl;
	return 0;
}