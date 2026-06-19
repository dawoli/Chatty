#include <bits/stdc++.h>
using namespace std;
const int N=10005;
const int M=3000005;
int c[15],cw[15][N],arr[15],n,m,C;
int uu[M],vv[M],ww[M];
int anc[N];
typedef struct node
{
	int u,v,w;
	bool operator < (const struct node & t) const
	{
		return w>t.w;
	}
}NODE;
priority_queue<NODE> pq;
int get_anc(int x)
{
	return anc[x]=x==anc[x]?x:get_anc(anc[x]);
}
void union_set(int x,int y)
{
	anc[get_anc(y)]=get_anc(x);
}
int zxscs()
{
	int ans=0;
	for(int i=1;i<=n;i++) anc[i]=i;
	while(!pq.empty())
	{
		NODE t=pq.top(); pq.pop();
		int u=t.u,v=t.v,w=t.w;
		if(get_anc(u)==get_anc(v))
			continue;
		union_set(u,v);
		ans+=w;
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int u,v,w;
	scanf("%d %d %d",&n,&m,&C);
	for(int i=1;i<=m;i++)
		scanf("%d %d %d",&uu[i],&vv[i],&ww[i]);
	int specialA=0;
	for(int i=1;i<=C;i++)
	{
		scanf("%d",&c[i]);
		specialA=max(specialA,c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&cw[i][j]);
			specialA=max(specialA,cw[i][j]);
		}
	}
	if(specialA==0)
	{
		cout<<0;
		return 0;
	}
	int ans=INT_MAX;
	for(int s=0;s<1<<C;s++)
	{
		int sum=0;
		for(int i=1;i<=C;i++)
			arr[i]=s&(1<<i-1);
		while(!pq.empty()) pq.pop();
		for(int i=1;i<=m;i++)
			pq.push(NODE{uu[i],vv[i],ww[i]});
		for(int i=1;i<=C;i++)
		{
			if(!arr[i]) continue;
			sum+=c[i];
			for(int u=1;u<n;u++)
				for(int v=u+1;v<=n;v++)
					pq.push(NODE{u,v,cw[i][u]+cw[i][v]});
		}
		ans=min(ans,zxscs()+sum);
	}
	cout<<ans;
	return 0;
}
