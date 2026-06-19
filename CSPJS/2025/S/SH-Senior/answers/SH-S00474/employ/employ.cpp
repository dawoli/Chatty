#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=510,mod=998244353;
string s;
ll n,m,ans,c[N],p[N];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s,s=" "+s;
	for(ll i=1; i<=n; ++i) cin>>c[i];
	for(ll i=1; i<=n; ++i) p[i]=i;
	do {
		ll sum=0,cnt=0;
		for(ll i=1; i<=n; ++i)
			if(cnt>=c[p[i]]) ++cnt;
			else {
				if(s[i]=='1') ++sum;
				else ++cnt;
			}
		if(sum>=m) ans=(ans+1)%mod;
	} while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}
