//#include <iostream> //����iostream�ļ�
//using namespace std; //����std��׼�����ռ�
//int main()
//{
//	int a = 0;
//	cin >> a;
//	cout << a << endl;
//	return 0;
//}

//#include <iostream> //����iostream�ļ�
//int main()
//{
//	int a = 0;
//	std::cin >> a; //ʹ��ʱָ�����������ռ�
//	std::cout << a << std::endl; //ʹ��ʱָ�����������ռ�
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 0, b = 0;
//	cin >> a; //���룺10 20
//	cout << a << endl;
//	cin >> b; //ֱ�Ӵ����뻺������ȡ
//	cout << b << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;          //���룺"hello world"
//	cout << s << endl; //�����"hello"
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s;
//	getline(cin, s);   //���룺"hello world"
//	cout << s << endl; //�����"hello world"
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
////��>>��������
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
////��<<��������
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "-" << d._month << "-" << d._day;
//	return out;
//}
//
//int main()
//{
//	Date d;
//	cin >> d;          //���룺2021 9 20
//	cout << d << endl; //�����2021-9-20
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
////�Զ����Ƶ���ʽ���ļ�����д��
//void WriteBinary()
//{
//	ofstream ofile; //�����ļ�������
//	ofile.open("test.bin", ofstream::out | ofstream::binary); //�Զ�����д��ķ�ʽ��test.bin�ļ�
//	char data[] = "2021dragon";
//	ofile.write(data, strlen(data)); //��data�ַ���д���ļ�
//	ofile.put('!'); //���ַ�'!'д���ļ�
//	ofile.close(); //�ر��ļ�
//}
////�Զ����Ƶ���ʽ���ļ����ж�ȡ
//void ReadBinary()
//{
//	ifstream ifile; //�����ļ�������
//	ifile.open("test.bin", ofstream::in | ofstream::binary); //�Զ����ƶ�ȡ�ķ�ʽ��test.bin�ļ�
//	ifile.seekg(0, ifile.end); //��ת���ļ�ĩβ
//	int length = ifile.tellg(); //��ȡ��ǰ�ַ����ļ����е�λ�ã����ļ����ַ�����
//	ifile.seekg(0, ifile.beg); //���»ص��ļ���ͷ
//	char data[100];
//	ifile.read(data, length); //���ļ����е�����ȫ����ȡ���ַ���data����
//	cout << length << endl; 
//	cout << data << endl;
//	ifile.close(); //�ر��ļ�
//}
////���ı�����ʽ���ļ�����д��
//void WriteTxt()
//{
//	ofstream ofile; //�����ļ�������
//	ofile.open("test.txt"); //��д��ķ�ʽ��test.txt�ļ�
//	char data[] = "2021dragon";
//	ofile.write(data, strlen(data)); //��data�ַ���д���ļ�
//	ofile.put('!'); //���ַ�'!'д���ļ�
//	ofile.close(); //�ر��ļ�
//}
////���ı�����ʽ���ļ����ж�ȡ
//void ReadTxt()
//{
//	ifstream ifile; //�����ļ�������
//	ifile.open("test.txt"); //�Զ�ȡ�ķ�ʽ��test.txt�ļ�
//	ifile.seekg(0, ifile.end); //��ת���ļ�ĩβ
//	int length = ifile.tellg(); //��ȡ��ǰ�ַ����ļ����е�λ�ã����ļ����ַ�����
//	ifile.seekg(0, ifile.beg); //���»ص��ļ���ͷ
//	char data[100];
//	ifile.read(data, length); //���ļ����е�����ȫ����ȡ���ַ���data����
//	cout << length << endl;
//	cout << data << endl;
//	ifile.close(); //�ر��ļ�
//}
////���ļ�����д�����
//void WriteFile()
//{
//	ofstream ofs("data.txt"); //�����ļ������󣬲����ļ�
//	ofs << "2021dragon!"; //�ַ��������롱�ļ�
//	ofs.close(); //�ر��ļ�
//}
////���ļ����ж�ȡ����
//void ReadFile()
//{
//	ifstream ifs("data.txt"); //�����ļ������󣬲����ļ�
//	char data[100];
//	ifs >> data; //�ļ����ݡ����롱�ַ���data
//	cout << data << endl;
//	ifs.close(); //�ر��ļ�
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
//	// ����ע��ʹ�ö����Ʒ�ʽ��д
//	ofstream ofs("data.txt", ifstream::out | ifstream::binary);
//	char data[] = "2021dragon����";
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
//	Person p = { "�ܲ�", 23 };
//	//д�����ݵ��ļ��� 
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
//	itoa(a, arr, 10); //�����͵�aת��Ϊʮ�����ַ����ִ洢���ַ���arr����
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int a = 10;
//	char arr[10];
//	sprintf(arr, "%d", a); //�����͵�aת��Ϊ�ַ�����ʽ�洢���ַ���arr����
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
//	s << a; //��int���͵�a����������
//	s >> sa; //��s�г�ȡǰ������int���͵�ֵ����ֵ��string���ͣ���ʽһ��
//	cout << sa << endl;
//	s.str(""); //��stringstream�ײ�����string��������Ϊ���ַ���
//	s.clear(); //���ϴ�ת��״̬��յ�
//	//������һ��ת��
//	double b = 3.14;
//	s << b;
//	sa = s.str(); //��ȡstringstream�й����string���ͣ���ʽ����
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
	s << "2021" << "dragon"; //������ַ�������stringstream��
	s >> rets; //��ʽһ��ȡ
	cout << rets << endl;
	s.str(""); //��stringstream�ײ�����string��������Ϊ���ַ���
	s.clear(); //���ϴ�ת��״̬��յ�
	s << "Thanks" << " " << "for" << " " << "reading"; //������ַ�������stringstream��
	rets = s.str(); //��ʽ����ȡ
	cout << rets << endl;
	return 0;
}