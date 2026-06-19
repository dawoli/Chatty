#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 5,mod = 998244353;
ll n,ans,a[N],tmp[N];
void input() {
	cin>>n;
	for(ll i = 1;i <= n;i++) cin>>a[i];
}
bool check1() {
	for(ll i = 1;i <= n;i++) {
		if(a[i] != 1) {
			cout<<a[i]<<'\n';
			return 0;
		}
	}
	return 1;
}
ll calc(ll x,ll y) {
	if(x == y) return 1;
	return tmp[x] / tmp[x - y] / tmp[y];
}
void solve1() {
	tmp[1] = 1;
	for(ll i = 2;i <= n;i++) tmp[i] = (tmp[i - 1] * i) % mod;
	for(ll i = 3;i <= n;i++) {
		ans = (ans + calc(n,i)) % mod;
	}
	cout<<ans<<'\n';
}
void solve2() {
	ll sum = 0,maxx = 0;
	for(ll i = 1;i <= n;i++) {
		sum += a[i]; maxx = max(maxx,a[i]);
	}
	if(sum > maxx * 2) cout<<1<<'\n';
	else cout<<0<<'\n';
}
void dfs(ll pos,ll sum,ll maxx,ll cnt) {
	if(pos == n + 1) {
		if(sum > maxx * 2 && cnt >= 3) ans += 1;
		return;
	}
	dfs(pos + 1,sum + a[pos],max(maxx,a[pos]),cnt + 1);
	dfs(pos + 1,sum,maxx,cnt);
}
void solve3() {
	dfs(1,0,0,0);
	cout<<ans<<'\n';
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	if(n <= 3) solve2();
	else if(n <= 20) solve3();
	else if(check1()) solve1();
	return 0;
} 
