#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int lcm(int a, int b)
{
	int temp = a * b;
	temp = temp / gcd(a, b);
	return temp;
}

int main()
{
	int a[4] = {40, 20, 10, 30};			//最小公倍数：120
	int L = sizeof(a) / sizeof(int);	//L为元素个数
	int m = a[0];	//初始化最小公倍数：a[0]
	for (int i = 1; i < L; i++)	//从 a[1]开始
	{		
		m = m * a[i] / gcd(m, a[i]);
	}
	cout << m;      				//输出最小公倍数：120
	return 0;
}
