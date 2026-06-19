#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans,p=998244353;
ll a[5005];
ll f[5005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	f[0]=1;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=a[i]+1;j<=5001;j++)
		{
			ans+=f[j];
			if(ans>=p)ans-=p;
		}
		for(ll j=5001;j>=0;j--)
		{
			m=j+a[i];
			if(m>5001)m=5001;
			f[m]+=f[j];
			if(f[m]>=p)f[m]-=p;
		}
	}
	cout<<ans;
	return 0;
}
