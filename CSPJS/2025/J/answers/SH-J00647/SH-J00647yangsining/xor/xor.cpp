#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n,k,a[N],s[N];
struct node {
	ll l,r;
} b[N];
void input() {
	cin>>n>>k;
	for(ll i = 1;i <= n;i++) cin>>a[i];
}
bool cmp(node x,node y) {
	if(x.r != y.r) return x.r < y.r;
	return x.l < y.l;
}
struct Trie {
	ll maxx[N * 2],tmp[N * 2][2],tot = 0;
	void insert(ll x,ll y) {
		ll now = 0;
		for(ll i = 0;i < 20;i++) {
			ll v = (x >> i) & 1;
			if(!tmp[now][v]) tmp[now][v] = ++tot;
			now = tmp[now][v];
		}
		maxx[now] = max(maxx[now],y + 1);
	}
	ll query(ll x) {
		ll now = 0;
		for(ll i = 0;i < 20;i++) {
			ll v = (x >> i) & 1;
			if(!tmp[now][v]) return 0;
			now = tmp[now][v];
		}
		return maxx[now];
	}
} T;
void solve1() {
	for(ll i = 1;i <= n;i++) s[i] = s[i - 1] ^ a[i];
	ll cur = 0;
	for(ll i = 1;i <= n;i++) {
		for(ll j = i;j <= n;j++) {
			if((s[j] ^ s[i - 1]) == k) {
				cur += 1; b[cur].l = i; b[cur].r = j;
			}
		}
	}
	sort(b + 1,b + cur + 1,cmp);
	ll lst = 0,ans = 0;
	for(ll i = 1;i <= cur;i++) {
//		cout<<b[i].l<<" "<<b[i].r<<'\n';
		if(lst < b[i].l) {
			lst = b[i].r; ans += 1;
		}
	}
	cout<<ans<<'\n';
}
void solve() {
	for(ll i = 1;i <= n;i++) s[i] = s[i - 1] ^ a[i];
	T.insert(0,0);
	ll cur = 0;
	for(ll i = 1;i <= n;i++) {
		ll tmp2 = T.query(s[i] ^ k);
		if(tmp2) {
			cur += 1; b[cur].l = tmp2; b[cur].r = i;
//			cout<<tmp2<<" "<<i<<" "<<(s[i] ^ s[tmp2 - 1])<<" "<<(s[i] ^ k)<<" "<<s[tmp2 - 1]<<'\n';
		}
		T.insert(s[i],i);
	}
	sort(b + 1,b + cur + 1,cmp);
	ll lst = 0,ans = 0;
	for(ll i = 1;i <= cur;i++) {
		if(lst < b[i].l) {
//			cout<<b[i].l<<" "<<b[i].r<<" "<<(s[b[i].r] ^ s[b[i].l - 1])<<'\n';
			lst = b[i].r; ans += 1;
		}
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	if(n * n <= 1e7) solve1();
	else solve();
	return 0;
} 
