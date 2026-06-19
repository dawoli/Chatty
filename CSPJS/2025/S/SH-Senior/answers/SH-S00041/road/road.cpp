#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m,k,fa[10005];
ll sum;
struct edge
{
	int u,v,w;
}e[1100005];
int find(int k)
{
	if(fa[k]==k)
		return k;
	return fa[k]=find(fa[k]);
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++)
	{
		int c;cin>>c;
		if(c==0)
		{
			int a[10005],a0;
			for(int j=1;j<=n;j++)
			{
				cin>>a[j];
				if(a[j]==0)
					a0=j;
			}
			for(int j=1;j<=n;j++)
			{
				if(j==a0)
					continue;
				e[++m].u=a0;
				e[m].v=j;
				e[m].w=a[j];
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
				cin>>c;
		}
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv)
		{
			fa[fu]=fv;
			sum+=e[i].w;
		}
	}
	cout<<sum<<"\n";
	return 0;
}

