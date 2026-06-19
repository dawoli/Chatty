#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	int u,v,cos;
}rd[6000005];
ll n,m,k,uu,vv,w,a[15][10005],vis[10005],p[15],pro[15],minn,ans=1e18,mon[15],cnt,t,ok,minl,sum;
bool flag;
bool cmp(node c1,node c2)
{
	return c1.cos<c2.cos;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	flag=1;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&uu,&vv,&w);
		rd[i].u=uu;
		rd[i].v=vv;
		rd[i].cos=w;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&mon[i]);
		if(mon[i]!=0) flag=0;
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	ll id=m;
	if(flag)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
				{ 
					rd[++id].u=j;
					rd[id].v=k;
					rd[id].cos=a[i][j]+a[i][k];
				}
		}
	}
	sort(rd+1,rd+id+1,cmp);
	for(int i=1;i<=id;i++)
	{
		if(vis[rd[i].u]==0||vis[rd[i].v]==0)
		{
			vis[rd[i].u]=1;
			vis[rd[i].v]=1;
			cnt++;
			sum+=rd[i].cos;
		}
		if(cnt==n-1) break;
	}
	cout<<sum<<endl;
	return 0;
 } 
