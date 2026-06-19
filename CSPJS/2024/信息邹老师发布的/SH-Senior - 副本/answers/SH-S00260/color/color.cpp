#include<bits/stdc++.h>
using namespace std;

typedef long long ll; 
const ll N=200005;
ll n,a[N];

inline void maxa(ll&x,ll b) {
	x=max(x,b);
}

namespace dp1 {
	const ll Ndp=2005;
	ll f[Ndp][2][Ndp];

	void solve() {
		memset(f,0,sizeof f);
		for(ll i=1; i<=n; ++i) {
			for(ll k=0; k<=1; ++k) {
				for(ll p=0; p<=i-2; ++p) {
					f[i][k][p]=f[i-1][k][p]+(a[i]==a[i-1])*a[i];
				}
				for(ll p=0; p<=i-2; ++p) {
					maxa(f[i][k][i-1],f[i-1][1-k][p]+(a[i]==a[p])*a[i]);
				}
			}
		}
		ll ans=0;
		for(ll k=0; k<1; ++k) {
			for(ll p=0; p<n; ++p) {
				maxa(ans,f[n][k][p]);
			}
		}
		cout<<ans<<endl;
	}
}

namespace dp1v {
	ll f[2][2][N];

	void solve() {
		memset(f,0,sizeof f);
		for(ll i=1; i<=n; ++i) {
			ll cur=i&1;
			for(ll k=0; k<=1; ++k) {
				for(ll p=0; p<=i-2; ++p) {
					f[cur][k][p]=f[cur^1][k][p]+(a[i]==a[i-1])*a[i];
				}
				for(ll p=0; p<=i-2; ++p) {
					maxa(f[cur][k][i-1],f[cur^1][1-k][p]+(a[i]==a[p])*a[i]);
				}
			}
		}
		ll ans=0;
		for(ll k=0; k<1; ++k) {
			for(ll p=0; p<n; ++p) {
				maxa(ans,f[n&1][k][p]);
			}
		}
		cout<<ans<<endl;
	}
}

int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ll T;
	cin>>T;
	while(T--) {
		cin>>n;
		for(ll i=1; i<=n; ++i) cin>>a[i];
		dp1v::solve();
	}
	return 0;
}

