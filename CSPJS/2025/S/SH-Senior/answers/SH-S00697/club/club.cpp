#include <bits/stdc++.h>
using namespace std;

//ni shi pian fen da shi, dui bu dui?
bool flag1 = 1, flag2 = 1;

struct Node
{
	int num[4];
}a[200010];

int n;

int ans = -1e8;

void dfs(int sum, int cur[], int step)
{
	if (step > n)
	{
		ans = max(ans, sum);
		return;
	}
	if (flag2 == 1)
	{
		for (int i = 1; i <= 2; i++)
		{
			if (cur[i] == n / 2) continue;
			cur[i]++;
			dfs(sum + a[step].num[i], cur, step + 1);
			cur[i]--;
		}
	}
	else
	{
		for (int i = 1; i <= 3; i++)
		{
			if (cur[i] == n / 2) continue;
			cur[i]++;
			dfs(sum + a[step].num[i], cur, step + 1);
			cur[i]--;
		}
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		ans = 0;
		int cur[4] = {0, 0, 0, 0};
		int pianfen = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].num[1] >> a[i].num[2] >> a[i].num[3];
			if (a[i].num[2] != 0 || a[i].num[3] != 0) flag1 = 0;
			if (a[i].num[3] != 0) flag2 = 0;
			pianfen += a[i].num[1];
		}
		if (flag1 == 1)
		{
			cout << pianfen << endl;
			return 0;
		}
		dfs(0, cur, 0);
		cout << ans << endl;
	}
	return 0;
}
