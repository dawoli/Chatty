#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5009, MOD = 998244353;
#define re(i, n) for(ll i = 1; i <= (n); i++)
#define rr(i, l, r) for(ll i = l; i <= r; i++)
#define pb push_back
ll n, a[N];
ll dp[N * 2];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	re(i, n) cin>>a[i];
	sort(a + 1, a + n + 1); 
	ll maxx = a[n];
	dp[0] = 1;
	ll ans = 0;
	re(i, n) {
		rr(j, a[i] + 1, maxx * 2 + 1) {
			ans = (ans + dp[j]) % MOD;
		}
		for(int j = maxx * 2 + 1; j >= 0; j--) {
			dp[min(j + a[i], maxx * 2 + 1)]
			 = (dp[j] + dp[min(j + a[i], maxx * 2 + 1)]) % MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}

