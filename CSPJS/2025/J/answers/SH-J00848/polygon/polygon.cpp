#include <iostream>
using namespace std;
const int MAXN = 5005, MOD = 998244353;
typedef long long ll;
int n, a[MAXN];
bool c[MAXN];
ll ans=0;
void print_c() {
	for(int i = 1;i <= n;i ++) {
		cout << c[i] << " ";
	}
}
void dfs(int k, bool ch) {
	if(k==n+1) {
		ll cur=0,max_=-0x3f3f3f3f;
		for(int i = 1;i <= n;i ++) {
			if(c[i]) cur += a[i],max_=max(max_, (ll)a[i]);
		}
		if(cur>2*max_) ans = (ans+1)%MOD;
//		printf("current c:");
//		print_c();
//		printf(", current ans=%d\n",ans);
		return;
	}
	c[k] = ch;
	if(k!=n) {
		dfs(k+1, true);
		dfs(k+1, false);
	} else dfs(k+1, 0);
	c[k] = 0;
	return;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	dfs(0, 0);
	cout << (ans - 1 + MOD) % MOD;
	return 0;
}
