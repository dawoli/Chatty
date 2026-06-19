#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N = 1e5+9;
const ld EPS = 1e-6;
int n,m,l,lmt,d,v,a,p[N];
ld lpos[N],rpos[N];
struct Info {int l,r;} x[N];
bool operator < (const Info&a, const Info&b) {return a.r < b.r;}
void mian()
{
	scanf("%d%d%d%d", &n, &m, &l, &lmt);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d%d", &d, &v, &a);
		if (!a)
		{
			if (v > lmt) lpos[i] = d,rpos[i] = l;
			else lpos[i] = l,rpos[i] = 0;
		}
		else if (a > 0)
		{
			if (v > lmt) lpos[i] = d,rpos[i] = l;
			else if (v * v + 2 * a * (l - d) <= lmt * lmt) lpos[i] = l,rpos[i] = 0;
			else lpos[i] = d + (lmt * lmt - v * v) * 1. / (2 * a) + EPS,rpos[i] = l;
		}
		else
		{
			if (v <= lmt) lpos[i] = l,rpos[i] = 0;
			else lpos[i] = d,rpos[i] = d + (lmt * lmt - v * v) * 1. / (2 * a) - EPS;
		}
	}
	for (int j = 1; j <= m; ++j) scanf("%d", &p[j]);
	int k = 0;
	for (int i = 1; i <= n; ++i)
	{
		int l = lower_bound(p + 1, p + m + 1, lpos[i]) - p;
		int r = upper_bound(p + 1, p + m + 1, rpos[i]) - p - 1;
		if (l <= r) x[++k] = (Info){l, r};
	}
	sort(x + 1, x + k + 1);
	int cnt = 0,pre = -1;
	for (int i = 1; i <= k; ++i)
		if (pre < x[i].l) ++cnt,pre = x[i].r;
	printf("%d %d\n", k, m - cnt);
}
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) mian();
	return 0;
}