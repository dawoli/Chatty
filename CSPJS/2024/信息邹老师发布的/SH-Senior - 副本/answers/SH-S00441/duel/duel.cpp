#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll a[301100];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll j;
		cin>>j;
		a[j]++;
	}
	for(ll i=1;i<=100000;i++){
		if(a[i]>0)ans=max(ans,a[i]);
	}
	cout<<ans;
	return 0;
}
