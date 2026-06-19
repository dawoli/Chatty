#include <bits/stdc++.h>
using namespace std;

int t;
struct Node
{
	int d, v, a;
	int in, out;
};
int b[1000001];
int p[100001];
Node a[100001];

int c[100001];
Node d[100001];

int main()
{
	
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0); 
	cin >> t;
	while(t--)
	{
		int n, m, l, vmax;
		int ans = 0, cnt = 0;
		for (int i = 0; i < 1000000; i++)
		{
			b[i] = 0;
		}
		for (int i = 0; i < 100000; i++)
		{
			p[i] = 0;
			c[i] = 0;
			d[i].in = 0;
			d[i].out = 0;
		}
		cin >> n >> m >> l >> vmax;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].d >> a[i].v >> a[i].a;
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> p[i];
			b[p[i]] = -1;
		}
		sort(p+1, p+m+1);
		for (int i = 1; i <= n; i++)
		{
			if (a[i].a == 0)
			{
				if (a[i].v > vmax)
				{
					a[i].in = a[i].d;
					a[i].out = l;
				}
				else
				{
					a[i].in = 0;
					a[i].out = -1;
				}
			}
			if (a[i].a > 0)
			{
				if (a[i].v > vmax)
				{
					a[i].in = a[i].d;
					a[i].out = l;
				}
				else if (a[i].v == vmax)
				{
					a[i].in = a[i].d + 1;
					a[i].out = l;
				}
				else
				{
					int x = (vmax*vmax - a[i].v*a[i].v) / 2 / a[i].a;
					a[i].in = a[i].d + x + 1;
					a[i].out = l;
				}
			}
			if (a[i].a < 0)
			{
				if (a[i].v > vmax)
				{
					double xd = (vmax*vmax - a[i].v*a[i].v) / 2.0 / a[i].a;
					int x = (vmax*vmax - a[i].v*a[i].v) / 2 / a[i].a;
					if (xd == x)	x--;	
					
					a[i].in = a[i].d;
					a[i].out = a[i].d + x;
				}
				else
				{
					a[i].in = 0;
					a[i].out = -1;
				}
			}
		}
//		for (int i = 1; i <= n; i++)
//		{
//			cout << a[i].in << " " << a[i].out << endl;
//		}
//		for (int i = 1; i <= m; i++)
//		{
//			cout << p[i] << endl;
//		}
		
		for (int i = 1; i <= n; i++)
		{
			if (a[i].in <= a[i].out && a[i].in <= p[m])
			{
				ans++;
			}
		}
		if (ans == 0)
			cout << ans << " " << m << endl;
		else
			cout << ans << " " << m - 1 << endl;
		
	}
	return 0;
}
