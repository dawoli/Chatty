#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;
ll ans = 1;
int n;


int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n;
    for (ll i=1;i<=n;i++){
    	ans *= i;
    	ans %= MOD;
	}
	cout << ans % MOD;
    return 0;
}
