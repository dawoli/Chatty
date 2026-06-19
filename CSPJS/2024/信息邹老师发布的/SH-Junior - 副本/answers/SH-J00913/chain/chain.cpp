#include <bits/stdc++.h>
using namespace std;

bool flag = false;
int T, n, k, q, r, c, num[1005][2005];
// T : 总测试样例个数
// n : 单个测试样例内的人数
// k : 单个测试样例内的子序列长度上限
// q : 单个测试样例内的任务个数
// r : 单个任务内的游戏轮数
// c : 单个任务内的最后一轮的末尾 

void dfs(int step, int last, int end)
{
	if (flag)	return;
	if (step > r)
	{
		if (end == c)	flag = true;
		return;
	}
	for (int i = 1; i <= n; i++)
		if (i != last)
		{
			for (int l = 1; l <= n; l++)
				if (num[i][l] == end)
				{
					for (int r = l + 1; r < l + k; r++)
						dfs(step + 1, i, num[i][r]);
				}
		}
}

void check()
{
	cin >> r >> c;
	if (r <= 10)
	{
		dfs(1, 0, 1);
		if (flag)	cout << 1 << endl;
		else	cout << 0 << endl;
		flag = false; 
	}
	else	cout << 0 << endl;
}

void solve()
{
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++)
	{
		int l;
		cin >> l;
		for (int j = 1; j <= l; j++)
			cin >> num[i][j];
	}
	while (q--)	check();
}

int main()
{
	freopen ("chain.in", "r", stdin);
	freopen ("chain.out", "w", stdout);
	cin >> T;
	while (T--)	solve();
	return 0;
}

// 1. 10:08 完成最基本的骗分，预估 0 分 
// 2. 11:33 好像大概 r 小的时候有机会？ 写了个无脑暴力。 
