#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

const int MXN = 1e5 + 5;
double p[MXN],d[MXN],v[MXN],a[MXN];
struct node
{
	int l = MXN,r = 0;
	bool overspeed = false;
} pt[MXN];

bool cmp(node x,node y)
{
	if (x.overspeed != y.overspeed) return x.overspeed;
	return x.r < y.r;
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin >> t;
	while (t--)
	{
		int n,m,ll,vv;
		cin >> n >> m >> ll >> vv;
		for (int i = 1;i <= n;i++)
		{
			pt[i].l = MXN,pt[i].r = 0;
			pt[i].overspeed = false;
		}
		for (int i = 1;i <= n;i++)
		{
			cin >> d[i] >> v[i] >> a[i];
		}
		for (int i = 1;i <= m;i++)
		{
			cin >> p[i];
		}
		int ans1 = 0,ans2 = 0;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= m;j++)
			{
				if (p[j] < d[i]) continue;
				double v1 = v[i] * v[i] + 2 * a[i] * (p[j] - d[i]);
				if (v1 < 0) break;
				v1 = sqrt(v1);
				if (v1 > vv)
				{
					pt[i].l = min(pt[i].l,j);
					pt[i].r = max(pt[i].r,j);
					if (!pt[i].overspeed)
					{
						pt[i].overspeed = true;
						ans1++;
					}
				}
			}
		}
		sort(pt + 1,pt + n + 1,cmp);
		int stt = 1;
		ans2 = 1;
		for (int i = 1;i <= n;i++)
		{
//			cout << pt[i].l << " " << pt[i].r << endl;
			if (pt[i].l > pt[stt].r && pt[i].overspeed)
			{
				stt = i;
				ans2++;
			}
		}
		if (ans1 == 0) ans2 = 0;
		cout << ans1 << " " << m - ans2 << endl;
	}
	return 0;
}
