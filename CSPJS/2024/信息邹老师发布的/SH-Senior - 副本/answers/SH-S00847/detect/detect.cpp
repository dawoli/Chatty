#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

const int NR = 1e5 + 10;

int d[NR] , v[NR] , a[NR] , p[NR] , n , m , l , lim , ans;
bool f[NR] , chk[NR] , isclose[NR];

int cal(int vv , int aa , int dis)
{
	return sqrt(1ll * vv * vv + 2ll * aa * dis) - 1e-6;
}

bool check()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = lower_bound(p + 1 , p + m + 1 , d[i]) - p; j <= m; j++)
		{
			if (f[j]) continue;
			if (cal(v[i] , a[i] , p[j] - d[i]) > lim)
			{
				chk[i] = true;
				break;
			}
		}
		if (f[i] != chk[i]) return false;
	}
	return true;
}

void dfs(int st , int close)
{
	if (n - st + close + 1 <= ans) return;
	if (st > m)
	{
		if (check()) ans = close;
		return;
	}
	isclose[st] = true;
	dfs(st + 1 , close + 1);
	isclose[st] = false;
	dfs(st + 1 , close);
}

int main()
{
	freopen("detect.in" , "r" , stdin);
	freopen("detect.out" , "w" , stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int mx = -1e9 , mn = 1e9 , cnt = 0;
		scanf("%d%d%d%d" , &n , &m , &l , &lim);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d" , &d[i] , &v[i] , &a[i]);
			mx = max(mx , a[i]);
			mn = min(mn , a[i]);
		}
		for (int i = 1; i <= m; i++)
		{
			scanf("%d" , &p[i]);
		}
		if (mn >= 0)
		{
			int cnt = 0 , ans = m;
			for (int i = 1; i <= n; i++)
			{
				if (d[i] <= p[m] && cal(v[i] , a[i] , p[m] - d[i]) >= lim) cnt++;
			}
			if (cnt != 0) ans--;
			printf("%d %d\n" , cnt , ans);
		}
		else if (m <= 20 && n <= 20)
		{
			ans = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = lower_bound(p + 1 , p + m + 1 , d[i]) - p; j <= m; j++)
				{
					if (cal(v[i] , a[i] , p[j] - d[i]) > lim)
					{
						f[i] = true;
						cnt++;
						break;
					}
				}
			}
			dfs(2 , 0);
			cout << cnt << " " << ans << endl;
		}
	}
	return 0;
}