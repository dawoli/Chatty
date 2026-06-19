#include <bits/stdc++.h>
using namespace std;
int father[10005],n,m,k,cnt,sum,c[15],a[10005][15],u[15];
struct road
{
	int u;
	int v;
	int w;
}r[1000015];
bool cmp(road x,road y)
{
	return x.w<y.w;
}
int find(int x)
{
	if (father[x]!=x) return find(father[x]);
	return father[x];
}
void unionn(int x,int y)
{
	x=find(x);
	y=find(y);
	if (x!=y) father[y]=x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
	{
		father[i]=i;
	}
	for (int i=1;i<=m;i++)
	{
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		r[i].u=uu;
		r[i].v=vv;
		r[i].w=ww;
	}
	for (int i=1;i<=k;i++)
	{
		cin>>c[i];
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=k;j++)
		{
			if (u[j]==1)
			{
				r[i].w=min(r[i].w,a[j][r[i].u]+a[j][r[i].v]);
			}
			else
			{ 
				if (r[i].w>=a[j][r[i].u]+a[j][r[i].v]+c[j])
				{
					r[i].w=a[j][r[i].u]+a[j][r[i].v]+c[j];
					u[j]=1;
				}
			}
		}
	}
	sort(r+1,r+m+1,cmp);
	int i=1;
	while (cnt<n-1)
	{
		if (find(r[i].u)!=find(r[i].v))
		{
			unionn(r[i].u,r[i].v);
			sum+=r[i].w;
			cnt++;
		}
		i++;
	}
	cout<<sum;
	return 0;
}
