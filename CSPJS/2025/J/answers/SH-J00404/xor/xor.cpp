#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 9;
#define re(i, n) for(ll i = 1; i <= (n); i++)
#define rr(i, l, r) for(ll i = l; i <= r; i++)
#define pb push_back
ll n, k;
ll a[N];
ll pxor[N];
map<ll, ll> buc;
pair<ll, ll> p[N]; ll cnt; 
bool cmp(pair<ll, ll> &a, pair<ll, ll> &b) {
	return a.second == b.second ? a.first > b.first : a.second < b.second;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	re(i, n) cin>>a[i];
	re(i, n) pxor[i] = pxor[i - 1] ^ a[i];
	for(int i = n; i >= 0; i--) {
		if(buc[pxor[i] ^ k])
			p[++cnt] = make_pair(i + 1, buc[pxor[i] ^ k]);
		buc[pxor[i]] = i;
	}
//	re(i, cnt) cout<<p[i].first<<" "<<p[i].second<<endl;
	
	sort(p + 1, p + cnt + 1, cmp);
	ll maxx = 0, ans = 0;
	re(i, cnt) {
		if(p[i].first <= maxx) continue;
		maxx = p[i].second; 
		ans++;
	}
	cout<<ans<<endl; 
	return 0;
}

