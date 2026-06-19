#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5 + 5;
int t,n,m,l,v,d[N],s[N],a[N],p[N],li[N],ri[N],nl[N],nr[N];
bool ls[N];
struct Node{int l,r;}ii[N];
int read()
{
	int ret = 0,f = 1;
	char x = ' ';
	while (x < '0' || x > '9') x = getchar(),f *= (x == '-'? -1:1);
	while (x >= '0' && x <= '9') ret = ret * 10 + x - '0',x = getchar();
	return f * ret; 
}
bool cmp(Node x,Node y) {return x.l < y.l;}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		memset(ls,0,sizeof(ls));
		n = read(); m = read(); l = read(); v = read();
//		scanf("%d %d %d %d",&n,&m,&l,&v);
		int cntz = 0;
		for (int i = 1; i <= n; i++) d[i] = read(),s[i] = read(),a[i] = read()/*scanf("%d %d %d",&d[i],&s[i],&a[i])*/,cntz += (a[i] == 0);
		for (int i = 1; i <= m; i++) p[i] = read();
		if (cntz == n)
		{
			int ans = 0,minn = INT_MAX;
			for (int i = 1; i <= n; i++)
				if (s[i] > v)
					ans += (d[i] <= p[m]);
			if (ans == 0) printf("%d %d\n",ans,m);
			else printf("%d %d\n",ans,m - 1);
			continue;
		}
		int ans1 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 0)
			{
				if (s[i] > v)
				{
					int lid = lower_bound(p + 1,p + m + 1,d[i]) - p;
					ii[i].l = lid,ii[i].r = m;
					if (lid <= m) ls[i] = 1,ans1++;
					else ii[i].l = ii[i].r = INT_MAX;
				}
				else ii[i].l = ii[i].r = INT_MAX;
				continue;
			}
			int w = (v * v - s[i] * s[i]) / (2 * a[i]);
			int c = d[i] + w;
			ii[i].l = ii[i].r = INT_MAX;
//			cout << i << " " << c << " " << w << " " << ans1 << endl;
			if (a[i] < 0 && w < 0) continue;
			if (a[i] > 0 && c > l) continue;
			if (a[i] > 0)
			{
				c = max(d[i] - 1,c);
				if ((v * v - s[i] * s[i]) % (2 * a[i]) != 0 && c == l) continue;
				int lid = upper_bound(p + 1,p + m + 1,c) - p;
				ii[i].l = lid; ii[i].r = m;
//				cout << lid << " " << m << endl;
				if (lid <= m) ls[i] = 1,ans1++;
				else ii[i].l = ii[i].r = INT_MAX;
			}
			else
			{
				if (v * v - s[i] * s[i] >= 0 && w == 0) continue;
//				if ((v * v - s[i] * s[i]) % (2 * a[i]) != 0 && w == 0) continue;
				int lid = lower_bound(p + 1,p + m + 1,d[i]) - p;
				int rid = lower_bound(p + 1,p + m + 1,c) - p - 1;
				if ((v * v - s[i] * s[i]) % (2 * a[i]) != 0) rid = upper_bound(p + 1,p + m + 1,c) - p - 1;
				ii[i].l = lid; ii[i].r = rid;
				if (lid <= rid) ls[i] = 1,ans1++;
				else ii[i].l = ii[i].r = INT_MAX;
			}
		}
		sort(ii + 1,ii + n + 1,cmp);
		int ans2 = 0;
		priority_queue<int> q;
		while (!q.empty()) q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (ii[i].l == INT_MAX) break;
			if (!q.empty() && ii[i].r <= q.top())
			{
				q.pop();
				q.push(ii[i].r);
			}
			else if (q.empty() || q.top() < ii[i].l)
			{
				ans2++;
				q.push(ii[i].r);
			}
		}
		printf("%d %d\n",ans1,m - ans2);
	}
	return 0;
}
//1
//9 10 158022 5
//65435 666 -3
//1342 672 -2
//10867 862 -8
//110389 708 -9
//1709 920 -8
//130502 291 626
//80612 947 -10
//48629 783 -3
//107502 903 -10
//15014 53560 78649 88021 91322 104253 111591 117138 138176 152757
