//函数模板定义
template<class T>
T Add(const T& x, const T& y)
{
	return x + y;
}
//显示实例化
template
int Add(const int& x, const int& y);
template
double Add(const double& x, const double& y);