#include <bits/stdc++.h>
using namespace std;

int n, ans, cnt, box[100005], cal[100005];

int main()
{
	freopen ("duel.in", "r", stdin);
	freopen ("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int r;
		cin >> r;
		box[r]++;
	}
	for (int i = 1; i <= 1e5; i++)
		cal[++cnt] = box[i];
	for (int i = 1; i <= cnt; i++)
	{
		if (cal[i] > cal[i + 1])//可以杀的比杀人的多 
		{
			ans += cal[i + 1];
			cal[i + 1] += (cal[i] - cal[i + 1]);
			cal[i] = 0;
		}//这一波攻击的人用完了，剩下的给下一波人杀 
		else//杀人的多 
		{
			ans += cal[i];
			cal[i] = 0;
		}
	}
	cout << n - ans;
	return 0;
}

// 1. 14:48 : 通过所有样例 
