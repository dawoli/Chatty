#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5*1e5+5;
ll a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	bool temp=true;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) temp=false;
	}
	if(temp){
		cout<<n/2;
		return 0;
	}
	ll cnt=0,mx=0;
	for(ll i=1;i<=n;i++)
	{
		if(a[i]==k) mx++;
	}
	for(ll i=1;i<n;i+=2)
	{
		if((a[i]^a[i+1])==k) cnt++;
	}
	cout<<max(mx,cnt);
	return 0;
}
