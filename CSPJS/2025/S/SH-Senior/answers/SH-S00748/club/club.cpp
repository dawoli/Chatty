#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define ll long long
int t, n, num[4];
ll ans;
priority_queue <pair <ll, ll> > pq[4];
struct node
{
	ll val, id;
}a[100001][4];
bool cmp(int a, int b)
{
	return pq[a].size() > pq[b].size();
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> t; 
	while (t--)
	{
		ans = 0;
		num[1] = 1, num[2] = 2, num[3] = 3;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				cin >> a[i][j].val;
				a[i][j].id = j;
			}
			for (int j = 1; j <= 3; j++)
			{
				for (int k = j + 1; k <= 3; k++)
					if (a[i][j].val < a[i][k].val) 
						swap(a[i][j], a[i][k]);
			}
			node tp1 = a[i][1], tp2 = a[i][2], tp3 = a[i][3];
			pq[tp1.id].push({-tp1.val + tp2.val, i});
			ans += tp1.val;
		}
		sort(num + 1, num + 4, cmp);
		for (int c = 1; c <= 3; c++)
		{
			int i = num[c];
			while (pq[i].size() > n / 2)
			{
				pair <int, int> pi = pq[i].top();
				pq[i].pop();
				int j = pi.second;
				node tp1 = a[j][1], tp2 = a[j][2], tp3 = a[j][3];
				if (pq[tp2.id].size() < n / 2) pq[tp2.id].push({-tp2.val + tp3.val, j});
				else pq[tp3.id].push({-tp2.val + tp3.val, j});
				ans += -tp1.val + tp2.val;
			}
		}
		cout << ans << '\n';
		for (int i = 1; i <= 3; i++)
		{
			while (pq[i].size())
				pq[i].pop();
		}
	}
	return 0;
}
/*
uid 1020835
On 15:30
*/
