#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//�����ӷ�
string AddString(string num1, string num2)
{
	int end1 = num1.size() - 1, end2 = num2.size() - 1;
	string ret; //�洢�����ַ�����Ӻ�Ľ��
	int carry = 0; //��λ����ʼʱ��λ����Ϊ0��
	while (end1 >= 0 || end2 >= 0)
	{
		//1��ȡ��num1�б��δ���ӵ�����
		int a = 0;
		if (end1 >= 0)
		{
			a = num1[end1] - '0';
			end1--;
		}
		//2��ȡ��num2�б��δ���ӵ�����
		int b = 0;
		if (end2 >= 0)
		{
			b = num2[end2] - '0';
			end2--;
		}
		//3����������������ӣ�ע����Ͻ�λ��
		int sum = a + b + carry;
		//4���ж��Ƿ���Ҫ��λ
		if (sum > 9)
		{
			sum -= 10;
			carry = 1; //��Ҫ��λ����carry����Ϊ1
		}
		else
		{
			carry = 0; //����Ҫ��λ����carry����Ϊ0
		}
		ret += (sum + '0');
	}
	if (carry != 0) //�ж��Ƿ����λ�����������������λ��Ӻ���λ��
		ret += '1';

	reverse(ret.begin(), ret.end()); //��ret�ַ������з�ת
	return ret; //���������ַ�����Ӻ�Ľ��
}

//�����Ƚ�
int Cmp(string& num1, string& num2)
{
	if ((num1.size() > num2.size()) || (num1.size() == num2.size() && num1 > num2))
		return 1; //num1����num2������1
	else if ((num1.size() < num2.size()) || (num1.size() == num2.size() && num1 < num2)) 
		return -1; //num1С��num2������-1
	else
		return 0; //num1����num2������0
}
//��������
string SubString(string num1, string num2)
{
	//��֤num1���ڵ���num2
	if (Cmp(num1, num2) == -1)
	{
		return "-" + SubString(num2, num1); //num1С��num2���򷵻�num2-num1���õ��Ľ���ĸ�ֵ
	}
	int end1 = num1.size() - 1, end2 = num2.size() - 1;
	string ret; //�洢�����ַ��������Ľ��
	int borrow = 0; //��λ����ʼʱ��λ����Ϊ0��
	while (end1 >= 0)
	{
		//1��ȡ��num1�б��δ����������
		int a = num1[end1] - '0';
		end1--;
		//2��ȡ��num2�б��δ����������
		int b = 0;
		if (end2 >= 0)
		{
			b = num2[end2] - '0';
			end2--;
		}
		//3�������������������ע���ȥ��λ��
		int differ = a - b - borrow;
		//4���ж��Ƿ���Ҫ��λ
		if (differ < 0)
		{
			differ = 10 + differ;
			borrow = 1; //��Ҫ��λ����borrow����Ϊ1
		}
		else
		{
			borrow = 0; //����Ҫ��λ����borrow����Ϊ0
		}
		ret += (differ + '0');
	}
	reverse(ret.begin(), ret.end()); //��ret�ַ������з�ת
	//���˵�ret�ַ���ǰ���'0'
	size_t pos = ret.find_first_not_of('0');
	if (pos == string::npos) //ret��ȫ��Ϊ'0'���������������Ľ��Ϊ0
	{
		return "0";
	}
	return ret.substr(pos); //���������ַ��������Ľ��
}

//�����˷�
string MulString(string num1, string num2)
{
	if (num1 == "0" || num2 == "0") //��������������һ��Ϊ0������Ϊ0
		return "0";

	int m = num1.size(), n = num2.size();
	vector<int> arr(m + n, 0); //��������arr�Ĵ�СΪm+n������ȫ����ʼ��Ϊ0
	
	//1��ȡ������ÿһλ�뱻������ÿһλ��ˣ�������ۼӵ�����arr�Ķ�Ӧ�±�λ��
	for (int i = n - 1; i >= 0; i--) //ȡ������ÿһλ
	{
		int a = num2[i] - '0';
		for (int j = m - 1; j >= 0; j--) //ȡ��������ÿһλ
		{
			int b = num1[j] - '0';
			arr[i + j + 1] += a*b; //������iλ�뱻������jλ��˺�Ľ���ۼӵ�����arr���±�Ϊi+j+1��λ��
		}
	}

	//2���Ӻ���ǰ������arr���н�λ����
	int end = m + n - 1;
	while (end > 0)
	{
		arr[end - 1] += arr[end] / 10; //��λ��ֵ�ӵ�ǰһ��λ��
		arr[end] %= 10; //��λ��ʣ�µ�ֵ��ŵ���ǰλ
		end--; //������һλ
	}

	//3�����ν�����β�嵽�ַ���ret����
	string ret; //��������ַ�����˺�Ľ��
	int flag = 1; //Ĭ����Чֵ������arr�����±�Ϊ1��λ�ÿ�ʼ
	if (arr[0] != 0)
		flag = 0; //������arr�����±�Ϊ0��λ�õ�ֵ��Ϊ0������Чֵ�ӵ�0λ��ʼ
	for (int i = flag; i < m + n; i++)
	{
		ret += (arr[i] + '0');
	}
	return ret; //���������ַ�����˺�Ľ��
}

//��������
string DivString(string num1, string num2, int n)
{
	if (num2 == "0") //��������Ϊ0
		return "error";
	string ret; //�洢�����ַ��������Ľ��
	string tmp; //����

	//1���ȼ���С����ǰ�����
	if (num1.size() < num2.size()) //num1��λ��С��num2
	{
		ret += "0."; //��Ϊ0
		tmp = num1; //����Ϊnum1
	}
	else //num1��λ�����ڵ���num2
	{
		size_t len = num2.size(); //�����ĳ���
		tmp = num1.substr(0, len); //��ȡ���������ĸ�lenλ
		while (1)
		{
			//a������tmp��������ж��ٸ�num2��tmp����num2���̣�
			int count = 0;
			while (Cmp(tmp, num2) != -1) //tmp���ڵ���num2����˵���̿��Ը���
			{
				tmp = SubString(tmp, num2);
				count++; 
			}

			//b������ֵβ�嵽ret����
			ret += (count + '0');

			//c�����num1������λ����ȡ���ˣ���С����֮ǰ�Ľ���������
			if (len >= num1.size())
				break;

			//d�����num1���л���δȡ��λ���������num1��һλβ�嵽tmp����
			tmp += num1[len];
			len++; //��һ�δ�ȡλ�±�
		}
		ret += "."; //С����֮ǰ�Ľ��������ϣ�����С����

		//���ret���λΪ0���Ҹ�λ���治��С���㣬����Ҫ�����0���˵�
		if (ret.size() != 2 && ret[0] == '0')
			ret = ret.substr(1);
	}

	//2���ټ���С����������������nλС����
	for (int i = 0; i < n; i++)
	{
		if (tmp == "0") //tmpΪ0������Ϊ0��
		{
			ret += "0"; //��ֱ����ret���油0����
		}
		else //tmp��Ϊ0��������Ϊ0��
		{
			tmp += "0"; //���������油0���������м���

			//a������tmp��������ж��ٸ�num2��tmp����num2���̣�
			int count = 0;
			while (Cmp(tmp, num2) != -1)
			{
				tmp = SubString(tmp, num2);
				count++;
			}

			//b������ֵβ�嵽ret����
			ret += (count + '0');
		}
	}
	return ret; //���������ַ��������Ľ��
}
int main()
{
	string num1("200");
	string num2("30");
	cout << DivString(num1, num2, 6) << endl;
	return 0;
}