#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int n,m,k;
long long ans=0;
int u[MAXN],v[MAXN],w[MAXN];
int a[11][10005],c[11];
int aa[10005+11][10005+11];
int fa[10005];
vector<int> vv;
int root(int x)
{
	if(root(x)==x)
		return x;
	return fa[x]=root(fa[x]);
}
void query(int x,int y)
{
	if(root(x)==root(y))
		return;
	fa[x]=fa[y];
}
void cal()
{
	while((int)vv.size()<n+k)
	{
		int dis=2e9,cnt=0,cnt2=0;
		for(int i=0;i<(int)vv.size();i++)
		{
			for(int j=1;j<=n+k-1;j++)
				if(root(j)!=root(vv[i])&&dis>aa[vv[i]][j])
					dis=aa[vv[i]][j],cnt=j,cnt2=i;
		}
		vv.push_back(cnt);
		query(vv[cnt2],cnt);
		ans+=dis;
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
		for(int j=1;j<=n+k;j++)
			aa[i][j]=2e9;
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i],aa[u[i]][v[i]]=aa[v[i]][u[i]]=w[i];
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j],aa[n+i][j]=aa[j][n+i]=a[i][j];
	}
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	vv.push_back(1);
	cal();
	return 0;
}
