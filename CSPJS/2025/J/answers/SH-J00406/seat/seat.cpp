#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll a[15][15],b[105];
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	ll sum=b[1];
	sort(b+1,b+n*m+1,cmp);
	ll cnt=1;
	for(ll i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(ll j=1;j<=n;j++)
			{
				a[j][i]=b[cnt++];
			}
		}
		else{
			for(ll j=n;j>=1;j--)
			{
				a[j][i]=b[cnt++];
			}
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			if(sum==a[i][j]){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
