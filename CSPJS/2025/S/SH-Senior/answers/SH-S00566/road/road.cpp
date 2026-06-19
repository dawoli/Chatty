#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 15,M = 25,X = 1e6 + 15;
int n,m,k,c[M],a[M][N],cnt,f[N],ans = 1e18;
struct Node{int u,v,w;}e[X],s[X];
bool cmp(Node a,Node b) {return a.w < b.w;}
int find(int x)
{
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}
void merge(int x,int y)
{
//	cout << x << " " << y << endl;
//	x = find(x); y = find(y);
//	if (x == y) return ;
	f[x] = y;
}
int read()
{
	int ret = 0; char c = ' ';
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') ret = ret * 10 + c - '0',c = getchar();
	return ret;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	n = read(); m = read(); k = read(); 
//	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) e[i].u = read(),e[i].v = read(),e[i].w = read(); 
	sort(e + 1,e + m + 1,cmp);
	for (int i = 1; i <= k; i++)
	{
		c[i] = read();
		for (int j = 1; j <= n; j++) a[i][j] = read();
	}
	for (int i = 0; i < (1 << k); i++)
	{
		for (int i = 1; i <= n + k; i++) f[i] = i;
		cnt = 0;
		int num = 0,ff = 0;
		for (int j = 1; j <= k; j++)
			if (i & (1 << j - 1))
			{
				num += c[j];
				ff--;
				for (int l = 1; l <= n; l++) s[++cnt] = {n + j,l,a[j][l]};
			}
		sort(s + 1,s + cnt + 1,cmp);
		int p = 1; bool co = 0;
		for (int j = 1; j <= cnt; j++)
		{
			while (p <= m && e[p].w < s[j].w)
			{
				int aa = find(e[p].u),bb = find(e[p].v);
				if (aa != bb)
				{
//					cout << e[p].u << " " << e[p].v << endl;
					merge(aa,bb);
					num += e[p].w;
					ff++;
					if (ff == n - 1)
					{
						co = 1;
						break;
					}
				}
				p++;
			}
			if (co) break;
			int aa = find(s[j].u),bb = find(s[j].v);
			if (aa != bb)
			{
//				cout << s[j].u << " " << s[j].v << endl;
				merge(aa,bb);
				num += s[j].w;
				ff++;
				if (ff == n - 1)
				{
					co = 1;
					break;
				}
			}
		}
		if (!co)
		{
			while (p <= m)
			{
				int aa = find(e[p].u),bb = find(e[p].v);
				if (aa != bb)
				{
	//				cout << e[p].u << " " << e[p].v << endl;
					merge(aa,bb);
					num += e[p].w;
					ff++;
					if (ff == n - 1)
					{
						co = 1;
						break;
					}
				}
				p++;
			}
		}
		ans = min(ans,num);
//		cout << bitset<3>(i) << " " << num << endl;
	}
	cout << ans;
	return 0;
}
