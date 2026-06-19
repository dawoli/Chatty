#include<bits/stdc++.h>
#define int long long
#define ll long long
#define db long long
using namespace std;
const int N=1e5,K=10,M=1e6,inf=1e17;
int n,m,k,ans=0;
int ans1=inf;
int a[K+5];
int b[K+5][N+10];
struct node2
{
	int x,y,z;
	bool operator< (const node2 &nnn) const
	{
		return z<nnn.z;
	}
} edge[M+N*K+10],e[M+N*K+10];
int cnt=0;
void add2(int x,int y,int z)
{
	node2 pu;
	pu.x=x,pu.y=y,pu.z=z;
	edge[++cnt]=pu;
	return;
}
int fa[N+K+10];
int find(int z)
{
	if(fa[z]==z) return z;
	return fa[z]=find(fa[z]);
}
int now=0;
void kruskal()
{
	for(int i=1;i<=n+now;i++) fa[i]=i;
	for(int i=1;i<=cnt;i++) e[i]=edge[i];
	sort(e+1,e+cnt+1);
	for(int i=1;i<=cnt;i++)
	{
		int x=e[i].x,y=e[i].y,z=e[i].z;
		x=find(x); y=find(y);
		if(x==y) continue;
		ans+=z;
		fa[x]=y;
	}
	return;
}
int suma=0;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%lld %lld %lld",&x,&y,&z);
		add2(x,y,z);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a[i]; suma+=a[i];
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&b[i][j]);
			add2(n+i,j,b[i][j]);
		}
	}
	if(suma==0)
	{
		now=k;
		kruskal();
		cout<<ans;
		return 0;
	}
	cnt=m;
	for(int i=0;i<(1<<k);i++)
	{
		cnt=m;
		now=0;
		ans=0;
		for(int j=1;j<=k;j++)
		{
			if(i&(1<<(j-1)))
			{
				now++;
				for(int K=1;K<=n;K++)
				{
					add2(n+now,K,b[j][K]);
				}
				ans+=a[j];
			}
		}
		kruskal();
//		cout<<ans<<endl;
		ans1=min(ans1,ans);
	}
	cout<<ans1;
	return 0;
}
