#include <bits/stdc++.h>
using namespace std;
int d[10005];
int fi(int x)
{
	if (d[x]==x)	return x;
	return d[x]=fi(d[x]);
}
struct node
{
	int u,v,w;
} bian[10000005];
int xz[15][10005];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m,k;
	cin>>n>>m>>k;
	int cur=0;
	for (int i=1;i<=n;i++)
	{
		d[i]=i;
	}
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		node temp;
		temp.u=u;
		temp.v=v;
		temp.w=w;
		bian[++cur]=temp;
	}
	for (int i=1;i<=k;i++)
	{
		int p;
		cin>>p;
		for (int j=1;j<=n;j++)
		{
			int p2;
			cin>>p2;
			xz[i][j]=p2;
		}
		for (int j=1;j<n;j++)
		{
			for (int kk=j+1;kk<=n;kk++)
			{
				node temp;
				temp.u=j;
				temp.v=kk;
				temp.w=xz[i][j]+xz[i][kk];
				bian[++cur]=temp;
			}
		}
	}
	int cha=n-1,sum=0;
	sort(bian+1,bian+cur+1,cmp);
	for (int i=1;i<=cur;i++)
	{
		if (fi(bian[i].u)!=fi(bian[i].v))
		{
			d[fi(bian[i].u)]=d[fi(bian[i].v)];
			cha--;
			sum+=bian[i].w;
		}
		if (cha==0)	break;
	}
	cout<<sum<<'\n';
	return 0;
}

