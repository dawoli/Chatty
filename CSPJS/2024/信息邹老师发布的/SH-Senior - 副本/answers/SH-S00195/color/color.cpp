# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200010;
ll T, n, ans;
ll a[N];
ll col[N];

void DFS(ll now)
{
	if (now > n)
	{
		ll posa, posb, tmp;
		posa = posb = -1;
		tmp = 0;
		for (int i = 1; i <= n; i++)
		{
			if (col[i] == 0)
			{
				if (posa == -1) posa = i;
				else if (a[posa] == a[i]) tmp += a[posa];
				posa = i;
			}
			else
			{
				if (posb == -1) posb = i;
				else if (a[posb] == a[i]) tmp += a[posb];
				posb = i;
			}
		}
		ans = max(ans, tmp);
		return;
	}
	col[now] = 0;
	DFS(now + 1);
	col[now] = 1;
	DFS(now + 1);
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%lld", &T);
	while (T--)
	{
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		ans = 0;
		DFS(1);
		printf("%lld\n", ans);
	}
	return 0;
}
