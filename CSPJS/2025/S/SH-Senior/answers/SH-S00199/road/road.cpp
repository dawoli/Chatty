#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace IO
{
	char buf[1<<16],*p1,*p2,ibuf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,sizeof(buf),stdin)),p1==p2?EOF:*p1++)
	int rd(int x=0,int f=1)
	{
		for(;!isdigit(ibuf);ibuf=getchar())if(ibuf=='-')f=-1;
		for(;isdigit(ibuf);ibuf=getchar())x=x*10+(ibuf^48);
			return x*f;
	}
}
using IO::rd;
int u[1100100],v[1100100],w[1100100];
int e[12][10100],ec[12];
int o[12][10100],oc[12];
int c[12];
int n,m,k;
int p[1100100];
int pa[10100];
int find(int x)
{
	return pa[x]==x?x:pa[x]=find(pa[x]);
}
bool con(int x,int y)
{
	return find(x)==find(y);
}
void uni(int x,int y)
{
	pa[find(x)]=find(y);
}
void init()
{
	for(int i=1;i<=n+k;i++)pa[i]=i;
}
int ans=1e18;
void dfs(int x,int sum=0)
{
	if(x==k+1)
	{
		int res=sum;
		for(int i=0;i<ec[x];i++)
		{
			int j=e[x][i];
			sum+=w[j];
		}
		ans=min(ans,sum);
		// cout<<sum<<' '<<res<<endl;
		// for(int i=0;i<ec[x];i++)cout<<e[x][i]<<' ';cout<<endl;
		return;
	}
	ec[x+1]=ec[x];
	for(int i=0;i<ec[x];i++)e[x+1][i]=e[x][i];
	if(x)dfs(x+1,sum);
	ec[x+1]=0;
	int p1=0,p2=0;
	init();
	while(p1<ec[x]||p2<oc[x])
	{
		int A=e[x][p1],B=o[x][p2];
		int i=-1;
		if(p2==oc[x]||(p1!=ec[x]&&w[A]<w[B]))i=A,p1++;
		else i=B,p2++;
		if(con(u[i],v[i]))continue;
		uni(u[i],v[i]),e[x+1][ec[x+1]++]=i;
	}
	dfs(x+1,sum+c[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cout.tie(0);
	n=rd(),m=rd(),k=rd();
	for(int i=0;i<m;i++)u[i]=rd(),v[i]=rd(),w[i]=rd();
	int tot=m;
	for(int i=1;i<=k;i++)
	{
		c[i]=rd();
		for(int j=1;j<=n;j++)u[tot]=n+i,v[tot]=j,w[tot++]=rd();
	}
	for(int i=0;i<=k;i++)
	{
		int id=i;
		init();
		int l=m+i*n-n,r=m+i*n;
		if(i==0)l=0;
		for(int i=l;i<r;i++)p[i]=i;
		sort(p+l,p+r,[&](int x,int y){return w[x]<w[y];});
		for(int i=l;i<r;i++)
		{
			int j=p[i];
			if(con(u[j],v[j]))continue;
			uni(u[j],v[j]),o[id][oc[id]++]=j;
		}
	}
	// for(int i=0;i<=k;i++,cout<<endl)for(int j=0;j<oc[i];j++)cout<<o[i][j]<<' ';
	dfs(0);
	cout<<ans<<'\n';
}