#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[200010][3],t,t1,t2;
ll n,q;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(ll i=1; i<=n; ++i) cin>>s[i][1]>>s[i][2];
	while(q--) {
		cin>>t1>>t2;
		ll ans=0;
		for(ll i=1; i<=n; ++i) {
			t=t1;
			ll id=t.find(s[i][1]);
			if(t.find(s[i][1])<t1.size()) {
				t.replace(id,s[i][1].size(),s[i][2]);
				if(t==t2) ++ans;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
