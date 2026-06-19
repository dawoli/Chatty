#include<bits/stdc++.h>
#define ll long long
const ll N=1e4+5;
using namespace std;
ll n,m,k,r[N][N],baile[N],i,ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(r,-1,sizeof(r));
	for(i=1;i<=m;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		r[a][b]=c;
		r[b][a]=c;
		baile[i]=c;
	}
	
	sort(baile,baile+m+1);
	for(int i=1;i<=n-1;i++)
	{
		ans+=baile[i];
	}
	cout<<ans;
}
