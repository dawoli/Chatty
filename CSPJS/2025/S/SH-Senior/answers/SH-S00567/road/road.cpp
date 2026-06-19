#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int w,from,to,id;
}e[1000001];
int vis[1000001];
int n,m,k,c[11],a[11][10001],fa[10001];
long long ans=0,f[11];
int finds(int t)
{
	if(fa[t]==t)
	{
		return t;
	}
	return fa[t]=finds(fa[t]);
}
void build(int x,int y)
{
	x=finds(x);
	y=finds(y);
	if(x!=y)
	{
		fa[x]=y;
	}
	return;
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
void kruskal(int n,int m)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(cnt==n-1)
		{
			break;
		}
		if(finds(e[i].from)==finds(e[i].to))
		{
			continue;
		}
		ans+=e[i].w;
		build(e[i].from,e[i].to);
		cnt++;
		vis[i]=1;
	}
	return;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(vis,0,sizeof vis);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].from>>e[i].to>>e[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	kruskal(n,m);
	long long ansn=ans;
	for(int i=1;i<=k;i++)
	{
		f[i]=ans+c[i];
		for(int j=m;j>=1;j--)
		{
			if(vis[j])
			{
				vis[j]=0;
				f[i]-=e[j].w;
				fa[fa[e[j].from]]=e[j].from;
				fa[e[j].from]=e[j].from;
				fa[fa[e[j].to]]=e[j].to;
				fa[e[j].to]=e[j].to;
				int min1=0,min2=0;
				for(int r=1;r<=n;r++)
				{
					if(finds(r)==e[j].to)
					{
						if(min1==0)
						{
							min1=a[i][r];
						}
						else
						{
							min1=min(min1,a[i][r]);
						}
					}
					if(finds(r)==e[j].from)
					{
						if(min2==0)
						{
							min2=a[i][r];
						}
						else
						{
							min2=min(min2,a[i][r]);
						}
					}
				}
				if(min1+min2<e[j].w)
				{
					f[i]+=(min1+min2);
					break;
				}
				else
				{
					f[i]+=e[j].w;
				}
			}	
		}
		ansn=min(ansn,f[i]);
	}
	cout<<ansn<<endl;
	return 0;
}
