#include <bits/stdc++.h>
using namespace std;

int T, n;
int use[10] = {6, 2, 5, 5, 4, 5, 6 ,3, 7, 6};

void solve1()//30pts
{
	for (int i = 1; i <= n / 7; i++)
		cout << 8;
	cout << endl;
}

void solve2()//30pts
{
	cout << 10;
	for (int i = 1; i < n / 7; i++)
		cout << 8;
	cout << endl;
}

void solve3()
{
	cout << 200;
	for (int i = 1; i <= (n - 14) / 7; i++)
		cout << 8;
	cout << endl;
}

void solve4()
{
	int lft = n % 7 + 7, cnt8 = n / 7 - 1, minn = 1e9;
	if (n < 7)
	{
		for (int i = 1; i <= 9; i++)
			if (use[i] == n)	
			{
				cout << i << endl;
				return;
			}
	}
	else if (n < 14)
	{
		for (int i = 1; i <= 9; i++)
			for (int j = 0; j <= 9; j++)
				if (use[i] + use[j] == n)	minn = min(minn, i * 10 + j);
		cout << minn << endl;
		return;
	}
	for (int i = 0; i <= 9; i++)
		for (int j = i; j <= 9; j++)
			if (use[i] + use[j] == lft)
			{
				int a, b, c;
				a = min(i, min(j, 8));
				c = max(i, max(j, 8));
				b = i + j + 8 - a - c;
				if (a == 0)	
				{
					if (b == 0)	a = 8, b = 0, c = 0;
					else	swap(a, b);
				}
				minn = min(minn, a * 100 + b * 10 + c);
			}
	cout << minn;
	for (int i = 1; i < cnt8; i++)
		cout << 8;
	cout << endl;
}

void solve()
{
	cin >> n;
	if (n == 1)	cout << -1 << endl;
	else if (n % 7 == 0)	solve1();
	else if (n % 7 == 1)	solve2();
	else if (n % 7 == 3 && n > 14)	solve3();
	else	solve4();
}

int main()
{
	freopen ("sticks.in", "r", stdin);
	freopen ("sticks.out", "w", stdout);
	cin >> T;
	while (T--)	solve();
	return 0;
}

// 1. 09:51 可以过所有样例 
// 2. 11:09 测试了从 1 ~ 45 的所有数据，填补了  (n % 7 == 3 && n > 14) 的问题
//	  感觉补丁打的比较悬，sticks 可能实际上拿不到太多分 
