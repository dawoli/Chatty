#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct interval
{
	int l, r;
};

const int Maxn = 100005;

int n, m, l, maxv;
int d[Maxn], v0[Maxn], a[Maxn];
interval iv[Maxn];
int stop[Maxn];
bool vis[Maxn], vis2[Maxn];

bool cmp(interval x, interval y);


int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> l >> maxv;
		for (int i = 1; i <= n; i++)
		{
			cin >> d[i] >> v0[i] >> a[i];
			if (v0[i] <= maxv && a[i] <= 0)
			{
				iv[i].l = iv[i].r = -1;
			}
			else if (v0[i] <= maxv && a[i] > 0)
			{
				long double s = double(maxv * maxv - v0[i] * v0[i]) / double(2 * a[i]);
				int si = ceil(s);
				if (s == si)
					si++;
				if (d[i] + si > l)
					iv[i].l = iv[i].r = -1;
				else
				{
					iv[i].l = d[i] + si; iv[i].r = l;
				}
			}
			else if (v0[i] > maxv && a[i] >= 0)
			{
				iv[i].l = d[i]; iv[i].r = l;
			}
			else
			{
				long double s = double(v0[i] * v0[i] - maxv * maxv) / double(2 * abs(a[i]));
				int si = floor(s);
				if (s == si)
					si--;
				if (d[i] + si > l)
					si = l - d[i];
				iv[i].l = d[i]; iv[i].r = d[i] + si;
			}
		}
		
		for (int i = 1; i <= m; i++)
			cin >> stop[i];
		
		int ans = 0;
		if (n > 20)
		{
			sort(stop + 1, stop + m + 1);
			for (int i = 1; i <= n; i++)
				if (iv[i].l <= stop[m] && stop[m] <= iv[i].r)
					ans++;
			cout << ans << ' ';
		}
		else
		{	
			memset(vis, 0, sizeof(vis));
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					if (iv[i].l <= stop[j] && stop[j] <= iv[i].r)
					{
						vis[i] = true;
						break;
					}
			
			memset(vis2, 0, sizeof(vis2));
			for (int i = 1; i <= n; i++)
			{
				if (vis[i])
					ans++;
				else
					vis2[i] = true;
			}
			cout << ans << ' ';
		}
		
		if (n > 20)
			cout << m - (ans > 0 ? 1 : 0) << '\n';
		else
		{
			for (int i = 0; i < (1 << m); i++)
			{
				memset(vis, 0, sizeof(vis));
				for (int j = 0; j < m; j++)
					if (i & (1 << j))
						for (int k = 1; k <= n; k++)
							if (iv[k].l <= stop[j + 1] && stop[j + 1] <= iv[k].r)
								vis[k] = true;
				
				bool flag = true;
				for (int j = 1; j <= n; j++)
				{
					if (!vis[j] && !vis2[j])
					{
						flag = false;
						break;
					}
				}
				
				if (flag)
				{
					ans = 0;
					for (int j = 0; j < m; j++)
						if (i & (1 << j))
							ans++;
					cout << m - ans << '\n';
					break;
				}
			}
		}
	}
	
	return 0;
}


bool cmp(interval x, interval y)
{
	return x.l < y.l;
}

