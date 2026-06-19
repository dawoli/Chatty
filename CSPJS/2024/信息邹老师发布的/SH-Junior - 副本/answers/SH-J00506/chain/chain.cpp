#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 2e5 + 5;
int t,n,k,q;
bool f[N][105],ans[N],cc[N];
struct Node{int i,j,s;}a[N];
struct Que{int id,r,c;}qu[N];
bool cmp(Que x,Que y){return x.r < y.r;}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> t;
	while (t--)
	{
		memset(f,0,sizeof(f));
		memset(ans,0,sizeof(ans));
		cin >> n >> k >> q;
		int cnt = 0;
		int ms = 0;
		for (int i = 1; i <= n; i++)
		{
			int l;
			cin >> l;
			for (int j = 1; j <= l; j++)
			{
				int s;
				cin >> s;
				a[++cnt] = {i,j,s};
				if (s == 1) f[cnt][1] = 1,ans[s] = 1;
				ms = max(ms,s);
			}
		}
		int mx = 0;
		for (int i = 1; i <= q; i++) cin >> qu[i].r >> qu[i].c,mx = max(mx,qu[i].r),qu[i].id = i;
		sort(qu + 1,qu + q + 1,cmp);
		int tmp = 1;
		for (int i = 2; i <= 2 * mx; i++)
		{
			int ss = 0;
			for (int j = 1; j <= ms; j++) ans[j] = 0;
			if (i % 2 == 0)
			{
				for (int j = 1; j <= cnt; j++)
				{
					if (a[j].j == 1) ss = 0;
					if (a[j].j > k) ss -= f[j - k][i - 1];
					if (ss) f[j][i] = 1,ans[a[j].s] = 1;
					if (f[j][i - 1]) ss++;
//					if (a[j].i != a[j - 1].i) cout << endl;
//					cout <<f[j][i] << " ";
				}	
			}
			else
			{
				for (int j = 1; j <= cnt; j++)
					for (int k = 1; k <= cnt; k++)
						if (a[k].i != a[j].i && a[j].s == a[k].s)
							f[j][i] |= f[k][i - 1],ans[a[j].s] |= f[j][i];
			}
			while (tmp <= q && 2 * qu[tmp].r <= i) cc[qu[tmp].id] = ans[qu[tmp].c],tmp++;
		}
		for (int i = 1; i <= q; i++) cout << cc[i] << endl;
	}
	return 0;
}
