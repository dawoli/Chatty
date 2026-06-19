#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=10005,M=1000006;
ll n,m,k,ans,id[N],c[N],a[N][N];
struct edge
{
	ll to,frm,cost;
}e[M];
map<ull,ll>mm;
bool cmp(const edge&a,const edge&b)
{
	return a.cost<b.cost;
}
ll find(ll i)
{
	return id[i]=i?id[i]:id[i]=find(id[i]);
}
void kruskal()
{
	ans=0;
	ll cnt=0;
	sort(e+1,e+1+m,cmp);
	for(ll i=1;i<=n;i++)
		id[i]=i;
	for(ll i=1;i<=m;i++)
	{
		ll rx=find(e[i].to),ry=find(e[i].frm);
		if(rx==ry)continue;
		ans+=e[i].cost;
		cnt++;
		id[rx]=ry;
		if(cnt==n-1)
		{
			cout<<ans<<endl;
			return;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll i,j;
	bool flagA=true;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		cin>>e[i].to>>e[i].frm>>e[i].cost;
		unsigned long long x;
		x=e[i].to*N*2+e[i].frm;
		mm[x]=i;
		cout<<x<<endl;
	}
	for(i=1;i<=k;i++)
	{
		cin>>c[i];
		if(flagA&&c[i]!=0)
			flagA=false;
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
			a[j][i]=a[i][j];
		}
	}
	if(k==0)
		kruskal();
	else if(flagA)
	{
		for(i=1;i<=m;i++)
			if(e[i].to<=k||e[i].frm<=k)
				if(a[e[i].to][e[i].frm]<e[i].cost)						
					e[i].cost=a[e[i].to][e[i].frm];
		kruskal();
	}
	else
	{
		bool flag=true;
		for(i=1;i<=k;i++)
		{
			for(j=1;j<=n;j++)
			{
				ull t=i*N+j;
				if(e[mm[t]].cost>0&&e[mm[t]].cost<c[i]+a[i][j])
					flag=false;
			}
			if(flag)
			{
				ans+=c[i];
				for(j=1;j<=n;j++)
				{
					ull t=i*N*2+j;
					e[mm[t]].cost=a[i][j];
					t=j*N*2+i;
					e[mm[t]].cost=a[i][j];
				}
			}
		}
		kruskal();
	}
	return 0;
}
