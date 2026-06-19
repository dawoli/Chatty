#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 5, mod = 998244353;
int n, a[N];
int ans = 0;
void dfs(int pos, int sum, int maxn, int cnt) {
	if(pos == n+1) {
		if(cnt < 3) return ;
		if(sum > maxn*2) {
			ans = (ans+1) % mod;
		}
		return ;
	}
	dfs(pos+1, sum+a[pos], max(maxn, a[pos]), cnt+1);
	dfs(pos+1, sum, maxn, cnt);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	dfs(1, 0, 0, 0);
	cout << ans%mod << endl;
	return 0;
}
