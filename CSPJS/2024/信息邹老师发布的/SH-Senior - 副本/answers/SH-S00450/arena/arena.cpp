#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
vector<char> d[2*N];
ll n,m,t,x[4],a[N],b[N],c[N];
ll dfs(ll l,ll r) {
	if(l==r) return l;
	ll mid=(l+r)>>1,resL=dfs(l,mid),resR=dfs(mid+1,r);
	ll R=log2(r-l+1),G=r/(r-l+1);
	if(d[R][G]=='0') return min(resL,resR);
	else return max(resL,resR);
}
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1; i<=n; ++i) cin>>a[i];
	for(ll i=1; i<=m; ++i) cin>>c[i];
	for(ll i=1,k=ceil(log2(n)); i<=k; ++i) {
		d[i].push_back(' ');
		char x;
		for(ll j=1; j<=1ll<<(k-i); ++j) {
			cin>>x;
			d[i].push_back(x);
		}
	}
	cin>>t;
	while(t--) {
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(ll i=1; i<=n; ++i) b[i]=a[i]^(x[i%4]);
		ll ans=0;
		for(ll i=1; i<=n; ++i) ans^=i*dfs(1,c[i]);
		cout<<ans<<"\n";
	}
	return 0;
}
