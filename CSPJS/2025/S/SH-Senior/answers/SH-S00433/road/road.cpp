#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,t,u,v,sum,tot;
struct node
{
	ll x;
	ll y;
	ll z;
};
bool cmp(node P,node Q)
{
	return P.z<Q.z;
}
node f[1100005];
int p[100015];
ll find(ll P)
{
	if(P!=p[P])p[P]=find(p[P]);
	return p[P];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;tot=n+k-1;
	for(int i=1;i<=n+k;i++)p[i]=i;
	for(int i=1;i<=m;i++)cin>>f[i].x>>f[i].y>>f[i].z;
	for(int i=n+1;i<=n+k;i++)
	{
		cin>>u;sum+=u;
		for(int j=1;j<=n;j++)
		{
			m++;
			f[m].x=i;
			f[m].y=j;
			cin>>f[m].z;
		}
	}
	sort(f+1,f+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		u=find(f[i].x);v=find(f[i].y);
		if(u!=v)
		{
			p[u]=v;
			sum+=f[i].z;
			tot--;
			if(tot==0)break;
		}
	}
	cout<<sum;
	return 0;
}
