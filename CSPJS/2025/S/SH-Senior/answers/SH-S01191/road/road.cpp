#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18,B=9050;
long long res=0;
long long n,m,k,cnt=0,cp=0,prs=0;
long long c[15],fa[300005];
struct fp
{
	long long val,id;	
}a[15][300005];
bool cmp(fp x,fp y)
{
	return x.val<y.val;
}
struct node
{
	long long to,w;
};
vector<node>g[300005];
bool gp[300005];
long long find(long long x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(long long u,long long v,long long w)
{
	u=find(u),v=find(v);
	if(u!=v)
	{
		fa[u]=v;
		cp--;
		prs+=w;
	}
}
struct edge
{
	long long u,v,w;	
};
bool operator < (edge x,edge y)
{
	return x.w<y.w;
}
using ve=vector<edge>;
int main()
{
	freopen("road3.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m>>k;
	ve tmp;
	for(int i=1;i<=m;i++)
	{
		long long u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		tmp.push_back({u,v,w});
	}
	sort(tmp.begin(),tmp.end());
	ve cc;
	for(int i=0;i<=min(B+15,(long long)tmp.size()-1);i++)
	{
		cc.push_back(tmp[i]);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j].val;
			a[i][j].id=j;
		}
		sort(a[i]+1,a[i]+n+1,cmp);
	}
	long long ans=INF;
	for(int i=0;i<=(1ll<<k)-1;i++)
	{
		prs=0;
		cnt=0;
		for(int j=1;j<=n+k+2;j++)
		{
			fa[j]=j;
		}
		for(int j=0;j<=k+1;j++)
		{
			gp[j]=0;
		}
		for(int j=0;j<=k-1;j++)
		{
			if((i>>j)&1) cnt++,gp[j+1]=1;
		}
		cp=n+cnt;
		long long cur=0,cost=0;
		ve res=cc;
		for(int j=1;j<=k;j++)
		{
			if(gp[j])
			{
				cost+=c[j];
				ve v=res;
				res.clear();
				long long vl=(long long)v.size();
				long long pt=1,pt1=0,pt2=1,ub=min(B,vl+n);
				while(pt<=ub&&pt1<=min(vl,B))
				{
					bool flag=0;
					while(pt<=ub&&pt2<=min(n,B)&&a[j][pt2].val<=v[pt1].w)
					{
						pt++;
						res.push_back({n+j,a[j][pt2].id,a[j][pt2].val});
						if(pt>ub)
						{
							flag=1;
							break;
						}
						pt2++;
					}
					if(flag)
					{
						break;
					}
					if(pt>ub)
					{
						break;
					}
					pt++;
					res.push_back({v[pt1].u,v[pt1].v,v[pt1].w});
					if(pt>ub)
					{
						break;
					}
					pt1++;
				}
				cur++;
			}
		}
		bool flag=0;
		long long cc=0;
		for(auto now:res)
		{
			cc++;
			merge(now.u,now.v,now.w);
			if(cp==1)
			{
				flag=1;
				break;
			}
		}
		if(flag) ans=min(ans,cost+prs);
	}
	cout<<ans<<endl;
	return 0;
}
