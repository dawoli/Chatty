#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, a[N], mp[N], res[N], cnt = 0, sum = 0, temp = 0;

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (mp[a[i]] == 0) res[++cnt] = a[i];
		mp[a[i]]++;
	}
	sort(res + 1, res + cnt + 1);
	for (int i = cnt; i >= 2; i--)
	{
		if (mp[res[i]] >= mp[res[i - 1]])
		{
			temp += mp[res[i]] - mp[res[i - 1]];
			sum += mp[res[i - 1]];
			mp[res[i]] -= mp[res[i - 1]];
		}
		else
		{
			mp[res[i]] += temp;
			if (mp[res[i]] >= mp[res[i - 1]])
			{
				sum += mp[res[i - 1]];
				mp[res[i]] -= mp[res[i - 1]];
				temp += mp[res[i]];
			}
			else
			{
				temp = 0;
				sum += mp[res[i]];
				mp[res[i]] = 0;
			}
		}
	}
	cout << n - sum;
	return 0;
}
