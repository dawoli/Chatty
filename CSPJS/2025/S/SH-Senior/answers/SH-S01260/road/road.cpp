#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int N = 1000010;
struct node
{
	unsigned long long l,r,cost,con;
};
bool cmp(node a,node b)
{
	return a.cost < b.cost;	
}
vector <node> a; 

int b[N];
int fa[N];
int find(int x)
{
	if(fa[x] == x) return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
int con[12];
bool buy[12];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> m >> k;
	for(int t = 1;t <= m;t++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		a.push_back({u,v,w,0});
		fa[t] = t;
	}
	for(int t = 1;t <= k;t++)
	{
		int x;
		cin >> x;
		con[t] = x;
		for(int i = 1;i <= n;i++)
		{
			cin >> b[i];
			for(int j = 1;j < i;j++) if(x + b[i] + b[j] + t)
			{
				a.push_back({i,j,x + b[i] + b[j],t});
			}
		}
	}
	sort(a.begin(),a.end(),cmp);
	int cnt = 0;
	long long ans = 0;
	for(int t = 0;t < int(a.size());t++)
	{
		int u = find(a[t].l),v = find(a[t].r);
		if(u != v)
		{
			//cout << a[t].l << " " << a[t].r << " " << a[t].cost << endl; 
			cnt++;
			ans += a[t].cost;
			if(a[t].con != 0 && buy[a[t].con] == 1)
			{
				ans -= con[a[t].con];
			}
			else
			{
				buy[a[t].con] = 1;
			}
			fa[u] = v;
		}
	}
	cout << ans;
	return 0;	
}

