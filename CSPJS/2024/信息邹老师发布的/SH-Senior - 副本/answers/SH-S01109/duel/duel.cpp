#include <bits/stdc++.h>
using namespace std;
int n, a[100005], sum, hit;
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	sum = n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int cur = a[1], cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cur != a[i]) 
		{
			cur = i;
			break;
		}
		else hit++;
	}
	int c = a[cur];
	for (int i = cur; i <= n; i++)
	{
		if (c == a[i])
		{
			cnt++;
		}
		else
		{
			if (cnt > hit)
			{
				sum -= hit;
				hit = cnt;
				cnt = 0;
			}
			else if (cnt == hit)
			{
				sum -= hit;
				hit = cnt;
				cnt = 0;
			}
			else
			{
				hit = hit;
				sum -= cnt;
				cnt = 0;
			}
			cnt++;
			c = a[i];
			continue;
		}
	}
	if (cnt > hit)
	{
		sum -= hit;
		hit = cnt - hit;
		cnt = 0;
	}
	else if (cnt == hit)
	{
		sum -= hit;
		hit = 0;
		cnt = 0;
	}
	else
	{
		hit = cnt;
		sum -= cnt;
		cnt = 0;
	}
	cout << sum << endl;
	return 0;
}
