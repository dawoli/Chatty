#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,s[510],c[510];
ll A(ll n,ll m) {
	ll ret1=1,ret2=1;
	for (ll i=n;i>=n-m+1;i++) {
		ret1*=i;
	}
	for (ll i=m;i>=1;i--) {
		if (ret1%i==0) ret1/=i;
		else ret2*=i;
	}
	return ret1/ret2;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (ll i=1;i<=n;i++) cin>>s[i];
	for (ll i=1;i<=n;i++) cin>>c[i];
	cout<<A(n,m);
	return 0;
}
