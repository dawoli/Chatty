#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
int n,m,k;
struct node{
	int num;
	int u,v;
	long long w;
	friend bool operator <(const node s1,const node s2)
	{
		if(s1.w==s2.w)
		{
			return s1.u>=s2.u;
		}
		return s1.w>=s2.w;
	}
};
int uu[N]={0};
int vv[N]={0};
long long ww[N]={0}; 
priority_queue <node> pq;

long long mp[20][10010]={0};
long long c[20]={0};
int sng[20]={0};
int vtms[20]={0};
bool vis[10010]={0};
int fa[10020]={0};
node tmp[2000010]={0};
int fnd(int x)
{
	if(fa[x]!=x)
	{
		fa[x]=fnd(fa[x]);
	}
	return fa[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	node inn;
	for(int i=1;i<=m;i++)
	{
		inn.num=i;
		scanf("%d%d%lld",&inn.u,&inn.v,&inn.w);
		pq.push(inn);
		uu[i]=inn.u;
		vv[i]=inn.v;
		ww[i]=inn.w;
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",c+i);
		inn.u=n+i;
		fa[n+i]=n+i;
		for(int j=1;j<=n;j++)
		{
			inn.v=j;
			long long nw;
			scanf("%lld",&nw);
			inn.w=nw+c[i];
			pq.push(inn);
			mp[i][j]=inn.w;
		}
	}
	
	int lft=n;
	long long ans=0;
	while(!pq.empty())
	{
		node nw=pq.top();
		pq.pop();
		if(fnd(nw.u)==fnd(nw.v)) continue;
		if(nw.u>n&&vtms[nw.u-n]==0)
		{
			sng[nw.u-n]=nw.w;
			int cnt=0;
			while(!pq.empty())
			{
				cnt++;
				tmp[cnt]=pq.top();
				pq.pop();
			}
			for(int i=1;i<=cnt;i++)
			{
				if(tmp[i].u==nw.u)
				{
					tmp[i].w-=c[nw.u-n];
				}
				pq.push(tmp[i]);
			}
		}
		if(nw.u>n)
		{
			vtms[nw.u-n]++;
		 } 
		fa[fnd(nw.v)]=fa[fnd(nw.u)];
		ans+=nw.w;
	}
	for(int i=1;i<=k;i++)
	{
		if(vtms[i]==1)
		{
			ans-=sng[i];
		}
	}
	printf("%lld",ans);
	
	
	return 0;
}
