#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll N=1e5+10;
pair<ll,ll> a[N];
ll n,m,cnt[N],ans;
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1,r; i<=n; ++i) cin>>r,++cnt[r];
	for(ll i=1; i<=1e5; ++i) if(cnt[i]) a[++m]= {i,cnt[i]};
	if(m==1) {
		cout<<a[1].se;
		return 0;
	}
	sort(a+1,a+m+1);
	for(ll i=2,j=1; i<=m; ++i) {
		ll cnt=a[i].se;
		while(j<i) {
			if(a[j].se>=cnt) {
				a[j].se-=cnt;
				break;
			} else cnt-=a[j].se,a[j].se=0;
			++j;
		}
	}
	for(ll i=1; i<=m; ++i) ans+=a[i].se;
	cout<<ans;
	return 0;
}
