#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,en,fa[10010],c[20],a[20][10010][3];
int vis[20];
long long ans=0,ans1=0,cnt=0;
//int head[10010];
//struct EDGE
//{
//	int nxt,num,val;
//}e[1000010];
struct NODE
{
	int a,b,len,vis;
}ed[1000010],e[1000010];
int cmp(NODE x,NODE y)
{
	return x.len<y.len;
}
int findfa(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=findfa(fa[x]);
}
int f(long long num)
{
	long long sum=0;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			a[i][j][1]=1;
	for(int i=en;i>=1;i--)
	{
		for(int j=1;j<=k;j++)
		{
			if(vis[j]==1 && a[j][e[i].a][1]*a[j][e[i].a][0]+a[j][e[i].b][1]*a[j][e[i].b][0]<e[i].len)
			{
				sum+=a[j][e[i].a][1]*a[j][e[i].a][0]+a[j][e[i].b][1]*a[j][e[i].b][0]-e[i].len;
				a[j][e[i].a][1]=0,a[j][e[i].b][1]=0;
				e[i].vis=0;
			}
		}
	}
//	cout<<ans1<<" "<<sum<<" "<<num<<endl;
	ans=min(ans1+sum+num,ans);
	return 0;
}
int dfs(int now,long long num)
{
	if(now>k)
	{
		f(num);
		return 0;
	}
	if(c[now]!=0)
	{
		vis[now]=0;
		dfs(now+1,num);
	}
	if(c[now]+num<ans)
	{
		vis[now]=1;
		dfs(now+1,num+c[now]);
	}
	return 0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&ed[i].a,&ed[i].b,&ed[i].len);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j][0]);
		}
	}
	sort(ed+1,ed+n+1,cmp);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(findfa(ed[i].a)==findfa(ed[i].b))
			continue;
		ans+=ed[i].len;
		cnt++;
		e[++en].a=ed[i].a;
		e[en].b=ed[i].b;
		e[en].len=ed[i].len;
		fa[findfa(ed[i].a)]=ed[i].b;
		if(cnt==n-1)
		{
			break;
		}
	}
	ans1=ans;
	if(k==0)
	{
		printf("%lld",ans);
		return 0;
	}
//	for(int i=1;i<=en;i++)
//	{
//		cout<<e[i].a<<" "<<e[i].b<<" "<<e[i].len<<endl;
//	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
