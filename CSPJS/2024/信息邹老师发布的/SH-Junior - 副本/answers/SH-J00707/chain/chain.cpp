#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std; 

int t;
int n, k, q; // 人数，接龙长度上限，任务个数
vector<int> v[100002];
bool flag;
int r, c;

void DFS(int rest, int x, int y) // 剩余接龙次数，行位置，列位置 
{
	if (flag)
	{
		return;
	}
	if (rest == 1)
	{
		if (v[x][y] == c)
		{
			flag = true;
//			cout << "suceed" << endl;
		}
//		else cout << "fail" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (i == x)
		{
			continue;
		}
		for (int j = 0; j < v[i].size(); j++)
		{
			if (v[i][j] == v[x][y])
			{
				for (int m = 1; m < k && j + m < v[i].size(); m++)
				{
//					cout << rest - 1 << ' ' << i << ' ' << j + m << endl;
					DFS(rest - 1, i, j + m);
				}
			}
		}
	}
}

void Task()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if (flag)
			{
				return;
			}
			if (v[i][j] == 1)
			{
				for (int m = 1; m < k && j + m < v[i].size(); m++)
				{
//					cout << r << ' ' << i << ' ' << j + m << endl;
					DFS(r, i, j + m);
				}
			}
		}
	 } 
}

int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> k >> q;
		for (int j = 0; j < n; j++)
		{
			int l;
			scanf("%d", &l);
			for (int m = 0; m < l; m++)
			{
				int s;
				scanf("%d", &s);
				v[j].push_back(s);
			}
		}
		for (int j = 0; j < q; j++)
		{
			flag = false;
			scanf("%d%d", &r, &c);
			Task();
			cout << flag << endl;
		}
	}
	return 0;
}

// 1000000000000000000s 10
