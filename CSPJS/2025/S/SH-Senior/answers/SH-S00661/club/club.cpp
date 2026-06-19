#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 1e5 + 10;

struct node
{
	int d[5];
} a[N];

int t, n;

int get_max(node x)
{
	if (x.d[1] >= x.d[2] && x.d[1] >= x.d[3])
	{
		return 1;
	}
	if (x.d[2] >= x.d[1] && x.d[2] >= x.d[3])
	{
		return 2;
	}
	if (x.d[3] >= x.d[1] && x.d[3] >= x.d[2])
	{
		return 3;
	}
}

int get_max2(node x)
{
	int mx = get_max(x);
	if (mx == 1)
	{
		return (x.d[2] >= x.d[3]) ? 2 : 3;
	}
	if (mx == 2)
	{
		return (x.d[1] >= x.d[3]) ? 1 : 3;
	}
	if (mx == 3)
	{
		return (x.d[1] >= x.d[2]) ? 1 : 2;
	}
}

bool cmp(node x, node y)
{
	return x.d[get_max(x)] - x.d[get_max2(x)] > y.d[get_max(y)] - y.d[get_max2(y)];
}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].d[1] >> a[i].d[2] >> a[i].d[3];
	}
	sort(a + 1, a + n + 1, cmp);
	int cnt[5] = {0};
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int mx1 = get_max(a[i]), mx2 = get_max2(a[i]);
		if (cnt[mx1] == n / 2)
		{
			cnt[mx2]++;
			ans += a[i].d[mx2];
		}
		else
		{
			cnt[mx1]++;
			ans += a[i].d[mx1];
		}
	}
	cout << ans << endl;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
} 
