#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int p[1000005];
int d[100005];
int v[100005];
int a[100005];
int tree[1000005];
int dp[1000005];
int head[1000005];
int nxt[100005];
int ev[100005];
int cnt;
inline void add(int u, int evv)
{
	cnt++;
	nxt[cnt] = head[u];
	head[u] = cnt;
	ev[cnt] = evv;
}
int ll;
inline int lowbit(int x)
{
	return x & (-x);
}
inline void modify(int k, int x)
{
	while (k)
	{
		tree[k] = min(tree[k],x);
		k-=lowbit(k);
	}
}
inline int query(int k)
{
	int result = 0x3f3f3f3f;
	while (k <= ll + 1)
	{
		result = min(result, tree[k]);
		k += lowbit(k);
	}
	return result;
}
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int tt;
	cin>>tt;
	while (tt-->0)
	{
		int n,m,vv;
		cin>>n>>m>>ll>>vv;
		ll++;
		memset(p, 0, sizeof(p));
		for (int i = 1; i <= n; i++)
		{
			cin >> d[i] >> v[i] >> a[i];
			d[i]++;
		}
		for (int i = 1; i <= m; i++)
		{
			int pp;
			cin >> pp;
			p[pp + 1]++;
		}
		for (int i = 1; i <= ll; i++)
		{
			p[i] += p[i - 1];
		}
		int result = 0;
		cnt = 0;
		memset(head, 0, sizeof(head));
		for (int i = 1; i <= n; i++)
		{
			if (a[i] < 0)
			{
				int l = d[i] - 1;
				int r = ll;
				while (r > l)
				{
					int mid = (l + r + 1) >> 1;
					if (v[i] * v[i] + 2 * a[i] * (mid - d[i]) > vv * vv)
					{
						l = mid;
					}
					else
					{
						r = mid - 1;
					}
				}
				//cout << l << endl;
				if (p[l] - p[d[i] - 1])
				{
					add(l, d[i]);
					result++;
				}
			}
			else
			{
				int l = d[i];
				int r = ll + 1;
				while (r > l)
				{
					int mid = (l + r) >> 1;
					if (v[i] * v[i] + 2 * a[i] * (mid - d[i]) > vv * vv)
					{
						r = mid;
					}
					else
					{
						l = mid + 1;
					}
				}
				if (p[ll] - p[r - 1])
				{
					add(ll, r);
					result++;
				}
			}
		}
		cout << result << ' ';
		int mxl = 0;
		memset(tree, 0x3f, sizeof(tree));
		modify(1, 0);
		for (int i = 1; i <= ll; i++)
		{
			if (p[i] > p[i - 1])
			{
				dp[i] = query(mxl + 1) + 1;
				modify(i + 1, dp[i]);
			}
			for (int j = head[i]; j; j = nxt[j])
			{
				int evv = ev[j];
				mxl = max(mxl, evv);
			}
		}
		result = 0x3f3f3f3f;
		if (!mxl)
		{
			cout << m << endl;
			continue; 
		}
		for (int i = mxl; i <= ll; i++)
		{
			if (p[i] > p[i - 1])
			{
				result = min(result, dp[i]);
			}
		}
		cout << m - result << endl;
	}
}

