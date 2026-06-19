#include <bits/stdc++.h>
using namespace std;
int n, x[4];
bool vis[100005];
struct node
{
	int sat, num, id, m;
} cb[300005];
bool cmp(node x, node y)
{
	if(x.m != y.m) return x.m > y.m;
	else if(x.sat != y.sat) return x.sat > y.sat;
	return x.id < y.id;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		memset(vis, false, sizeof(vis));
		memset(x, 0, sizeof(x));
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			cb[i].sat = a, cb[n+i].sat = b, cb[n*2+i].sat = c;
			int mn = min(a, min(b, c));
			cb[i].m= a - mn, cb[n+i].m= b-mn, cb[i+n*2].m= c-mn;
			cb[i].num = i, cb[i+n].num = i, cb[i+2*n].num = i;
			cb[i].id = 1, cb[i+n].id = 2, cb[i+2*n].id = 3;
		}
		sort(cb+1, cb+n*3+1, cmp);
		int cnt = 0;
		for(int i = 1; i <= 3 * n; i++)
		{
			if(x[cb[i].id] >= n / 2) continue;
			if(vis[cb[i].num]==true) continue;
			vis[cb[i].num] = true;
			cnt += cb[i].sat;
			x[cb[i].id]++;
		}
		cout << cnt << endl;
	}
	return 0;
}
