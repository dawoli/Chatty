#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 998244353, maxn = 5010;
ll n, a[maxn], cnt = 1, ans = 0, counts, sm;
vector<ll> sum;

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	sum.push_back(0);
	for (ll i = 1; i <= n; i++){
		counts = sum.size();
		for (ll j = 0; j < counts; j++){
			sm = sum[j] + a[i];
			sum.push_back(sm);
			if (sm > a[i] * 2 && i >= 3) ans = (ans + 1) % mod;
		}
	}
	cout << ans;
	return 0;
}
