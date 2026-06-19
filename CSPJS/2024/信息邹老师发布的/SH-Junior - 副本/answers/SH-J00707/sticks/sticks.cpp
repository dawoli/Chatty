#include <iostream>
#include <stdio.h>
using namespace std; 

int t, n;
long long mini;
bool flag;
int lb[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

void DFS(int rest, long long num)
{
	if (num >= mini)
	{
		return;
	}
	if (rest == 0)
	{
		flag = true;
		mini = num;
		return;
	}
	if (rest < 2)
	{
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (rest < lb[i] || num == 0 && i == 0)
		{
			continue;
		}
		DFS(rest - lb[i], num * 10 + i);
	}
}

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		mini = 1e18;
		flag = false;
		DFS(n, 0);
		if (flag)
		{
			cout << mini << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}

// 1s 60
