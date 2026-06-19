#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10010
ll n,m,k,u,v,w,a[11][N],c,minw,minv,ans;
bool f[N];
struct node{
	ll v,w;
};
vector<int> vis;
vector<node> es[N];
bool cmp(node a,node b)
{
	return a.w < b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i = 1 ; i <= m ; i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		es[u].push_back((node){v,w});
		es[v].push_back((node){u,w});
	}
	for(int i = 1 ; i <= k ; i++)
	{
		scanf("%lld",&a[i][0]);
		for(int j = 1 ; j <= n ; j++) scanf("%lld",&a[i][j]);
	}
	f[1] = 1;
	c = 1;
	vis.push_back(1);
	while(c < n)
	{
		minw = INT_MAX;
		for(int i = 0 ; i < vis.size() ; i++)
		{
			for(int j = 0 ; j < es[vis[i]].size() ; j++)
			{
				if(es[vis[i]][j].w < minw && !f[es[vis[i]][j].v])
				{
					minw = es[vis[i]][j].w;
					minv = es[vis[i]][j].v;
				}
			}
		}
		vis.push_back(minv);
		c++;
		f[minv] = 1;
		ans += minw; 
	}
	printf("%lld\n",ans);
	return 0;
}
