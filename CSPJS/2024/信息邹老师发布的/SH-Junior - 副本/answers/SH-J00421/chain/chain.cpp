#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
vector<ll> s[N];
ll t,n,k,q,r,c,l[N];
bool ans;
void dfs(ll stp,ll ch,ll lst) {
	if(stp>r) {
		if(ch==c) ans=1;
		return;
	}
	for(ll i=1; i<=n; ++i)
		if(i!=lst)
			for(ll x=1; x<=l[i]; ++x)
				if(s[i][x]==ch)
					for(ll y=x+1; y<=l[i] && y-x+1<=k; ++y)
						dfs(stp+1,s[i][y],i);
}
void solveBF() {
	ans=0;
	dfs(1,1,0);
	cout<<ans<<"\n";
}
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n>>k>>q;
		for(ll i=1,x; i<=n; ++i) {
			cin>>l[i];
			s[i].clear();
			s[i].push_back(0);
			for(ll j=1; j<=l[i]; ++j) cin>>x,s[i].push_back(x);
		}
		while(q--) {
			cin>>r>>c;
			solveBF();
		}
	}
	return 0;
}
