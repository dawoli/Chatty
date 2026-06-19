#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define up(i,a,b) for (ll i=(a);i<=(b);++i)
#define down(i,a,b) for (ll i=(a);i>=(b);--i)
const ll MOD=998244353;
const ll N=510;
ll n,m,c[N];
bool s[N];
namespace N10{
	ll p[N];
	void solve() {
		ll ans=0;
		up(i,1,n) {
			p[i]=i;
		}
		do {
			ll cnt=0;
			ll cntFailed=0;
			up(i,1,n) {
				if (cntFailed>=c[p[i]]) {
					++cntFailed;
					continue;
				}
				if (s[i]==0) {
					++cntFailed;
				} else {
					++cnt;
				}
			}
			ans+=(cnt>=m);
		} while (next_permutation(p+1,p+n+1));
		cout<<ans%MOD<<'\n';
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string str;
	cin>>n>>m>>str;
	up(i,1,n) {
		s[i]=(str[i-1]-'0');
	}
	up(i,1,n) {
		cin>>c[i];
	}
	if (n<=10) {
		N10::solve();
		return 0;
	}
	return 0;
}

