#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int t, n, ans;
int a[N];
bool b[N];

int get()
{
	int p1 = 0, p2 = 0, res = 0;
	for (int i = 1; i <= n; i++)
	{
		if (b[i])
		{
			if (a[p1] == a[i])
			{
				res += a[i];
			}
			p1 = i;
		}
		else
		{
			if (a[p2] == a[i])
			{
				res += a[i];
			}
			p2 = i;
		}
	}
	return res;
}

void dfs(int x)
{
	if (x > n)
	{
		ans = max(ans, get());
		return;
	}
	b[x] = 0;
	dfs(x + 1);
	b[x] = 1;
	dfs(x + 1); 
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--)
	{
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}
